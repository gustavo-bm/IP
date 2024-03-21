/* ================================================================== *
 *  Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercicio -  Totiente de Euler
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

#define MDC 	"MDC(%d,%d) = %d\n"
#define PHI 	"Phi(%d) = %d\n"
#define EQUACAO "%d ^ %d (mod %d) = %ld\n"
#define VALIDO "Os numeros sao validos para o teorema.\n"
#define INVALIDO 	"Os numeros nao sao validos para o teorema.\n"

int calcularMDC(int a, int b);
int calcularPhi(int num);
unsigned long exponenciacaoModular(unsigned long a, unsigned long b, unsigned long c);

int main() { 
	int a, b;
	scanf("%d %d", &a, &b);

	int mdc = calcularMDC(a, b);
	printf(MDC, a, b, mdc );

	int phi = calcularPhi(b);
	printf(PHI, b, phi);
	printf(EQUACAO, a, phi, b, exponenciacaoModular(a, phi, b));
	
	if (mdc == 1)
		printf(VALIDO);
	else
		printf(INVALIDO);
  
  return (0);
} /// <---- ATE AQUI!!! ----


/// ---- APENAS IMPLEMENTE AS FUNCOES DAQUI PRA BAIXO

/* <<< COMPLETE AQUI >>> */

int calcularMDC(int a, int b)
{

  // achar os divisores de a e b
  unsigned long int divisores_a[1000], divisores_b[1000];
  unsigned long int k = 0;
  unsigned long int w = 0;
  unsigned long int mdc = 0;

  //achar os divisores de a e b
  
  for (int i = 1; i <= a; i++)
  {
    if (a % i == 0)
    {
      divisores_a[k] = i;
      k++;
    }
  }

  for (int i = 1; i <= b; i++)
  {
    if (b % i == 0)
    {
      divisores_b[w] = i;
      w++;
    }
  }

  unsigned long int w_aux;
  unsigned long int k_aux, aux = 0;

  w_aux = w;
  k_aux = k;
  
  //achar o MDC

    for (k = 0; k < k_aux; k++)
    {
      for (w = 0; w < w_aux; w++)
      {
        if (divisores_a[k] == divisores_b[w])
        {
          mdc = divisores_a[k];
          
        }
      }
      
    }
  

  return(mdc);
  
}

int calcularPhi(int num)
{
  unsigned long int phi = 1;

  // checar se mdc entre b e os demais é 1
  
  for (int i = 0; i < num - 1; i++)
  {
    int mdc = calcularMDC(i, num);
    if (mdc == 1)
    {
      phi++;
    }
  }

  
  return(phi);
}

unsigned long exponenciacaoModular(unsigned long a, unsigned long b, unsigned long c)
{

  unsigned long int result;
  int a_aux = a;
  
  for (int i = 0; i < b - 1; i++)
  {
    a_aux *= a;
    a_aux %= c;
  }

  a_aux %= c;
  
  return (a_aux);
}