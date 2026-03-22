# Flappy Bird on ESP32

## Description

I developed a simple Flappy Bird-style game using an ESP32 and an OLED display. The game is controlled via a button that allows the player to navigate the bird and avoid obstacles.

This project helped me gain a better understanding of embedded systems, particularly the interaction between hardware and software components.

---

## Technologies Used

* ESP32
* Arduino (C/C++)
* OLED Display (SSD1306)
* Breadboard
* Buzzer
* Push Button

---

## Features

* Control the bird using a button
* Randomly generated obstacles
* Score increases when passing obstacles
* Game over when hitting an obstacle or leaving the screen
* Audio feedback for button press and game over

---

## How It Works (Overview)

The bird moves upward when the button is pressed and falls downward due to simulated gravity. Obstacles move from right to left with randomized positions.

---

## Hardware Connections

### OLED Display

* GND → GND
* VCC → 3.3V
* SCL → GPIO 22
* SDA → GPIO 21

---

### Buzzer

* Positive pin → GPIO 23
* Negative pin → GND

---

### Push Button

* One pin → GPIO 4
* Other pin → GND

(The button uses INPUT_PULLUP, no external resistor required)

---

## How to Run

1. Open the project in Arduino IDE
2. Select the ESP32 board
3. Upload the code
4. Press the button to start the game

---

## Project Structure

* flappy_bird_esp32.ino
* images.h
* fontovi.h

---

## Notes

This project was based on an open-source implementation (Volos Projects), which I adapted both in terms of hardware and software to fit my setup.

---

## Author

Bogdan Sima
