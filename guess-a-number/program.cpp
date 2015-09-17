/* The following program is the game
called " Guess a Number " designed by Abdulhameed Ahmed */
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNum(int, int);

int main()
{
	char play = 'y';
	int guess;
	int x;
	int start_number = 1;
	int end_number = 1000;
	srand(time(0));
	while (play == 'y')
	{
		
        x = getRandomNum( start_number, end_number );

		cout << " You are now playing: 'Guess a Number' " << endl;
		cout << " Please guess a number between 1 and 1000. " << endl;
		cin >> guess;
		
		while (guess != x)
		{
			if (guess > x)
			{cout << " Guess is to high. Guess Again: ";
			cin >> guess;
			}
			if (guess < x)
			{	cout << " Guess is to low. Guess Again: ";
			cin >> guess;
			}
			if (guess == x)
				cout << "Congratulations!!! Your guess is correct!!! "<<endl;
		}

		cout << " Would you like to play again(y or n)? ";
		cin >> play;
	}
}

	int getRandomNum(int s, int e)
	{
		int number = ( s + rand() % e );
			return number;
	}