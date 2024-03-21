/* ================================================================== *
 *  Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercício - Depósitos de minerais
 *
 *  Instruções
 *  ----------
 *
 *    Este arquivo contém o código que auxiliará no desenvolvimento do
 *    exercício. Você precisará completar as partes requisitadas.
 *
 * ================================================================== */

#include <stdio.h>

struct mapa {
    int tamanho;
    int m[20][20];
};

int main (){

    int i, aux, qtdedepositos, minerio, qtdeminerio[400], maisabundante = 0,ContDepSem = 0,min;
    struct mapa deposito[10];
    
    scanf(" %d", &qtdedepositos);
    
    for (int i = 0; i < qtdedepositos; i++) 
    {
        scanf(" %d", &deposito[i].tamanho);
        
        for (int l = 0; l < deposito[i].tamanho; l++)
        {
            for (int c = 0; c < deposito[i].tamanho; c++){
                scanf(" %d", &deposito[i].m[l][c]);
            }
        }
        
    }
    
    scanf(" %d", &minerio);
    
    for (int i = 0; i < qtdedepositos; i++) 
    {
        for (int l = 0; l < deposito[i].tamanho; l++)
        {
            for (int c = 0; c < deposito[i].tamanho; c++){
                if (deposito[i].m[l][c] == minerio)
                {
                    qtdeminerio[i]++;
                }
            }
        }
        
    }
    
  // achar o deposito mais abundante
  int k = 0;
  for (int j = 0; j < qtdedepositos; j++)
  {
    if (qtdeminerio[k] == qtdeminerio[j])
    {
      if (deposito[j].tamanho < deposito[k].tamanho)
      {
        k = j;
      } else if (deposito[k].tamanho < deposito[j].tamanho)
      {
        k = k;
      }
    } else if (qtdeminerio[k] < qtdeminerio[j])
    {
      k = j;
    }
  }
   
  maisabundante = k + 1;
  
  // checar se todos os depositos estao sem o minerio em questao
  for (int i = 0; i < qtdedepositos; i++)
  {
    if (qtdeminerio[i] == 0) 
    {
      ContDepSem++;
    }
  }

  if (ContDepSem == qtdedepositos)
  {
     printf("Nenhum deposito possui esse minerio");
  } else if (ContDepSem < qtdedepositos)
  {
    printf("O deposito mais ambundante deste minerio e o %d", maisabundante);
  }
    
   
    
    

    

    return (0);
}

