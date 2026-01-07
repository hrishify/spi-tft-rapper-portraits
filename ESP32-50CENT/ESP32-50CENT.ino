#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   21
#define TFT_RST  22

// ---- RGB565 COLORS ----
#define BG_PALE_YELLOW  0xFFBC   // pale yellow background
#define SKIN_BROWN      0xA145   // dark brown skin
#define DURAG_WHITE     0xFFFF   // white durag
#define BLACK           0x0000
#define GREY            0x7BEF

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void draw50CentFace() {
  // ---- Background ----
  tft.fillScreen(BG_PALE_YELLOW);

  // ---- Head (strong, square) ----
  tft.fillRoundRect(28, 24, 72, 112, 10, SKIN_BROWN);

  // ---- White Durag ----
  tft.fillRect(28, 24, 72, 20, DURAG_WHITE);             // top
  tft.fillTriangle(28, 44, 64, 36, 100, 44, DURAG_WHITE); // fold

  // ---- Eyebrows (heavy) ----
  tft.fillRect(38, 56, 18, 4, BLACK);
  tft.fillRect(72, 56, 18, 4, BLACK);

  // ---- Eyes (focused stare) ----
  tft.fillRect(42, 64, 10, 4, BLACK);
  tft.fillRect(76, 64, 10, 4, BLACK);

  // ---- Nose (wide bridge) ----
  tft.drawLine(64, 66, 60, 96, BLACK);
  tft.drawLine(64, 66, 68, 96, BLACK);
  tft.drawLine(60, 96, 68, 96, BLACK);

  // ---- Mouth (flat, serious) ----
  tft.drawLine(48, 108, 80, 108, BLACK);

  // ---- Jaw emphasis ----
  tft.drawLine(32, 96, 32, 124, BLACK);
  tft.drawLine(96, 96, 96, 124, BLACK);

  // ---- Vest / tank top ----
  tft.fillRect(28, 136, 72, 24, GREY);
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  draw50CentFace();
}

void loop() {
  // Static portrait
}
