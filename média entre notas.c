#include <stdio.h>
#include <math.h>
int main(void) {
  
  int n, i;
  float vetor[i], soma = 0, media = 0,  dif, quadradodif, somadif = 0, variancia, dp;

  scanf("%d\n", &n);

  // obter todos os valores
  for(i = 0; i < n; i++){
  scanf("%f\n", &vetor[i]);
  }
  // fazer a soma destes valores
  for(i = 0; i < n; i++){
    soma += vetor[i];
  }
  // calcular a media
  media = soma / (1.0 * n);

  // calcular a soma das diferenças, ao quadrado, entre cada valor e a media
  for(i = 0; i < n; i++){
    dif = vetor[i] - media;
    quadradodif = pow(dif, 2);
    somadif+= quadradodif;
  }

  // achar a variância 
  variancia = (somadif) / (1.0 *(n - 1));

  // achar o desvio padrao

  dp = sqrt(variancia);

  // exibir o resultado
  printf("Dp=%.2f", dp);
  
  return (0);
}