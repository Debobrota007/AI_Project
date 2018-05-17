/*------ Arduino Object avoider Code----- */


define rightMotorA 7
#define rightMotorB 8
#define leftMotorA 10
#define leftMotorB 9

#define rightMotorSpeed 5
#define leftMotorSpeed 6

int avgSpeed= 150;






int trigPin = A2;
int echoPin = A1;
long duration, cm;

void setup() {
  
  
  
  Serial.begin(9600);
  pinMode(rightMotorA, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  pinMode(leftMotorA, OUTPUT);
  pinMode(leftMotorB, OUTPUT);
  pinMode(rightMotorSpeed, OUTPUT);
  pinMode(leftMotorSpeed, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 29 / 2;
 // Serial.println(duration);
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  
  
  if(cm<=20)
  {
  stop();
  delay(100);
  
  backward();
  delay(150);
  
  right();
  delay(200);
  left();
  delay(350);
  }
  
  else if(cm>100)
  {
    forward();
    
  }
  
  
  
  
  
}

void forward()
{ 
  
  analogWrite(rightMotorSpeed, avgSpeed);
  analogWrite(leftMotorSpeed, avgSpeed);
  
  digitalWrite(rightMotorA, HIGH);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(leftMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  
}

void backward()
{ 
  
  analogWrite(rightMotorSpeed, avgSpeed);
  analogWrite(leftMotorSpeed, avgSpeed);
  
  digitalWrite(rightMotorA, LOW);
  digitalWrite(rightMotorB, HIGH);
  digitalWrite(leftMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  
}

void right()
{ 
  
  analogWrite(rightMotorSpeed, avgSpeed);
  analogWrite(leftMotorSpeed, avgSpeed);
  
  digitalWrite(rightMotorA, LOW);
  digitalWrite(rightMotorB, HIGH);
  digitalWrite(leftMotorA, HIGH);
  digitalWrite(leftMotorB, LOW);
  
}


void left()
{ 
  
  analogWrite(rightMotorSpeed, avgSpeed);
  analogWrite(leftMotorSpeed, avgSpeed);
  
  digitalWrite(rightMotorA, HIGH);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(leftMotorA, LOW);
  digitalWrite(leftMotorB, HIGH);
  
}

void stop()
{ 
  
  analogWrite(rightMotorSpeed, avgSpeed);
  analogWrite(leftMotorSpeed, avgSpeed);
  
  digitalWrite(rightMotorA, LOW);
  digitalWrite(rightMotorB, LOW);
  digitalWrite(leftMotorA, LOW);
  digitalWrite(leftMotorB, LOW);
  
}