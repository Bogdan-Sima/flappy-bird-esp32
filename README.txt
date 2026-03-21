# Flappy Bird pe ESP32 


## Descriere
Am realizat un joc simplu de tip Flappy Bird folosind un ESP32 și un display OLED. Jocul funcționează prin apăsarea unui buton pentru a controla pasărea și a evita obstacolele.

Proiectul m-a ajutat să înțeleg mai bine cum funcționează un sistem embedded (interacțiune hardware + software).

---

## Tehnologii folosite
- ESP32  
- Arduino (C/C++)  
- Display OLED SSD1306  
- Breadboard  
- Buzzer  
- Buton  

---

## Ce face jocul
- controlezi pasărea cu un buton  
- apar obstacole generate random  
- scorul crește când treci de obstacole  
- jocul se termină dacă lovești un obstacol sau ieși din ecran  
- există sunet la apăsare și la game over  

---

## Cum funcționează (pe scurt)
Pasărea se mișcă în sus când apeși butonul și cade în jos din cauza „gravitației” (simulată în cod). Obstacolele se deplasează din dreapta spre stânga și au poziții random.

---

## Conexiuni hardware

### OLED
- GND → GND  
- VCC → 3.3V  
- SCL → GPIO 22  
- SDA → GPIO 21  

---

### Buzzer
- Pin lung → GPIO 23  
- Pin scurt → GND  

---

### Buton
- Un pin → GPIO 4  
- Celălalt → GND  

(butonul folosește INPUT_PULLUP, nu am pus rezistență externă)

---

## Cum rulezi
1. Deschizi proiectul în Arduino IDE  
2. Selectezi placa ESP32  
3. Încarci codul  
4. Apeși butonul și începi jocul  

---

## Structură proiect
flappy_bird_esp32.ino
images.h
fontovi.h

---

## Observații
Am pornit de la un proiect open-source (realizat de Volos Projects) și l-am adaptat (hardware + modificări în cod) pentru a funcționa pe setup-ul meu.

---

## Autor
Bogdan Sima


