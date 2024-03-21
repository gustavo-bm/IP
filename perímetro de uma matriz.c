#include <stdio.h>

int main() {

  int i, j, perimetro = 0, l, c, elemento[51][51] = {0};

  // obter tamanho da matriz l×c (linha por coluna)
  scanf("%d %d", &l, &c);

  // obter a matriz
  for(i = 0; i < l; i++){
    for(j = 0; j < c; j++){
      scanf("%d", &elemento[i][j]);
    }
  }

  // calcular o perímetro 
  for(i = 0; i < l; i++){
    for(j = 0; j < c; j++){
      
      if(elemento[i][j] == 1){
        perimetro += 4;
        
        if(i == 0 && j == 0){
          
          if(elemento[i + 1][j] == 1){
            perimetro -= 1;
            
          }
          if(elemento[i][j + 1] == 1){
            perimetro -= 1;
            
          }
        }else if(i == 0 && j == c - 1){
          if(elemento[i + 1][j] == 1){
            perimetro -= 1;
            
          } if(elemento[i][j - 1] == 1){
            perimetro -= 1;
            
          }
      }else if(i == l - 1 && j == 0){
          if(elemento[i - 1][j] == 1){
            perimetro -= 1;
            
          } if(elemento[i][j + 1] == 1){
            perimetro -= 1;
            
          }
      }else if(i == l - 1 && j == c - 1){
          if(elemento[i - 1][j] == 1){
            perimetro -= 1;
            
          } if(elemento[i][j - 1] == 1){
            perimetro -= 1;
            
          }
      }else if(i == 0 && j > 0 && j < c - 1)
        {
          if(elemento[i + 1][j] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j - 1] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j + 1] == 1)
          {
            perimetro -= 1;
            
          }
      }else if(j == 0 && i > 0 && i < l - 1)
        {
          if(elemento[i + 1][j] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j + 1] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i - 1][j] == 1)
          {
            perimetro -= 1;
            
          }
      }else if(i == l - 1 && j > 0 && j < c - 1)
        {
          if(elemento[i - 1][j] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j + 1] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j - 1] == 1)
          {
            perimetro -= 1;
            
          }
      }else if(j == c - 1 && i > 0 && i < l - 1)
        {
          if(elemento[i - 1][j] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i + 1][j] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j - 1] == 1){
            perimetro -= 1;
            
          }
      }else if(i > 0 && i < l - 1 && j > 0 && j < c - 1)
        {
          if(elemento[i - 1][j] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i + 1][j] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j - 1] == 1)
          {
            perimetro -= 1;
            
          } if(elemento[i][j + 1] == 1)
          {
            perimetro -= 1;
            
          }
      }
    }
  }
  }

  printf("%d", perimetro);

  return (0);
}