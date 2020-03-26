# BLE-HM10-BASED-INTRUSION-DETECTION-AND-LED-CONTROLLING-MODE
<br><b> OBJECTIVE</b></br>
<br>to create a ble HM-10 based project which uses LightBlue app to exhibit different commands through the app like controlling the led and intrusion detection which activates the pir motion detection sensor when someone enters the room and control led accordingly.</br>
<br><b>DESCRIPTION</b></br>
<br>•we have used BLE HM10 module to communicate with arduino uno through LightBlue app which scans for BLE devices on ios and we can access the custom characteristics of the device through the app (read /write or notify operations) .</br>
<br>•Then after opening the app it scans for ble devices nearby and will give option to conect with them and access its properties and read or write values onto it.</br>
<br>•Then we find our device named MLTBT05 and connect with it before a connection is established the red light on the device is blinking which gets stable after the connection is established and indicate a successfull connection.</br>
<br>•Then click on the TX &RX-V4.0 or the custom characteristics option through which we can read values or write value to arduino.</br>
<br>•After that change the hex option on top right corner to UTF-8 String which shows that data we are going to write will be of String data type</br>
<br>•Then go to written values section and write new value where we will be writing our 3 modes to arduino which on receiving wil execute the suggested commands on the hardware side.</br>
<br>•Write "on" value which will turn on the connected led on arduino and "off" to turn off the led.</br>
<br>•Write "spy" which will activate the motion sensor and turns on led on detecting motion and after motion has ended it will turn  off the led .</br>
<br>• Also try to enter a value different from above mentioned which it will ignore and will continue functioning normally after that value.</br>
<br><b>HM-10 BLE MODULE</b>
<br>The HM-10 is a small 3.3v SMD Bluetooth 4.0 BLE module based on the TI CC2540 or CC2541 Bluetooth SOC.The breakout board includes a 3.3v power regulator that makes them 5V compatible.You should note that the RX pin is is still 3.3v and when using a 5v Arduino you should covert the Arduino’s 5v TX to 3.3v for the HM-10 RX you can do this by creating a voltage divider of 1k and 2k ohm between rx pin of ble and tx of arduino.</br>
<br><br><b>LightBlue app scanning page</b><br>
<img src="https://user-images.githubusercontent.com/23056679/77564602-ff205b00-6ee8-11ea-8103-479e95411a91.PNG" width="300">
<br><br><b>Peripheral characteristics page after connection is established</b><br>
<img src="https://user-images.githubusercontent.com/23056679/77643039-ad2d1300-6f84-11ea-852f-3f1b3db56756.PNG" width="300">
<br><br><b>Custom Characteristics page</b><br>
<img src="https://user-images.githubusercontent.com/23056679/77643495-773c5e80-6f85-11ea-80f4-47773de5076e.PNG" width="300">
<br><br><b>ON Mode</b><br>
<img src="https://user-images.githubusercontent.com/23056679/77644300-cc2ca480-6f86-11ea-8438-37f61dee7dee.jpg" width="300">   <img src="https://user-images.githubusercontent.com/23056679/77644334-d9499380-6f86-11ea-982b-fbd7ab9ea5f1.jpg" width="300">
<br><br><b>SPY Mode with motion detected</b><br>
<img src="https://user-images.githubusercontent.com/23056679/77644944-e915a780-6f87-11ea-818b-70c80eb13056.jpg" width="300">
<br><br><b>Values sent to arduino</b><br>
<img src="https://user-images.githubusercontent.com/23056679/77644951-eb780180-6f87-11ea-9d14-bb30d5ab2efd.PNG" width="300">
