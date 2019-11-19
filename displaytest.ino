// This #include statement was automatically added by the Particle IDE.
#include <PietteTech_DHT.h>

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_SSD1306.h>
#include "Adafruit_GFX.h"

// /* Uncomment this block to use hardware SPI
// If using software SPI (the default case):
#define OLED_MOSI   D0
#define OLED_CLK    D1
#define OLED_DC     D2
#define OLED_CS     D3
#define OLED_RESET  D4

#define DHTTYPE  DHT11              // Sensor type DHT11/21/22/AM2301/AM2302
#define DHTPIN   D6           	    // Digital pin for communications
#define DHT_SAMPLE_INTERVAL   2000  // Sample every two seconds

 //declaration
void dht_wrapper(); // must be declared before the lib initialization

// Lib instantiate
PietteTech_DHT DHT(DHTPIN, DHTTYPE, dht_wrapper);

// globals
unsigned int DHTnextSampleTime;	    // Next time we want to start sample
bool bDHTstarted;		    // flag to indicate we started acquisition

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

char incoming;

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC);
    Serial.begin(9600);
    
    DHT.begin();

    DHTnextSampleTime = 0;  // Start the first sample immediately
    
    display.clearDisplay();
}

// This wrapper is in charge of calling
 // must be defined like this for the lib work
void dht_wrapper() {
  DHT.isrCallback();
}

void loop() {
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    DHT.acquire();
    
    if (!DHT.acquiring()) {
        display.clearDisplay();
        display.display();
   
        String s1 = String("Temp: ");
        String sT = String(DHT.getCelsius(), 0);
        s1.concat(sT);
        s1.concat(String(" C\r\n"));
        
        String s2 = String("Hum: ");
        String sH = String(DHT.getHumidity(), 0);
        s2.concat(sH);
        s2.concat(String(" %\r\n"));
        
        display.println(s1);
        display.println(s2);
        
        display.display();
        delay(DHT_SAMPLE_INTERVAL);
    }
}