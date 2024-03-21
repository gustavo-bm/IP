#include <stdio.h>

int main(void) {
  int i, n;
  float soma = 0, menor = 1000, maior = 0, nota[i], media;

  // quantidade de juízes //
  scanf("%d\n", &n);

  //ler as notas //
  for(i = 0; i < n; i++){
    scanf("%f ", &nota[i]);
    soma += nota[i];
  }

  // achar a menor nota //
  for(i = 0; i < n; i++){
    if (nota[i] < menor){
      menor = nota[i];
}
  }
  // achar a maior nota //
  for(i = 0; i < n; i++){
    if (nota[i] > maior){
      maior = nota[i];
    }
  }

  // achar a media entre as notas, desconsiderando a maior e a menor //
  media = (soma - maior - menor) / (1.0 * (n - 2));

  //exibir o resultado
  printf("%.2f", media);

return 0;
  }
