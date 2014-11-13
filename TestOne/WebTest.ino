#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

// Initialises Arduino server and sets pin being used.
YunServer server;
int ledPin = 13;

void setup() {

	// Makes sure LED is off.
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);

	// Begins the bridge and sets the server to listen locally.
	Bridge.begin();
	server.listenOnLocalhost();
	server.begin();

}

void loop() {

	// Attempts to accept a connection.
	YunClient client = server.accept();

	// Processes client request.
	if (client) {

		// Reads the command from the client and trims whitespace.
		String command = client.readString();
		command.trim();

		// Lights the pin.
		if (command == "lightup") {
			digitalWrite(ledPin, HIGH);
			client.print("ON");
		} else if (command == "lightdown") {
			digitalWrite(ledPin, LOW);
			client.print("OFF");
		}

		// Closes the client connection.
		client.stop();

	}

	// Prevents overwork of processor.
	delay(50);

}
