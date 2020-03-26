#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9);                                      //serial communication rx and tx pins for ble communication
char c = ' ';
String readstring;                                                  //response string from ble
int ledPin = 13;
int pirPin = 12;
int sensorval = 0;
int pirState = LOW;
int flag = 0;
String prevstring = "";

void setup()
{
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.println("BLE module started");
  Serial.println("caliberating pir sensor");                         //caliberating pir sensor
  for (int i = 0; i < 2; i++)
  {
    delay(1000);
  }
}

void loop()
{
  while (BTSerial.available())                                       //give us all the serial data as complete string
  {
    c = BTSerial.read();
    readstring += c;                                                 //captures ble data from lightblue app
  }
 
  if (readstring.length() > 0 || prevstring.length() > 0)            //condition to check if there is an incoming data which is not null
  {
    

    if (readstring.length() >0)                                      //rechecking for readstring length
    {
      prevstring = readstring;                                       // copy values of incoming string t prevstring variable
    }

     
    Serial.println(prevstring);
      if (prevstring == "on")                                        //check if command from app is "on"
      {
        readstring = "\0";                                           //empty the readstring to receive the next command
        digitalWrite(ledPin, HIGH);                                  //turns on the led
       
      }
      
      else if (prevstring == "off")                                  //check if command from app is "off"
      {
        readstring = "\0";                                          //empty the readstring to receive the next command
        digitalWrite(ledPin, LOW);                                  //turns off the led
      }
      
      else if (prevstring == "spy")                                //check if command from app is "spy" in which pir motion sensor starts and check for incoming person in room and control led
      {
        readstring = "\0";                                         //empty the readstring to receive the next command
        sensorval = digitalRead(pirPin);                           //reads the pir sensor value
        Serial.println(sensorval);
        if (sensorval == HIGH)                                     //if sensor detects motion
        {
          digitalWrite(ledPin, HIGH);                              //turn on the led
        }
        else

        {
          digitalWrite(ledPin, LOW);                              // turn off the led
        }
        delay(1000);
      }
      
      else                                                        //else if there is data other then the specified ones then 
      { 
      readstring = "\0";                                          //clear both the strings and read from btserial again
      prevstring = "\0"; 
     }
  }    

  delay(1000);
}
