int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
const int buttonPin =2;
int buttonState = 0;
byte colDataMatrix[8] = { 
   B01111111,
   B10111111,
   B11011111,
   B11101111,
   B11110111,
   B11111011,
   B11111101,
   B11111110
  };
                      
byte rowDataMatrix[8] = { 
  B00111100,
  B01000010,
  B01000010,
  B01000010,
  B01000010,
  B00111100,
  B00000000,
  B11111111
  };

  byte yayDataMatrix[8] = { 
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B00000000,
  B11111111
  };

  

int delay_time = 1;
       
void setup() {
pinMode(latchPin,OUTPUT);
pinMode(clockPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(buttonPin,INPUT);
digitalWrite(buttonPin,HIGH);
}
void loop() {
  buttonState = digitalRead(buttonPin);

  if(buttonState == HIGH){
    for(int i = 0; i < 8 ; i++){
 
    digitalWrite(latchPin,LOW);
  
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, rowDataMatrix[i]);
   
    digitalWrite(latchPin,HIGH);
    delay(delay_time);
    }
  }
  else{
    for(int i = 0; i < 8 ; i++){
 
    digitalWrite(latchPin,LOW);
  
    shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
    shiftOut(dataPin, clockPin, MSBFIRST, yayDataMatrix[i]);
   
    digitalWrite(latchPin,HIGH);
    delay(delay_time);
    }
    
  }

 
}
void pickDigit(int x) {
  byte rowByte = 1 << x;
  shiftOut(dataPin, clockPin, MSBFIRST, rowByte);

}
