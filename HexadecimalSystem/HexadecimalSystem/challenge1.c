/*
 This challenge is about convert hexa to decimal and show
 and make the inverse too.

 Caio Madeira
*/

#include <stdio.h>


int main(void) {

	int a = 0x00CFFB80;
	unsigned int b = 0x00CFFB80;

	showHexa(a, b);
	HexaToDecimal(a, b);

}

int showHexa(int aParameter, unsigned int bParameter) {

	printf("hexadecimal 1: %80X\nhexadecimal 2: %80X\n", aParameter, bParameter);

	return 0;
}

int HexaToDecimal(int aParameter, unsigned int bParameter) {

	printf("hexadecimal to decimal 1: %d\nhexadecimal to decimal 2: %d", aParameter, bParameter);

	return 0;
}