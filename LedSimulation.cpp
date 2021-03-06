
#include "LedSimulation.h"

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF


LedSimulation::LedSimulation(Adafruit_ILI9341 &tft) {
  pTft = &tft;
  clear();
}

void LedSimulation::clear(void) {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      this->Scene[i][j] = 1;
      this->SceneWas[i][j] = 1;
    }
  }
}

void ::LedSimulation::clearScene(void) {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 16; j++) {
      this->Scene[i][j] = 1;
    }
  }
}

void LedSimulation::display(void)
{
  for ( int i = 0 ; i < 16 ; i++ ) {
    for ( int j = 0 ; j < 16 ; j++ ) {
      if (this->Scene[i][j] != this->SceneWas[i][j]) {
        int nColor = BLACK;
        int eColorNew = Scene[i][j];
        if (eColorNew == 0) {
          nColor = RED;
        } else if (eColorNew == 2) {
          nColor = BLUE;
        } else if (eColorNew == 3) {
          nColor = GREEN;
        }
        //pTft->fillCircle(j * 15 + 7, i * 15 + 7, 6, nColor);
        pTft->fillCircle(i * 15 + 7, j * 15 + 7, 6, nColor);
        this->SceneWas[i][j] = eColorNew;
      }
    }
  }
}

void LedSimulation::draw(void)
{
  display();
  clearScene();
}

void LedSimulation::setScene(unsigned char Scene[16][16])
{
  for (byte i = 0; i < 16; i++) {
    for (byte k = 0; k < 16; k++) {
      this->Scene[i][k] = Scene[i][k];
    }
  }
}

void LedSimulation::setLedOn(int x, int y)
{
  Scene[x][y] = 0;
}

void LedSimulation::setLedOff(int x, int y)
{
  Scene[x][y] = 1;
}

void LedSimulation::setLedRed(int x, int y)
{
  Scene[x][y] = 0;
}

void LedSimulation::setLedBlue(int x, int y)
{
  Scene[x][y] = 2;
}

void LedSimulation::setLedGreen(int x, int y)
{
  Scene[x][y] = 3;
}

int LedSimulation::getLedState(int x, int y)
{
  return Scene[x][y];
}

int LedSimulation::getLedStateCur(int x, int y)
{
  return SceneWas[x][y];
}

