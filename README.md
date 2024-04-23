# Group-34-ECE-Senior-Design-LED-Code

About
-----
The following GitHub repository includes the final release version of the code utilized in our coaster device.
In this document, we will detail how you can install the Arduino IDE and other necessary software to flash your own code to our coaster device to mess around with the LED Matrix onboard the PCB. 

Install
-------
Step 1: Follow this document to download the Arduino IDE: https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE

Step 2: Follow this document to install the Raspberry Pi Pico W board manager library onto your working environment: 
(Start at Step 6 for Windows/Mac users!!!)
https://www.tomshardware.com/how-to/program-raspberry-pi-pico-with-arduino-ide

Step 3: Install LedControl 

Acquire the latest release of the LedControl library from the following link (click on the .zip file to download it):
https://github.com/wayoda/LedControl/releases

Import the ZIP file of the LedControl library into the Arduino IDE, here is a link explaining how to do so if needed:
https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries/

Congrats! You have finished setting up your development environment!

Documentation (How to create designs on the LED Matrix)
-------------
Step 1: Follow this link to access the sprite generator: https://embed.plnkr.co/3VUsekP3jC5xwSIQDVH
<img width="606" alt="Screen Shot 2024-04-04 at 10 55 08 AM" src="https://media.github.ncsu.edu/user/19411/files/e141a93b-a65f-44fd-bce1-012e42f1528c">

Step 2: Set the rows and columns to 8x8 (the size of the LED matrix) and fill in each square to create your design.

Step 3: At the bottom of the screen, the generator generates an array of bytes that represents each row of the matrix and which LEDs should be on(a bit of 1) and which LEDs should be off(a bit of 0).

Step 4: Using the LedControl library functions from the documentation, set any specific rows, columns, or single LEDs to turn on. You can implement your own functions to perform various patterns such as scrolling, flashing, or use the brightness function to change the intensity of each LED.

(Make sure you are using the Raspberry Pi PICO W board in the Arduino IDE when flashing code!)

(If you are struggling with flashing code to the PICO, try holding the BOOTSEL button on the PICO while plugging the USB cable into your computer, make sure to click on the "Select other board and port..." menu from the dropdown box next to the upload and debug buttons, then click on the "Show all ports" box.)

(We recommend using the Final Code.ino file as a good starting point as that is what was flashing on the coaster when it was packaged!)

Libraries
---------
Below are the links to documentation for the individual code libraries used in this project:
LedControl: https://wayoda.github.io/LedControl/pages/software.html


__We hope you enjoyed Design Day and our project! Happy coding and Go Pack!__
