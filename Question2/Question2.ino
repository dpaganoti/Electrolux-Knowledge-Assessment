/*Question 2 - Electrolux Knowledge Assessment. Author: Denner Paganoti - August, 20, 2022*/
/*This code has been implemented for an Arduino Mega*/

#define button 2

int buttonState=-1;

void returnToOn(){
  	buttonState=0;
}

void setup() {
	/*Sets an interrupt in the PIN 2 from the Arduino everytime the button is pressed.*/
  	attachInterrupt(INT0,returnToOn,RISING);
  	pinMode(button, INPUT);
}

void loop() {
	/*Sets the finite states machine. If buttonState is -1, the machine is OFF; if it's 0 the machine is ON and, if it's 1 the machine is in the PROTECTED state.*/
  	switch(buttonState){
        case(-1):
      		if(digitalRead(button)==1){
        		buttonState=0;
      		}
      		else{
              	buttonState=-1;
            }        
      		break;
      	case(0):
      		if(digitalRead(button)==0){
        		buttonState=1;
      		}
      		else{
              	buttonState=0;
            }    
      		break;
      	case(1):
      		delay(10000);
      		if(digitalRead(button)==0){
        		buttonState=-1;
      		}
      		else{
              	buttonState=1;
            }   
      		break;
      	default:
      		buttonState=-1;
      		break;
  	}

}
