/*Question 4 - Electrolux Knowledge Assessment. Author: Denner Paganoti - August, 20, 2022*/
/*This code has been implemented for an Arduino Mega*/

/*This 128 bits buffer will be iniatilized to store the messages received through the UART*/
char uartBuffer[128]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                      ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',};

void setup() {
  /*baud rate setted on 9600 bps*/
  Serial.begin(9600);
  pinMode(2, OUTPUT);  
}

void loop() {
  /*Just for a matter of debug, the message stored in the uartBuffer is presented in the screen at a 1Hz rate*/
  delay(1000);
  Serial.println("BUFFER: ");
  Serial.println(uartBuffer);
}

void serialEvent(){
  /*Triggers the UART interruption. If there's some message received by the UART, the content is write on the buffer.
  Just for a matter of debug, a led on the port 2 has been setted to blink to indicate each time a interruption happens*/
  while(Serial.available()){
    digitalWrite(2, HIGH);
    static unsigned short bufferOccupation=0;
    char bufferRX;
    bufferRX=(char)Serial.read();
    if (bufferOccupation>=128){
      bufferOccupation=0;
    }
    else{
      bufferOccupation++;
    }
    uartBuffer[bufferOccupation]=bufferRX;
  }
  digitalWrite(2, LOW);
}



