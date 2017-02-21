#include <Stepper.h> 

const int stepsPerRevolution = 200; 
Stepper myStepper(stepsPerRevolution, 8,9,10,11);            
Stepper myStepper2(stepsPerRevolution, 4,5,6,7);

String readString; 
char unChar;
String input;
int out ;

void setup()
{
  Serial.begin(115200);
  Serial.println("console...");
}

void loop() {
  
 if (Serial.available()) {  //verify firs character in serial port
    unChar = Serial.read();
    
    if(unChar=='A'){ //if A go to motor1 function
      
      mode1();
    }
    
    if(unChar=='B'){ //if B go to motor2 function
      
      mode2();
      
    }
    
  }  
}
  
void mode1(){
      delayMicroseconds(300);   
        Serial.println("A");
        while (Serial.available()) { //Now the numerical data of the angle of the servomotor is received
          delayMicroseconds(100);                  
          char c = Serial.read();  // Se leen los caracteres que ingresan por el puerto
          readString += c;         //each character builds in a string
        }
        if (readString.length() >0) {   //the length of the string is verified
          out = readString.toInt();
          //Serial.println(readString);
          //newout = out ; 
          Serial.print("out: ");
          Serial.println(out);
          readString ="";
     }
}

void mode2(){
      
     delayMicroseconds(3000); 
        Serial.println("B");
        while (Serial.available()) { 
          //delayMicroseconds(100);                  
          char c = Serial.read();  
          input += c;         
        }
        for (int i = 0; i < input.length(); i++){
              //int stepsPerRevolution = 10;
              Serial.print(input[i]);
              //Serial.print(" ");
            }
          Serial.println(" ");    
          moveMotor(); 
          input = "";
          
      } 


void moveMotor(){

  Serial.print("motor speed : ");
  Serial.println(out);
  
  myStepper.setSpeed(out);
  myStepper2.setSpeed(out);
  
  myStepper.step(stepsPerRevolution);
  delay(300);
  myStepper2.step(stepsPerRevolution);
  delay(300);
  myStepper.step(-stepsPerRevolution);
               
}
