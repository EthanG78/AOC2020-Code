/* *************************************************************************
Program: 		Day3.c
by: 			Ethan Garnier
Program Date: 	December 3rd, 2020
****************************************************************************
Purpose: AOC 2020 Day 3 Problem
************************************************************************* */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nTreesEncountered(int slopeX, int slopeY, 
	int width, int height, char map[height][width]);

int main()
{
	FILE* fptr;
	char buff[255];
	int width = 0, height = 0;

	// Open input file with error checking
	if ((fptr = fopen("input.txt", "r")) == NULL)
	{
		printf("Error opening file\n");
		return 0;
	}

	// Need to find dimensions of the map
	do 
	{
		fscanf(fptr, "%s", buff);
		height++;
	} while(!feof(fptr));

	width = strlen(buff);

	char map[height][width];

	// Need to rewind file pointer to copy over the map 
	rewind(fptr);

	for (int i = 0; i < height; i++)
	{
		fscanf(fptr, "%s", map[i]);
	}
	fclose(fptr);

	// PART 1 to find number of trees we will hit on the map
	// going down by 1 and over by 3 each turn
	printf("Going to the right 3 and down 1 you will encounter %d trees\n", 
		nTreesEncountered(3, 1, width, height, map));

	// PART 2 Find the number of trees encountered for the following slopes: 
    // Right 1, down 1.
    // Right 3, down 1. 
    // Right 5, down 1.
    // Right 7, down 1.
    // Right 1, down 2.
    // Multiply their answers together
	int s1, s2, s3, s4, s5;
	double product;
	s1 = nTreesEncountered(1, 1, width, height, map);
	printf("%d\n", s1);
	s2 = nTreesEncountered(3, 1, width, height, map);
	printf("%d\n", s2);
	s3 = nTreesEncountered(5, 1, width, height, map);
	printf("%d\n", s3);
	s4 = nTreesEncountered(7, 1, width, height, map);
	printf("%d\n", s4);
	s5 = nTreesEncountered(1, 2, width, height, map);
	printf("%d\n", s5);
	product = (double) s1 * s2 * s3 * s4 * s5;

	printf("Product of number of trees encountered on each different slope: %.1lf\n", product);


	return 0;
}

// Counts the trees ('#') you will encounter 
// going to the right and down a repeating map by slopeX and slopeY
int nTreesEncountered(int slopeX, int slopeY, 
	int width, int height, char map[height][width])
{
	char location;
	int currentY = 0, currentX = 0;
	int nTrees;

	while (currentY < height)
	{
		// Go across slopeX and down slopeY every turn
		currentX += slopeX;
		currentY += slopeY;

		// The pattern is repeating so make sure 
		// we correct the current x coordinate if we need to
		if (currentX >= width)
		{
			currentX -= width;
		}

		// Current location on the map
		location = map[currentY][currentX];

		// Trees are represented by # in the map
		if (location == '#')
			nTrees++;
	}

	return nTrees;
}