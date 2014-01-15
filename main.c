/*
 * File:   main.c
 * Author: Petr Kortanek, i4wifi a.s.
 *
 * Created on 23rd November 2013
 *
 * 11.1.2013 - využití MCLR vstup na tlačítko
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
char button_pressed_counter = 0;
char current_settings = 16;
char runADCflag = 0;

//attached to RC1
void relayon() {
  latchc = latchc | 0b00000010;
  PORTC = latchc;
}
void relayoff() {
  latchc = latchc & 0b11111101;
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

void main() {

    OSCCON = 0b01101010; // 4MHz

    TRISA = 0b11111111; //pilot detect RA2, button detect RA3
    TRISC = 0b11110001; //relay RC1, LED RC2, pilot RC3
    latcha = 0;
    latchc = 0;
    PORTA = latcha;
    PORTC = latchc;

    ADCON1 = 0b01100000; // f/64 4MHz, 16 us
    ADON = 1;
    ADCON0bits.CHS = 2; //RA2

    //pilot PWM RC3
    PSTR1CONbits.STR1C = 1;
    APFCON1bits.P1CSEL = 0; //P1C function is on RC3
    
    PR2 = 249 ;//period value
    CCP1CON = 0b00001100; //PWM mode

    OPTION_REGbits.nWPUEN = 0;
    //old: WPUAbits.WPUA4 = 1; //button pressed detect
    WPUAbits.WPUA3 = 1; //button pressed detect - MCLR

    //T2CON timer ON + prescaler 4
    T2CON = 0b00000101 ;

    GIE = 1;
    PEIE = 1;
    ADIE = 1;
    TMR2IE = 1;
    
    while(1) {

        //current limits
        if (current_settings < 5)
          current_settings = 5;
        if (current_settings > 20)
          current_settings = 20;

        //PWM width
        CCPR1L = 256 - current_settings*4;

        //MODE set current
        if(Button_pressed == 0) {
          button_pressed_counter++;
          //setting mode entered - rapid led flashing
          if (button_pressed_counter == 5) {
            button_flashing();
            current_settings = 0;
          }
          if (button_pressed_counter >= 5) {
            current_settings++;
            ledoff();
            __delay_ms(350);
            ledon();
            __delay_ms(350);
          } else {
            __delay_ms(900);
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

        runADCflag = 1;
        __delay_ms(5);
    }
}

void interrupt isr() {

  if (ADIF) {
    pilot_value = ADRESH;
    ADIF = 0;
  }
  //rising edge MCU, pilot falling edge
  if (TMR2IF) {
    TMR2IF = 0;
    if (runADCflag == 1) {
      runADCflag = 0;
      __delay_us(950);
      GO_nDONE = 1;
    }
  }
}

