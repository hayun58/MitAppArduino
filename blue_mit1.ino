
#include <SoftwareSerial.h>

SoftwareSerial mySerial(A1, A0); // RX, TX

int cnt = 0;
String str;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {

  Serial.println(cnt);

  str = "c" + String(cnt);
  mySerial.print(str);
  if (cnt < 99) cnt++;
  else cnt = 0;
  if (mySerial.available()) {
    char tav = mySerial.read();
    if (tav == 's') cnt = 0;
  }
  delay(1000);
}
