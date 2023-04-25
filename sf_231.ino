// C++ code
//
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(11, OUTPUT); //Enable 3&4   MOTOR-2
  pinMode(10, OUTPUT); //Enable 1 & 2 MOTOR-1
  
  pinMode(7, OUTPUT);  //Input 1 for Motor-1
  pinMode(4, OUTPUT);  //Input 2 for Motor-1
  
  pinMode(5, OUTPUT);  //Input 3 for Motor-2
  pinMode(3, OUTPUT);  //Input 4 for Motor-2
}

void loop()
{
  
  
  //moveForward();
  
  //moveBack();
  
  steerRight();
  
  //steerLeft();
  

}

void moveForward(){
  //Motor-1 direction
  digitalWrite(7, HIGH);
  digitalWrite(4, LOW);
  //Motor-1 speed
  analogWrite(10, 500);
  
  //Motor-2 direction
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  //Motor-2 speed
  analogWrite(11,500);
  
}

void moveBack(){
  //Motor-1 Direction
  digitalWrite(7,LOW);
  digitalWrite(4, HIGH);
  //Motor-1 Speed
  analogWrite(10,500);
  
  //Motor-2 Direction
  digitalWrite(5,LOW);
  digitalWrite(3,HIGH);
  //Motor-2 Speed
  analogWrite(11,500);
}

void steerLeft(){
  //Motor-1 Direction
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  //Motor-1 Speed
  analogWrite(10,100);
  
  //Motor-2 Direction
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  //Motor-2 Speed
  analogWrite(11, 500);
}

void steerRight(){
  //Motor-1 Direction
  digitalWrite(7,HIGH);
  digitalWrite(4,LOW);
  //Motor-1 Speed
  analogWrite(10, 500);
  
  //Motor-2 direction
  digitalWrite(5,HIGH);
  digitalWrite(3,LOW);
  //Motor-2 speed
  analogWrite(11,100);
}

