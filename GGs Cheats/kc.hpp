class keyController{
  private:
  int inputID = 0;
  const char** elem;
  size_t sizeOfElem[2] {0,0};
  const char** elem2;
  bool kS[2]{false, false};
  public:
  keyController(int id, const char* elem[], size_t s1, const char* elsm[], size_t s2){
    inputID = id;
    this->elem = elem;
    sizeOfElem[0] = s1;
    sizeOfElem[1] = s2;
    this->elem2 = elsm;
    pinMode(id, INPUT_PULLUP);
    }

    bool checkIfAndRun(const bool& left){
        kS[0] = digitalRead(inputID) == LOW;
        if(kS[0] != kS[1]){
          if(kS[0])
            playAttck(left ? this->elem : this->elem2, sizeOfElem[left ? 0 : 1]);
          kS[1] = kS[0];
          return true;
        }
        return false;
      }
  };
