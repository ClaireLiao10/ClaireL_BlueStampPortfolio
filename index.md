# Prank Trick-o-Treat Bowl
When I was a little kid, I have always wanted to prank the kids who would steal my candy. So, during this Halloween, with the use of an ultrasonic sensor, this special trick-o-treat bowl can detect any hand that is ten centimeters away that reaching to grab the candy. Once this sensor detects the hand, the wheels will move away from the hand, preventing the children from stealing my candy. 

| **Engineer** | **School** | **Area of Interest** | **Grade** |
|:--:|:--:|:--:|:--:|
| Claire L | Basis Independent Silicon Valley | Mechanical Engineering | Incoming Sophomore

![Headstone Image](Claire-Headshot.png)

<!--# Final Milestone
For your final milestone, explain the outcome of your project. Key details to include are:
- What you've accomplished since your previous milestone
- What your biggest challenges and triumphs were at BSE
- A summary of key topics you learned about
- What you hope to learn in the future after everything you've learned at B


**Don't forget to replace the text below with the embedding for your milestone video. Go to Youtube, click Share -> Embed, and copy and paste the code to replace what's below.**

<iframe width="560" height="315" src="https://www.youtube.com/embed/F7M7imOVGug" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
-->
# Second Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/Jjfn467eo7o" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
After my ultrasonic sensor successfully worked, the next step was to connect the motors to the Ultrasonic sensors. My second milestone was to ensure that if the ultrasonic sensor detects a distance greater than ten centimeters, the motors will spin. The L298 DCM driver, the red chip connected to the breadboard, Arduino Uno, and the motors, controls the direction and speed of DC motors. A single DCM driver can control up to two motors. There are four input plugs for the motor and four output plugs for the motor. The DCM driver has an H-bridge configuration, which is made up of four switches. Inside the DCM driver, there is also a voltage regulator that regulates the voltage so that nothing ever blows up from overheating. During my second miletsone, wires had to be connected, and I figured out the correct wiring due to circuit.io. I had a hard time getting the correct wiring and had to recheck the wiring multiple times. I sometimes accidentally put the wires in the wrong spot, and sometimes the wires would fall out due to me dropping the project. Another challenge that I had was getting the USB connected to the Arduino Uno. That issue was solved by using a different USB connector. Otherwise, my second milestone went really smoothly compared to my first milestone and starter project. For my third milestone, I will be assembling everything together. Some changes I would want to make to this project are to make it a trick-or-treat bowl where the bowl will move away when a child tries to get the candy.

# First Milestone
<iframe width="560" height="315" src="https://www.youtube.com/embed/EVdSUeaPyqM" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>
My first milestone was to connect and test the ultrasonic sensor to my serial monitor. I needed to use the ultrasonic sensor in order to detect the distance of anything that approached the box. The ultrasonic sensor is a type of proximity sensor that transmits ultrasonic sound waves to detect the distance of an object. In the ultrasonic sensor, there is a transmitter that sends out the soundwaves and a receiver that receives the soundwaves. Using the time it takes for the ultrasonic pulse to first reach the object and then bounce back from the object, divided by two, and the speed of the pulse, the ultrasonic sensor can calculate the distance between the object and the ultrasonic sensor. Despite the fact that the ultrasonic sensor has a limited range for detecting objects from different angles, my project needed an ultrasonic sensor. During the last two days, I have finished wiring and uploading the necessary code onto the serial monitor. I have learned to look up documentation to upload the code necessary to use the ultrasonic sensor. So far, my project has gone really smoothly, and there are no big challenges that I have to face at this time. My plan after this is to add the motors and incorporate the ultrasonic sensor into the motor.

# Starter Project
<iframe width="560" height="315" src="https://www.youtube.com/embed/-cQ8sZ7sLtw" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

For my starter project, I was originally supposed to work on the Arduino clock; however, due to a few mistakes that I made, such as soldering components incorrectly, I had a change of plans and decided to work on a different starter project. Although I didn't end up finishing the Arduino clock, I learned a lot. For example, I learned to follow instructions very closely and to solder everything. For example, the microcontroller was not fully soldered due to the fact that I thought it only needed to be soldered at the ends. Due to the microcontroller not being fully soldered, the LED display would also need to be desoldered, which is why I ended up making a Robot Badge that has two lights that blink. The Robot Badge is a badge that has two LEDs that never stop blinking. Inside the Robot Badge are resistors and transistors that were already soldered in, so I only had to solder in the LEDs. The Robot Badge went by really smoothly, and there were not many challenges that I had to go through.

<!--# Schematics 
Here's where you'll put images of your schematics. [Tinkercad](https://www.tinkercad.com/blog/official-guide-to-tinkercad-circuits) and [Fritzing](https://fritzing.org/learning/) are both great resoruces to create professional schematic diagrams, though BSE recommends Tinkercad becuase it can be done easily and for free in the browser. -->

# Code

This is the code for my first milestone: 

```c++
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}
```

This is the code for my second milestone:

```c++

// Include Libraries
#include "Arduino.h"
#include "DCMDriverL298.h"
#include "NewPing.h"


// Pin Definitions
#define DCMOTORDRIVERL298_PIN_INT1 2
#define DCMOTORDRIVERL298_PIN_ENB 6
#define DCMOTORDRIVERL298_PIN_INT2 3
#define DCMOTORDRIVERL298_PIN_ENA 5
#define DCMOTORDRIVERL298_PIN_INT3 4
#define DCMOTORDRIVERL298_PIN_INT4 7
#define HCSR04_PIN_TRIG 9
#define HCSR04_PIN_ECHO 8



// Global variables and defines

// object initialization
DCMDriverL298 dcMotorDriverL298(DCMOTORDRIVERL298_PIN_ENA, DCMOTORDRIVERL298_PIN_INT1, DCMOTORDRIVERL298_PIN_INT2, DCMOTORDRIVERL298_PIN_ENB, DCMOTORDRIVERL298_PIN_INT3, DCMOTORDRIVERL298_PIN_INT4);
NewPing hcsr04(HCSR04_PIN_TRIG, HCSR04_PIN_ECHO);


// define vars for testing menu
const int timeout = 10000;  //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() {
  // Setup Serial which is useful for debugging
  // Use the Serial Monitor to view printed messages
  Serial.begin(9600);
  // wait for serial port to connect. Needed for native USB
  Serial.println("start");
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() {
  // L298N Motor Driver with Dual Hobby DC motors - Test Code
  //Start both motors. note that rotation direction is determined by the motors connection to the driver.
  //You can change the speed by setting a value between 0-255, and set the direction by changing between 1 and 0.
  // Ultrasonic Sensor - HC-SR04 - Test Code
  // Read distance measurment from UltraSonic sensor
  int hcsr04Dist = hcsr04.ping_cm();
  delay(10);
  Serial.print(F("Distance: "));
  Serial.print(hcsr04Dist);
  Serial.println(F("[cm]"));
  if (hcsr04Dist <= 30) {
    dcMotorDriverL298.setMotorA(200, 1);
    dcMotorDriverL298.setMotorB(200, 0);
    delay(2000);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    delay(2000);
  }
}
```

# Bill of Materials

| **Part** | **Note** | **Price** | **Link** |
|:--:|:--:|:--:|:--:|
| Half-sized Breadboard | Wiring | $6.69 for 4 | <a href ="https://www.amazon.com/Qunqi-point-Experiment-Breadboard-5-5×8-2×0-85cm/dp/B0135IQ0ZC/ref=asc_df_B0135IQ0ZC/tag=hyprod20&linkCode=df0&hvadid=198091709182&hvpos=&hvnetw=g&hvrand=16296269868778412770&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9032183&hvtargid=pla-407203040794&psc=1"> Link </a> |
| Arduino Uno | Wiring | $28.50 for 1 | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6"> Link </a> 
| DC Motor and wheels | Makes the contraption move | $10.99 for 4 | <a href="https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/](https://www.amazon.com/Gikfun-Miniature-Motors-Arduino-Projects/dp/B07SQXRSNR/ref=sr_1_1_sspa?crid=1C2AKRH232BXX&keywords=arduino+dc+motor&qid=1688167706&sprefix=arduino+dc+motor%2Caps%2C143&sr=8-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)](https://www.amazon.com/AEDIKO-Motor-Gearbox-Shaft-200RPM/dp/B099Z85573/ref=sr_1_3?crid=2ZENV625HNXZE&keywords=dc+motor+wheels&qid=1688167968&sprefix=dc+motor+wheel%2Caps%2C161&sr=8-3)](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6"> Link </a> |

<!--# Other Resources/Examples
One of the best parts about Github is that you can view how other people set up their own work. Here are some past BSE portfolios that are awesome examples. You can view how they set up their portfolio, and you can view their index.md files to understand how they implemented different portfolio components.
- [Example 1](https://trashytuber.github.io/YimingJiaBlueStamp/)
- [Example 2](https://sviatil0.github.io/Sviatoslav_BSE/)
- [Example 3](https://arneshkumar.github.io/arneshbluestamp/)

To watch the BSE tutorial on how to create a portfolio, click here.-->
