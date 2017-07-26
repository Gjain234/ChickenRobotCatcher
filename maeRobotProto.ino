/*
  DigitalReadSerial
 Reads a digital input on pin 2, prints the result to the serial monitor

 This example code is in the public domain.
 */

// digital pin 2 has a pushbutton attached to it. Give it a name:
int irSensorL = 8;
int irSensorR = 9;
int leftWheel1 = 2; //** NEED TO INITIALIZE ALL PIN NUMBERS
int leftWheel2 = 3;
int rightWheel1 = 4;
int rightWheel2 = 5;
int qti = 6;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(irSensorL, INPUT);
  pinMode(irSensorR, INPUT);
  pinMode(qti, INPUT);
  pinMode(leftWheel1, OUTPUT);
  pinMode(leftWheel2, OUTPUT);
  pinMode(rightWheel1, OUTPUT);
  pinMode(rightWheel2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  while(digitalRead(irSensorL)==1 && digitalRead(irSensorR)==1 &&  digitalRead(qti)!=0)// neither sensor senses a signal - turn till it finds ir signal and isn't outside ring
  {
      digitalWrite(rightWheel1, 0); // right wheel forward
      digitalWrite(rightWheel2, 1); // ''
      digitalWrite(leftWheel1, 1); // left wheel backward
      digitalWrite(leftWheel2, 0); // ''
    }
  while(digitalRead(irSensorL) ==0 && digitalRead(irSensorR) ==0 && digitalRead(qti)!=0) //advance toward signal and make sure not to leave the course
  {
      digitalWrite(rightWheel1,0); // right wheel forward
      digitalWrite(rightWheel2, 1); // ''
      digitalWrite(leftWheel1, 0); // left wheel forward
      digitalWrite(leftWheel2, 1); // ''
    }
  while( digitalRead(irSensorL) ==0 && digitalRead(irSensorR) != 1) // only left sensor senses ir-> spin CCW
  {
    digitalWrite(rightWheel1, 0); // right wheel forward
      digitalWrite(rightWheel2, 1); // ''
      digitalWrite(leftWheel1, 1); // left wheel backward
      digitalWrite(leftWheel2, 0); // ''
    }
  while( digitalRead(irSensorR) ==0 && digitalRead(irSensorL) != 1) // only rightt sensor senses ir -> spin CW
  {
    digitalWrite(leftWheel1, 0); // left wheel forward
      digitalWrite(leftWheel2, 1); // ''
      digitalWrite(rightWheel1, 1); // right wheel backward
      digitalWrite(rightWheel2, 0); // ''
    }
  if (digitalRead(qti) ==0)// back up and continue if exits race
  {
      digitalWrite(rightWheel1, 1); // right wheel backward
      digitalWrite(rightWheel2, 0); // ''
      digitalWrite(leftWheel1, 1); // left wheel backward
      digitalWrite(leftWheel2, 0); // ''
      delay(1000);
    }
}



