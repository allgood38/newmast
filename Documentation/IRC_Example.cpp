/*
  Basic IRC Client
 
 This sketch connects to an IRC Server and Idles in a
 specified Channel
 
 Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 
 Credits :
 * Arduino Web Client by David A. Mellis
 
 created 18 Jan 2011
 by Keiran "Affix" Smith <affix@affix.me>
 
 */

#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
byte ip[] = { 192,168,1,28 };
byte server[] = { 38,229,70,20 }; // Freenode
int port = 6667;
String chan = "#arduino";
String nick = "arduBot";
String join = "JOIN ";
String nickcmd = "NICK ";
String user = "USER ";
String pong = "PONG ";


Client client(server, port);

void setup() {
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  delay(1000);
  Serial.println("connecting to IRC Server...");

  if (client.connect()) {
    Serial.println("connected");
    client.println(nickcmd.concat(nick));
    client.println(user.concat(nick));
    client.println();
  }
  else {
    Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available()) {
    client.println(join.concat(chan));
    while(true)
    {
      String data;
      data = client.read();
      
      if(data.startsWith("PING"))
      {
        client.println(pong.concat(data.substring(5)));
      }
    }
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }
}
