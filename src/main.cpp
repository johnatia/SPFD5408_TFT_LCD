#include <Arduino.h>

#include "tft.h"
#include "game.h"
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4    // optional

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

 unsigned long test_FillScreen(void)
{
  unsigned long start = micros();
  tft_FillScreen(RED);
  tft_FillScreen(GREEN);
  tft_FillScreen(BLUE);
  return (micros()-start);  
}

void Animation(void)
{
    for(int y = 0; y<320-92;  y+=10 )
    {
      tft_drawRGBBitmap( 10 ,  y, Game, 83 , 92);
      tft_FillScreen(WHITE);
    }
}

void setup() {

  tft_lcd(LCD_CS , LCD_CD ,LCD_WR ,LCD_RD ,LCD_RESET);
  tft_init();
  tft_reset();
  tft_begin();
  
  tft_FillScreen(WHITE);


}

void loop() {
  
    Animation();
}