#define Pin_RX2 16
#define Pin_TX2 17
int LED_Test = 2;
int SW_Test[8] = {15,4,5,18,19,21,22,23};
int swRead[8];

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  Serial2.setPins(Pin_RX2, Pin_TX2);
  pinMode(LED_Test, OUTPUT);
  for(int i = 0 ; i <= 7 ; i++){
    pinMode(SW_Test[i], INPUT_PULLUP);
  }
  
}

void loop() {
  for(int i = 0 ; i <= 7 ; i++){
    swRead[i] = digitalRead(SW_Test[i]);
  }
  Serial.printf("1%d%d%d%d%d%d%d%d\n",swRead[0],swRead[1],swRead[2],swRead[3],swRead[4],swRead[5],swRead[6],swRead[7]);
  Serial2.printf("1%d%d%d%d%d%d%d%d\n",swRead[0],swRead[1],swRead[2],swRead[3],swRead[4],swRead[5],swRead[6],swRead[7]);
  delay(100);
}
