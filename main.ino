#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Largeur de l'écran OLED
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED

// Adresse I2C de l'écran OLED (généralement 0x3C pour les écrans 0.96 pouces)
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // Initialisation du port série pour le débogage
  Serial.begin(115200);

  // Initialisation de l'écran OLED avec l'adresse directement
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
    Serial.println(F("Échec de l'initialisation de l'écran OLED"));
    while (true); // Boucle infinie en cas d'échec
  }

  // Effacer l'écran
  display.clearDisplay();

  // Exemple de texte à afficher
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10);
  display.println(F("Je suis le patron"));
  display.display(); // Affiche le texte sur l'écran
}

void loop() {
  // Rien à faire ici
}
