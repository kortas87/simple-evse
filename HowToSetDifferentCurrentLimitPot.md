#How to set different charging current limit (pot)

# Setting different charging current limit (potentiometer) #

You can use a potentiometer to change PWM width (charging current).

![http://evracing.cz/wiki/simple-evse/images/controll_pot.jpg](http://evracing.cz/wiki/simple-evse/images/controll_pot.jpg)

Default charging current 16A is set every time the plug is removed from the electric network (reset).

Here is an algorithm used:
```

//we get current limit from the pot
if (pot_value <= 222) { //<4.4V, amps 6-80
  amps = 6 + (222-pot_value)/3;
}

```

Then if we know ampers and want to determine voltage on the pin:
```
pot_value = 240-3*amps
Vpin = 5*pot_value/255
```

  * for 32A the voltage should be around 2.82V
  * for 10A the voltage should be around 4.12V

Minimum is 6A and the voltage is 4.35V. Above 4.4V it means that this potentiometer feature of setting current is not used and default 16A is used.