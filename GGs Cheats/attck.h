#include <string.h>

void playAttck(const char** atck, size_t siz){
  for (size_t i = 0;i < siz;i++){
    #ifdef LNUMDB
    Serial.println(strlen(atck[i]));
    #else
    for(size_t x = 0;x < strlen(atck[i]); x++){
      #ifdef DBUG
      Serial.println(atck[i][x]);
      #else
      Keyboard.press(atck[i][x]);
      #endif
    }
    delay(delayed);
    #ifndef DBUG
      Keyboard.releaseAll();
    #endif
    #endif
  }
}
