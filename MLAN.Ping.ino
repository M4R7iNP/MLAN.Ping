/**
* Marikollan Network Light
* Sets ledPin HIGH when ping is successful, LOW when ping failed
* Based on Blake Foster's Arduino-Ping
* Free software, GNU General Public Licence v2, yadda yadda
*/

#include <SPI.h>				 
#include <Ethernet.h>
#include <ICMPPing.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED}; // max address for ethernet shield
byte ip[] = {192,168,0,254}; // ip address for ethernet shield
IPAddress pingAddr(8,8,8,8); // ip address to ping
int ledPin = 31;

SOCKET pingSocket = 0;
ICMPPing ping(pingSocket, (uint16_t)random(0, 255));

void setup() {
	// start Ethernet
	Ethernet.begin(mac, ip);
	pinMode(ledPin, OUTPUT);
}

void loop() {
	ICMPEchoReply echoReply = ping(pingAddr, 4);
	if (echoReply.status == SUCCESS) {
		digitalWrite(ledPin, HIGH);
		delay(1000);
	} else {
		digitalWrite(ledPin, LOW);
		delay(100);
	}
}
