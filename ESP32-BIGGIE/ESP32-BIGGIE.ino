#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   21
#define TFT_RST  22

// -------- RGB565 COLORS --------
#define BG_PALE_YELLOW  0xFFBC   // pale yellow background
#define SKIN_BROWN      0x8A43   // darker brown skin
#define BLACK           0x0000
#define DARK_RED        0x7800   // coat (burgundy)
#define GOLD            0xFD20   // gold chain
#define GREY            0x7BEF

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void drawBiggieFace() {

  // -------- BACKGROUND --------
  tft.fillScreen(BG_PALE_YELLOW);

  // -------- FEDORA (KEY DETAIL) --------
  tft.fillRoundRect(22, 16, 84, 18, 8, BLACK);   // brim
  tft.fillRoundRect(38, 4, 52, 18, 6, BLACK);    // crown

  // -------- HEAD (wide & heavy) --------
  tft.fillRoundRect(26, 26, 76, 118, 20, SKIN_BROWN);

  // -------- EYEBROWS (thick, low) --------
  tft.fillRect(40, 56, 20, 5, BLACK);
  tft.fillRect(70, 56, 20, 5, BLACK);

  // -------- EYES (droopy) --------
  tft.fillRect(44, 64, 12, 4, BLACK);
  tft.fillRect(74, 64, 12, 4, BLACK);

  // -------- NOSE (wide) --------
  tft.drawLine(64, 66, 60, 98, BLACK);
  tft.drawLine(64, 66, 68, 98, BLACK);
  tft.drawLine(58, 98, 70, 98, BLACK);

  // -------- MOUTH (serious, relaxed) --------
  tft.drawLine(50, 108, 78, 108, BLACK);

  // -------- CHEEK / JAW EMPHASIS --------
  tft.drawLine(30, 92, 30, 126, BLACK);
  tft.drawLine(98, 92, 98, 126, BLACK);

  // -------- COAT (burgundy) --------
  tft.fillRect(22, 144, 84, 40, DARK_RED);

  // -------- GOLD CHAIN --------
  tft.drawCircle(64, 144, 8, GOLD);
  tft.drawLine(56, 142, 44, 128, GOLD);
  tft.drawLine(72, 142, 84, 128, GOLD);

  // -------- PENDANT --------
  tft.fillRect(60, 152, 8, 12, GOLD);
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  drawBiggieFace();
}

void loop() {
  // Static portrait
}
