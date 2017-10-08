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

typedef struct Results
{
	int playerOneScore;
	int PlayerTwoScore;
}GameResults;
static int playerOneCount = 0;
static int playerTwoCount = 0;

static GameResults gameResults;
static GameResults* ptr = &gameResults;

#pragma region Printing The Board

void PrintBoard(int matrixBoard[][8], int IsPlayerSkipped)
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
	ptr->playerOneScore = score1;
	ptr->PlayerTwoScore = score2;
	printf("\t\t\t\t"ANSI_COLOR_RED"player 1: [%d]"ANSI_COLOR_RESET"\n", score1);
	printf("\t\t\t\t"ANSI_COLOR_GREEN"player 2: [%d]"ANSI_COLOR_RESET"\n", score2);
	//printf(ANSI_COLOR_RED"%c"ANSI_COLOR_RESET"\n", (char)178); => idea for future changing tiles look
	
	if (IsPlayerSkipped == 1)
	{
		printf("Player 1 was skipped due to no available moves...\n");
	}
	else if (IsPlayerSkipped == 2)
	{
		printf("Player 2 was skipped due to no available moves...\n");
	}

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

#pragma region Checking all the 0 tiles every round
//Checking each round whether there are moves left for either players
void CheckAllTiles(int gameBoard[8][8])
{
	int nw, north, ne, east = 0, se, south, sw, west;
	int turn = 1, fl = 1;

	//Iterating over all of the empty tiles to see if there are any moves left for the players
	for (int indexI = 0; indexI < 8 && fl == 1; indexI++)
	{
		for (int indexJ = 0; indexJ < 8; indexJ++)
		{
			//Only check if it's an empty tile
			if (gameBoard[indexI][indexJ] == 0)
			{
				//Only checking for player one if the counter equals zero.
				//Also, for efficiency, only checking neccessary directions; 
				//i.e: if we found ne equals more than 0, than we stop, and don't check all the other directions
				if (playerOneCount == 0)
				{
					//Checking the directions from the tile, 
					nw = CheckNW(gameBoard, indexI, indexJ, turn, 0);
					if (nw > 0)
					{
						playerOneCount += nw;

					}
					else
					{
						ne = CheckNE(gameBoard, indexI, indexJ, turn, 0);
						if (ne > 0)
						{
							playerOneCount += ne;

						}
						else
						{
							north = CheckNorth(gameBoard, indexI, indexJ, turn, 0);
							if (north > 0)
							{
								playerOneCount += north;

							}
							else
							{
								east = CheckEast(gameBoard, indexI, indexJ, turn, 0);
								if (east > 0)
								{
									playerOneCount += east;

								}
								else
								{
									se = CheckSE(gameBoard, indexI, indexJ, turn, 0);
									if (se > 0)
									{
										playerOneCount += se;

									}
									else
									{
										south = CheckSouth(gameBoard, indexI, indexJ, turn, 0);
										if (south > 0)
										{
											playerOneCount += south;

										}
										else
										{
											sw = CheckSW(gameBoard, indexI, indexJ, turn, 0);
											if (sw > 0)
											{
												playerOneCount += sw;

											}
											else
											{
												west = CheckWest(gameBoard, indexI, indexJ, turn, 0);
												if (west > 0)
												{
													playerOneCount += west;

												}
											}
										}
									}
								}
							}
						}
					}
				}

				//Now we're doing the same for player 2
				turn = 2;
				if (playerTwoCount == 0)
				{
					//Checking the directions from the tile, 
					nw = CheckNW(gameBoard, indexI, indexJ, turn, 0);
					if (nw > 0)
					{
						playerTwoCount += nw;

					}
					else
					{
						ne = CheckNE(gameBoard, indexI, indexJ, turn, 0);
						if (ne > 0)
						{
							playerTwoCount += ne;

						}
						else
						{
							north = CheckNorth(gameBoard, indexI, indexJ, turn, 0);
							if (north > 0)
							{
								playerTwoCount += north;

							}
							else
							{
								east = CheckEast(gameBoard, indexI, indexJ, turn, 0);
								if (east > 0)
								{
									playerTwoCount += east;

								}
								else
								{
									se = CheckSE(gameBoard, indexI, indexJ, turn, 0);
									if (se > 0)
									{
										playerTwoCount += se;

									}
									else
									{
										south = CheckSouth(gameBoard, indexI, indexJ, turn, 0);
										if (south > 0)
										{
											playerTwoCount += south;

										}
										else
										{
											sw = CheckSW(gameBoard, indexI, indexJ, turn, 0);
											if (sw > 0)
											{
												playerTwoCount += sw;

											}
											else
											{
												west = CheckWest(gameBoard, indexI, indexJ, turn, 0);
												if (west > 0)
												{
													playerTwoCount += west;

												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//Outside inner for loop
		if (playerOneCount > 0 && playerTwoCount > 0)
		{
			//Tell the outer for loop to stop executing
			fl = 0;
		}
	}
}
#pragma endregion



void BeginGame(int gameBoard[8][8], int playerSkipNumber)
{
	int turn = 1, indexI = 0, indexJ = 0, fl = 1, winner = 0;

	//from left to right: 
	//North West
	//Nort
	//North East
	//East
	//South East
	//South
	//South West
	//West
	int nw = 0, north = 0, ne = 0, east = 0, se = 0, south = 0, sw = 0, west = 0;


	PrintBoard(gameBoard, 0);

	while (fl < 3)
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
			printf("Enter a location, separated by a space:\n");
			scanf("%d %d", &indexI, &indexJ);

			indexI -= 1;
			indexJ -= 1;

			//-1000 for stopping because we decrement 1
			if (indexI == -1000)
			{
				fl = 3;
				printf("Quitting game...\n");
			}
			else if (indexI > 7 || indexJ > 7 || indexI < 0 || indexJ < 0)
			{
				printf("Invalid Values\n");
			}
			else
			{
				nw = CheckNW(gameBoard, indexI, indexJ, turn, 0);
				ne = CheckNE(gameBoard, indexI, indexJ, turn, 0);
				north = CheckNorth(gameBoard, indexI, indexJ, turn, 0);
				east = CheckEast(gameBoard, indexI, indexJ, turn, 0);
				se = CheckSE(gameBoard, indexI, indexJ, turn, 0);
				south = CheckSouth(gameBoard, indexI, indexJ, turn, 0);
				sw = CheckSW(gameBoard, indexI, indexJ, turn, 0);
				west = CheckWest(gameBoard, indexI, indexJ, turn, 0);


				if (gameBoard[indexI][indexJ] == 0)
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
		}

		if (fl < 3)
		{
			//if we got here, it means that we've successfuly conquered tile(s)
			//thus we assign the starting input tile our turn's value
			gameBoard[indexI][indexJ] = turn;

			//Blank the counters for the next round's check
			playerOneCount = 0;
			playerTwoCount = 0;

			CheckAllTiles(gameBoard);

			//if no more moves for both players, then quit the game
			if (playerOneCount == 0 && playerTwoCount == 0)
			{
				fl = 4;
			}
			//if only player 1 is out of moves and this is player two's turn
			//then skip player 1's turn
			else if (playerOneCount == 0 && turn == 2)
			{
				playerSkipNumber = 1;
				fl = 0;
			}
			//if only player two is out of moves and it's player 1's turn
			//then skip player 2's turn
			else if (playerTwoCount == 0 && turn == 1)
			{
				playerSkipNumber = 2;
				fl = 0;
			}
			//if both players have moves left, then continue as usual
			else
			{
				turn = 3 - turn;
			}

			PrintBoard(gameBoard, playerSkipNumber);

		}
	}

	printf("Game Over !\n");
	if (fl == 4)
	{
		printf("No more moves for both players.\n");
	}

	printf("Results:\n\n");
	//1 = player 1
	//2 = player 2
	//3 = a tie
	winner = (ptr->playerOneScore > ptr->PlayerTwoScore ? 1 : ptr->playerOneScore == ptr->PlayerTwoScore ? 3 : 2);

	switch (winner)
	{
	case 1:
		printf("#1: "ANSI_COLOR_RED"Player 1, score: %d"ANSI_COLOR_RESET"\n", ptr->playerOneScore);
		printf("#2: "ANSI_COLOR_GREEN"Player 2, score: %d"ANSI_COLOR_RESET"\n", ptr->PlayerTwoScore);
		break;
	case 2:
		printf("#1: "ANSI_COLOR_GREEN"Player 2, score: %d"ANSI_COLOR_RESET"\n", ptr->PlayerTwoScore);
		printf("#2: "ANSI_COLOR_RED"Player 1, score: %d"ANSI_COLOR_RESET"\n", ptr->playerOneScore);
		break;
	case 3:
		printf(ANSI_COLOR_YELLOW"It's a tie, both players have reached a score of: %d"ANSI_COLOR_RESET"\n", ptr->playerOneScore);
		break;
	default:
		break;
	}
}