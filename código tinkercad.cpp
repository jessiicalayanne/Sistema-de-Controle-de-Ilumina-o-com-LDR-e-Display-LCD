#include <Wire.h>

#include <LiquidCrystal_I2C.h>

// Define os pinos do display LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define os pinos do sensor LDR e do LED
const int sensorLDR = A0;
const int led = 12;

// Define os limiares de acionamento (ajustáveis)
int limiarSuperior = 500; // Ajustar de acordo com a luminosidade ambiente
int limiarInferior = 350; // Ajustar de acordo com a luminosidade ambiente

// Define o estado da lâmpada
bool estadoLampada = false;

void setup() {
  Serial.begin(9600);
  
  // Display LCD
  lcd.begin(16, 2);
  lcd.init();                // Inicializar a LCD
  lcd.backlight();            // acender
  lcd.clear();                // Borrar pantalla 
  
  // Define o modo do pino do LED como saída
  pinMode(led, OUTPUT);

  // Define o modo dos pinos dos botões como entrada (opcional)
  // pinMode(botaoSuperior, INPUT);
  // pinMode(botaoInferior, INPUT);
}

void loop() {
  // Leitura do sensor LDR
  int luminosidade = analogRead(sensorLDR);

  // Verifica os limiares de acionamento
  if (luminosidade > limiarSuperior && estadoLampada) {
    // Des liga a lâmpada
    digitalWrite(led, LOW);
    estadoLampada = false;
  } else if (luminosidade < limiarInferior && !estadoLampada) {
    // Liga a lâmpada
    digitalWrite(led, HIGH);
    estadoLampada = true;
  }

  // Atualiza o display LCD com as informações
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Lum: ");
  lcd.print(luminosidade);
  lcd.setCursor(0, 1);
  lcd.print("Lamp: ");
  lcd.print(estadoLampada ? "Ligada" : "Desligada");


  delay(500); // Aguarda meio segundo antes da próxima leitura
}
