/* ================================================================== *
 *  Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercício - Maior e menor palavra
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

/* --- prototipos das funcoes ---- */

/* coleta a palavra do texto */
int preencherPalavra(char texto[1500], char palavra[30], int p);

/* se a palavra for maior, coloca em mx */
void eMaior(char palavra[30], char mx[20]);

/* se a palavra for menor, coloca em mn */
void eMenor(char palavra[30], char mn[20]);



int main() {
  char texto[1500], palavra[20], mx[20], mn[20], c;
  int achou = 0, p2 = 0;

  for (int k = 0; k < 1500; k++){
    texto[k] = '\0';
  }

  scanf(" %[^\n]", texto);

  for (int p = 0; p < strlen(texto); p++) {

    p = preencherPalavra(texto, palavra, p);

    eMaior(palavra, mx);
    eMenor(palavra, mn);
  }

  printf("Maior palavra: %s \nMenor palavra: %s\n", mx, mn);

  return (0);
}
/// <---- ATE AQUI!!! ----

/// ---- APENAS IMPLEMENTE OU COMPLETE AS FUNCOES ABAIXO ---->
int preencherPalavra(char texto[], char palavra[], int p){
  long int i = p, k = 0, tam_texto;

  tam_texto = strlen(texto);
  
  if ((p == 0 || texto[p - 1] == ' ')/* && p != (tam_texto - 1)*/)
  { 
    for (i = p; (texto[i] != ' ' && texto[i] != '\0') ; i++)
    {
      palavra[k] = texto[i];
      k++;
    }
  }
  palavra[k] = '\0';
  return(i);
}

/* se a palavra for maior, coloca em mx */
void eMaior(char palavra[], char mx[])
{
  int tam_mx, tam_palavra;

  tam_mx = strlen(mx);
  tam_palavra = strlen(palavra);

  if (tam_palavra > tam_mx)
  {
    strcpy(mx, palavra);
  }
}

/* se a palavra for menor, coloca em mn */
void eMenor(char palavra[], char mn[]){
  int tam_mx, tam_palavra;

  if (mn[0] == '\0')
  {
    strcpy(mn, palavra);
  }
  tam_mx = strlen(mn);
  tam_palavra = strlen(palavra);

  if (tam_palavra < tam_mx)
  {
    strcpy(mn, palavra);
  }
  
}
