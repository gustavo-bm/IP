/* ================================================================== *
 *  Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercicio - Localizar e substituir
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
#include <string.h>
#include <ctype.h>

/* --- constantes, variaveis globais e registros ---- */

/* recebe o texto, a palavra a ser procurada e a palavra a ser colocada 
   no lugar a variável texto do parametro da função deve ser atualizada */
void localizareSubstituir(char texto[], char palavra[], char palavraS[]);

int main() {
    char texto[1000];
    char palavra[50];
    char palavraS[50];

    for(int i = 0; i < 50; i++){
        palavra[i] = palavraS[i] = '\0';
    }

    for(int i = 0; i < 1000; i++){
        texto[i] = '\0';
    }


    scanf(" %[^\n]", texto);
    scanf(" %[^\n]", palavra);
    scanf(" %[^\n]", palavraS);

    localizareSubstituir(texto, palavra, palavraS);

    printf("%s\n", texto);

    return (0);
}
/// <---- ATE AQUI!!! ----

/// ---- APENAS IMPLEMENTE OU COMPLETE AS FUNCOES ABAIXO ---->
void localizareSubstituir(char texto[], char palavra[], char palavraS[])
{
  int tam_texto, tam_palavra, caracteres_iguais, j;
  char texto_quebrado[3][1000];

  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 1000; j++){
      texto_quebrado[i][j] = '\0';
    }
  }
  
  tam_texto = strlen(texto); 
  tam_palavra = strlen(palavra);
  //tam_palavra -= 1;
  
  for (int i = 0; i < tam_texto; i++)
  {
    caracteres_iguais = 0;
    j = 0;
    while (texto[i] == palavra[j] && j <= tam_palavra)
    {
      caracteres_iguais++;
      i++;
      j++;
    }
    /*printf("%d\n", tam_palavra);*/
    /*printf("%d\n", j);*/

    if (j == tam_palavra)
    {
      strncpy(texto_quebrado[0], &texto[0], i - tam_palavra);
      strncpy(texto_quebrado[1], &texto[i], tam_texto - i);
      

      strcat(texto_quebrado[0], palavraS);
      strcat(texto_quebrado[0], texto_quebrado[1]);
    
      strcpy(texto, texto_quebrado[0]);

       for (int i = 0; i < 2; i++)
       {
          for (int j = 0; j < 1000; j++)
          {
            texto_quebrado[i][j] = '\0';
          }
        }
      tam_texto = strlen(texto); 
      i -= tam_palavra;
    }
  }
}
