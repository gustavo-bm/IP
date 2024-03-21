#include <stdio.h>

int main (){

	// <<< complete aqui >>>
	float SalMin, ValKWatt, QtdeKWatt, ValAPagar, ValComDesconto;
	
	scanf("%f %f", &SalMin, &QtdeKWatt);
	
	ValKWatt = SalMin / 5;
	ValAPagar = QtdeKWatt * ValKWatt;
    ValComDesconto = ValAPagar * 0.85;
    
    printf("%.2f \n %.2f \n %.2f", ValKWatt, ValAPagar, ValComDesconto);
	return (0);
}