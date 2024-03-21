#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  float qtde_palavras = 1;
  float qtde_palavras_com = 0, porcentagem = 0, tamanho_texto = 0, qtde_espacos = 0;
  char caso, texto[1000];

  for (int i = 0; i < 1000; i++){
    texto[i] = '\0';
  }

  scanf("%c\n", &caso);
  if (isupper(caso))
  {
    caso = tolower(caso);
  }
  
  int j = 0;
    while (1)
    {
    texto[j] = getchar();
    if (texto[j] == EOF)
    {
      break;
    }
    j++;
    }
  
  tamanho_texto = strlen(texto);
  
  for (int i = 0; i < tamanho_texto; i++)
  {
    if (texto[i] != ' ' && isupper(texto[i]))
    {
      texto[i] = tolower(texto[i]);
    }
  }

  for (int i = 0; i < tamanho_texto; i++){
    if (texto[i] == ' ')
    {
      qtde_palavras++;
    }
  }
  int qtde_quebras = 0;
  for (int i = 0; i < tamanho_texto; i++)
  {
    if (texto[i] == '\n')
    {
      qtde_quebras++;
    }
  }

  qtde_palavras += qtde_quebras - 1;
  for (int j = 0; j < tamanho_texto; j++)
  {
    if (texto[j] != ' ')
    {
      if (texto[j] == caso)
      {
        qtde_palavras_com++;
        qtde_palavras_com--;
        qtde_palavras_com++;
        
        while (texto[j] != ' ')
        {
          j++;
        }
      }
    }
  }
  
  porcentagem = 100.0 * qtde_palavras_com/ qtde_palavras;
  printf("%.1f", porcentagem);
  
  return 0;
}