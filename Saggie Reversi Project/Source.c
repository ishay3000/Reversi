#pragma warning(disable:4996)
#include <stdio.h>
#include "ReversiFuncs.h"
#include <Windows.h>
#include <stdlib.h>
//#include <unistd.h>


char happy[] = { 0xe2, 0x98, 0xba };  /* U+263A */

int main()
{
#pragma region comments
	//SetConsoleCP(437);
	//SetConsoleOutputCP(437);
	////SetConsoleCP(437);
	////SetConsoleOutputCP(437);
	////char c = (char)0x2022;
	//char c = 9675;

	//printf("%s\n", (char)157);

	//system("CHCP 1252");
	//system("cls");
	//printf("Now accents are right: áéíüñÇ  \n");


	//write(1, happy, 3);
	//puts("");
#pragma endregion

#pragma region comments begin game
	/*int turn = 1, indexI = 0, indexJ = 0, fl = 1;


	int gameBoard[][8] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0 }
	};


	PrintBoard(gameBoard);

	while (indexI != -999)
	{
	fl = 1;

	while (fl == 1)
	{
	printf("It's player %d's turn!\n", turn);
	printf("Enter a location, separated by a space:\n");
	scanf("%d %d", &indexI, &indexJ);
	indexI -= 1;
	indexJ -= 1;
	if (gameBoard[indexI][indexJ] == 0)
	{
	fl = 0;
	}
	else if (gameBoard[indexI][indexJ] == (3 - turn))
	{
	printf("[%d], [%d] is already occupied by player %d !\n", indexI + 1, indexJ + 1, 3 - turn);
	}
	}

	gameBoard[indexI][indexJ] = turn;
	PrintBoard(gameBoard);
	turn = 3 - turn;
	}*/

#pragma endregion

	int gameBoard[][8] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 2, 0, 0, 0 },
			{ 0, 1, 2, 2, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		};

	BeginGame(gameBoard);



	system("pause");

	return 0;
}