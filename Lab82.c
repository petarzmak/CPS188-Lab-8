#include <stdio.h>
#include "mylibrary.h"

int main(void)
{
	double ls[10][10], calc[5], results[5];
	int i = 0, k;
	
	//Read values from file
	FILE *in;
	in = fopen("L8_real.txt", "r");
	
	while (!feof(in)){
		for (k = 0; k < 10; k++)
			fscanf(in, "%lf", &ls[i][k]);
				
		i++;
	}
	fclose(in);
	
	//Pass array to each function to get calculations
	calc[0] = sumdiag(ls);
	calc[1]= sumall(ls);
	calc[2] = avright(ls);
	calc[3] = corners(ls);
	calc[4] = largeanti(ls);
	
	
	//Write calculations to Binary File
	FILE *out;
	out = fopen("results.bin", "wb");
	
	for	(i = 0; i < 10; i++)
		fwrite(&calc[i], sizeof(double), 1, out);
	fclose(out);
		
	//Read results from Binary File
	FILE *read;
	read = fopen("results.bin", "rb");
	
	i = 0;
	while (!feof(read)){
		fread(&results[i], sizeof(double), 1, read);
		i++;
	}
	
	//Print Results
	printf("The sum of the diagonal numbers is %.1lf.\n", results[0]);
	printf("The sum of the all numbers is %.1lf.\n", results[1]);
	printf("The average of the rightmost numbers is %.1lf.\n", results[2]);
	printf("The sum of the four corners is %.1lf.\n", results[3]);
	printf("The largest number on the antidiagonal is %.1lf.\n", results[4]);
	
	return 0;
}

