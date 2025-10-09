#include <CircularBuffer.hpp>

void setup() {
  Serial.begin(9600);
  delay(500);

  CircularBuffer<uint8_t, 4> buffer;

  buffer.push(10);
  buffer.push(20);
  buffer.push(30);
  buffer.push(40);
  buffer.push(50);

  Serial.print("Oldest:        "); Serial.println(buffer.oldest());
  Serial.print("Latest:        "); Serial.println(buffer.latest());
  Serial.print("Min:           "); Serial.println(buffer.minValue());
  Serial.print("Max:           "); Serial.println(buffer.maxValue());
  Serial.print("Average:       "); Serial.println(buffer.avg());
  Serial.print("Contains (10): "); Serial.println(buffer.contains(10) ? "Yes" : "No");
}

void loop() {}
