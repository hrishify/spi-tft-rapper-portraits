#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   21
#define TFT_RST  22

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void drawEminemFace() {
  tft.fillScreen(ST77XX_BLACK);

  // ----- Head base -----
  tft.fillRoundRect(24, 20, 80, 120, 20, ST77XX_WHITE);

  // ----- Hair cap (bleached look) -----
  tft.fillRoundRect(24, 20, 80, 30, 18, ST77XX_YELLOW);

  // ----- Eyes -----
  tft.fillRect(42, 60, 12, 6, ST77XX_BLACK);
  tft.fillRect(74, 60, 12, 6, ST77XX_BLACK);

  // Eyebrows (angry / intense)
  tft.drawLine(40, 55, 56, 52, ST77XX_BLACK);
  tft.drawLine(72, 52, 88, 55, ST77XX_BLACK);

  // ----- Nose shadow -----
  tft.drawLine(64, 70, 60, 95, ST77XX_BLACK);
  tft.drawLine(64, 70, 68, 95, ST77XX_BLACK);

  // ----- Mouth (tight, serious) -----
  tft.drawLine(50, 105, 78, 105, ST77XX_BLACK);

  // ----- Hoodie outline -----
  tft.drawRoundRect(18, 15, 92, 135, 25, ST77XX_WHITE);
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  drawEminemFace();
}

void loop() {
  // static portrait
}
