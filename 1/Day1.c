/* *************************************************************************
Program: 		Day1.c
by: 			Ethan Garnier
Program Date: 	December 1st, 2020
****************************************************************************
Purpose: AOC 2020 Day 1 Problem
************************************************************************* */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fptr;
	int nInputs = 0;
	int num1, num2 = -1, i, j;
	int buff = 0;

	// Open input file with error checking
	if ((fptr = fopen("input.txt", "r")) == NULL)
	{
		printf("Error opening file\n");
		return 0;
	}

	// Loop through each element in input to number of inputs
	do
	{
		fscanf(fptr, "%d", &buff);
		nInputs++;
	} while(!feof(fptr));

	// Create an array that will hold each integer input
	int inArr[nInputs];

	// Reset the file pointer to beginning of file
	rewind(fptr);

	// Scan each integer input into the array
	for (i = 0; i < nInputs; i++)
	{
		fscanf(fptr, "%d", &buff);
		inArr[i] = buff;
	}

	// Iterate through the array one input at a time
	// checking to see if the sum of itself and 
	// any other of the inputs equals 2020
	// When this is true, we have found our two answers
	for (i = 0; i < nInputs; i++)
	{	
		num1 = inArr[i];

		for (j = 0; j < nInputs; j++)
		{
			if (j != i && num1 + inArr[j] == 2020)
			{
				num2 = inArr[j];
				break;
			}
		}

		if (num2 != -1)
			break;
	}

	fclose(fptr);

	// ANSWER FOR PART 1
	// Final answer is the product of the two found numbers
	printf("Num1: %d\nNum2: %d\n", num1, num2);
	printf("Answer: %d\n", num1 * num2);

	// START OF PART 2
	num2 = -1;
	int num3 = -1, k;
	// Iterate through the array one input at a time
	// checking to see if the sum of itself and 
	// two other of the inputs equals 2020
	// When this is true, we have found our three answers
	for (i = 0; i < nInputs; i++)
	{	
		num1 = inArr[i];

		for (j = 0; j < nInputs; j++)
		{
			if (j != i)
			{
				for (k = 0; k < nInputs; k++)
				{
					if (k != j && num1 + inArr[j] + inArr[k] == 2020)
					{
						num3 = inArr[k];
						break;
					}
				}

				if (num3 != -1)
				{
					num2 = inArr[j];
					break;
				}
			}
		}

		if (num2 != -1)
			break;
	}

	// ANSWER FOR PART 2
	// Final answer is the product of the three found numbers
	printf("Num1: %d\nNum2: %d\nNum3: %d\n", num1, num2, num3);
	printf("Answer: %d\n", num1 * num2 * num3);

	return 0;
}