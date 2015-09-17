//Project 1.
//Simulation: The Tortoise and the Hare.
//By AbdulHameed Ahmed.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void moveTortoise(int *);

void moveHare(int *);

void movespace(int *, int *);

int main()
{
	srand(time(0));
	enum Status {CONTINUE, WON, TIE};

	Status gameStatus=CONTINUE;

	

	int tortoise = 1;
	int hare = 1;

	cout << "BANG!!!!!!!!!!!" << endl;
	cout << "AND THEY'RE OFF!!!!!!!!!!!!!" << endl;

	while (gameStatus == CONTINUE)
	{
		moveTortoise(&tortoise);
		moveHare(&hare);
		movespace(&tortoise, &hare);

		if ((tortoise >= 70) && (hare >= 70))
		{
			cout << "It;s a tie..." << endl;
		    gameStatus = TIE;
		}

		else if ((tortoise >= 70) && (hare < 70))
		{
			cout << "TORTOISE WINS!!! YAY!!!" << endl;
			gameStatus = WON;
		}
		else if ((hare >= 70) && (tortoise < 70))
		{
			cout << "HARE WINS!!! YUCH!" << endl;
		    gameStatus = WON;
		}
	
	}

}

void moveTortoise(int *pT)
{
	int position = 1 + rand() % 10;

	if ((position >= 1) && (position <= 5))
		*pT += 3;

	if ((position >= 6) && (position <= 7))
		*pT -= 6;

	if ((position >= 8) && (position <= 10))
		*pT += 1;

	if (*pT < 1)
		*pT = 1;
}

void moveHare (int *pH)
{
	int position = 1 + rand() % 10;

	if((position >= 1) && (position <= 2));

	
    if((position >= 6) && (position <= 7))
		*pH += 9;

	if(position <= 1)
		*pH -= 12;

	if((position >= 3) && (position <= 5))
		*pH += 1;

	if((position >= 8) && (position <= 9))
		*pH -= 2;

	if(*pH < 1)
		*pH = 1;
}

void movespace (int *pA, int *pB)
{
	for(int space = 0; space <= 70; space++)
	{
		if((space == *pA) && (space != *pB))
			cout << 'T';
		else if ((space != *pA) && (space == *pB))
			cout << 'H';
			
		else if ((space == *pA) && (space == *pB))
			cout << "OUCH!!!";
		else
		cout << '.';
	}
	cout << endl;

}
