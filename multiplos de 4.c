#include <stdio.h>

int main() {

  int num;

  scanf("%d", &num);

  if (num % 4 == 0) {
    printf("O inteiro %d eh multiplo de 4", num);
  }

  else {
    printf("O inteiro %d nao eh multiplo de 4", num);
  }
  return (0);
}