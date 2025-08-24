
int leds[4] = {2, 3, 4, 5};
int buzzer = 8;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  float temperatura = (-40 + 0.488155 * (analogRead(A0) - 20));
  alarme(temperatura > 30);
}

void alarme(bool ativar){
  for(int i = 0; i < 4; i++){
    digitalWrite(leds[i], ativar);
  }
  if(ativar){
    tone(buzzer, 350, 1250);
  }
  else{
    noTone(buzzer);
  }
}
