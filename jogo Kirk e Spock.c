#include <stdio.h>

#define KIRK "Kirk venceu!\n"
#define SPOCK "Spock venceu!\n"
#define EMPATE "Empate!\n"

int main() {
  int Kirk = 0, Spock = 0, x = 0, y = 0;

  do {

    scanf("%d\n", &Kirk);
    scanf("%d\n", &Spock);

    if ((Kirk < 21) && (Spock < 21)) {
      Kirk = Kirk + x;
      x = Kirk;
    }

    if ((Kirk < 21) && (Spock < 21)) {
      Spock = Spock + y;
      y = Spock;
    } 
    if ((Kirk > 21) || (Spock == 21)){
      Spock = y + Spock;
    }

  } while ((Kirk < 21) && (Spock < 21));

  if (Kirk == 21) {
    printf(KIRK);
    printf("Kirk: %d e Spock: %d", Kirk, Spock);
  }
  if (Spock == 21) {
    printf(SPOCK);
    printf("Kirk: %d e Spock: %d", Kirk, Spock);
  }
  if ((Kirk > 21) && (Spock <= 21)) {
    printf(SPOCK);
    printf("Kirk: %d e Spock: %d", Kirk, Spock);
  }
  if ((Spock > 21) && (Kirk <= 21)) {
    printf(KIRK);
    printf("Kirk: %d e Spock: %d", Kirk, Spock);
  }
  if ((Kirk > 21) && (Spock > 21)) {
    printf(EMPATE);
    printf("Kirk: %d e Spock: %d", Kirk, Spock);
  }
  if ((Kirk == 21) && (Spock == 21)) {
    printf(EMPATE);
    printf("Kirk: %d e Spock: %d", Kirk, Spock);
  }

  return (0);
}