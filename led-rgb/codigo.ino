struct Led{
    int id;
    int botao;
    int status;
};

struct Led leds[3] = {
  {8, 2, 0},
  {9, 3, 0},
  {10, 4, 0}
};

void setup(){

  for(int i = 0; i < 3; i++){
    pinMode(leds[i].id, OUTPUT);
    pinMode(leds[i].botao, INPUT);
  }

  Serial.begin(9600);

}

void loop(){
  for(int i = 0; i < 3; i++){
    if(digitalRead(leds[i].botao) == HIGH){
      leds[i].status = (leds[i].status == 0) ? 1 : 0;
      digitalWrite(leds[i].id, leds[i].status);
      delay(1000);
    }
  }
}