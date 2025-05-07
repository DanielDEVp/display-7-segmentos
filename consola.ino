const int segmentos[7] = {13, 12, 11, 7, 6, 5, 4}; // Pines conectados al display

const byte numeros[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,0,0,1,1}  // 9
};

void mostrarNumero(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], numeros[num][i]);
  }
}

void apagarDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentos[i], LOW);
  }
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
}

void loop() {
  if (Serial.available() > 0) {
    int numero = Serial.parseInt();
    if (numero >= 0 && numero <= 9) {
      mostrarNumero(numero);
      delay(2000); // Mantiene el número en pantalla por 2 segundos
      apagarDisplay();
    } else {
      Serial.println("Introduce un número entre 0 y 9.");
    }
  }
}
