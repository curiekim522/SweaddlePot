const int lightPin = A0;
const int waterPin = A1;
int value = 0;

int rLED = 11;
int gLED = 10;
int bLED = 9;

int r = 0;
int g = 0;
int b = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lightPin, INPUT);
  pinMode(waterPin, INPUT);
  pinMode(rLED, OUTPUT);
  pinMode(gLED, OUTPUT);
  pinMode(bLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   Serial.println("running");
   Serial.println("lightPin : " + analogRead(A0));
   Serial.println("waterPin : " + analogRead(A0));
   if (analogRead(A0) < 100 && analogRead(A1) < 30) {
    setRed();
   } else if (analogRead(A0) < 100) {
    Serial.println("here");
    setYellow();   
   } else if (analogRead(A1) < 30) {
    setBlue();
   } else {
     setColor(255, 0, 0, value);    // red
     setColor(0, 255, 0, value);    // green
     setColor(0, 0, 255, value);    // blue
     setColor(255, 255, 0, value);  // yellow
     setColor(80, 0, 80, value);    // purple
     setColor(0, 255, 255, value);  // aqua   
   }
}


void setColor(int red, int green, int blue, int value) {
  while ( r != red || g != green || b != blue ) {
   if (analogRead(A0) < 100 && analogRead(A1) < 30) {
    Serial.println("not enough light or water");
    setRed();
   } else if (analogRead(A0) < 100) {
    Serial.println("not enough light");
    setYellow();   
   } else if (analogRead(A1) < 30) {
    Serial.println("not enough water");
    setBlue();
   }
    if ( r < red ) {
      r++;
    } else{ 
      r--;
    }

    if ( g < green ) {
      g++;
    } else {
      g--;
    }

    if ( b < blue ) {
      b++;
    } else { 
      b--;
    }

    setLight();
    delay(15);
  }
}

void setRed() {
  while (analogRead(A1) < 30 && analogRead(A0) < 100) {
    Serial.print("No Light"); 
    analogWrite(rLED, 255);
    analogWrite(gLED, 0);
    analogWrite(bLED, 255); 
  }
}

void setYellow() {
  while (analogRead(A0) < 100 && analogRead(A1) > 30) {
    analogWrite(rLED, 0);
    analogWrite(gLED, 0);
    analogWrite(bLED, 255); 
  }
}

void setBlue() {
  while (analogRead(A1) <30 && analogRead(A0) >= 100) {
    analogWrite(rLED, 255);
    analogWrite(gLED, 255);
    analogWrite(bLED, 0); 
  }
}

void setLight() {
  analogWrite(rLED, r);
  analogWrite(gLED, g);
  analogWrite(bLED, b); 
}
