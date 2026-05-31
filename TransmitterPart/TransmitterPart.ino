const int laserPin = 13;
const int unit = 500; // 500ms (Half a second)

void setup() {
  pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("ULTRA-SLOW Morse Transmitter Ready.");
}

void sendMorse(String pattern) {
  for (int i = 0; i < pattern.length(); i++) {
    digitalWrite(laserPin, HIGH);
    if (pattern[i] == '.') delay(unit);
    else if (pattern[i] == '-') delay(unit * 3);
    
    digitalWrite(laserPin, LOW);
    delay(unit); // Wait between parts of same letter
  }
  delay(unit * 2); // Wait after a full letter
}

void loop() {
  if (Serial.available()) {
    char c = toupper(Serial.read());
    Serial.print("Sending: "); Serial.println(c);

    if (c == 'A') sendMorse(".-");
    else if (c == 'B') sendMorse("-...");
    else if (c == 'C') sendMorse("-.-.");
    else if (c == 'D') sendMorse("-..");
    else if (c == 'E') sendMorse(".");
    else if (c == 'F') sendMorse("..-.");
    else if (c == 'G') sendMorse("--.");
    else if (c == 'H') sendMorse("....");
    else if (c == 'I') sendMorse("..");
    else if (c == 'J') sendMorse(".---");
    else if (c == 'K') sendMorse("-.-");
    else if (c == 'L') sendMorse(".-..");
    else if (c == 'M') sendMorse("--");
    else if (c == 'N') sendMorse("-.");
    else if (c == 'O') sendMorse("---");
    else if (c == 'P') sendMorse(".--.");
    else if (c == 'Q') sendMorse("--.-");
    else if (c == 'R') sendMorse(".-.");
    else if (c == 'S') sendMorse("...");
    else if (c == 'T') sendMorse("-");
    else if (c == 'U') sendMorse("..-");
    else if (c == 'V') sendMorse("...-");
    else if (c == 'W') sendMorse(".--");
    else if (c == 'X') sendMorse("-..-");
    else if (c == 'Y') sendMorse("-.--");
    else if (c == 'Z') sendMorse("--..");
    else if (c == ' ') delay(unit * 5); // Space between words
  }
}