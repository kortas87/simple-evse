#This guide will show you how to build a J1772 charging station.

We suppose that you have prepared J1772 connector and simple-evse kit. These components can be obtained from [EV Power](http://www.ev-power.eu/index.php?cl=search&searchparam=EVSE).

## Step 1 ##

Disassemble the connector and prepare a hole for LED and connect it to the board.

![http://evracing.cz/wiki/simple-evse/images/j1772_LED_installed_400.jpg](http://evracing.cz/wiki/simple-evse/images/j1772_LED_installed_400.jpg)

## Step 2 ##

Install 230V to 12V DC power source. You will need to take the main board out of the black case.

![http://evracing.cz/wiki/simple-evse/images/j1772_DC-12V_installed_400.jpg](http://evracing.cz/wiki/simple-evse/images/j1772_DC-12V_installed_400.jpg)

## Step 3 ##

Prepare the end of the cable. You should cut the orange isolation about 4cm in order to get L wire long enough. N + PE will be longer however it does not matter.

![http://evracing.cz/wiki/simple-evse/images/cable_cut_400.jpg](http://evracing.cz/wiki/simple-evse/images/cable_cut_400.jpg)

## Step 4 ##

Install relay which interrupts mains (red wire). The most reliable method is probably soldering (only fastons are not recommended). L + N goes in DC adaptor and PE needs to join GND.

![http://evracing.cz/wiki/simple-evse/images/relay_mounting_400.jpg](http://evracing.cz/wiki/simple-evse/images/relay_mounting_400.jpg)

## Step 5 ##

Connect the remaining very short wire from button (microswitch) to pin 1 of programming connector (5 pin header). This pin is set as input with internal pull up resistor. [Details of this connection](J1772buttonConnectionSchematic.md).

![http://evracing.cz/wiki/simple-evse/images/button_connection_400.jpg](http://evracing.cz/wiki/simple-evse/images/button_connection_400.jpg)

## Step 6 ##

Stack everything inside the connector with care and screw the second half to it. Do not use any force. If you did well it should go together smoothly.

![http://evracing.cz/wiki/simple-evse/images/j1772_final_before_covering_400.jpg](http://evracing.cz/wiki/simple-evse/images/j1772_final_before_covering_400.jpg)

## Step 7 ##

Finally you can mount any of common connector to use this cable in a regular socket. However these connectors are not supposed to conduct 16A continuously and high quality connector with properly tightend terminals must be used.

![http://evracing.cz/wiki/simple-evse/images/schuko_400.jpg](http://evracing.cz/wiki/simple-evse/images/schuko_400.jpg)
![http://evracing.cz/wiki/simple-evse/images/schuko2_400.jpg](http://evracing.cz/wiki/simple-evse/images/schuko2_400.jpg)

The kit can be obtained from [EV Power](http://www.ev-power.eu/index.php?cl=search&searchparam=EVSE) (Czech Republic).