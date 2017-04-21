#include "UbidotsMicroESP8266.h"

#define TOKEN  "fL7bB5nkQJ2NAkZNoaiy3U3Kz2H16V"  // Put here your Ubidots TOKEN
#define ID_1 "58f9c22076254238893ef4c8" // Put your variable ID1 here (score of the player)
#define ID_2 "58f8b3af7625423887675651"// Put your variable ID2 here (score of the other player)
#define WIFISSID "ESGI" // Put here your Wi-Fi SSID
#define PASSWORD "Reseau-GES" // Put here your Wi-Fi password

Ubidots client(TOKEN);

const int L1 = D4; // broche 2 du micro-contrôleur se nomme maintenant : L1
int scoreJ1 = 0;   // Initialize player's score

// the setup routine runs once when you press reset:
void setup() {
  pinMode(L1, OUTPUT); //L1 is the Out pin
  pinMode(D3, OUTPUT); //D3 is the Out pin
  digitalWrite(D3, 0); 
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  delay(10);
  client.wifiConnection(WIFISSID, PASSWORD); // Setting wifi connection with ssid and password

}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // variable to get the game over time
  int gameOver = 0;
  // print out the value you read:
  Serial.printf("%d 0 500 \n", sensorValue);
  delay(1);        // delay in between reads for stability
  // if the brightness is under 150, event which is triggered when there is a goal
  if (sensorValue < 150) {
    digitalWrite(L1, HIGH); // Turn on Led 
    if (client.getValue(ID_2) < 8) { // If the other player's score is not under 8
      if (scoreJ1 > 8) {
        scoreJ1 = 0;  // reset score of the player
        gameOver = 1; // setting gameover
        client.add(ID_2, 0.0); // Reset score
      } else {
        scoreJ1++; // score + 1
      }
      printf("score du joueur 1 : %d \n", scoreJ1);
      digitalWrite(L1, LOW); // turn off led
      client.add(ID_1, static_cast<float>(scoreJ1)); // sending player's score
      client.sendAll(false);
    }
  }
}
