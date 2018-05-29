void loop() {
  if(Serial.available()){
    Serial.println("gogo");
    String incoming=Serial.readString();
    Serial.println("get"+incoming);
    sendMessageToSIM5360(incoming);
    Serial.println("ok~~~");
    } 
}
