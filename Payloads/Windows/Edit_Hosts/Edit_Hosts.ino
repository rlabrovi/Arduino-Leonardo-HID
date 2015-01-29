const int buttonPin = 2;
const int ledPin =  13;
int buttonState = 0; 
char ctrlKey = KEY_LEFT_GUI;


void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
}

void loop(){
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { 
    digitalWrite(ledPin, HIGH); 
    
    delay(1000);
    Keyboard.press(ctrlKey);
    Keyboard.press('r');
    delay(100);
    Keyboard.release(ctrlKey);
    Keyboard.release('r');
    delay(500);
    Keyboard.print("cmd");
    Keyboard.write('\n');
    
    delay(500);
    
    Keyboard.print("echo 0.0.0.0 websitename.com >> %WINDIR%\\System32\\Drivers\\Etc\\Hosts");
    delay(500);
    Keyboard.write('\n');
    } 
  else {
    digitalWrite(ledPin, LOW); 
  }
}
