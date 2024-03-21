#include <stdio.h>

int main(void) {
  int contador = 0, x, n, soma = 0, produto = 0, n1, n2, a, b;

  scanf("\n%d %d", &n1, &n2);
  a = n1;
  b = n2;

  //encontrar os numeros perfeitos no intervalo [n1,n2]
  printf("Perfeitos: ");
  if (n1 == 0 || n1 == 1){
    n1 = 2;
  }else{
    n1 = n1;
  }
  for( ;n1 < n2; n1++){

for(soma = 0, n = 1; n < n1; n++){
       x = n1 % n;
      if (x == 0){
      soma += n;
      }
}
    if(soma == n1){
        printf(" %d", n1);
      contador++;
    }
    }
  if(contador == 0){
    printf(" vazio");
  }

//encontrar os numeros triangulares entre [n1,n2]
n1 = a;
n2 = b;
contador = 0;
  
printf("\nTriangulares:");
for(; n1 < n2; n1++){
  
   for(n = 1, produto = 0; produto <= n1; n++){
     
  produto = n * (n + 1) * (n + 2);
     if (produto == n1){
    
    printf(" %d", n1);
    contador++;
     }
   }
  
  
}

  if (contador == 0){
    printf(" vazio");
  }


  return 0;
}