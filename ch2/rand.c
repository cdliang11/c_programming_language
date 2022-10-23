#include <stdio.h> 

unsigned long int next = 1;

int rand(void) {
	// 0-32767
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768; 
}

void srand(unsigned int seed) {
	next = seed;
}

int main(){
	srand(77);
	int num = rand();
	printf("%d\n", num);
	return 0;
}
