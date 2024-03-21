#include <stdio.h>
#define FORATABULEIRO   "Voce saiu para fora do tabuleiro e perdeu!\n"
#define JOGADORGANHOU   "Voce venceu! Restaram %d vidas\n"
#define BATEUBARREIRA   "Voce bateu na barreira e perdeu uma vida, restam %d vidas\n"
#define PONTOSACABARAM  "Voce perdeu!\n"
#define ACERTOUCAMINHO  "Voce acertou o caminho!\n"
#define TENTOUVOLTAR    "Voce tentou voltar e perdeu!\n"

int main(void) {
  
  // Dois inteiros N e M, sendo N≤10 e M≤10, representando as dimensões do tabuleiro (linhas e colunas);
  // Uma matriz de N linhas e M colunas, de valores 0, 1, e 2, indicando o tabuleiro;
  // Dois inteiros O e P, sendo O≤10 e P≤10, representando a posição do jogador no tabuleiro no inicio do jogo (linha e coluna);
  int N = 0, M = 0, O = 0, P = 0, i = 0, j = 0, tabuleiro[10][10] = {0}, saiuprafora = 0;
  
  // Movimentos do jogador, sendo D para movimentar para direita, C para movimentar para cima, B para movimentar para baixo, e E para movimentar para esquerda.
  char D, C, B, E;
  
  // dimensoes do tabuleiro
  do{
    scanf("%d %d", &N, &M);
  } while(N > 10 || M > 10);

  // matriz do tabuleiro
  for(i = 0; i < N; i++)
  {
    for(j = 0; j < M; j++)
    {
      scanf(" %d", &tabuleiro[i][j]);
    }
  }

  // posição inicial do jogador
  do{
    scanf("%d %d", &i, &j);
    tabuleiro[i][j] = 1;
    
  }while(i > 10 || j > 10);

  // movimentos do jogador
  int vidas = 10;
  char movimento, movimentoanterior = 0;

  do{
    scanf(" %c", &movimento);

    switch(movimento){
      case 'C':
        if('B' == movimentoanterior)
        {
          printf(TENTOUVOLTAR);
          return(0);
        } else if(i - 1 < 0)
        {
          printf(FORATABULEIRO);
          saiuprafora = 1;
          vidas = 0;
          
        }else if(tabuleiro[i - 1][j] == 0)
        {
          vidas -= 1;
          if(vidas >= 1)
          {
            printf(BATEUBARREIRA, vidas);
          }
          
        }else if(tabuleiro[i - 1][j] == 1)
        {
          printf(ACERTOUCAMINHO);
          i -= 1;
          movimentoanterior = movimento;
          
        }else if(tabuleiro[i - 1][j] == 2)
        {
          printf(JOGADORGANHOU, vidas);
          return(0);
          
        }
      break;
      
      case 'B':
        if('C' == movimentoanterior)
        {
          printf(TENTOUVOLTAR);
          return(0);
        } else if(i + 1 >= N)
        {
          printf(FORATABULEIRO);
          saiuprafora = 1;
          vidas = 0;
          
        }else if(tabuleiro[i + 1][j] == 0)
        {
          vidas -= 1;
          if(vidas >= 1)
          {
            printf(BATEUBARREIRA, vidas);
          }
          
        }else if(tabuleiro[i + 1][j] == 1)
        {
          printf(ACERTOUCAMINHO);
          i += 1;
          movimentoanterior = movimento;
        }else if(tabuleiro[i + 1][j] == 2)
        {
          printf(JOGADORGANHOU, vidas);
          return(0);
          
        }
      break;
      
      case 'D':
        if('E' == movimentoanterior)
        {
          printf(TENTOUVOLTAR);
          return(0);
        }else if(j + 1 >= M)
        {
          printf(FORATABULEIRO);
          saiuprafora = 1;
          vidas = 0;
          
        } else if(tabuleiro[i][j + 1] == 0)
        {
          vidas -= 1;
          if(vidas >= 1)
          {
            printf(BATEUBARREIRA, vidas);
          }
          
        } else if(tabuleiro[i][j + 1] == 1)
        {
          printf(ACERTOUCAMINHO);
          j += 1;
          movimentoanterior = movimento;
        } else if(tabuleiro[i][j + 1] == 2)
        {
          printf(JOGADORGANHOU, vidas);
          return(0);
          
        }
      break;
      
      case 'E':
        if('D' == movimentoanterior)
        {
          printf(TENTOUVOLTAR);
          return(0);
        }
        if(j - 1 < 0)
        {
          printf(FORATABULEIRO);
          saiuprafora = 1;
          vidas = 0;
          
        }else if(tabuleiro[i][j - 1] == 0)
        {
          vidas -= 1;
          if(vidas >= 1)
          {
            printf(BATEUBARREIRA, vidas);
          }
          
        }if(tabuleiro[i][j - 1] == 1)
        {
          printf(ACERTOUCAMINHO);
          j -= 1;
          movimentoanterior = movimento;
        }else if(tabuleiro[i][j - 1] == 2)
        {
          printf(JOGADORGANHOU, vidas);
          return(0);
          
        }
      break;
    }
  }while(vidas > 0);

  if(vidas == 0 && saiuprafora == 0){
    printf(PONTOSACABARAM);
  }
  
  return 0;
}