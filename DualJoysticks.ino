const int ledPin = 13;

const int Joy1Button1 = 0;
const int Joy1Button2 = 1;
const int Joy2Button1 = 2;
const int Joy2Button2 = 3;

const int Joy1X = 0;
const int Joy1Y = 1;
const int Joy2X = 2;
const int Joy2Y = 3;

void setup() {
  // initialize joypad pins 
  pinMode(Joy1Button1, INPUT_PULLUP);
  pinMode(Joy1Button2, INPUT_PULLUP);
  pinMode(Joy2Button1, INPUT_PULLUP);
  pinMode(Joy2Button2, INPUT_PULLUP);
  
  analogReadAveraging(32);
  
  //Serial.begin(9600);
}

const float Rc = 38000.0f;    // resistance of parallel resistor
const float Uc = 3.3f;        // analog input voltage
const float Pmax = 100000.0f; // max resistance of gamepad analog input

int linearize(int x) {
  float U = x / 1023.0f * Uc;
  float R = Rc * (Uc / U - 1.0f);
  float val = min(1.0f, R / Pmax);
  return int(1023.0f * val);
}

void loop() {
  
  // flip button inputs (no connection = 1 due to INPUT_PULLUP)
  Joystick.button(1, 1 - digitalRead(Joy1Button1));
  Joystick.button(2, 1 - digitalRead(Joy1Button2));
  Joystick2.button(1, 1 - digitalRead(Joy2Button1));
  Joystick2.button(2, 1 - digitalRead(Joy2Button2));

  // linearize values read from analog input
  Joystick.X(linearize(analogRead(Joy1X)));
  Joystick.Y(linearize(analogRead(Joy1Y)));
  Joystick2.X(linearize(analogRead(Joy2X)));
  Joystick2.Y(linearize(analogRead(Joy2Y)));
  
  /*
  // debug prints
  Serial.print("X1 ");
  Serial.print(X1);

  Serial.print("\tY1 ");
  Serial.print(Y1);

  Serial.print("\tX2 ");
  Serial.print(X2);

  Serial.print("\tY2 ");
  Serial.print(Y2);

  Serial.println();
  */
  
  delay(10);
}

