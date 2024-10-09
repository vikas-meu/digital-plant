 #include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

const int ldrPin = 2; // LDR sensor pin
const int tPin = 3; // touch sensor pin
const int moistureSensorPin = A0;//moisture sensor


// Initialize with the I2C address of your OLED display (usually 0x3C)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
bool eyesClosed = false; // Flag to track eyes blinking

void setup() {
  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }

  // Initialize PIR sensor pin
  pinMode(ldrPin, INPUT);
   pinMode(tPin, INPUT);

  // Clear the display buffer
  display.clearDisplay();
}

void loop() {
  // Read PIR sensor value
  int ldrValue = digitalRead(ldrPin);//ldr ke liye 
  int tValue = digitalRead(tPin);//touch sensor ke liye
  int sensorValue = analogRead(moistureSensorPin);//moisture sensor ke liye
  int moisturePercentage = map(sensorValue, 0, 1023, 100, 0); // Map the analog value to a percentage

  Serial.print("Moisture Level: ");
  Serial.print(moisturePercentage);
  Serial.println("%");
  delay(1000); // Delay for a second before taking the next reading

  if (ldrValue == 0) {
    // Human detected, show smiley face
    if (moisturePercentage >70){
    display.clearDisplay();
    drawSmiley(); 
    delay(100);
    ///////////////////////////////
    if (tValue == HIGH)
    {
      display.clearDisplay();
      display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
      display.clearDisplay();

  // Set text size and color
      display.setTextSize(4);
      display.setTextColor(SSD1306_WHITE);

  // Set initial cursor position
      display.setCursor(0, 0);

  // Display a message before drawing the heart
      display.println("hellooo!!");
      display.display();
      delay(2000); // Wait 2 seconds before drawing

  // Clear the display
      display.clearDisplay();
      display.display();
  // Draw the heart shape
  
  drawHeartShape(); 
    }}
//////////////////////////////////////////////////////////////////
    else{
      display.clearDisplay();
      sadFunction();
      delay(200);
    }
  } else {
    // No human detected, show sad face
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
  // Set initial cursor position
      display.setCursor(0, 0);
  // Display a message before drawing the heart
      display.println("moisture   value ");
      display.println(moisturePercentage);
      display.println("%");
      display.display();
      delay(200); // Wait 2 seconds before drawing 
  }

  // Refresh the display
  display.display();
  delay(100); // Add a small delay
}

// Function to draw a smiley face on the display
void drawSmiley() {
  // Draw eyes
  display.fillCircle(27, 18, 15, WHITE); // Left eye
  display.fillCircle(97, 18, 15, WHITE); // Right eye

  // Draw smile
  for (int i = 0; i < 180; i++) {
    int x = 64 + cos((i - 180) * 0.0174533) * 20; // 0.0174533 = Degrees to radians conversion
    int y = 50 - sin((i - 180) * 0.0174533) * 10;
    display.drawPixel(x, y, WHITE);
  }

  // Draw small circles for eyes (eye balls) when eyes are open
  if (!eyesClosed) {
    display.fillCircle(27, 16, 5, BLACK); // Left eye ball
    display.fillCircle(97, 16, 5, BLACK); // Right eye ball
  }
}

// Function to draw a sad face on the display
void sadFunction() {
  // Draw eyes
  display.fillCircle(27, 18, 15, WHITE); // Left eye
  display.fillCircle(97, 18, 15, WHITE); // Right eye

  // Draw frown
  for (int i = 0; i < 180; i++) {
    int x = 64 + cos((i - 0) * 0.0174533) * 20; // 0.0174533 = Degrees to radians conversion
    int y = 50 - sin((i - 0) * 0.0174533) * 10;
    display.drawPixel(x, y, WHITE);
  }

  // Draw small circles for eyes (eye balls) when eyes are open
  if (!eyesClosed) {
    display.fillCircle(27, 16, 5, BLACK); // Left eye ball
    display.fillCircle(97, 16, 5, BLACK); // Right eye ball
  }
}

void drawHeartShape() {//this is for heart shape 
  int x0 = SCREEN_WIDTH / 2;
  int y0 = SCREEN_HEIGHT / 2;

  display.fillTriangle(x0 - 18, y0 - 10, x0 + 18, y0 - 10, x0, y0 + 15, SSD1306_WHITE);
  display.fillCircle(x0 - 7, y0 - 7, 10, SSD1306_WHITE);
  display.fillCircle(x0 + 7, y0 - 7, 10, SSD1306_WHITE);

  display.display();
}
