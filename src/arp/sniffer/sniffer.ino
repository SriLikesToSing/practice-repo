#include <ESP8266WiFi.h>
#include <ESP8266WifiMulti.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ESP8266Ping.h>
#include <WiFiClient.h>



#define htons(_n) ((uint16_t)((((_n) & 0xff) << 8) | (((_n) >> 8) & 0xff)))

void sendArpRequest(){
  
  IPAddress targetIP(192, 168, 0, 151);
  IPAddress routerIP(192, 168, 0, 1);

  uint8_t arpPacket[] = {
    0, 1,
    8, 0,
    6,
    4, 
    0, 1,

  //  0xE0, 0x0A, 0xF6, 0x51, 0x91, 0x95,
    //0xC0, 0xC9, 0xE3, 0xC8, 0xF0, 0x83,
    //our devices MAC address
    0x4C,0x75, 0x25, 0x36, 0xC4, 0x0C,

    
    routerIP[0], routerIP[1], routerIP[2], routerIP[3],

    0, 0, 0, 0, 0, 0,

    targetIP[0], targetIP[1], targetIP[2], targetIP[3], 
  };

  WiFiUDP udp;

  udp.beginPacket(targetIP, 0x0806);
  udp.write(arpPacket, sizeof(arpPacket));
  udp.endPacket();
  Serial.println("successfully sent packet");
  
}

void sendArpRequest2(){
  struct arphdr{
    uint16_t htype;
    uint16_t ptype;
    uint8_t hlen;
    uint8_t plen;
    uint16_t oper; 
    uint8_t sha[6];
    uint8_t spa[4];
    uint8_t tha[6];
    uint8_t tpa[4];
  } arpPacket;

  unsigned char espMac[] = {0x4C, 0x75, 0x25, 0x36, 0xC4, 0x0C};
  IPAddress targetIP(192, 168, 0, 151);
  IPAddress routerIP(192, 168, 0, 1);
  arpPacket.htype = htons(1);
  arpPacket.ptype = htons(0x0800);
  arpPacket.hlen = 6;
  arpPacket.plen = 4;
  arpPacket.oper = htons(1);
  memcpy(arpPacket.sha, espMac, 6);
  memcpy(arpPacket.spa, routerIP, 4);
  memset(arpPacket.tha, 0, 6);
  memcpy(arpPacket.tpa, targetIP, 4);

  WiFiClient client;
  client.connect(targetIP, 0);
  
  client.write((uint8_t*)&arpPacket, sizeof(arpPacket));
  client.stop();

  Serial.println("ARP request sent");
}

void connectWifi(){
  WiFi.begin("TP-link_Kish", "6267345363");
  Serial.print("Connecting");

  int i =0;
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(++i); Serial.print(' ');
  }
  Serial.println("\n");
  Serial.println("made connection.");
  Serial.print(WiFi.localIP());
  //getClientInfo();
  //sendArpRequest();
}


void setup(){
  Serial.begin(115200);
  delay(10);
  Serial.println('\n');
  connectWifi();
  //Serial.println(WiFi.macAddress());

}


void loop(){
 sendArpRequest2(); 
 delay(5000);

 
}

void getClientInfo(){
  int devicesFound = 0;

  for(int x=1; x<255; x++){
    String ipAddress = "192.168.0." + String(x);

    if(Ping.ping(ipAddress.c_str())){
      Serial.println("Device found at: " + ipAddress);
      devicesFound++;
    }
  }
    Serial.println("Scan complete. Found " + String(devicesFound) + " devices.");

}
