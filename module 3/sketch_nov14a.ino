void setup() {
  Serial.begin(9600);
}

void loop() {
  String a=String(millis()/1000)+String(";")+String(random(20,250));
  Serial.println(a);
  delay(1000);
}
