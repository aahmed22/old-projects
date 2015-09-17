//Exercise 5.33.
//By AbdulHameed Ahmed.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int flip(void);

int main()
{
	srand(time(0));

	int heads = 0;
	int tails = 0;

	int i = 1;
	while(i <= 100)
	{
		if(flip() == 0)
		{
			cout << "Heads" << endl;
			heads++;
		}
		else
		{
			cout << "Tails" << endl;
			tails++;
		}
	i++;
	}
	
	cout << "Head count:" << heads << endl;
	cout << "Tail count:" << tails << endl;

	return 0;
}

int flip(void)
{
	return rand() % 2;
}