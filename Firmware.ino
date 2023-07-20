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
  if (hcsr04Dist>0 && hcsr04Dist <= 30) {
    dcMotorDriverL298.setMotorA(200, 1);
    dcMotorDriverL298.setMotorB(200, 0);
    dcMotorDriverL298.setMotorA(50, 1);
    dcMotorDriverL298.setMotorB(50, 0);
    delay(100);
    //Stop both motors
    dcMotorDriverL298.stopMotors();
    delay(100);
  }
}