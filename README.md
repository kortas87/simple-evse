# NEWS #

**24.12.2014**

---

At the moment we are testing new sealed AC/DC converters which should replace the original black 12V 500mA power adapters. The greatest advantage is that these power supply units are small enough to fit in the connector J1772 easily (no need for pushing or changing anything) and they are more or less water resistant (please do not forget that in the connector there are usually other things as well which may cause short if too much of water gets in - e.g. relay contacts)

## Project introduction ##

We have developed a board based on PIC microcontroller which is able to generate 1kHz PWM signal, detect the vehicle and control the relay. It is also possible to adjust PWM width for current regulation. The board is small enough to be installed directly into J1772 Yazaki connector.

The kit can be obtained from [EV Power](http://www.ev-power.eu/index.php?cl=search&searchparam=EVSE) (Czech Republic).

  * [How to make your own J1772 connector with EVSE](SimpleEvseJ1772guide.md)
  * [J1772 button connection scheme](J1772buttonConnectionSchematic.md)
  * [Setting different charging current limit (6 - 20A)](HowToSetDifferentCurrentLimit.md)

![http://evracing.cz/wiki/simple-evse/images/evse-scheme.png](http://evracing.cz/wiki/simple-evse/images/evse-scheme.png)

![http://evracing.cz/wiki/simple-evse/images/j1772_final_before_covering_400.jpg](http://evracing.cz/wiki/simple-evse/images/j1772_final_before_covering_400.jpg)


# EVSE Kit includes #

1. Mounted PCB including microcontroller with latest [firmware](http://code.google.com/p/simple-evse/source/checkout)

![http://evracing.cz/wiki/simple-evse/images/board_400.jpg](http://evracing.cz/wiki/simple-evse/images/board_400.jpg)

2. 12V DC power supply

![http://evracing.cz/wiki/simple-evse/images/dc_12V_400.jpg](http://evracing.cz/wiki/simple-evse/images/dc_12V_400.jpg)

3. AC relay 230V 20A

![http://evracing.cz/wiki/simple-evse/images/relay_400.jpg](http://evracing.cz/wiki/simple-evse/images/relay_400.jpg)