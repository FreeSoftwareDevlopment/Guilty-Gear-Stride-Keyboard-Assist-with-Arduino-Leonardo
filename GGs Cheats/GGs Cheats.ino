#define delayed 20
#include "Keyboard.h"
#include "def.h"
//#define DBUG
//#define LNUMDB
#include "attck.h"
#include "kc.hpp"

#define cal(x) sizeof(x)/sizeof(char*)
#define doubled(x) x, cal(x)

#define KCSIZE 4
keyController* kc[KCSIZE];

void setup() {
  kc[0] = new keyController(8, doubled(GreatYamadaAttackLeft), doubled(GreatYamadaAttackRight));
  kc[1] = new keyController(7, doubled(TheWonderfulAndDynamicGoshogawaraLeft), doubled(TheWonderfulAndDynamicGoshogawaraRight));
  kc[2] = new keyController(6, doubled(overheadKissLeft), doubled(overheadKissRight));
  kc[3] = new keyController(5, doubled(ArisugawaSparkleLeft), doubled(ArisugawaSparkleRight));
  pinMode(7, INPUT_PULLUP);
  #ifndef DBUG
  Keyboard.begin();
  #else
  Serial.begin(9600);
  #endif
}

bool left = true;
void loop() {
  left = analogRead(A0) > 500;
  digitalWrite(13, left ? HIGH : LOW);
  for(unsigned char i = 0;i<KCSIZE;i++){
    if(kc[i]->checkIfAndRun(left)) break;
  }
}
