# Baby-GLT Project.
This project is a system for count the table soccer goals.
For display the score we used ubidots.

0. Organisation
1. Hardware.
2. Firmware.
3. Software.
4. Installation on table soccer.
5. Demo


## Organisation
Each people have an organisation like this :
![planning](img/pics.png) 

### Hardware.
We use an ESP8266 : 
![ESP8266](img/ESP8266.jpg)


we used this componants :
![hardware](img/Fritzing2.png)
 
We have use a LED ,Laser and a sensor for detect the laser light, and img.

We have connect the componants like this : 

![componant](img/img_comp.jpg)

![componant](img/mirroir.jpg)

![componant](img/lighton.png)

![componant](img/lightoff.png)


#### Firmware : 
We used this [program](babyfoot.ino) for communicate with [ubidots](http://www.ubidots.com) board.

***You need to [download](https://github.com/ubidots/ubidots-esp8266/) the library for communicate with ubidots and add to the arduino Library.***

You need to add the credentials access to the board.
``` C
#define TOKEN  "fL7bB5nkQJ2NAkZNoaiy3U3Kz2H16V"  // Put here your Ubidots TOKEN
#define ID_1 "58f8b3af7625423887675651"
#define ID_2 "58f9c22076254238893ef4c8"// Put your variable ID here

```

You need to configure with your wifi access.
``` C
#define WIFISSID "SSID"
#define PASSWORD "Password"
```

You can found an other environment is Cayenne.


##### Installation on table soccer : 
We have install the componenent in each part of the goal inside the table soccer like this schema.

![tablesoccer](img/Tbs.png)


The score interface is like this on the web : 
![score](img/score2.png)

###### Demo on youtube.

The first link : [TableSoccer1](https://youtu.be/AaErkM0wb-8)
The second link : [TableSoccer2](https://youtu.be/VqBfhZimKc8)

