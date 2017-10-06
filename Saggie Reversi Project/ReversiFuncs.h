#pragma once
#include<stdio.h>
#include<stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#pragma region Printing The Board

void PrintBoard(int matrixBoard[][8])
{
	system("cls");

	//Dummy 0'ed matrix (8x8)
	//int gameBoard[][8] = {
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 }
	//};

	int tmp = 0, score1 = 0, score2 = 0;


	printf("      1    2    3    4    5    6    7    8\n");
	printf("---------------------------------------------\n");
	for (int i = 0; i < 8; i++)
	{
		printf("%d  |", i + 1);
		for (int j = 0; j < 8; j++)
		{
			tmp = matrixBoard[i][j];
			//if (tmp == 1)
			//{
			//	printf("");
			//}
			if (tmp == 1)
			{
				score1++;
				printf("| "ANSI_COLOR_RED"%d"ANSI_COLOR_RESET" |", tmp);
			}
			else if (tmp == 2)
			{
				score2++;
				printf("| "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET" |", tmp);
			}
			else if (tmp == 0)
			{
				printf("| %d |", tmp);

			}
		}
		printf("|\n---------------------------------------------\n");
	}
	printf("\t\t\t\t"ANSI_COLOR_RED"player 1: [%d]"ANSI_COLOR_RESET"\n", score1);
	printf("\t\t\t\t"ANSI_COLOR_GREEN"player 2: [%d]"ANSI_COLOR_RESET"\n", score2);
	//printf(ANSI_COLOR_RED"%c"ANSI_COLOR_RESET"\n", (char)178); => idea for future changing tiles look
}

#pragma endregion

#pragma region Checkings

int CheckNW(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		indexi++;
		indexj++;
	}

	while (fl)
	{

		indexi--;
		indexj--;

		//if we've reached an empty tile
		if (board[indexi][indexj] == 0)
		{
			fl = 0;
		}
		//if we've reached our own tile again, then increment closure
		//to inform that we've ended a sequence, starting at our tile and also ending.
		//worth mentioning that only if 'closure' is true, and 'count' (which represents
		//how many times we've met the other player's tiles) is true, then it means we've
		//reached a real sequence
		else if (board[indexi][indexj] == turn)
		{
				closure++;
				fl = 0;
			
		}
		//if we're out of array bounds
		else if (indexi < 0)
		{
			fl = 0;
		}
		//if we've reached an enemy's tile, then increment 'count'
		else if (board[indexi][indexj] == 3 - turn)
		{
			count++;
		}
		i++;
	}

	//i we've met at least one enemy tile and we've reached a full length sequence
	//which ends at our own tile, then return count. otherwise return 0.
	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

//Look at [CheckNW()] for comments.
int CheckNE(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		indexi++;
		indexj--;
	}

	while (fl)
	{
		indexi--;
		indexj++;

		//if we've reached an empty tile
		if (board[indexi][indexj] == 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == turn)
		{
			closure++;
			fl = 0;
		}
		else if (indexj > 7 || indexi < 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == 3 - turn)
		{
			count++;
		}
		i++;

	}

	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

//Look at [CheckNW()] for comments.
int CheckNorth(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		indexi++;
		//indexj++;
	}

	while (fl)
	{
		indexi--;

		if (board[indexi][indexj] == 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == turn)
		{
			closure++;
			fl = 0;
		}
		else if (indexi < 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == 3 - turn)
		{
			count++;
		}
		i++;

	}

	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

//Look at [CheckNW()] for comments.
int CheckEast(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		//indexi++;

		indexj--;
		//indexj++;
	}

	while (fl)
	{
		indexj++;

		if (board[indexi][indexj] == 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == turn)
		{
			closure++;
			fl = 0;
		}
		else if (indexj > 7)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == 3 - turn)
		{
			count++;
		}
		i++;
	}

	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

//Look at [CheckNW()] for comments.
int CheckSE(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		indexi--;
		indexj--;
	}

	while (fl)
	{
		indexi++;
		indexj++;

		if (board[indexi][indexj] == 0)
		{
				fl = 0;
		}
		else if (board[indexi][indexj] == turn)
		{
			closure++;
			fl = 0;
		}
		else if (indexj > 7 || indexi > 7)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == 3 - turn)
		{
			count++;
		}
		i++;

	}

	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

//Look at [CheckNW()] for comments.
int CheckSouth(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		indexi++;
		//indexj++;
	}

	while (fl)
	{
		indexi++;

		if (board[indexi][indexj] == 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == turn)
		{
			closure++;
			fl = 0;
		}
		else if (indexi > 7)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == 3 - turn)
		{
			count++;
		}
		i++;
	}

	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

//Look at [CheckNW()] for comments.
int CheckSW(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		//indexi++;
		indexi--;
		indexj++;
	}

	while (fl)
	{
		indexi++;
		indexj--;

		if (board[indexi][indexj] == 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == turn)
		{
			closure++;
			fl = 0;
		}
		else if (indexi > 7 || indexj < 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == 3 - turn)
		{
			count++;
		}
		i++;
	}

	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

//Look at [CheckNW()] for comments.
int CheckWest(int board[8][8], int indexi, int indexj, int turn, int isTicked)
{
	int count = 0, i = 0, fl = 1, closure = 0;

	//isTicked means that we only want to check the values after the tile
	//if it's 0, then it means we want to check including the starting tile
	//(in the double for loop, where we iterate over every tile).
	if (isTicked == 1)
	{
		//indexi++;
		indexj++;
	}

	while (fl)
	{
		indexj--;

		if (board[indexi][indexj] == 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == turn)// && board[indexi][indexj + 1] != 0)
		{
			closure++;
			fl = 0;
		}
		else if (indexj < 0)
		{
			fl = 0;
		}
		else if (board[indexi][indexj] == 3 - turn && board[indexi][indexj + 1] != turn)
		{
			count++;
		}
		i++;
	}

	if (count > 0 && closure > 0)
	{
		return count;
	}
	else
	{
		return 0;
	}
}

#pragma endregion

#pragma region Changings

void ChangeNW(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		i--;
		j--;
		count--;
		board[i][j] = turn;
	}
}

void ChangeNorth(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		i--;
		count--;
		board[i][j] = turn;
	}
}

void ChangeNE(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		i--;
		j++;
		count--;
		board[i][j] = turn;
	}
}

void ChangeEast(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		j++;
		count--;
		board[i][j] = turn;
	}
}

void ChangeSE(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		i++;
		j++;
		count--;
		board[i][j] = turn;
	}
}

void ChangeSouth(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		i++;
		count--;
		board[i][j] = turn;
	}
}

void ChangeSW(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		i++;
		j--;
		count--;
		board[i][j] = turn;
	}
}

void ChangeWest(int board[8][8], int i, int j, int turn, int count)
{
	while (count > 0)
	{
		j--;
		count--;
		board[i][j] = turn;
	}
}
#pragma endregion

void CheckAllTiles()
{

}

void BeginGame(int gameBoard[8][8])
{
	int turn = 1, indexI = 0, indexJ = 0, fl = 1, currentTile = 0;


	int nw, north, ne, east = 0, se, south, sw, west;

	//int gameBoard[][8] = {
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0 }
	//};

//	for (int i = 0; i < 8; i++)
//	{
//		for (int j = 0; j < 8; j++)
//		{
//			#pragma region Checking tile directions
//			
//			if (i == 5 && j == 2)
//			{
//				puts("");
//			}
//			nw = CheckNW(gameBoard, i, j, turn);
//			north = CheckNorth(gameBoard, i, j, turn);
//			ne = CheckNE(gameBoard, i, j, turn);
//			//east = CheckEast(gameBoard, i, j, turn);
//			se = CheckSE(gameBoard, i, j, turn);
//			south = CheckSouth(gameBoard, i, j, turn);
//			sw = CheckSW(gameBoard, i, j, turn);
//			west = CheckWest(gameBoard, i, j, turn);
//
//#pragma endregion
//
//			#pragma region Changing Tile if matches
//
//			if (nw)
//			{
//				ChangeNW(gameBoard, i, j, turn, nw);
//			}
//			if (north)
//			{
//				changeNorth(gameBoard, i, j, turn, north);
//			}
//			if (ne)
//			{
//				ChangeNE(gameBoard, i, j, turn, ne);
//			}
//			if (east)
//			{
//				ChangeEast(gameBoard, i, j, turn, east);
//			}
//			if (se)
//			{
//				ChangeSE(gameBoard, i, j, turn, se);
//			}
//			if (south)
//			{
//				ChangeSouth(gameBoard, i, j, turn, south);
//			}
//			if (sw)
//			{
//				ChangeSW(gameBoard, i, j, turn, sw);
//			}
//			if (west)
//			{
//				ChangeWest(gameBoard, i, j, turn, west);
//			}
//#pragma endregion
//
//
//		}
//	}
//	
	PrintBoard(gameBoard);

	while (indexI >= 0)
	{
		fl = 1;

		while (fl == 1)
		{
			if (turn == 1)
			{
				printf(ANSI_COLOR_RED"It's player "ANSI_COLOR_RED"%d"ANSI_COLOR_RESET"'s turn!\n", turn);
			}
			else if (turn == 2)
			{
				printf(ANSI_COLOR_GREEN"It's player "ANSI_COLOR_GREEN"%d"ANSI_COLOR_RESET"'s turn!\n", turn);
			}
			//printf("It's player %d's turn!\n", turn);
			printf("Enter a location, separated by a space:\n");
			scanf("%d %d", &indexI, &indexJ);



			indexI -= 1;
			indexJ -= 1;

			nw = CheckNW(gameBoard, indexI, indexJ, turn, 0);
			ne = CheckNE(gameBoard, indexI, indexJ, turn, 0);
			north = CheckNorth(gameBoard, indexI, indexJ, turn, 0);
			east = CheckEast(gameBoard, indexI, indexJ, turn, 0);
			se = CheckSE(gameBoard, indexI, indexJ, turn, 0);

			currentTile = gameBoard[indexI][indexJ];
			south = CheckSouth(gameBoard, indexI, indexJ, turn, 0);
			sw = CheckSW(gameBoard, indexI, indexJ, turn, 0);
			west = CheckWest(gameBoard, indexI, indexJ, turn, 0);

			if (indexI > 7 || indexJ > 7 || indexI < 0 || indexJ < 0)
			{
				printf("Invalid Values\n");
			}
			else if (gameBoard[indexI][indexJ] == 0)
			{
				if (nw > 0)
				{
					ChangeNW(gameBoard, indexI, indexJ, turn, nw);
					fl = 0;
				}
				if (ne > 0)
				{
					ChangeNE(gameBoard, indexI, indexJ, turn, ne);
					fl = 0;
				}
				 if (north > 0)
				{
					 ChangeNorth(gameBoard, indexI, indexJ, turn, north);

					fl = 0;
				}
				 if (east > 0)
				{
					 ChangeEast(gameBoard, indexI, indexJ, turn, east);
					fl = 0;
				}
				 if (se > 0)
				{
					 ChangeSE(gameBoard, indexI, indexJ, turn, se);
					fl = 0;
				}
				 if (south > 0)
				{
					 ChangeSouth(gameBoard, indexI, indexJ, turn, south);

					fl = 0;
				}
				 if (sw > 0)
				{
					 ChangeSW(gameBoard, indexI, indexJ, turn, sw);

					fl = 0;
				}
				 if (west > 0)
				{
					 ChangeWest(gameBoard, indexI, indexJ, turn, west);

					fl = 0;
				}
				else
				{
					printf("Taking over [%d, %d] will NOT conquer anything !\n", indexI + 1, indexJ + 1);
				}
			}
			else if (gameBoard[indexI][indexJ] == (3 - turn))
			{
				printf("[%d], [%d] is already occupied by player %d !\n", indexI + 1, indexJ + 1, 3 - turn);
			}
			else if (gameBoard[indexI][indexJ] == turn)
			{
				printf("You've already conquered [%d][%d] !\n", indexI + 1, indexJ + 1);
			}
		}

		gameBoard[indexI][indexJ] = turn;
		PrintBoard(gameBoard);
//		for (int i = 0; i < 8; i++)
//		{
//			for (int j = 0; j < 8; j++)
//			{
//#pragma region Checking tile directions
//
//				if (gameBoard[3][4] == 1)
//				{
//					//puts("");
//				}
//				nw = CheckNW(gameBoard, i, j, turn, 1);
//				north = CheckNorth(gameBoard, i, j, turn, 1);
//				ne = CheckNE(gameBoard, i, j, turn, 1);
//				east = CheckEast(gameBoard, i, j, turn);
//				se = CheckSE(gameBoard, i, j, turn, 1);
//				south = CheckSouth(gameBoard, i, j, turn, 1);
//				sw = CheckSW(gameBoard, i, j, turn, 1);
//				west = CheckWest(gameBoard, i, j, turn, 1);
//
//#pragma endregion
//
//#pragma region Changing Tile if matches
//
//				if (nw)
//				{
//					ChangeNW(gameBoard, i, j, turn, nw);
//				}
//				if (north)
//				{
//					changeNorth(gameBoard, i, j, turn, north);
//				}
//				if (ne)
//				{
//					ChangeNE(gameBoard, i, j, turn, ne);
//				}
//				if (east)
//				{
//					ChangeEast(gameBoard, i, j, turn, east);
//				}
//				if (se)
//				{
//					ChangeSE(gameBoard, i, j, turn, se);
//				}
//				if (south)
//				{
//					ChangeSouth(gameBoard, i, j, turn, south);
//				}
//				if (sw)
//				{
//					ChangeSW(gameBoard, i, j, turn, sw);
//				}
//				if (west)
//				{
//					ChangeWest(gameBoard, i, j, turn, west);
//				}
//#pragma endregion
//
//
//			}
//		}
		turn = 3 - turn;


	}
}



