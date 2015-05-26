# PWM implementation #

For more information check http://en.wikipedia.org/wiki/SAE_J1772

**6-50A**
  * Amps = Duty cycle X 0.6
  * Duty cycle = Amps / 0.6

**51-80A**
  * Amps = (Duty cycle - 64) X 2.5
  * Duty cycle = (Amps / 2.5) + 64


| 6A  | 10% |
|:----|:----|
| 12A | 20% |
| 18A | 30% |
| 24A | 40% |
| 30A | 50% |
| 40A | 66% |
| 48A | 80% |
| 65A | 90% |
| 75A | 94% |
| 80A | 96% |

---


Code:
```

if (amps < 51)
  duty = 1000 - (100 * amps) / 6;
else
  duty = 1000 - (4*amps+640);

//set PWM output 10bit
CCPR1L = duty >> 2;
duty &= 0b00000011;
duty <<= 4;
CCP1CON = duty + 12; //1100

```