/*
 * File:   main.c
 * Author: Petr Kortanek, i4wifi a.s.
 *
 * Created on 23rd November 2013
 *
 * 2014-01-11 - RA3 (MCLR, prog 1) input for button
 * 2014-04-09 - RA0 (ICSPDAT, prog 4) potentiometer input
 * 2014-08-11 - fixed PWM duty (+10bit), RA1 (ICSPCLK, prog 5) input switch 6A / 10A
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#define _XTAL_FREQ 4000000
#define Button_pressed PORTAbits.RA3

#pragma config LVP = OFF, MCLRE = OFF, BOREN = OFF, PLLEN = OFF, FOSC = INTOSC, WDTE = OFF, CP = OFF, PWRTE = OFF

char latcha = 0;
char latchc = 0;
char pilot_value = 255;
char pot_value = 255;
char pot_value2 = 255;
char adchannel = 2;
char measure_nth = 0;
char button_pressed_counter = 0;
char amps = 16;
char amps_to_set = 16;
char setbypot = 0;
short duty = 500; //50%

//attached to RC1
void relayon() {
  latchc = latchc | 0b00000011;//RC1+backup RC0
  PORTC = latchc;
}
void relayoff() {
  latchc = latchc & 0b11111100;//RC1+backup RC0
  PORTC = latchc;
}

//attached to RC2
void ledon() {
  latchc = latchc | 0b00000100;
  PORTC = latchc;
}
void ledoff() {
  latchc = latchc & 0b11111011;
  PORTC = latchc;
}

void button_flashing() {
  for (int i=0; i<20; i++) {
    ledon();
    __delay_ms(30);
    ledoff();
    __delay_ms(30);
  }
}

void setAmps() {
  setbypot = 0;

  //we get current limit from the pot
  if (pot_value <= 222) { //<4.4V, amps 6-80
    amps = 6 + (222-pot_value)/3;
    setbypot = 1;
  }
  //we get current limit from the "pot2" (set 6A / 10A)
  if (pot_value2 <= 222) { //<4.4V,
    amps = 10;
    if (pot_value2 <= 25) { //short => amps 6 ~ >3kOhm
      amps = 6;
    }
    setbypot = 1;
  }
  if (setbypot == 0) {
    amps = amps_to_set;
  }
  //minimum
  if (amps < 5)
    amps = 5;
  //maximum
  if (amps > 80)
    amps = 80;
  
  //compute PWM duty
  if (amps < 51)
    duty = 1000 - (100 * amps) / 6;
  else
    duty = 1000 - (4*amps+640);

  //set PWM output 10bit
  CCPR1L = duty >> 2;
  duty &= 0b00000011;
  duty <<= 4;
  CCP1CON = duty + 12; //1100

}

void main() {

    OSCCON = 0b01101010; // 4MHz

    TRISA = 0b11111111; //pilot detect RA2, button detect RA3, pot RA0, pot2 RA1
    TRISC = 0b11110000; //relay RC1 (+backup RC0), LED RC2, pilot RC3
    latcha = 0;
    latchc = 0;
    PORTA = latcha;
    PORTC = latchc;

    ADCON1 = 0b01100000; // f/64 4MHz, 16 us
    ADON = 1; //channel: RA2=PWM detect, RA0=pot value, RA1=pot2 value
    ADCON0bits.CHS = 2;

    //pilot PWM RC3
    PSTR1CONbits.STR1C = 1;
    APFCON1bits.P1CSEL = 0; //P1C function is on RC3
    
    PR2 = 249 ;//period value
    CCP1CON = 0b00001100; //PWM mode

    OPTION_REG = 0b00000001; //pullups and TMR0
    WPUAbits.WPUA3 = 1; //button pressed detect - MCLR
    WPUAbits.WPUA1 = 1;  //6A / 10A input RA1

    //T2CON timer ON + prescaler 4
    T2CON = 0b00000101 ;

    //INTCON = 0b11100000;
    GIE = 1;
    PEIE = 1;
    
    ADIE = 1;
    TMR2IE = 1;
    
    setAmps();

    while(1) {

        //MODE set current
        if(Button_pressed == 0) {
          button_pressed_counter++;
          //setting mode entered - rapid led flashing
          if (button_pressed_counter == 5) {
            button_flashing();
            amps_to_set = 0;
          }
          if (button_pressed_counter >= 5) {
            amps_to_set++;
            setAmps();
            ledoff();
            __delay_ms(300);
            ledon();
            __delay_ms(300);
          } else {
            __delay_ms(800);
          }

        //MODE normal operation
        } else {
          if(button_pressed_counter>=5) {
            //current setting mode exit confirmation
            button_flashing();
          }
          button_pressed_counter = 0;

          //car connected (pilot pulled down <8V)
          if(pilot_value < 111) {
            relayon();
            ledon();
            __delay_ms(800);

          } else {
            ledon();
            __delay_ms(30);
            relayoff();
          }
          ledoff();
          __delay_ms(300);
        }
    }
}

void interrupt isr() {

  //channel: RA2=PWM detect or RA0=pot value
  if (ADIF) {
    if (adchannel == 0) {
      pot_value = ADRESH;
      setAmps();
      adchannel = 1;
    } else if (adchannel == 1) {
      pot_value2 = ADRESH;
      setAmps();
      adchannel = 2;
    } else   {
      pilot_value = ADRESH;
      adchannel = 0;
    }
    ADCON0bits.CHS = adchannel;
    ADIF = 0;
  }

  if (TMR2IF) {
    TMR2IF = 0;
    //voltage must be measured when voltage is "up"
    measure_nth++;
    if (measure_nth>98) {
      __delay_us(950);
      GO_nDONE = 1;
      measure_nth = 0;
    }
  }
}

