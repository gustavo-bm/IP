#include <stdio.h>

int main(void) {
  char Letra; // A ou B
  float m1, m2, mr, ms, sx1, sx2, sy1, sy2, rx1, rx2, ry1, ry2; // "m" sendo o coeficiente angular da reta, s e r sendo as duas retas

  scanf("%c\n", &Letra);

  if ((Letra != 'A') && (Letra != 'B')){
    printf("OPCAO INVALIDA");
    return(0);
  }
  else{
    if(Letra == 'A'){
      scanf("%f %f", &mr, &ms);
      if (mr * ms == -1){
          printf("RETAS PERPENDICULARES");
          return(0);}
      else {
        if (mr == ms){
          printf("RETAS PARALELAS");
          }
        else {
          printf("RETAS CONCORRENTES");
        }
        }
      }
    }
    
  if (Letra == 'B'){
      scanf("%f\n%f\n%f\n%f\n%f\n%f\n%f\n%f", &sx1, &sx2, &sy1, &sy2, &rx1, &rx2, &ry1, &ry2);
      ms = (sy2 - sy1)  / (sx2 - sx1);
      mr = (ry2 - ry1)  / (rx2 - rx1);

      if (ms == mr){
         printf("RETAS PARALELAS");
         return(0);
  
        }else if ((mr * ms) == -1){
          printf("RETAS PERPENDICULARES");
          return(0);
        }
        else{
          printf("RETAS CONCORRENTES");
          return(0);
          }

      }
       
      
  return (0);
    }
  
  


  


  
 
