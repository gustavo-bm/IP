/* ================================================================== *
 *  Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercicio - Jangadas
 *
 *  Instruções
 *  ----------
 *
 *    Este arquivo contém o código que auxiliará no desenvolvimento do
 *    exercício. Você precisará completar as partes requisitadas.
 *
 * ================================================================== */

/// ---- ATENCAO: NAO ALTERAR DAQUI ---->
#include <stdio.h>

/* PROTOTIPOS DAS FUNCOES */

// Função que vai realizar a leitura do desenho de Fabio
void lerDesenho(char des[][20], int lin, int col);

// Função que encontra a quantidade total que seria usada de cada tamanho de
// madeira
void quantidadeMadeira(char des[][20], int mad[], int lin, int col);

// Função para mostrar a quantidade de cada tamanho de madeira que
// seria utilizado para construir as jangadas do desenho
void mostrarRelatorio(int mad[]);

int main() {
  // Matriz que armazenara o desenho
  char desenho[20][20];
  // Vetor que guardara a quantidade de madeira de cada tamanho
  int madeiras[6];
  // Quantidade de linhas do desenho
  int linhas;
  // Quantidade de colunas do desenho
  int colunas;

  scanf("%d %d", &linhas, &colunas);

  lerDesenho(desenho, linhas, colunas);
  quantidadeMadeira(desenho, madeiras, linhas, colunas);
  mostrarRelatorio(madeiras);

  return (0);
}
/// <---- ATE AQUI!!! ----

/// ---- APENAS IMPLEMENTE AS FUNCOES DAQUI PRA BAIXO

/* <<< COMPLETE AQUI >>> */
void lerDesenho(char des[][20], int lin, int col) {
  
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      des[i][j] = 0;
    }
  }
  
  for (int i = 0; i < lin; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%c", &des[i][j]);
      if (des[i][j] == '\n')
      {
        scanf("%c", &des[i][j]);
      }
    }
  }
}

void quantidadeMadeira(char des[][20], int mad[], int lin, int col) {
  int qtdemadeiras = 0;
  
  for (int w = 0; w < 6; w++) {
    mad[w] = 0;
  }

  for (int i = 0; i < lin; i++)
  {
    qtdemadeiras = 0;
    
    for (int j = 0; j < col; j++) 
    {
        if (j < col && des[i][j] == '_' && des[i][j + 1] != '_')
        {
          mad[0]++;
        } else if (j < (col ) && des[i][j] == '_' && des[i][j + 1] == '_' && des[i][j + 2] != '_')
        {
          mad[1]++;
        } else if (j < (col ) && des[i][j] == '_' && des[i][j + 1] == '_' && des[i][j + 2] == '_' && des[i][j + 3] != '_')
        {
          mad[2]++;
        } else if (j < (col ) && des[i][j] == '_' && des[i][j + 1] == '_' && des[i][j + 2] == '_' && des[i][j + 3] == '_' && des[i][j + 4] != '_')
        {
          mad[3]++;
        } else if (j < (col ) && des[i][j] == '_' && des[i][j + 1] == '_' && des[i][j + 2] == '_' && des[i][j + 3] == '_' && des[i][j + 4] == '_' && des[i][j + 5] != '_')
        {
          mad[4]++;
        } else if (j < (col ) && des[i][j] == '_' && des[i][j + 1] == '_' && des[i][j + 2] == '_' && des[i][j + 3] == '_' && des[i][j + 4] == '_' && des[i][j + 5] == '_' && des[i][j + 6] != '_')
        {
          mad[5]++;
        }
    }
  }
}

/*void mostrarRelatorio(int mad[]) {
  printf("MADEIRAS:\n");
  printf("MADEIRA DE 1m: ");
  printf("= %d unidade(s)\n", mad[0] );

  printf("MADEIRA DE 2m: ");
  printf("= %d unidade(s)\n", mad[1] );

  printf("MADEIRA DE 3m: ");
  printf("= %d unidade(s)\n", mad[2]);

  printf("MADEIRA DE 4m: ");
  printf("= %d unidade(s)\n", mad[3]);

  printf("MADEIRA DE 5m: ");
  printf("= %d unidade(s)\n", mad[4] );

  printf("MADEIRA DE 6m: ");
  printf("= %d unidade(s)\n", mad[5]);
} */
 void mostrarRelatorio(int mad[]) {


   mad[5] = mad[5];
   mad[4] -= mad[5];
   mad[3] -= mad[4] + mad[5];
   mad[2] -= mad[3] + mad[4] + mad[5];
   mad[1] -= mad[2] + mad[3] + mad[4] + mad[5];
   mad[0] -= mad[1] + mad[2] + mad[3] + mad[4] + mad[5];
   

   
  printf("MADEIRAS\n");
  printf("MADEIRA DE 1m ");
  printf("= %d unidade(s)\n", mad[0]);

  printf("MADEIRA DE 2m ");
  printf("= %d unidade(s)\n", mad[1]);

  printf("MADEIRA DE 3m ");
  printf("= %d unidade(s)\n", mad[2]);

  printf("MADEIRA DE 4m ");
  printf("= %d unidade(s)\n", mad[3]);

  printf("MADEIRA DE 5m ");
  printf("= %d unidade(s)\n", mad[4]);

  printf("MADEIRA DE 6m ");
  printf("= %d unidade(s)\n", mad[5]);
} 