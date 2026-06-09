//Jair Ierich RM: RM569524 
//Maria Gabriela RM: RM569047 
//Vicente de Souza RM: RM569205 
//Felipe Marialva RM: RM569031 
//Bianca Veloso RM: 572036

//Para testar se o Buzzer esta em funcionamento, é so clicar no DHT22 e mudar a temperatura,
//para menos de 18 C ou para mais de 30 C, para deixar normal é so colocar a temperatura entre 18 a 30 C.
//para testar o buzzer para a umidade segue o msm principio. é so clicar no DHT22 e mudar a umidade,
//para menos de 50% ou para mais de 80%, para deixar tudo normal é so colocar a umidade entre 50% a 80%.

//o servo motor nesse caso representa um ventilador, ja que nao existe uma representacao de um aqui no wokwi,
//mas o rele e ele funcionam ao mesmo tempo, quanto a temperatura ou a umidade estao alta,
//o rele passa a energia e o "fan"(servo motor), comeca a girar ao mesmo tempo, mas claro q se Houvesse,
//uma fan ou ventilador o mesmo seria colocado, junto de uma fonte de energia externa, 
//pois o arduino nao consegueria passar a energia necessaria para ligar o fan ja que o limite dele é 5V,
//e um ventilador comum pode ser entre 127v ou 220v e uma fan pode chegar ate a 12V.

//Resumindo quando a temperatura e a umidade estiverem em niveis criticos inferiores ao citados a cima, 
//o led vermelho ira brilhar, o buzzer ira comecar a tocar, mas não sera ligado o ventilador, 
//pois é preciso aquecer o ambiente e não refrigerar.
//Enquanto se a temperatura e a umidade antigirem niveis criticos elevados ao citados a cima, 
//o led vermelho ira brilhar, o buzzer ira comecar a tocar o rele passara energia,  
//e o ventilador(servo motor) ira girar

//O sistema realiza a leitura contínua da temperatura e da umidade do ar no interior da estufa, 
//analisando se os valores estão dentro da faixa ideal definida para cada cultura plantada. 
//Quando identifica condições inadequadas, o sistema atua automaticamente acionando 
//a ventilação e emitindo alertas sonoros ou visuais, 
//garantindo um ambiente adequado para o crescimento saudável das plantas.

#include <DHT.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

Servo fan;

// LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

int led = 7;
int buzzer = 9;
int ventilacao = 8;

float tempMax = 30;
float tempMin = 18;

float umiMin = 50;
float umiMax = 80;

void setup() {

  Serial.begin(9600);

  dht.begin();

  fan.attach(6);

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ventilacao, OUTPUT);

  fan.write(90);

  // LCD
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Sistema Estufa");

  lcd.setCursor(0, 1);
  lcd.print("Iniciando...");

  delay(2000);

  lcd.clear();
}

void loop() {

  float temperatura = dht.readTemperature();
  float umidade = dht.readHumidity();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");

  // LCD mostrando dados
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperatura);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("U:");
  lcd.print(umidade);
  lcd.print("%");

  // ===== TEMPERATURA ALTA =====
  if (temperatura > tempMax) {

    Serial.println("TEMPERATURA ALTA");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TEMP ALTA!");

    lcd.setCursor(0, 1);
    lcd.print("Ventilando");

    digitalWrite(ventilacao, HIGH);
    digitalWrite(led, HIGH);

    tone(buzzer, 1000);

    fan.write(180);
    delay(200);

    fan.write(0);
    delay(200);
  }

  // ===== TEMPERATURA BAIXA =====
  else if (temperatura < tempMin) {

    Serial.println("TEMPERATURA BAIXA");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("TEMP BAIXA!");

    digitalWrite(ventilacao, LOW);
    digitalWrite(led, HIGH);

    tone(buzzer, 500);

    fan.write(90);

    delay(1000);
  }

  // ===== UMIDADE ALTA =====
  else if (umidade > umiMax) {

    Serial.println("UMIDADE ALTA");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("UMIDADE ALTA");

    lcd.setCursor(0, 1);
    lcd.print("Ventilando");

    digitalWrite(ventilacao, HIGH);
    digitalWrite(led, HIGH);

    tone(buzzer, 1200);

    fan.write(180);
    delay(200);

    fan.write(0);
    delay(200);
  }

  // ===== UMIDADE BAIXA =====
  else if (umidade < umiMin) {

    Serial.println("UMIDADE BAIXA");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("UMIDADE BAIXA");

    digitalWrite(ventilacao, LOW);
    digitalWrite(led, HIGH);

    tone(buzzer, 700);

    fan.write(90);

    delay(1000);
  }

  // ===== AMBIENTE OK =====
  else {

    Serial.println("AMBIENTE OK");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AMBIENTE OK");

    lcd.setCursor(0, 1);
    lcd.print("Tudo normal");

    digitalWrite(ventilacao, LOW);
    digitalWrite(led, LOW);

    noTone(buzzer);

    fan.write(90);

    delay(1000);
  }

  Serial.println("----------------");
}
