
#include <Wire.h>

void setup() {
  Wire.begin(0x0B);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(115200);
}

void loop() {
}

volatile char c ;

void receiveEvent(int howMany) {
  //  Serial.print("howMany ");         // print the character
  //  Serial.println(howMany);         // print the character
  howMany--;
  c = Wire.read();
  while (howMany) {
    Wire.read();
    howMany--;
    if (c == 0x2f) {
      Serial.print(Wire.read(), HEX);
    }
  }
  if (c == 0x2f) {
    Serial.println("");         // print the character
  }
}


void requestEvent()
{
  delayMicroseconds(15);
  byte buffer[3];
  if (c == 0x09) {
    buffer[0] = 0x2a;
    buffer[1] = 0x2e;
    buffer[2] = 0x8d;
    Wire.write( buffer, 3);
  } else if (c == 0x0f) {
    buffer[0] = 0x5b;
    buffer[1] = 0x01;
    buffer[2] = 0x83;
    Wire.write( buffer, 3);
  } else if (c == 0x0a) {
    buffer[0] = 0xe2;
    buffer[1] = 0xfd;
    buffer[2] = 0xc5;
    Wire.write( buffer, 3);
  } else if (c == 0x0d) {
    buffer[0] = 0x23;
    buffer[1] = 0x00;
    buffer[2] = 0xA2;
    Wire.write( buffer, 3);
  } else if (c == 0x08) {
    buffer[0] = 0x96;
    buffer[1] = 0x0b;
    buffer[2] = 0xd3;
    Wire.write( buffer, 3);
  } else if (c == 0x3f) {
    buffer[0] = 0x3c;
    buffer[1] = 0x0f;
    buffer[2] = 0x9e;
    Wire.write( buffer, 3);
  } else if (c == 0x3e) {
    buffer[0] = 0xb0;
    buffer[1] = 0x0f;
    buffer[2] = 0xc2;
    Wire.write( buffer, 3);
  } else if (c == 0x3d) {
    buffer[0] = 0x3e;
    buffer[1] = 0x0f;
    buffer[2] = 0x98;
    Wire.write( buffer, 3);
  } else if (c == 0x18) {
    buffer[0] = 0xe8;
    buffer[1] = 0x03;
    buffer[2] = 0xf8;
    Wire.write( buffer, 3);
  } else if (c == 0x10) {
    buffer[0] = 0x5f;
    buffer[1] = 0x03;
    buffer[2] = 0xf6;
    Wire.write( buffer, 3);
  } else if (c == 0x17) {
    buffer[0] = 0x07;
    buffer[1] = 0x00;
    buffer[2] = 0xa3;
    Wire.write( buffer, 3);
  } else if (c == 0x1c) {
    buffer[0] = 0x22;
    buffer[1] = 0x03;
    buffer[2] = 0xcf;
    Wire.write( buffer, 3);
  } else if (c == 0x1b) {
    buffer[0] = 0x30;
    buffer[1] = 0x48;
    buffer[2] = 0x26;
    Wire.write( buffer, 3);
  }
}

