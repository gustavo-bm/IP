#include <stdio.h>
#include <string.h>

void ler_emails (int qtde_nomes, char texto[10000], char enderecos_email[100][100]);
void emails_lenght (int qtde_nomes, int enderecos_email_len[100], char enderecos_email[100][100]);
void local_names (int enderecos_email_len[100], int qtde_nomes, char local_name[100][100], char enderecos_email[100][100], int local_name_len[100]);
void domain_names (int enderecos_email_len[100], int local_name_len[100], int qtde_nomes, char domain_name[100][100], char enderecos_email[100][100]);
int comparar_emails (char local_name[100][100], char domain_name[100][100], int qtde_nomes);

int main(void) {

  int saida = 0, qtde_nomes, enderecos_email_len[100] = {0}, local_name_len[100] = {0}, texto_len[1];
  char enderecos_email[100][100], local_name[100][100], domain_name[100][100], texto[10000];
  
  ler_emails (qtde_nomes, texto, enderecos_email);
  emails_lenght (qtde_nomes, enderecos_email_len, enderecos_email);
  local_names (enderecos_email_len, qtde_nomes, local_name, enderecos_email, local_name_len);
  domain_names (enderecos_email_len, local_name_len, qtde_nomes, domain_name, enderecos_email);
  saida = comparar_emails(local_name, domain_name, qtde_nomes);

  printf("%d", saida);
} 

// ler todas as strings de endereços de email
void ler_emails (int qtde_nomes, char texto[10000], char enderecos_email[100][100]){
  char enderecos_email_;

  int j = 0;
    while (1)
    {
    texto[j] = getchar();
    if (texto[j] == ']')
    {
      break;
    }
    j++;
    }

  //teste
  printf("\n");
  
  for (int i = 0; i < j; i++){
    printf("%c", texto[i]);
  }
}

  // para cada uma, contar quantos caracteres há (strlen)
void emails_lenght (int qtde_nomes, int enderecos_email_len[100], char enderecos_email[100][100]){
  
  // arrumar para checar apenas até a quantidade de nomes submetida
  for (int i = 0; i < qtde_nomes; i++)
  {
    enderecos_email_len[i] = strlen(enderecos_email[i]);
  }

  // teste
  for (int i = 1; i < qtde_nomes; i++)
  {
    printf("%u\n", (unsigned)enderecos_email_len[i] - 1);
  }
}

  // obter os local names
void local_names (int enderecos_email_len[100], int qtde_nomes, char local_name[100][100], char enderecos_email[100][100], int local_name_len[100]){

  int aux, cont = 0;
  
  for (int i = 0; i < qtde_nomes + 1; i++)
  {
    for (int j = 0; j < enderecos_email_len[i]; j++)
    {
      if (enderecos_email[i][j] != '@')
      {
        local_name_len[i]++;
      } else if (enderecos_email[i][j] == '@' || enderecos_email[i][j] == '+')
      {
        break;
      }
    }
	}

  // ignorar tudo depois do +
  for (int i = 0; i < qtde_nomes + 1; i++)
  {
    for (int j = 0; j < local_name_len[i]; j++)
    {
      if (enderecos_email[i][j] != '+')
      {
        local_name[i][j] = enderecos_email[i][j];
      } else if (enderecos_email[i][j] == '+')
      {
        break;
      }
    }
  }

  //transformar em minusculas
  for (int i = 0; i < qtde_nomes + 1; i++)
  {
    for (int j = 0; j < local_name_len[i]; j++)
    {
      if (local_name[i][j] >= 65 && local_name[i][j] <= 90)
      {
        local_name[i][j] += 32;
      }
    }
  }
  printf("\n");
}

  // obter os domain names
void domain_names (int enderecos_email_len[100], int local_name_len[100], int qtde_nomes, char domain_name[100][100], char enderecos_email[100][100]){

  int k;
  
  for (int i = 0; i < qtde_nomes + 1; i++)
  {
    k = 0;
    for (int j = local_name_len[i] + 1; j < enderecos_email_len[i]; j++)
    {
      domain_name[i][k] = enderecos_email[i][j];
      k++;
    }
  }
  
// teste
  for (int i = 1; i < qtde_nomes + 1; i++)
  {
    printf("%s", domain_name[i]);
  }
  
}

  // comparar uma a uma (strcmp)
int comparar_emails (char local_name[100][100], char domain_name[100][100], int qtde_nomes){
  int saida = 0;
  char str_random[] = "00000";

  for (int i = 0; i < qtde_nomes + 1; i++)
  {
    for (int j = i + 1; j < qtde_nomes; j++)
    {
      if ((strcmp(local_name[i], local_name[j])) != 0)
      {
        if ((strcmp(domain_name[i], domain_name[j])) != 0)
        {
          saida++;
          strcpy(local_name[i], str_random);
          strcpy(domain_name[i], str_random);
        }
      }
    }
  }

  /*saida = qtde_nomes - saida;*/
  return(saida);
}