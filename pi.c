#include <stdio.h>
int main ( int argc, char* argv[]) {
	double tot= 0.0;
	int i;
	for ( i=0; i< 50000000; i++){
		if ((i%2) ==0){
			tot=tot + ( 1.0/ (2.0 *(double)i +1.0));
		}
		else {
			tot= tot - (1.0/ (2.0*(double)i +1));
		}

	} 
	tot*=4;
	printf("El valor de pi es: %.45f \n", tot);
	return 0;
}
