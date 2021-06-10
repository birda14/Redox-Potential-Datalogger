#include "orp_grav.h"

//--------------------------------------

  Gravity_ORP ORP1 = Gravity_ORP(A0);
  Gravity_ORP ORP2= Gravity_ORP(A1);
  Gravity_ORP ORP3 = Gravity_ORP(A2);
  Gravity_ORP ORP4= Gravity_ORP(A3);
  int cal_value= 225;
//--------------------------------------
void setup() {
  Serial.begin(9600);
  ORP1.cal_clear();
  ORP2.cal_clear();
  ORP3.cal_clear();
  ORP4.cal_clear();
  Serial.println("Calibration Cleared");
  ORP1.cal(cal_value);
  ORP2.cal(cal_value);
  ORP3.cal(cal_value);
  ORP4.cal(cal_value);
  Serial.println("ORP Probes Calibrated, 225mV");
}

void loop() {
 
  Serial.println((int)ORP1.read_orp());
  Serial.println((int)ORP2.read_orp());
  Serial.println((int)ORP3.read_orp());
  Serial.println((int)ORP4.read_orp());
  delay(3000);
  
}
