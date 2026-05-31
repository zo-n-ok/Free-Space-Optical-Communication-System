// --- RECEIVER CODE ---
const int ldrPin = 2;

// CHANGE THIS: If you see nothing, change 'LOW' to 'HIGH'
const int LASER_ON_SIGNAL = LOW; 

unsigned long startTime;
unsigned long duration;
bool laserActive = false;
String currentMorse = "";

void setup() {
  pinMode(ldrPin, INPUT);
  Serial.begin(9600);
  Serial.println("--- Optical Morse Decoder Ready ---");
}

// Function to convert Morse string to a Letter
char decodeMorse(String morse) {
  if (morse == ".-") return 'A';
  if (morse == "-...") return 'B';
  if (morse == "-.-.") return 'C';
  if (morse == "-..") return 'D';
  if (morse == ".") return 'E';
  if (morse == "..-.") return 'F';
  if (morse == "--.") return 'G';
  if (morse == "....") return 'H';
  if (morse == "..") return 'I';
  if (morse == ".---") return 'J';
  if (morse == "-.-") return 'K';
  if (morse == ".-..") return 'L'; // Fixed: removed the extra ;
  if (morse == "--") return 'M';
  if (morse == "-.") return 'N';
  if (morse == "---") return 'O';
  if (morse == ".--.") return 'P';
  if (morse == "--.-") return 'Q';
  if (morse == ".-.") return 'R';
  if (morse == "...") return 'S';
  if (morse == "-") return 'T';
  if (morse == "..-") return 'U';
  if (morse == "...-") return 'V';
  if (morse == ".--") return 'W';
  if (morse == "-..-") return 'X';
  if (morse == "-.--") return 'Y';
  if (morse == "--..") return 'Z';
  return '?'; 
}

void loop() {
  int sensorValue = digitalRead(ldrPin);

  // 1. Detect Pulse Start (Laser hits LDR)
  if (sensorValue == LASER_ON_SIGNAL && !laserActive) {
    startTime = millis();
    laserActive = true;
  }

  // 2. Detect Pulse End (Laser turns off)
  if (sensorValue != LASER_ON_SIGNAL && laserActive) {
    duration = millis() - startTime;
    laserActive = false;

    if (duration > 50 && duration < 700) {
      currentMorse += ".";
      Serial.print("."); // Show the dots as they come
    } 
    else if (duration >= 700) {
      currentMorse += "-";
      Serial.print("-"); // Show the dashes as they come
    }
  }

  // 3. Detect End of Letter (No light for 1.5 seconds)
  static unsigned long lastTimeSignalSeen;
  if (sensorValue == LASER_ON_SIGNAL) lastTimeSignalSeen = millis();

  if (millis() - lastTimeSignalSeen > 1500 && currentMorse != "") {
    char decodedChar = decodeMorse(currentMorse);
    Serial.print(" -> ");
    Serial.println(decodedChar); // Print the actual letter!
    currentMorse = ""; // Reset for next letter
  }
}