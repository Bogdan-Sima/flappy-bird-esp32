#include <Wire.h>  
#include "SSD1306Wire.h"

#include "images.h"
#include "fontovi.h"

SSD1306Wire display(0x3c, 21, 22);

// ---------------- OBSTACOLE ----------------
float obstacleX[4];        // poziții X obstacole
int gapY[4];               // poziție gol obstacol
int obstacleSpacing = 32;  // distanță între obstacole
int gapHeight = 30;        // înălțime spațiu liber

void setup() {

  pinMode(23, OUTPUT);        // buzzer
  pinMode(4, INPUT_PULLUP);   // buton

  display.init();

  // inițializare obstacole
  for(int i = 0; i < 4; i++)
  {
    obstacleX[i] = 128 + ((i + 1) * obstacleSpacing);
    gapY[i] = random(8, 32);
  }

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

// ---------------- VARIABILE JOC ----------------
int score = 0;

int buttonPressed = 0;

float birdX = 30.0;
float birdY = 22.0;

int direction = 0;  // 0 = jos, 1 = sus

unsigned long lastJumpTime = 0;

int gameState = 0;  // 0 = meniu, 1 = joc

int playSound = 0;
unsigned long soundTimer = 0;

// ---------------- LOOP ----------------
void loop() {

  display.clear();

  // -------- MENIU --------
  if(gameState == 0)
  {
    display.setFont(ArialMT_Plain_16);
    display.drawString(0,4,"Flappy");

    display.drawXbm(0, 0, 128, 64, pozadina);
    display.drawXbm(20, 32, 14, 9, ptica);

    display.setFont(ArialMT_Plain_10);
    display.drawString(0,44,"press to start");

    if(digitalRead(4) == 0)
      gameState = 1;
  }

  // -------- JOC --------
  if(gameState == 1)
  {
    display.drawString(3,0,String(score));

    // -------- CONTROL --------
    if(digitalRead(4) == 0)
    {
      if(buttonPressed == 0)
      {
        lastJumpTime = millis();
        direction = 1;
        playSound = 1;
        buttonPressed = 1;
        soundTimer = millis();
      }
    } 
    else 
    {
      buttonPressed = 0;
    }

    // -------- OBSTACOLE --------
    for(int j = 0; j < 4; j++)
    {
      display.setColor(WHITE);
      display.fillRect(obstacleX[j], 0, 6, 64);

      display.setColor(BLACK);
      display.fillRect(obstacleX[j], gapY[j], 6, gapHeight);
    }

    // -------- PASĂRE --------
    display.setColor(WHITE);
    display.drawXbm(birdX, birdY, 14, 9, ptica);

    // -------- MIȘCARE OBSTACOLE --------
    for(int j = 0; j < 4; j++)
    {
      obstacleX[j] -= 0.01;

      if(obstacleX[j] < -7)
      {
        score++;
        digitalWrite(23, 1);

        gapY[j] = random(8,32);
        obstacleX[j] = 128;
      }
    }

    // -------- GRAVITAȚIE --------
    if((lastJumpTime + 185) < millis())
      direction = 0;

    if((soundTimer + 40) < millis())
      playSound = 0;

    if(direction == 0)
      birdY += 0.01;
    else
      birdY -= 0.03;

    // -------- SUNET --------
    digitalWrite(23, playSound);

    // -------- COLIZIUNE MARGINI --------
    if(birdY > 63 || birdY < 0)
    {
      gameState = 0;
      birdY = 22;
      score = 0;

      digitalWrite(23,1);
      delay(500);
      digitalWrite(23,0);

      for(int i = 0; i < 4; i++)
      {
        obstacleX[i] = 128 + ((i + 1) * obstacleSpacing);
        gapY[i] = random(4,30);
      }
    }

    // -------- COLIZIUNE OBSTACOLE --------
    for(int m = 0; m < 4; m++)
    {
      if(obstacleX[m] <= birdX + 7 && birdX + 7 <= obstacleX[m] + 6)
      {
        if(birdY < gapY[m] || birdY + 8 > gapY[m] + gapHeight)
        {
          gameState = 0;
          birdY = 22;
          score = 0;

          digitalWrite(23,1);
          delay(500);
          digitalWrite(23,0);

          for(int i = 0; i < 4; i++)
          {
            obstacleX[i] = 128 + ((i + 1) * obstacleSpacing);
            gapY[i] = random(8,32);
          }
        }
      }
    }

    display.drawRect(0,0,128,64);
  }

  display.display();
}