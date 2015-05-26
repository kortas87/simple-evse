#Frequently Asked Questions

## What is the maximum allowed current of the relay-coil, that the board can handle? ##

This current is mainly determined by a transistor 2N7002 - maximum of 115mA according to a datasheet. Recommendation is that the current is lower than 80mA which should be enough for common automotive relay having coil resistance 180 Ohm. We also recommend to use anti-parallel diode directly mounted on a relay to minimize high voltage spikes.

## When I plug in the car I only get 13,2 Amps. Why? ##

You have probably reached the limit of the internal's vehicle charger. EVSE tells the car that it can charge 16A, however the car cannot. In other words EVSE can limit the current however it cannot "boost" the internal charger to exceed its limits.

Here are some limits of tested vehicles:

  * PHEV Mitsubishi Outlander 14.5A
  * C-zero 13A

## Sometimes the EVSE "tries" to trigger relay (you can hear relay clicking) and stays on after a few attempts, why? ##

You have probably PE wire not connected. EVSE uses isolated AC/DC converter and PE should have the same potencial as N. When you do not connect PE, then the potencial of GND is somewhere between 0 - 300V (undefined, floating <== it is isolated power supply so it is correct). When relay is triggered then this undefined potencial can change (there is always some capacitance between AC and DC side) and this change can cause processor to reset and relay is opened and then quickly connected back when processor starts up again.

## What vehicles have you tried to charge with simple EVSE? ##

Simple EVSE circuit was successfully tested with following vehicles:

  * Mitsubishi iMiev (C-Zero etc.)
  * Nissan Leaf
  * Opel Ampera
  * eGolf
  * Mitsubishi Outlander
  * Citroen Berlingo Electrique