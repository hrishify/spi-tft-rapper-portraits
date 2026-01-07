#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   21
#define TFT_RST  22

// -------- RGB565 COLORS --------
#define BG_PALE_YELLOW  0xFFBC   // pale yellow background
#define SKIN_BROWN      0x9A64   // brown skin tone
#define BLACK           0x0000
#define WHITE           0xFFFF
#define GREY            0x7BEF

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void drawKanyeFace() {

  // -------- BACKGROUND --------
  tft.fillScreen(BG_PALE_YELLOW);

  // -------- HEAD --------
  tft.fillRoundRect(30, 22, 68, 112, 18, SKIN_BROWN);

  // -------- HAIR (short cut) --------
  tft.fillRect(30, 22, 68, 14, BLACK);

  // -------- SHUTTER SHADES (ICONIC) --------
  tft.fillRect(36, 54, 56, 16, BLACK);   // main frame

  // Vertical slats (shutter look)
  for (int x = 38; x < 92; x += 4) {
    tft.drawLine(x, 54, x, 70, GREY);
  }

  // -------- NOSE --------
  tft.drawLine(64, 70, 62, 98, BLACK);
  tft.drawLine(64, 70, 66, 98, BLACK);
  tft.drawLine(62, 98, 66, 98, BLACK);

  // -------- MOUTH (neutral, confident) --------
  tft.drawLine(54, 108, 74, 108, BLACK);

  // -------- JAW EMPHASIS --------
  tft.drawLine(32, 94, 32, 124, BLACK);
  tft.drawLine(96, 94, 96, 124, BLACK);

  // -------- JACKET / COLLAR --------
  tft.fillRect(30, 136, 68, 24, BLACK);
  tft.drawLine(30, 136, 50, 160, WHITE);
  tft.drawLine(98, 136, 78, 160, WHITE);
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  drawKanyeFace();
}

void loop() {
  // Static portrait
}
