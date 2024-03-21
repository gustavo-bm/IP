/* ================================================================== *
 *  Universidade Federal de São Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercicio - O Primo de Engenheiro
 *
 *  Instruções
 *  ----------
 *
 *  Este arquivo contém o código que auxiliará no desenvolvimento do
 *  exercício. Você precisará completar as partes requisitadas.
 *
 * ================================================================== */

/// ---- ATENCAO: NAO ALTERAR DAQUI ---->
#include <stdio.h>
#include <math.h>

#define PRIMO "primo\n"
#define ENGENHEIRO "primo de engenheiro de grau %d\n"
#define NAO_PRIMO "nao primo\n"

/* Recebe um valor candidato, um vetor de primos obtidos até o momento e um vetor com o tamanho do primeiro vetor. 
   Retorna 1 se candidato for primo, retorna 0 se não for */
int teste_primo(long long int candidato, long long int primos[], int tamanho[]);

/* Recebe um valor candidato, um vetor de primos obtidos até o momento e um vetor com o tamanho do primeiro vetor.
   Retorna o grau de engenheiro do valor candidato */
int teste_engenheiro(long long int candidato, long long int primos[], int tamanho[]);

int main() {
    long long int candidate;
    long long int primos[10000] = {2};
    int tamanho[1] = {1};

    for (int i = 0; i < 12; i++) {
        scanf("%lld", &candidate);

        if (teste_primo(candidate, primos, tamanho)) {
            printf(PRIMO);
        } else {
            int teste = teste_engenheiro(candidate, primos, tamanho);
            if (teste > 0) {
                printf(ENGENHEIRO, teste);
            } else {
                printf(NAO_PRIMO);
            }
        }
    }
}
/// <---- ATE AQUI!!! ----


/// ---- APENAS IMPLEMENTE AS FUNCOES DAQUI PRA BAIXO

/* <<< COMPLETE AQUI >>> */

/* Recebe um valor candidato, um vetor de primos obtidos até o momento e um vetor com o tamanho do primeiro vetor. 
   Retorna 1 se candidato for primo, retorna 0 se não for */
int teste_primo(long long int candidato, long long int primos[], int tamanho[])
{
  int k = 0, saida, primo, div;
  saida = 0;
  primo = 0;

  for (int i = 0; i < tamanho[0]; i++)
  {
    if (candidato == primos[i])
    {
      saida = 1;
    }
  }

  if (saida == 0)
  {
    for (long long int j = 2; j <= sqrt(candidato); j++)
    {
      div = candidato % j;
      if (div == 0)
      {
        saida = 0;
        primo++;
      }
    }

  if (primo == 0)
  {
    saida = 1;
    primos[k] = candidato;
    k++;
    tamanho[0]++;
  }
  }
  

  return (saida);
}

/* Recebe um valor candidato, um vetor de primos obtidos até o momento e um vetor com o tamanho do primeiro vetor.
   Retorna o grau de engenheiro do valor candidato */
int teste_engenheiro(long long int candidato, long long int primos[], int tamanho[])
{
  int grau = 0, div, result;

  for (long long int i = 2; i < sqrt(candidato); i++)
  {
    result = teste_primo(i, primos, tamanho);
    if (result == 1)
    {
      div = candidato % i;

      if (div == 0)
      {
        break;
      } else if (div != 0)
      {
        grau++;
      }
    }
  }

  return (grau);
}
