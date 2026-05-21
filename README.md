# Alicat_mass_flow_controller_arduino
Arduino (Teensy) firmware to control three Alicat "GP" firmware mass flow controllers

These are old Alicat mass flow controllers, which are so old, they do not quite follow the specification currently published by Alicat.  As far as I can tell, they only will accept a flow control integer.  No other functions (gas type, etc) can be changed via RS232.  Gas type can be changed via the front panel buttons, and will remain after a power cycle.

![Controllers connected to Teensy](controllers.png)



![Three hardware serial ports on Teensy](wiring.png)
