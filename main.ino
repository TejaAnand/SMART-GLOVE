const int x = A4;
const int y = A5;

float r, s, t, u;

void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

float readResistance(int pin) {
  float val = analogRead(pin);
  float voltage = (val * 5.0) / 1023.0;
  return (1000.0 * voltage) / (5.0 - voltage);
}

void loop() {
  // Read flex sensor resistances
  r = readResistance(A1);  // Finger 1
  s = readResistance(A3);  // Finger 2
  t = readResistance(A0);  // Finger 3
  u = readResistance(A2);  // Finger 4
  
  int xVal = analogRead(x);  // Palm x-axis tilt?
  int yVal = analogRead(y);  // Palm y-axis tilt?

  // ✋ Gesture 1: Thumb bent
  if (r > 35000 && s < 35000 && t < 35000 && u < 35000 && xVal < 360 && yVal < 360) {
    Serial.println("a worm welcome to you all");
  }

  // ✋ Gesture 2: Index bent
  else if (r < 35000 && s > 40000 && t < 35000 && u < 35000 && xVal < 360 && yVal < 360) {
    Serial.println("good morning one and all");
  }

  // ✋ Gesture 3: Middle bent
  else if (r < 35000 && s < 35000 && t > 35000 && u < 35000 && xVal < 360 && yVal < 360) {
    Serial.println("i want some food");
  }

  // ✋ Gesture 4: Ring bent
  else if (r < 35000 && s < 35000 && t < 35000 && u > 35000 && xVal < 360 && yVal < 360) {
    Serial.println("i need medicine");
  }

  // 👋 Gesture: Palm tilt right, all fingers straight
  else if (r < 35000 && s < 35000 && t < 35000 && u < 35000 && xVal > 360 && yVal < 360) {
    Serial.println("nice to meet you");
  }

  // Numbers (1-7) based on finger combinations (only x > 360)
  else if (xVal > 360) {
    if (r > 35000 && s < 35000 && t < 35000 && u < 35000) Serial.println("1");
    else if (r < 35000 && s > 35000 && t < 35000 && u < 35000) Serial.println("2");
    else if (r < 35000 && s < 35000 && t > 35000 && u > 35000) Serial.println("3");
    else if (r < 35000 && s < 35000 && t < 35000 && u > 35000) Serial.println("4");
    else if (r > 35000 && s > 35000 && t < 35000 && u < 35000) Serial.println("5");
    else if (r < 35000 && s > 35000 && t < 35000 && u > 35000) Serial.println("6");
    else if (r > 35000 && s < 35000 && t < 35000 && u > 35000) Serial.println("7");
  }

  // Special gestures with x > 300 and y < 300
  else if (xVal > 300 && yVal < 300) {
    if (r < 35000 && s < 35000 && t < 55000 && u < 35000) Serial.println("here we are introduce smart glove");
    else if (r < 35000 && s < 35000 && t > 35000 && u > 35000) Serial.println("10");
    else if (r < 35000 && s < 35000 && t < 35000 && u > 35000) Serial.println("11");
    else if (r > 35000 && s > 35000 && t < 35000 && u < 35000) Serial.println("12");
    else if (r < 35000 && s > 35000 && t < 35000 && u > 35000) Serial.println("13");
    else if (r > 35000 && s < 35000 && t < 35000 && u > 35000) Serial.println("14");
  }

  // Additional gesture numbers with x < 360 and y < 360
  else if (xVal < 360 && yVal < 360) {
    if (r > 35000 && s > 40000 && t < 35000 && u < 35000) Serial.println("15");
    else if (r < 35000 && s > 40000 && t < 35000 && u > 35000) Serial.println("16");
    else if (r > 35000 && s < 40000 && t < 35000 && u > 35000) Serial.println("17");
    else if (r > 35000 && s > 40000 && t < 35000 && u > 35000) Serial.println("18");
  }

  delay(2000);
}
