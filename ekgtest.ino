#include <MsTimer2.h>

int EKG[] = {61, 61, 61, 61, 62, 64, 68, 67, 67, 65, 61, 61, 61, 50, 120, 220, 100, 40, 61, 61, 61, 61, 61, 64, 67, 70, 72, 74, 74, 73, 70, 69, 63, 61, 61, 61, 61, 61};


void vector() {
  static int vectorVar = 0;
  static int test = 0;
  
  int volumen = analogRead(A1);
  volumen = map(volumen, 0, 1023, 0, 100);
  int maxSize = sizeof(EKG) / sizeof(int);
  test = (volumen * EKG[vectorVar++]) / 100;
  ///Test for end of EKG array
  if (vectorVar >= maxSize) {
    vectorVar = 0;
  }
  Serial.println(test);

  int bpm = map(analogRead(A0), 0, 1023, 40, 7);
  static int bpmNow = 0;
  if (bpmNow != bpm){
    bpmNow = bpm;
    MsTimer2::set(bpmNow, vector);
    MsTimer2::start();
//    Serial.println(bpmNow);
  }
}

void setup() {
  Serial.begin(115200);
  MsTimer2::set(40, vector);
  MsTimer2::start();
  // put your setup code here, to run once:
}

void loop() {

}
