#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "https://api.jcdecaux.com";  

EthernetClient client;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
  }
  delay(1000);
  Serial.println("connecting...");
  if (client.connect(server, 80)) {
    Serial.println("connected");
    client.println("GET /vls/v1/stations?contract=paris&apiKey=833f7a451533ba92a04cf8fcbb840fff9612cae8");
    client.println();
  } 
  else {
    Serial.println("connection failed");
  }
}
void loop(){
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  
  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();

    // do nothing forevermore:
    for(;;)
      ;
  }
}





