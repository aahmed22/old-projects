/* MAT 375 Operating Systems
   Project 1
   By AbdulHameed Ahmed. */
#include <iostream>
#include <Windows.h> // Necessary to Access the Windows API, which contains Windows Data Types and Functions.
using namespace std;

/* Function prototype, description below:
   The function prototype has a return type of DWORD. DWORD is a 32 bit unsigned integer.
   Next to DWORD is WINAPI, which is the calling convention for system functions. 
   Finally the function outPutPrime's parameter takes in an argument of type LPVOID, 
   LPVOID is a pointer to any type. */
DWORD WINAPI outPutPrime( LPVOID );

const int HOLDER = 1;

int main()
{

	int number;

	cout << "Please enter a number greater than 1: ";
	cin >> number;

	// Set a condition in case the user tries to enter an invalid value.
	while( number <= HOLDER )
	{
		cout << "Error!!! Enter a number greater than 1: ";
		cin >> number;
	}

	// Created the ThreadID which is of type DWORD.
	DWORD ThreadID;

	/* Created ThreadHandle which is of type HANDLE, HANDLE is a handle to an object.
	   CreateThread() is a function that creates a thread to execute within the 
	   virtual address space of the calling process. */
	/* Within the CreateThread Parameter are the following arguments:
	   Parameter 1: Null //  Default security attributes.
	   Parameter 2: 0   // Default stack size.
	   Parameter 3: outPutPrime  // Thread function.
	   Parameter 4: &number     //  Parameter to thread function.
	   Parameter 5: 0          //   Default creation flag.
	   Parameter 6: &ThreadID //    Returns the thread identifier. */
	HANDLE ThreadHandle = CreateThread( NULL, 0, outPutPrime, &number, 0, &ThreadID );


	if( ThreadHandle != NULL )
	{
		/* WaitForMultipleObjects() is a function that waits until one or all
		   of the specified objects are in the signaled state or the time-out
		   interval elapses. */
		WaitForSingleObject( ThreadHandle, INFINITE );

		//ClosedHandle closes an open object handle.
	   // In this case it closes ThreadHandle.
		CloseHandle( ThreadHandle );
	}


	system("pause");

	return 0;
}

/* The thread runs in this seperate function. Now the function outPutPrime takes in an argument and prints
   all of the prime numbers up to that arugument's value. If the value itself happens to be a prime number,
   it will also be INCLUDED in the print. However if the argument's value is NOT A PRIME NUMBER, then it 
   will be EXCLUDED from the print. */
DWORD WINAPI outPutPrime( LPVOID value )
{
	bool flag;

	for( int i = 2; i <= *(DWORD*)value; i++ )
	{
		for( int j = 2; j <= *(DWORD*)value; j++ )
		{
			if( ( i != j ) && ( i % j  == 0 ) )
			{
				flag = false;
				break;
			}
			else
				flag = true;
		}

		if( flag )
			cout << i << " is a Prime number! " << endl;
	}

	return (DWORD)value;
}