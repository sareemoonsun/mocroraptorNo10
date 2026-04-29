#define Pin_RX2 16
#define Pin_TX2 17
int LED_Test[8] = {15,4,5,18,19,21,22,23};
int SW_Test = 0;
int keyInput;
int bit[8];
void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  Serial2.setPins(Pin_RX2, Pin_TX2);
  for(int i = 0 ; i <= 7 ; i++){
    pinMode(LED_Test[i], OUTPUT);
  }
  pinMode(SW_Test, INPUT_PULLUP);
}

void loop() {
  if (Serial2.available() > 0) {
    keyInput = Serial2.parseInt();
    bit[0] = (keyInput/10000000) % 10;
    bit[1] = (keyInput/1000000) % 10;
    bit[2] = (keyInput/100000) % 10;
    bit[3] = (keyInput/10000) % 10;
    bit[4] = (keyInput/1000) % 10;
    bit[5] = (keyInput/100) % 10;
    bit[6] = (keyInput/10) % 10;
    bit[7] = keyInput % 10;
    Serial.println(keyInput);
    for(int i = 0 ; i <= 7 ; i++){
      digitalWrite(LED_Test[i], bit[i]);
    }
  }
}
