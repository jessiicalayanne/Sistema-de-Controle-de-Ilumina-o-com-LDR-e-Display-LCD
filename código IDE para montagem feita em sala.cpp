// Define o pino do sensor LDR
const int sensorLDR = A0; // Conecte o LDR ao pino A0
const int rele = 8;       // Pino do relé
int luminosidade;         // Variável para armazenar a leitura do LDR
const int valor_ligar = 230;   // Valor de luminosidade para ligar o relé
const int valor_desligar = 210; // Valor de luminosidade para desligar o relé

void setup() {
  pinMode(rele, OUTPUT); // Corrigido: deve ser pinMode, não pin.Mode
  pinMode(13, OUTPUT);   // Configura o pino 13 como saída (LED embutido)
  
  // Inicializa a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Leitura do sensor LDR
  luminosidade = analogRead(sensorLDR); // Removido o tipo 'int' para evitar redefinição

  // Verifica a luminosidade e controla o relé
  if (luminosidade > valor_desligar && luminosidade < valor_ligar) {
    digitalWrite(rele, HIGH); // Liga o relé
    digitalWrite(13, HIGH);   // Liga o LED embutido
  } else {
    digitalWrite(rele, LOW);  // Desliga o relé
    digitalWrite(13, LOW);    // Desliga o LED embutido
  }

  // Envia a leitura do LDR para o Serial Monitor
  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);

  // Aguarda meio segundo antes da próxima leitura
  delay(500);
}
