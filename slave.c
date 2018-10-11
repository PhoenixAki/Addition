#include <stdio.h>

int main(int argc, char* argv[]){
	int numOne = atoi(argv[0]), numTwo = atoi(argv[1]);
	printf("Nums to add: %d + %d\n", numOne, numTwo);
	return numOne + numTwo;
}
