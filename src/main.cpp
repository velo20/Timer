
#include <Arduino.h>
#include <RotaryEncoder.h>
#define PIN_A 32
#define PIN_B 35
RotaryEncoder encoder(PIN_A, PIN_B,
RotaryEncoder::LatchMode::FOUR3);
#define MENU_ANZ 5;
char *menu[] = {
"Eintrag 1",
"Eintrag 2",
"Eintrag 3",
"Eintrag 4",
"Eintrag 5",
};
void setup() {
Serial.begin(115200);
Serial.println("Einfaches Beispiel zum Rotary Encoder");
}
static long pos = 0;
int wahl = 0;
void loop() {
encoder.tick();
int newPos = encoder.getPosition();
if (pos != newPos)
{
Serial.printf("new pos = %d\n", newPos);
Serial.print("direction = %d \n",
(int)encoder.getDirection());
wahl = newPos % MENU_ANZ;
if (wahl < 0) { wahl += MENU_ANZ; }
Serial.printf("wahl = %d \n", wahl);
Serial.println(menu[wahl]);
pos = newPos;
}
}