void initializeNetwork()
{
  //Initial 3G
  pinMode(netowrkResetPin, OUTPUT);
  digitalWrite(netowrkResetPin, LOW);
  delay(100);
  digitalWrite(netowrkResetPin, HIGH);
  delay(5000);
  networkBaudrate = 115200;
  networkSerial.begin( networkBaudrate );
  sendCMDtoNetworkDevice("\r",1000, DEBUG);
  sendCMDtoNetworkDevice("AT+IPR=2400\r", 1000, DEBUG);
  networkBaudrate = 2400;
  networkSerial.begin( networkBaudrate );
  sendCMDtoNetworkDevice("\r", 1000, DEBUG);
  sendCMDtoNetworkDevice("AT+CGSOCKCONT=1,\"IP\",\"internet\"", 1000, DEBUG);

}

void flushNetworkSerial() {
  long int time = millis();
  while ( (time + 2000) > millis())
  {
    while (networkSerial.available() > 0) {
      char t = Serial.read();
      delay(20);
    }
  }
}

/*
  Name: sendCMDtoNetworkDevice
  Description: Function used to send data to ESP8266.
  Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
  Returns: The response from the esp8266 (if there is a reponse)
*/
String sendCMDtoNetworkDevice(String command, const int timeout, boolean debug)
{
  String response = "";
  networkSerial.print(command); // send the read character to the esp8266
  networkSerial.print("\r\n");
  delay(1000);

  long int time = millis();

  while ( (time + timeout) > millis())
  {
    while (networkSerial.available() > 0)
    {
      char c = (char)networkSerial.read(); // read the next character.
      response += c;
      delay(50);
    }
  }

  if (debug)
  {
    Serial.println("Input : ");
    Serial.println(command);
    Serial.println("Output : ");
    Serial.println(response);
  }

  return "";
}

void sendMessageToSIM5360(String Meg)
{
  initializeNetwork();
sendCMDtoNetworkDevice("AT+CHTTPACT=\"" + uploadServer + "\",80", 1000, DEBUG);
   delay(5000);
  String cmd = "";
    cmd = cmd + "GET "+ uploadPage +  Meg;
    //cmd = cmd +  uploadPage +  Meg;
    //cmd = cmd + " HTTP/1.1\r\n";
    //cmd = cmd + "Host: "+uploadServer+"\r\n";
    //cmd = cmd + "User-Agent: My Web Agent\r\n";
    //cmd = cmd + "Connection: close\r\n";

  
  sendCMDtoNetworkDevice(cmd, 1000, DEBUG);
  sendCMDtoNetworkDevice(uploadEndSymbol, 1000, false);
  sendCMDtoNetworkDevice("AT+CPOF", 1000, false);
}

