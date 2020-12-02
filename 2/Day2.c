/* *************************************************************************
Program: 		Day2.c
by: 			Ethan Garnier
Program Date: 	December 2nd, 2020
****************************************************************************
Purpose: AOC 2020 Day 2 Problem
************************************************************************* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE* fptr;
	char buff[255];
	char letter[255];
	int upper, lower, nValid = 0, charCount = 0, i, len;


	// Open input file with error checking
	if ((fptr = fopen("input.txt", "r")) == NULL)
	{
		printf("Error opening file\n");
		return 0;
	}

	// PART 1
	do
	{
		fscanf(fptr, "%d-%d %[^:] %s %s", &lower, &upper, letter, buff, buff);

		len = strlen(buff);
		charCount = 0;
		for (i = 0; i < len; i++)
		{
			if (buff[i] == letter[0])
			{
				charCount++;
			}
		}

		if (charCount <= upper && charCount >= lower)
		{
			nValid++;
		}

	} while(!feof(fptr));

	printf("Part1: %d\n", nValid);

	rewind(fptr);

	// PART 2
	nValid = 0;
	do
	{
		fscanf(fptr, "%d-%d %[^:] %s %s", &lower, &upper, letter, buff, buff);

		len = strlen(buff);
		if (len >= upper - 1)
		{
			if ((buff[upper - 1] == letter[0] && buff[lower - 1] != letter[0])
				|| (buff[upper - 1] != letter[0] && buff[lower - 1] == letter[0]))
			{
				nValid++;
			}
		}
	} while(!feof(fptr));

	printf("Part2: %d\n", nValid);

	fclose(fptr);

	return 0;
}