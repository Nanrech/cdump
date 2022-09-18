#include <stdio.h>
#define STEP 10
#define UPPER 100


int main(){
	
	// C = (5/9)*(F-32)
	// F = (9/5)
	
	float celsius, fahrenheit;
	float lower = 0.0;
	
	printf("\nFAHRENHEIT TO CELSIUS!\n");
	while (lower <= UPPER) {
		celsius = (5.0 / 9.0) * (lower - 32.0);
		printf("%3.0fF*\t:\t%6.2fC*\n", lower, celsius);
		lower = lower + STEP;
	}
	
	printf("\nCELSIUS TO FAHRENHEIT\n");

	celsius, lower = 0.0;

	while (lower <= UPPER){
		fahrenheit = (9.0 / 5.0 * lower) + 32.0;
		printf("%3.0fC*\t:\t%6.2fF*\n", lower, fahrenheit);
		lower = lower + STEP;
	}
	
	
	return 0;
}