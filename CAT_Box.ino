/*
http://github.com/joshuajayg
Date: 6 January 2024
Author: Joshua Griffin
Amateur Callsign: KJ7LVZ
The purpose of this sketch is to control a radio over an RS-232 serial connection.  
The physical interface is intended to be a few push buttons.  You can pogram your macros below.
Put as many macros as you want under each section below.  They will be executed in order.
The delay between CAT commands is to give the radio enough time to respond before sending another command.
No code is written to listen to responses from the radio though it can be added.  One idea is to have a red LED
that gets illuminated if the CAT command isn't accepted by the radio.
*/

#define numButtons 5            //How many buttons are on your resistor ladder?
#define resolution 1023         //What is the resolution of your ADC?

int button;
int lastButton;
int buttonPin=A0;               //Which pin is your resistor ladder connected to?

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }
  pinMode(buttonPin, INPUT);
}

void loop() {
  button=readAnalogButton();
  if (button!=lastButton) {
    lastButton=button;
    if (button==1) {                  //*****PUT THE BUTTON 1 MACROS HERE*****//
      Serial.write("FR0;");           //Set VFO A Receive
      delay(5);
      Serial.write("FT0;");           //Set VFO A Transmit
      delay(5);
      Serial.write("FA00003885000;"); //Set 3.885 MHz
      delay(5);
      Serial.write("OM05;");          //Set AM
      delay(5);
      Serial.write("PC010;");         //Set Power to 10w
      delay(5);
      Serial.write("EX00606 000;");    //Set TX Lowcut to 10 Hz
      delay(5);
      Serial.write("EX00607 007;");    //Set TX Highcut to 4000 Hz
      delay(5);
      Serial.write("VV;");            //A=B
      delay(5); 
      Serial.write("OM03;");          //Set CW to tune
      delay(5);
      Serial.write("FA00003885000;"); //Set frequency to carrier
      delay(5);
      Serial.write("PC020;");         //Set power to 20w for tuning
      delay(5);
      Serial.write("AC100;");         //Turn off antenna tuner
      delay(5);
    }

    if (button==2) {                  //*****PUT THE BUTTON 2 MACROS HERE*****//
      Serial.write("OM01;");          //Set LSB
      delay(5);
      Serial.write("EX00606 001;");    //Set TX Lowcut to 100 Hz
      delay(5);
      Serial.write("EX00607 004;");    //Set TX Highcut to 2900 Hz
      delay(5);
      Serial.write("PC100;");         //Set power to 100w for tuning
      delay(5);
    }

    if (button==3) {                  //*****PUT THE BUTTON 3 MACROS HERE*****//
      Serial.write("FR0;");           //Set VFO A Receive
      delay(5);
      Serial.write("FT0;");           //Set VFO A Transmit
      delay(5);
      Serial.write("FA00007293000;"); //Set 7.293 MHz
      delay(5);
      Serial.write("OM05;");          //Set AM
      delay(5);
      Serial.write("PC010;");         //Set Power to 10w
      delay(5);
      Serial.write("EX00606 000;");    //Set TX Lowcut to 10 Hz
      delay(5);
      Serial.write("EX00607 007;");    //Set TX Highcut to 4000 Hz
      delay(5);
      Serial.write("VV;");            //A=B
      delay(5); 
      Serial.write("OM03;");          //Set CW to tune
      delay(5);
      Serial.write("FA00007293000;"); //Set frequency to carrier
      delay(5);
      Serial.write("PC020;");         //Set power to 20w for tuning
      delay(5);
      Serial.write("AC100;");         //Turn off antenna tuner
      delay(5);
    }

    if (button==4) {                  //*****PUT THE BUTTON 4 MACROS HERE*****//
      Serial.write("");
      delay(5);
    }

    if (button==5) {                  //*****PUT THE BUTTON 5 MACROS HERE*****//
      Serial.write("");
      delay(5);
    }

  }
  else{
    delay(50);                        //If no button press, hang out for a moment.
  }
}

int readAnalogButton() {              //This code reads the ADC, calculates the button, and sends it back.
  float avg = resolution / float(numButtons);
  int val = analogRead(buttonPin);

  if (val > (numButtons - 0.5) * avg) { 
    return 0; 
  }

  for (int i = 0; i < numButtons; i++) {
    if (val < round((i + 0.5) * avg)) { 
      return i + 1; 
    }
  }

  return 0;
}