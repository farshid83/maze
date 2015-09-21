/*
 * maze.cpp
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

typedef struct
{
	int x; // x pos
	int y; // y pos
	int right; // 0 or 1
	int bottom; // 0 or 1
} CELL;

CELL** cell;

char check(int i, int j)
{
	if((i == 0) && (j == 0))
			return '|';

	if((i == 0) && (j == 1))
			return ' ';

	if((i == 0) && (j%2 == 1))
		return '-';
	else if((i == 0) && (cell[0][j/2-1].right == 0))
			return '+';
	else if((i == 0) && (cell[0][j/2-1].right == 1))
			return '-';

	if((j == 0) && (cell[i/2][0].bottom == 0))
		return '+';
	else if((j == 0) && (cell[i/2][0].bottom == 1))
		return '|';

	if((i%2 == 1) && (j%2 == 1))
		return ' ';

	if((i%2 == 1) && (cell[i/2][j/2-1].right == 0))
			return '|';
	else if((i%2 == 1) && (cell[i/2][j/2-1].right == 1))
			return ' ';

	if((j%2 == 1) && (cell[i/2-1][j/2].bottom == 0))
			return '-';
	else if((j%2 == 1) && (cell[i/2-1][j/2].bottom == 1))
			return ' ';

	if((i%2 == 0) && (j%2 == 0))
	{
		if((cell[i/2-1][j/2-1].right == 0) && (cell[i/2-1][j/2-1].bottom == 0))
			return '+';
		if((cell[i/2-1][j/2-1].right == 0) && (cell[i/2-1][j/2].bottom == 0))
			return '+';
		if((cell[i/2][j/2-1].right == 0) && (cell[i/2-1][j/2-1].bottom == 0))
			return '+';
		if((cell[i/2][j/2-1].right == 0) && (cell[i/2-1][j/2].bottom == 0))
			return '+';
		if((cell[i/2-1][j/2-1].bottom == 0) && (cell[i/2-1][j/2].bottom == 0))
			return '-';
		if((cell[i/2-1][j/2-1].right == 0) && (cell[i/2][j/2-1].right == 0))
			return '|';
	}
	return ' ';
}


int main(int argc, char** argv)
{
	srand(time(NULL));
	int row = 5;//atoi(argv[2]);
	int col = 4;//atoi(argv[1]);

	cell = new CELL* [row];
	for(int i = 0; i < row; i++)
	{
		cell[i] = new CELL [col];
		for(int j = 0; j < col; j++)
		{
			cell[i][j].x = i;
			cell[i][j].y = j;
			cell[i][j].right = rand() % 2;
			cell[i][j].bottom = rand() % 2;
			if(i == row-1)
				cell[i][j].bottom = 0;
			if(j == col-1)
				cell[i][j].right = 0;
		}
	}

	cell[0][0].right = 0;
	cell[0][0].bottom = 1;
	cell[row-1][col-1].right = 0;
	cell[row-1][col-1].bottom = 1;

	for(int i = 0; i < 2 * row + 1; i++)
	{
		//cout << "hey\n";
		for(int j = 0; j < 2 * col + 1; j++)
		{
			cout << check(i,j);
			//cout << "heyin\n";
		}
		cout << "\n";
	}

	for(int i = 0; i < row; i++)
		delete cell[i];
	return 0;
}
