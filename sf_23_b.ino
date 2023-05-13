#include <SoftwareSerial.h>
SoftwareSerial blue(11,10);
char NOMBRE[21] = "SF23";
char PASS[5] = "4455";
char appData;
String inData;



void setup()
{
  //Bluetooth config
  Serial.begin(9600);
  Serial.println("Listo");
  blue.begin(9600);
  blue.print("AT+NAME");
  blue.print(NOMBRE);
  

  //Motors Config
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT); //Enable 3&4   MOTOR-2
  pinMode(8, OUTPUT); //Enable 1 & 2 MOTOR-1
  
  pinMode(7, OUTPUT);  //Input 1 for Motor-1
  pinMode(4, OUTPUT);  //Input 2 for Motor-1
  
  pinMode(5, OUTPUT);  //Input 3 for Motor-2
  pinMode(3, OUTPUT);  //Input 4 for Motor-2

  

}

void loop()
{

  blue.listen();

  while( blue.available() > 0){
    appData = blue.read();
    inData = String(appData);
    Serial.write(appData);

  }

  if( Serial.available() ){
    delay(10);
    blue.write(Serial.read());
  }


  if (inData == "W"){
    stopMotors();
    moveForward();
    Serial.println("Move forward");
  }
  else if(inData == "E"){
    stopMotors();
    moveBack();
    Serial.println("Move back");
  }
  else if(inData == "N"){
    stopMotors();
    steerRight();
    Serial.println("Steer right");
  }
  else if(inData == "S"){
    stopMotors();
    steerLeft();
    Serial.println("Steer left");
  }  
  else if(inData == "1"){
    stopMotors();
    Serial.println("Stop");
  }


}

void moveForward(){
  //Motor-1 direction
  digitalWrite(7, LOW);
  digitalWrite(4, HIGH);
  //Motor-1 speed
  analogWrite(8, 150);
  
  //Motor-2 direction
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  //Motor-2 speed
  analogWrite(9,255);
  
}

void stopMotors(){
  //Motor-1 direction
  digitalWrite(7, LOW);
  digitalWrite(4, LOW);
  //Motor-1 speed
  analogWrite(8, 0);
  
  //Motor-2 direction
  digitalWrite(5, LOW);
  digitalWrite(3, LOW);
  //Motor-2 speed
  analogWrite(9,0);

}

void moveBack(){
  //Motor-1 Direction
  digitalWrite(7,HIGH);
  digitalWrite(4, LOW);
  //Motor-1 Speed
  analogWrite(8,150);
  
  //Motor-2 Direction
  digitalWrite(5,LOW);
  digitalWrite(3,HIGH);
  //Motor-2 Speed
  analogWrite(9,255);
}

void steerLeft(){
  //Motor-1 Direction
  digitalWrite(7,LOW);
  digitalWrite(4,HIGH);
  //Motor-1 Speed
  analogWrite(8,0);
  
  //Motor-2 Direction
  digitalWrite(5, HIGH);
  digitalWrite(3, LOW);
  //Motor-2 Speed
  analogWrite(9, 150);
}

void steerRight(){
  //Motor-1 Direction
  digitalWrite(7,LOW);
  digitalWrite(4,HIGH);
  //Motor-1 Speed
  analogWrite(8, 150);
  
  //Motor-2 direction
  digitalWrite(5,HIGH);
  digitalWrite(3,LOW);
  //Motor-2 speed
  analogWrite(9,0);
}
