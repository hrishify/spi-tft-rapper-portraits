#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   21
#define TFT_RST  22

// -------- RGB565 COLORS --------
#define BG_PALE_YELLOW  0xFFBC   // pale yellow background
#define SKIN_BROWN      0x9A64   // brown skin
#define BANDANA_WHITE   0xFFFF
#define BLACK           0x0000
#define GREY            0x7BEF
#define GOLD            0xFD20   // gold chain

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void drawTupacFace() {

  // -------- BACKGROUND --------
  tft.fillScreen(BG_PALE_YELLOW);

  // -------- HEAD --------
  tft.fillRoundRect(30, 22, 68, 112, 18, SKIN_BROWN);

  // -------- BANDANA --------
  tft.fillRect(30, 22, 68, 20, BANDANA_WHITE);              // band
  tft.fillTriangle(30, 22, 44, 10, 58, 22, BANDANA_WHITE);  // left tie
  tft.fillTriangle(72, 22, 86, 10, 98, 22, BANDANA_WHITE);  // right tie

  // -------- EYEBROWS (thick) --------
  tft.fillRect(40, 50, 18, 4, BLACK);
  tft.fillRect(70, 50, 18, 4, BLACK);

  // -------- EYES (sharp stare) --------
  tft.fillRect(44, 58, 10, 4, BLACK);
  tft.fillRect(74, 58, 10, 4, BLACK);

  // -------- NOSE --------
  tft.drawLine(64, 60, 62, 90, BLACK);
  tft.drawLine(64, 60, 66, 90, BLACK);
  tft.drawLine(62, 90, 66, 90, BLACK);

  // -------- NOSE RING --------
  tft.drawCircle(66, 82, 2, BLACK);

  // -------- MOUSTACHE --------
  tft.drawLine(54, 96, 62, 96, BLACK);
  tft.drawLine(66, 96, 74, 96, BLACK);

  // -------- GOATEE --------
  tft.fillTriangle(64, 100, 58, 118, 70, 118, BLACK);

  // -------- MOUTH --------
  tft.drawLine(56, 102, 72, 102, BLACK);

  // -------- JAW LINES --------
  tft.drawLine(32, 94, 32, 124, BLACK);
  tft.drawLine(96, 94, 96, 124, BLACK);

  // -------- CHEST --------
  tft.fillRect(30, 136, 68, 24, SKIN_BROWN);

  // -------- CHAIN --------
  tft.drawCircle(64, 138, 8, GOLD);
  tft.drawLine(56, 136, 44, 124, GOLD);
  tft.drawLine(72, 136, 84, 124, GOLD);
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  drawTupacFace();
}

void loop() {
  // Static portrait
}
