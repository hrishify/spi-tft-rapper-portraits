#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   21
#define TFT_RST  22

// -------- RGB565 COLORS --------
#define BG_PALE_YELLOW  0xFFBC   // pale yellow background
#define SKIN_BROWN      0x9A64   // brown skin tone
#define HAIR_BLACK      0x0000
#define GLASS_BLACK     0x0000
#define GOATEE_BLACK    0x0000
#define EARRING_WHITE   0xFFFF
#define SUIT_WHITE      0xFFFF
#define TIE_BLACK       0x0000

Adafruit_ST7735 tft(TFT_CS, TFT_DC, TFT_RST);

void drawDiddyFace() {

  // -------- BACKGROUND --------
  tft.fillScreen(BG_PALE_YELLOW);

  // -------- HEAD SHAPE --------
  tft.fillRoundRect(30, 22, 68, 112, 18, SKIN_BROWN);

  // -------- MOHAWK (KEY DETAIL) --------
  tft.fillRoundRect(58, 16, 12, 24, 6, HAIR_BLACK);  // center strip

  // -------- SUNGLASSES --------
  tft.fillRoundRect(38, 58, 22, 12, 4, GLASS_BLACK); // left lens
  tft.fillRoundRect(68, 58, 22, 12, 4, GLASS_BLACK); // right lens
  tft.drawLine(60, 64, 68, 64, GLASS_BLACK);         // bridge

  // -------- NOSE --------
  tft.drawLine(64, 70, 62, 96, HAIR_BLACK);
  tft.drawLine(64, 70, 66, 96, HAIR_BLACK);
  tft.drawLine(62, 96, 66, 96, HAIR_BLACK);

  // -------- GOATEE (SMALL, SHARP) --------
  tft.fillRect(60, 108, 8, 12, GOATEE_BLACK);        // chin
  tft.drawLine(58, 104, 70, 104, GOATEE_BLACK);      // moustache

  // -------- MOUTH --------
  tft.drawLine(56, 102, 72, 102, HAIR_BLACK);

  // -------- EARRINGS --------
  tft.fillCircle(30, 78, 3, EARRING_WHITE);          // left ear stud
  tft.fillCircle(98, 78, 3, EARRING_WHITE);          // right ear stud

  // -------- JAW EMPHASIS --------
  tft.drawLine(32, 94, 32, 124, HAIR_BLACK);
  tft.drawLine(96, 94, 96, 124, HAIR_BLACK);

  // -------- SUIT --------
  tft.fillRect(30, 136, 68, 24, SUIT_WHITE);

  // -------- TIE --------
  tft.fillTriangle(64, 136, 58, 160, 70, 160, TIE_BLACK);
}

void setup() {
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  drawDiddyFace();
}

void loop() {
  // Static portrait
}
