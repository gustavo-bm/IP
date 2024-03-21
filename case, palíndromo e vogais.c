/* ================================================================== *
 *  Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercicio - Os Estranhos
 *
 *  Instruções
 *  ----------
 *
 *	Este arquivo contém o código que auxiliará no desenvolvimento do
 *	exercício. Você precisará completar as partes requisitadas.
 *
 * ================================================================== */

/// ---- ATENCAO: NAO ALTERAR DAQUI ---->
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXTEXTO    500
#define MAIUSCULA   1
#define MINUSCULA   0
#define VERDADEIRO  1
#define FALSO       0

/* prototipos das funcoes */

// retorna quantidade de palavras na string (delimitadas por espaços)
int calculaTamanho(char texto[]); 

// retorna MAIUSCULA ou MINUSCULA dependendo da primeira letra da primeira palavra
int incial(char texto[]);

// retorna VERDADEIRO se palindromo e FALSO se nao
int palindromo(char texto[]); 

// retorna numero total de vogais distintas
int vogalDistinta(char texto[]); 

// retorna VERDADEIRO se valida (creterios no pdf) ou FALSO se nao
int senhaValida(char texto[]); 

// imprime o texto de [ ESTATISTICA ]
void imprimeEstatistica(char texto[]); 

int main() {
    char texto[MAXTEXTO];

    scanf(" %[^\n]",texto);

    int valida = senhaValida(texto);

    if (valida)
        printf("Autorizado!\n");
    else
        printf("Bloqueado!\n");

    imprimeEstatistica(texto);

    return (0);
}
/// <---- ATE AQUI!!! ----


/// ---- APENAS IMPLEMENTE AS FUNCOES ---->
  // retorna quantidade de palavras na string (delimitadas por espaços)
int calculaTamanho(char texto[]){
  int tam_texto, qtde_palavras;

  qtde_palavras = 0;

  tam_texto = strlen(texto);

  for (int i = 0; i < tam_texto; i++)
  {
    if (texto[i] == ' ')
    {
      qtde_palavras++;
    }
  }

  return(qtde_palavras);
}

// retorna MAIUSCULA ou MINUSCULA dependendo da primeira letra da primeira palavra
int incial(char texto[]){
  
  if (isupper(texto[0]))
  {
    return(MAIUSCULA);
  } else 
  {
    return(MINUSCULA);
  }

  return(0);
}
  
// retorna VERDADEIRO se palindromo e FALSO se nao
int palindromo(char texto[]){
  int d = 0, e = 0, x, tam_texto, iguais, k;
  char texto_aux[MAXTEXTO];

    scanf(" %[^\n]",texto);

  iguais = 0;
  
  strcpy(texto_aux, texto);

  tam_texto = strlen(texto_aux);

  for (int i = 0; i < tam_texto; i++){
    if (isupper(texto_aux[i]))
    {
      texto_aux[i] = tolower(texto_aux[i]);
    } 
  }

  for (int i = 0; i < tam_texto; i++){
    while (ispunct(texto_aux[i]))
    {
      i++;
    } 
    texto_aux[d] = texto_aux[i];
    d++;
  }
  
  for (int i = 0; i < tam_texto; i++){
    if (isspace(texto_aux[i]))
    {
      i++;
    } 
    texto_aux[e] = texto_aux[i];
    e++;
  }

  texto_aux[e] = '\0';

  tam_texto = strlen(texto_aux);

  if (tam_texto % 2 == 0)
  {
    k = tam_texto - 1;
    for (int i = 0; i < (tam_texto / 2); i++, k--)
    {
      if (texto_aux[i] == texto_aux[k])
      {
        iguais++;
      } else if (texto_aux[i] != texto_aux[k])
      {
        return(FALSO);
      }
    }

    if (iguais == (tam_texto / 2))
    {
      return(VERDADEIRO);
    }
  } else if (tam_texto % 2 == 1)
  {
    k = tam_texto - 1;
    for (int i = 0; i < (tam_texto + 1 / 2); i++, k--)
    {
      if (texto_aux[i] == texto_aux[k])
      {
        iguais++;
      } else if (texto_aux[i] != texto_aux[k])
      {
        return(FALSO);
      }
    }

    if (iguais == (tam_texto - 1 / 2))
    {
      return(VERDADEIRO);
    }
  }
  return(0);
}

// retorna numero total de vogais distintas
int vogalDistinta(char texto[]){
  int tam_texto, a, e, i, o, u, vogais = 0, controle_a = 0, controle_e = 0, controle_i = 0, controle_o = 0, controle_u = 0;
  a = 0;
  e = 0;
  i = 0;
  o = 0;
  u = 0;

  tam_texto = strlen(texto);

  for (int i = 0; i < tam_texto; i++){
    if (isupper(texto[i])){
      texto[i] = tolower(texto[i]);
    }
  }

  for (int i = 0; i < tam_texto; i++)
  {
    if (texto[i] == 'a' && controle_a < 2){
      a++;
      controle_a += 100;
      vogais++;
    } else if (texto[i] == 'e' && controle_e < 2){
      e++;
      controle_e += 100;
      vogais++;
    } else if (texto[i] == 'i' && controle_i < 2){
      i++;
      controle_i += 100;
      vogais++;
    } else if (texto[i] == 'o' && controle_o < 2){
      o++;
      controle_o += 100;
      vogais++;
    } else if (texto[i] == 'u' && controle_u < 2){
      u++;
      controle_u += 100;
      vogais++;
    }
  }
  
  return(vogais);
}

// retorna VERDADEIRO se valida (creterios no pdf) ou FALSO se nao
int senhaValida(char texto[]){

  int qtde_palavras, inicial, verif_palindromo, vogais;
  
  qtde_palavras = calculaTamanho(texto); 
  inicial = incial(texto);
  verif_palindromo = palindromo(texto); 
  vogais = vogalDistinta( texto);

  if (qtde_palavras >= 10 && inicial == 1 && verif_palindromo == 1 && vogais >= 2){
    return(VERDADEIRO);
  } else 
  {
    return(FALSO);
  }
      
  return(0);
}

// imprime o texto de [ ESTATISTICA ]
void imprimeEstatistica(char texto[]){
  int qtde_palavras, inicial, verif_palindromo, vogais;
  
  qtde_palavras = calculaTamanho(texto); 
  inicial = incial(texto);
  verif_palindromo = palindromo(texto); 
  vogais = vogalDistinta( texto);

  printf("[ ESTATISTICA ]\n");

  /*Tamanho: 9
  Inicio: maiuscula
  Vogais: 4
  Palindromo: sim*/

  printf("Tamanho: %d\n", qtde_palavras + 1);

  if (inicial == 0)
  {
    printf("Inicio: maiuscula\n");
  } else if (inicial == 1)
  {
    printf("Inicio: minuscula\n");
  }

  printf("Vogais: %d\n", vogais);

  if (verif_palindromo == 1){
    printf("Palindromo: sim\n");
  } else if (verif_palindromo == 0){
    printf("Palindromo: nao\n");
  }
}