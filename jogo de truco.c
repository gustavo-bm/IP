/* ================================================================== *
 *  Universidade Federal de Sao Carlos - UFSCar, Sorocaba
 *
 *  Disciplina: Introdução à Programação
 *  Prof. Tiago A. Almeida
 *
 *  Exercicio - Truco paulista
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

#define RODADA1 	"(Time 1 venceu a rodada)\n"
#define RODADA2 	"(Time 2 venceu a rodada)\n"
#define EMPATE 		"(Rodada empatada)\n"
#define GANHOU1 	"Time 1 ganhou a mao!\n"
#define GANHOU2 	"Time 2 ganhou a mao!\n"
#define EMPATEmao 	"Mao empatada!\n"

typedef struct {
  char naipe;
  char valor;
}carta;

void receberCartas(carta v[]);
int maiorNaipe(char n1, char n2);
int checarGanhador(carta c1, carta c2, char manilha);

int main(){
	carta cartas[4], vencedor;
	char manilha;
	scanf(" %c", &manilha);
	
	int g1, g2, round, p1 = 0, p2 = 0, draw = 0, aux = 0;

	while (p1 < 2 && p2 < 2 && draw < 3) {
	    receberCartas(cartas);
	    g1 = checarGanhador(cartas[0], cartas[2], manilha);
	    g2 = checarGanhador(cartas[1], cartas[3], manilha);

	    if (g1 != 0 && g2 != 0)
			round = checarGanhador(cartas[1-g1], cartas[2-g2], manilha);
	    else if (g1 == 0 && g2 != 0)
			round = checarGanhador(cartas[0], cartas[2-g2], manilha);
	    else if (g1 != 0 && g2 == 0)
			round = checarGanhador(cartas[1-g1], cartas[1], manilha);
	    else
			round = checarGanhador(cartas[0], cartas[1], manilha);

		if (round == 1){
			if (aux == 0)
				aux = 1;

			printf("(Time 1 venceu a rodada)\n");
			p1 += 1;
		} 
		else if (round == -1){
			if (aux == 0)
				aux = -1;

			printf("(Time 2 venceu a rodada)\n");
			p2 += 1;
		}
    	else{
			printf("(Rodada empatada)\n");
			draw += 1;
		}

		if (draw > 0 && ((p1 != 0) || (p2 != 0))){
			if (aux == 1){
				printf("Time 1 ganhou a mao!\n");
				return (0);        
			}
			else if(aux == -1){
				printf("Time 2 ganhou a mao!\n");
				return (0);
			}
			else if (p1 > p2){
				printf("Time 1 ganhou a mao!\n");
				return (0);
			}
			else if (p1 < p2){
				printf("Time 2 ganhou a mao!\n");
				return (0);
			}
			else {
				printf("Mao empatada!\n");
				return (0);
			}
    	}

	}

	if (p1 > p2)
		printf("Time 1 ganhou a mao!\n");
	else if(p1 < p2)
		printf("Time 2 ganhou a mao!\n");
	else
		printf("Mao empatada!\n");

	return (0);
} /// <---- ATE AQUI!!! ----


/// ---- APENAS IMPLEMENTE AS FUNCOES DAQUI PRA BAIXO

/* <<< COMPLETE AQUI >>> */
void receberCartas(carta v[])
{
  for (int i = 0; i < 4; i++)
  {
    scanf(" %c", &v[i].valor);
    scanf(" %c", &v[i].naipe);
  }
}
int maiorNaipe(char n1, char n2)
{
  int maior = 2;
  
  // Paus (P) > Copas (C) > Espadas (E) > Ouros (O)      1 representa empate

  if (n1 == 'P' && n2 != 'P')
  {
    maior = 1;
  } else if (n1 == 'C' && n2 != 'P')
  {
    maior = 1;
  } else if (n1 == 'E' && n2 != 'P'&& n2 != 'C')
  {
    maior = 1;
  } else if (n1 == 'O' && n2 != 'P' && n2 != 'C' && n2 != 'E')
  {
    maior = 1;
  }
  
  return (maior);
}

int checarGanhador(carta c1, carta c2, char manilha)
{
  int ordem1 = 0, ordem2 = 0, vencedor = 0;

  // ordem de força das cartas
  switch (c1.valor)
  {
    case 4:
      ordem1 = 0;
      break;
    
    case 5:
      ordem1 = 1;
      break;
    
    case 6:
      ordem1 = 2;
      break;
    
    case 7:
      ordem1 = 3;
      break;
    
    case 'Q':
      ordem1 = 4;
      break;
    
    case 'J':
      ordem1 = 5;
      break;
    
    case 'K':
      ordem1 = 6;
      break;
    
    case 'A':
      ordem1 = 7;
      break;
    
    case '2':
      ordem1 = 8;
      break;
    
    case '3':
      ordem1 = 9;
      break;
  }
  
  // ordem de força das cartas
  switch (c2.valor)
  {
    case 4:
      ordem2 = 0;
      break;
    
    case 5:
      ordem2 = 1;
      break;
    
    case 6:
      ordem2 = 2;
      break;
    
    case 7:
      ordem2 = 3;
      break;
    
    case 'Q':
      ordem2 = 4;
      break;
    
    case 'J':
      ordem2 = 5;
      break;
    
    case 'K':
      ordem2 = 6;
      break;
    
    case 'A':
      ordem2 = 7;
      break;
    
    case '2':
      ordem2 = 8;
      break;
    
    case '3':
      ordem2 = 9;
      break;
  }

  if (c1.valor != manilha && c2.valor != manilha)
  {
    if (ordem1 > ordem2)
    {
      vencedor = 1;
    } else if (ordem2 > ordem1)
      {
      vencedor = -1;
      }
  } else if (c1.valor == manilha && c2.valor != manilha)
  {
      vencedor = 1;
  } else if (c1.valor != manilha && c2.valor == manilha)
  {
      vencedor = -1;
  } else if (c1.valor == manilha && c2.valor == manilha)
  {
    int maior_naipe;
    maior_naipe = maiorNaipe(c1.valor, c2.valor);
    if (maior_naipe == 1)
    {
      vencedor = 1;
    } else if (maior_naipe == 2)
    {
      vencedor = -1;
    }
    
  }
  return(vencedor);
}
