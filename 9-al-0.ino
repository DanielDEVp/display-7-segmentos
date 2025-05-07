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
  for (int i = 0; i < 7; i++) {
    pinMode(segmentos[i], OUTPUT);
  }
}

void loop() {
  for (int numero = 9; numero >= 0; numero--) {
    mostrarNumero(numero);
    delay(3000); // Espera 3 segundos antes de cambiar el número
  }
  apagarDisplay(); // Apaga el display al terminar la cuenta regresiva
}
