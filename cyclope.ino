#include <Ethernet.h>

byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(213,41,121,149);

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
    client.println("GET /vls/v1/stations?contract=paris&apiKey=833f7a451533ba92a0.................");
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
}





