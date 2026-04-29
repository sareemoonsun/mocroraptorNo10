String Cmd, strData, gfunc;
int strInt, strlength, Pulse = 0, Freq = 0;
char buffer[40];

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    strData = Serial.readString();
    strlength = strData.length();
    Cmd = strData.substring(0, 1);
    strInt = strData.substring(2, strlength).toInt();
    gfunc = strData.substring(2, strlength);

    if (Cmd == "F") {
      if (strInt != 0) Freq = strInt;
      sprintf(buffer, "read F = %S --> %d", strData, strInt);
      Serial.println(buffer);
    }

    if (Cmd == "P") {
      if (strInt != 0) Pulse = strInt;
      sprintf(buffer, "read P = %S --> %d", strData, strInt);
      Serial.println(buffer);
    }


    if (Cmd == "?") {
      sprintf(buffer, "Developer : Sarun, Version : 1");
      Serial.println(buffer);

    } else {
      sprintf(buffer, "Pulse=%d, Freq=%d, Cmd=%s", Pulse, Freq, Cmd.c_str());
      Serial.println(buffer);
    }
  }
}
