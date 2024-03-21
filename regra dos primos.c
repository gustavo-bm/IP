#include <stdio.h>

int main(void) {
  int primo;
  scanf("%d", &primo);

  if ((primo + 1) % 4 == 0) {
    printf("Somando 1 a %d temos um multiplo de 4\n", primo);
  } else {
    printf("Subtraindo 1 de %d temos um multiplo de 4\n", primo);
  }
}