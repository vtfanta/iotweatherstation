 This #include statement was automatically added by the Particle IDE.
#include Adafruit_SSD1306.h
#include Adafruit_GFX.h

  Uncomment this block to use hardware SPI
 If using software SPI (the default case)
#define OLED_MOSI   D0
#define OLED_CLK    D1
#define OLED_DC     D2
#define OLED_CS     D3
#define OLED_RESET  D4
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

char incoming;

void setup() {
    display.begin(SSD1306_SWITCHCAPVCC);
    Serial.begin(9600);
    
}

void loop() {
     Reads a string from the serial input and prints it on the screen for 2 seconds
    display.clearDisplay();
    display.display();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    Serial.print(Hellorn);
   
   
    int len = Serial.available();
    Serial.print(len);
    if (len  0) {
        char incoming = (char )malloc(len  sizeof(char)+1);
        for (int i = 0; i  len; i++) {
            incoming[i] = Serial.read();
        }
        incoming[len] = '0';
        
        display.println(incoming);
        free(incoming);
    } else {
        display.println(Sadface...);    
    }
    display.display();
    delay(2000);
    display.clearDisplay();
     display.invertDisplay(true);
     delay(2000);
     display.invertDisplay(false);
     delay(2000);
}