# CAT_Box
RS-232 CAT control for your Kenwood (or other) radio.  Sends macros at the push of a button.

This is a very simple RS-232 serial interface between and Arduino Nano and a radio (I have used it with the Ts-890S.)  You hardcode the CAT commands (macros) into the Nano, hit a button, and the nano sends the CAT commands to the radio through a serial level converter.  

![alt text](https://github.com/joshuajayg/CAT_Box/blob/main/Images/20240101_161745.jpg?raw=true)
![alt text](https://github.com/joshuajayg/CAT_Box/blob/main/Images/20240102_204656.jpg?raw=true)

Thank you to Chris at ignorantofthings.com for the code for the resistor ladder, explanations on his website, and calculator spreadsheet.

Construction:
  Assembly is pretty straight forward.  
  -You can use any number of input buttons you want as long as the ADC resolution will not confuse which putton you are pressing.  Use Chris's spreadsheet here: https://www.ignorantofthings.com/2018/07/the-perfect-multi-button-input-resistor.html to choose the correct resistor values.
  -It is very important to use 3.3v for the MAX3232 power.  Scope traces show that with a 5v supply, it is not possible for the Serial-USB converter to pull down the Nano's RX line enough to send serial data.  Uploading sketches will not be possible if you connect the MAX3232 to 5v power.  A work around would be to use the soft serial library and use different pins for the MAX3232 than the hardware serial port on the Nano.
  -The Nano's USB port is used for power and sketch uploads, the RS-232 port connects to the radio with a null modem cable.  All you need is TX,RX,and GND connected.  At this point, the radio's TX side is not even used.
  -Upload the edited CAT_Box.ino to your Nano with your own macros inserted.
  -The serial port is defaulted to 9600b so either set your radio to 9600b or change the sketch to something your radio wants.
  -Plug it in and test the buttons.
