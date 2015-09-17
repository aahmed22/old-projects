/* A program that simulates a calculator
design by Abdulhameed Ahmed. */

#include <iostream>
using namespace std;

int main()
{
	char symbol = '0';
	double number1, number2;
	int num1,num2;
	while ( symbol != '$')
	{
		cout << " Choose an operation: *,+,-,/,%,^ or $ to exit" << endl;
		cin >> symbol;

		if (symbol == '$')
			break;
		
		if (symbol == '*')
		{
		  cout << "Please enter the first number " << endl;
		  cin >> number1;
		  cout << "Plese enter the second number " << endl;
		  cin >> number2;
		  cout << " Your product is: " << (number1 * number2) << endl;

		}

		if (symbol == '+')
		{
			cout << "Please enter the first number " << endl;
		    cin >> number1;
		    cout <<"Please enter the second number " << endl;
		    cin >>number2;
		    cout << " Your sum is: " << (number1 + number2) << endl;
		}
		
		if (symbol == '-')
		{
			cout << "Please enter the first number " << endl;
		    cin >> number1;
		    cout << "Please enter the second number " << endl;
		    cin>> number2;
		    cout << "Your difference is: " << (number1 - number2) << endl;
		}
		
		if (symbol == '/')
		{
			cout << "Please enter the first number " << endl;
			cin >> number1;
			cout << "Please enter the second number " << endl;
			cin >> number2;
			while (number2 == 0)
			{
				cout << " Please enter a number other than zero " << endl;
				cin >> number2;
			}
			cout << " Your quotient is " << (number1 / number2) << endl;
		}

		if (symbol == '%')
		
		{
			cout << "Please enter the first number " << endl;
			cin >> num1;
			cout << "Please enter the second number " << endl;
			cin >> num2;
			
			while (num2 == 0)
			{
				cout << " Please enter a number other than zero" << endl;
				cin >> num2;
			}
			int result=num1%num2;
			cout << " Your modulus result is " << result<< endl;
		}

		if (symbol == '^')
		{
			cout << "Please enter the base " << endl;
			cin >> number1;
			cout << "Please enter the exponent " << endl;
			cin >> number2;
			
			double result = 1;
			if (number2 == 0)
				cout << " The exponential result is " << result << endl;
			else
			{
				while (number2 > 0)
				{
					result *= number1;
					number2 -= 1;
				}
				cout << " The exponential result is " << result << endl;
			}
		}
		else
			continue;
			
		}

	}