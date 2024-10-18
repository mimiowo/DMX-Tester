# DMX-Tester
An Arduino-based DMX512 tester for lighting equipment purposes.

# How to use

1- Edit the fixture parameters and channels to use in the loadParameters() section. You can load parameters of more than one machine in the loadParameters() section, sepparated by if sentences corresponding to the machine name.<br />
2- Change the name of the test machine used ("lb200") to the machine you're going to use in the loadParameters() call inside the setup() section.<br />
3- If needed, change what does every individual fader do.<br />
4- Upload the code to your Arduino NANO.<br />
5- Enjoy!

# NOTES

-The DMX output is set by default to PIN 3. To change that, simply specify it in line 6.<br />
-The faders have to be plugged into A0 - A7.<br />
