#include <Keypad.h>
#include <string.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
const byte linhas = 4;
const byte colunas = 4;

int c = 0;
const int tam_senha = 7;
char senha[tam_senha] = "123456";
char tentativa[tam_senha] = "";

char teclas[linhas][colunas] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte pinosLinhas[linhas] = {9, 8, 7, 6};
byte pinosColunas[colunas] = {5, 4, 3, 2};

Keypad teclado = Keypad(makeKeymap(teclas), pinosLinhas, pinosColunas, linhas, colunas);

int verde = 10;
int vermelho = 11;

void setup()
{
    pinMode(verde, OUTPUT);
    pinMode(vermelho, OUTPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setBacklight(1);
    lcd.setCursor(0, 0);
    lcd.print("Senha:");
    lcd.setCursor(0, 1);
    
}

void loop()
{
    char tecla = teclado.getKey();

    if (tecla)
    {
        adiciona(tecla);
    }
}

void verifica()
{
    if (strcmp(senha, tentativa) == 0)
    { 
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Correto");
        digitalWrite(verde, HIGH);
        delay(1500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Senha:");
        lcd.setCursor(0, 1);
    }
    else
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Errado");
        digitalWrite(vermelho, HIGH);
        delay(1500);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Senha:");
        lcd.setCursor(0, 1);
    }
    tentativa[0] = '\0';
    c = 0;

    digitalWrite(verde, LOW);
    digitalWrite(vermelho, LOW);
}

void adiciona(char tecla)
{
    tentativa[c] = tecla;
    c++;
    tentativa[c] = '\0';
    lcd.print(tecla);

    if (c == tam_senha - 1)
    {
        verifica();
    }
}
