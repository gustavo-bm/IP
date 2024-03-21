#include <stdio.h>
#define PRATELEIRACHEIA "Prateleira cheia!\n"
#define LIVROEMPRESTADO "Livro emprestado!\n"
#define ESPACODISPONIVEL "Ha espaco disponivel!\n"
#define ESTANTECHEIA "Estante cheia!\n"

int main(void) {
  int statuslocalestante[999][999], i, prateleiras, j, colunas, i2, j2, vazio = 0, colunasvazias[999], contador = 1, numcolunasvazias = 0, cheia = 1;

  // (I) Inserir um livro na prateleira i. Imprime as colunas em que o livro pode ser inserido ou "Prateleira cheia!", caso não haja espaço;
  //(E) Emprestar o livro da prateleira i e coluna j. Imprime "Livro emprestado!", caso o espaço esteja vazio;
  //(V) Verificar se ainda cabem livros na estante. Imprime "Ha espaco disponivel!" ou "Estante cheia!";
  //(T) Trocar o conteúdo da posição (i1,j1) pelo da posição (i2,j2).Imprime a estante após a troca.
  //(S) Sair do programa.
  char comando = ' ', I, E, V, T, S;

  scanf("%d %d", &prateleiras , &colunas);

  for(i = 0; i < prateleiras; i++){
    for(j = 0; j < colunas; j++){
      scanf("%d", &statuslocalestante[i][j]);
    }
  }
  
  do{
    
    scanf("%c", &comando);

    if(comando == 'I'){
      scanf("%d", &i);

      for(j = 0; j < colunas; j++){
      if(statuslocalestante[i][j] == 0){
        vazio = 1;
      }
    }
      if(vazio == 0){
        printf(PRATELEIRACHEIA);
      }else if(vazio == 1){
        printf("Coluna(s): ");
        for(j = 0; j < colunas; j++){
      if(statuslocalestante[i][j] == 0){
        j += 1;
        printf("%d ", j);
        j -= 1;
      }
    }
        printf("\n");
      }

      
    }else if(comando == 'E'){
      scanf("%d %d", &i, &j);
      
      if(statuslocalestante[i][j] == 0){
        printf(LIVROEMPRESTADO);
        
      }else if(statuslocalestante[i][j] == 1){
        statuslocalestante[i][j] = 0;
      }
      
    }else if(comando == 'V'){
      for(i = 0; i < prateleiras; i++){
    for(j = 0; j < colunas; j++){
      if(statuslocalestante[i][j] == 0){
        printf(ESPACODISPONIVEL);
        cheia = 0;
        j += 999;
        i += 999;
      }
    }
    
  }if(cheia == 1){
          printf(ESTANTECHEIA);
        }
    }else if(comando == 'T'){
      scanf("%d %d", &i, &j);
      scanf("%d %d", &i2, &j2);


      int aux;
      aux = statuslocalestante[i][j];
      statuslocalestante[i][j] = statuslocalestante[i2][j2];
      statuslocalestante[i2][j2] = aux;

      for(i = 0; i < prateleiras; i++){
    for(j = 0; j < colunas; j++){
     printf("%d ", statuslocalestante[i][j]);
    }
         printf("\n");
  }
    }

  }while(comando != 'S');
  
  return 0;
}