#This guide will show you how to build EVSE charging station.

<img src='http://evracing.cz/wiki/simple-evse/images/type2station_description.png' align='right' />


You can use either J1772 connector as well as IEC 62196-2 connector (DSIEC 2B).

These products can be obtained from [EV Power](http://www.ev-power.eu/index.php?cl=search&searchparam=EVSE)

## Introduction ##

Here is a list of cars having J1772/Type 2 charging possibilities. All of these cars can be charged at a station built using simple EVSE kit. In this document we will show you how make such a charging station. The maximum amperage (charging power) is limited **only** by cars internal charger of course ([FAQ](FAQ.md)).

**NOTE: We have tested our station made according to this guide with a new eGolf - it does work.**

Basic information about signaling protocol and connectors:
  * http://en.wikipedia.org/wiki/SAE_J1772#Signaling
  * http://en.wikipedia.org/wiki/IEC_62196

### J1772 cars ###
  * Nissan Leaf
  * Citroen Berlingo Electrique
  * Opel Ampera
  * Renault Fluence
  * Mitsubishi Miev
  * Mitsubishi Outlander PHEV
  * Mia Electric
  * Citroen C-Zero
  * Peugeot iOn
  * Tesla (with adapter)

### Mennekes 62196-2 cars ###
  * BMW i3
  * Renault ZOE 22kW charging
  * Volkswagen (eUp, eGolf)
  * Skoda
  * Audi
  * Smart
  * Mercedes
  * Tesla S

![http://evracing.cz/wiki/simple-evse/images/mennekes-konektor.png](http://evracing.cz/wiki/simple-evse/images/mennekes-konektor.png)

**WARNING: This guide does not include any information about PP (proximity pilot). Please check more information about it in Wikipedia - see the links above (IEC\_62196). PP-PE resistance should normally tell the EVSE the cable's cross-section in order to allow safe current, however simple EVSE does not care about that (therefore simple). Your cable should probably include appropriate PP resistor, or car may refuse to charge.**

## Step 1 - prepare EVSE-KIT wiring harness ##

![http://evracing.cz/wiki/simple-evse/images/evse-kit_connection_description.jpg](http://evracing.cz/wiki/simple-evse/images/evse-kit_connection_description.jpg)

## Step 2 - prepare distribution box and power cables ##

![http://evracing.cz/wiki/simple-evse/images/rozvadec.jpg](http://evracing.cz/wiki/simple-evse/images/rozvadec.jpg)

## Step 3 - install components ##

  * make a hole for LED
  * install button
  * you can also use potentiometer or switch(es) for current controll
  * install 4-pole contactor and circuit breaker

![http://evracing.cz/wiki/simple-evse/images/led_button.jpg](http://evracing.cz/wiki/simple-evse/images/led_button.jpg)
![http://evracing.cz/wiki/simple-evse/images/contactor.jpg](http://evracing.cz/wiki/simple-evse/images/contactor.jpg)

## Step 4 - close the box ##

You can see how easily EVSE-KIT fits in.

![http://evracing.cz/wiki/simple-evse/images/evse-kit_hidden.jpg](http://evracing.cz/wiki/simple-evse/images/evse-kit_hidden.jpg)

## Step 5 - get some vehicles to charge! ##

![http://evracing.cz/wiki/simple-evse/images/vehicles.jpg](http://evracing.cz/wiki/simple-evse/images/vehicles.jpg)

## Note about Type2 extension cable ##

Please note that it is not possible to extend connector DSIEC2E using DSIEC2B. It needs to be plugged directly to a car (=DSIEC2F). It means that you cannot use DSIEC2B-2E cord to extend the cable! These connectors do not act as regular male/female and pins at DSIEC2B are too deep so there is no contact for CP and PP.

In fact DSIEC2F (vehicle's inlet = socket) would have to be used to provide such an extension.

![http://evracing.cz/wiki/simple-evse/images/extension_cables.png](http://evracing.cz/wiki/simple-evse/images/extension_cables.png)