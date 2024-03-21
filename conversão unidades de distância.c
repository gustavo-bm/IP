#include <stdio.h>

int main(void) {
  long int M;
  float Pes, Polegadas, Jardas, Milhas;

  scanf("%ld", &M);
  Pes = M / 0.3048;
  Polegadas = M / 0.0254;
  Jardas = M / 0.9144;
  Milhas = M * 0.000621371;

  printf("%.1f\n" "%.1f\n" "%.1f\n" "%.1f", Pes, Polegadas, Jardas, Milhas);

  return 0;
}