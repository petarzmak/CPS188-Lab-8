//Sums all values along the main diagonal
double
sumdiag(double array[10][10]){
	
	int i;
	double sum = 0;
	
	for (i = 0; i < 10; i++)
		sum = sum + array[i][i];

	return(sum);
}

//Sums all of the values
double
sumall(double array[10][10]){
	
	int i, k;
	double sum = 0;
	
	for (i = 0; i < 10; i++){
		for (k = 0; k < 10; k++)
			sum = sum + array[i][k];
	}

	return(sum);
}

//Finds the average of all of the rightmost values
double
avright(double array[10][10]){
	
	int i, count = 0;
	double avr = 0;
	
	for (i = 0; i < 10; i++){
		avr = avr + array[i][9];
		count = count + 1;
	}
	
	avr = avr/count;

	return(avr);
}

//Sums all of the values found in the four corners of the array
double
corners(double array[10][10]){
	
	double sum;
	
	sum = array[0][0] + array [9][9] + array[0][9] + array [9][0];

	return(sum);
}

//Finds the largest number along the antidiagonal
double
largeanti(double array[10][10]){
	
	int i, k = 9;
	double numbers[10], largest;
	
	for (i = 0; i < 10; i++){
		numbers[i] = array[i][k];
		k--;
	}
	
	largest = numbers[0];
	for (i = 0; i < 10; i++){
		if (numbers[i] > largest)
			largest = numbers[i];
	}
	
	return(largest);
}
