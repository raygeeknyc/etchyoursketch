#include <SPI.h> 
#include <Wire.h>
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h>

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO: A4(SDA), A5(SCL) 
// On an arduino MEGA 2560: 20(SDA), 21(SCL) 
// On an arduino LEONARDO: 2(SDA), 3(SCL), ... #define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)

#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Uncomment one of these 
//#define SCREEN_WIDTH 64 // OLED display width, in pixels
//#define SCREEN_WIDTH 128 // OLED display width, in pixels 

// Uncomment one of these
//#define SCREEN_ADDRESS 0x3C //< 0x3C for 128x32
//#define SCREEN_ADDRESS 0x3D //< 0x3D for 128x64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int potpin = A0;
int potpin2 = A1;
int val;
int val2;
float x = 0; 
float y = 0;

void setup() {
  Serial.begin(9600);
  Serial.print("setup")
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {  
    Serial.println(F("SSD1306 allocation failed")); 
    for(;;); // Don't proceed, loop forever
  } 
  display.display(); 
  delay(2000); // Pause for 2 seconds
  display.clearDisplay();
  // Draw a single pixel in white 
  display.drawPixel(10, 10, SSD1306_WHITE); 
  display.display(); 
  delay(2000);
}

void loop() { 
  val = analogRead(potpin);
  x = map(val,0,1023,0,128); 
  val2 = analogRead(potpin2);
  y = map(val2, 0,1023,0,64);
  //Serial.printl(x);
  //Serial.println(y);
  display.drawPixel(x,y, SSD1306_WHITE);
  display.display();
}
