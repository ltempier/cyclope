#include <SPI.h>
#include <Ethernet.h>
#include <JsonParser.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "adrienbaptiste.com";
EthernetClient client;

JsonParser<4> parser;
String jsonData = "";
int myStations[] = { 20024, 20025, 20026 };
int myLedStations[] = { 8, 7, 2 };

int led = 8;
int currentIndex = 0;
String apiKey = "833f7a451533ba92a04cf8fcbb840fff9612cae8";

const unsigned long requestInterval = 10000; // delay between requests
unsigned long lastAttemptTime = 0;

boolean startParse = false;
boolean endParse = false;

void setup() {
  for (int thisPin = 0; thisPin < 3; thisPin++) { 
    pinMode(myLedStations[thisPin], OUTPUT);
    digitalWrite(myLedStations[thisPin], LOW);   

  }

  Serial.begin(9600);
  while (!Serial) {
  }  
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
  }

  delay(1000);
  Serial.println("connecting...");
  connectToServer();
}

void loop(){
  if (client.connected()) {
    if (client.available()) {
      char c = client.read();
      if (c == '{') {
        startParse = true;
      }

      if(startParse) {
        jsonData.concat(c);
      }

      if (c == '}') {
        endParse = true;
      }
    }

    if (endParse) {
      jsonData.concat("}");
      char charBuf[jsonData.length()];
      jsonData.toCharArray(charBuf, jsonData.length());
      JsonHashTable hashTable = parser.parseHashTable(charBuf);

      if (!hashTable.success()) {
        Serial.println("parsing failed");
      }
      
      int availableBikes = hashTable.getLong("available_bikes");
      
      Serial.println(myStations[currentIndex]);
      Serial.println(availableBikes);
       
      if (availableBikes == 0) {
          digitalWrite(myLedStations[currentIndex], LOW);
           Serial.println("ZRO");
      } else {
         digitalWrite(myLedStations[currentIndex], HIGH);
         Serial.println(myLedStations[currentIndex]);
      }
      
     

      currentIndex++;
      
      if (currentIndex == (sizeof(myStations) / sizeof(int))) {
        currentIndex = 0;
      }
      
      client.stop();
    }
  } 
  else if (millis() - lastAttemptTime > requestInterval) {
    connectToServer();
  }
}

void connectToServer() {
  if (client.connect(server, 80)) {
    String httpQuery = "GET /proxy-arduino/proxy.php?apiKey=" + apiKey + "&station=" +  myStations[currentIndex] + " HTTP/1.1";
    client.println(httpQuery);
    client.println("HOST: adrienbaptiste.com");
    client.println();    

    startParse = false;
    endParse = false;
    jsonData = "";
  }

  lastAttemptTime = millis();
}   

