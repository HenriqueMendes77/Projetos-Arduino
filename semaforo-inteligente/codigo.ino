

int botao = 2;

void setup()
{
  pinMode(botao, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  Serial.begin(9600);
  digitalWrite(3, HIGH);
}

void loop()
{
  if(digitalRead(botao)){
    fechar_semaforo();
  }
}

void fechar_semaforo(){
  delay(5000);
  digitalWrite(3, LOW);
  delay(200);
  digitalWrite(4, HIGH);
  delay(2000);
  digitalWrite(4, LOW);
  delay(200);
  digitalWrite(5, HIGH);
  delay(5000);
  digitalWrite(5, LOW);
  delay(200);
  digitalWrite(3, HIGH);
}