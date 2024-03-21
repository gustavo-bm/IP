#include <stdio.h>
#define JOGADORJAPERDEU "JOGADOR %d JA PERDEU\n"

int main(void) {
  int N, i, pontos[10], jogadorataque, jogadorsubmetido, jogadores, vencedor, posicao[8], j = 1;
  char habilidade;
  
pontos[0] = pontos[1] = pontos[2] = pontos[3] = pontos[4] = pontos[5] = pontos[6] = pontos[7] = pontos[8] = 10;

    do{
    scanf("%d", &N);
  }while(N < 2 || N > 8);

    do{
    
    scanf(" %c %d %d", &habilidade, &jogadorataque, &jogadorsubmetido);

    
      if(habilidade == 'A'){
        if(pontos[jogadorataque] <=0){
printf(JOGADORJAPERDEU, jogadorataque);

        }else if(pontos[jogadorsubmetido] <= 0){
          printf(JOGADORJAPERDEU, jogadorsubmetido);
          
        }else if(pontos[jogadorsubmetido] > 0){
          pontos[jogadorsubmetido] -= 2;
          if(pontos[jogadorsubmetido] <= 0){
            pontos[jogadorataque] += 2;
            if(pontos[jogadorataque] >= 10){
              pontos[jogadorataque] = 10;
            }
            posicao[j] = jogadorsubmetido;
          j++;
          }else if(pontos[jogadorsubmetido] == 0){
            posicao[j] = jogadorsubmetido;
          j++;
          }

        }

            
      }else if(habilidade == 'B'){
        
        if(pontos[jogadorataque] <=0){
printf(JOGADORJAPERDEU, jogadorataque);

        }else if(pontos[jogadorsubmetido] <= 0){
          printf(JOGADORJAPERDEU, jogadorsubmetido);
          
        }else if(pontos[jogadorsubmetido] > 0){
          pontos[jogadorsubmetido] -= 3;
          if(pontos[jogadorsubmetido] <= 0){
            pontos[jogadorataque] += 3;
            if(pontos[jogadorataque] >= 10){
              pontos[jogadorataque] = 10;
            }
            posicao[j] = jogadorsubmetido;
          j++;
          }else if(pontos[jogadorsubmetido] == 0){
            posicao[j] = jogadorsubmetido;
          j++;
          }

        }

      }else if(habilidade == 'C'){
        
        if(pontos[jogadorataque] <=0){
printf(JOGADORJAPERDEU, jogadorataque);

        }else if(pontos[jogadorsubmetido] <= 0){
          printf(JOGADORJAPERDEU, jogadorsubmetido);
          
        }else if(pontos[jogadorsubmetido] > 0){
          pontos[jogadorsubmetido] -= 4;
          if(pontos[jogadorsubmetido] <= 0){
            pontos[jogadorataque] += 4;
            if(pontos[jogadorataque] >= 10){
              pontos[jogadorataque] = 10;
            }
            posicao[j] = jogadorsubmetido;
          j++;
          }else if(pontos[jogadorsubmetido] == 0){
            posicao[j] = jogadorsubmetido;
          j++;
          }

      } }
    
    
      for(jogadores = N, i= 1; i <= N; i++){
  if(pontos[i] <= 0){
    jogadores--;
  }
      }
    
    }while(jogadores > 1);

  if(N == 2){
    for(i = 1; i <= N; i++){
      if(pontos[i] > 0){
        vencedor = i;
      }
    }
    printf("1 LUGAR: JOGADOR %d\n", vencedor);
    printf("2 LUGAR: JOGADOR %d\n", posicao[1]);

  }else if(N > 2){
    for(i = 1; i <= N; i++){
      if(pontos[i] > 0){
        vencedor = i;
      }
    }
    printf("1 LUGAR: JOGADOR %d\n", vencedor);
    printf("2 LUGAR: JOGADOR %d\n", posicao[N - 1]);
    printf("3 LUGAR: JOGADOR %d\n", posicao[N - 2]);
  }

  return 0;
}


