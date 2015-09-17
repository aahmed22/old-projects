/* MAT 375 Operating Systems
   Project 2
   By AbdulHameed Ahmed. */
#include <iostream>
#include <cstdlib> // Needed for the rand and srand functions.
#include <ctime> // Needed for the time function.
#include <fstream> // Needed for file handling and processing.
#include <Windows.h> // Necessary to Access the Windows API, which contains Windows Data Types and Functions.
using namespace std;

#define MAX_THREADS 2 // Creating two threads.
#define BUFFER 15  // Initialize the buffer size to 15.

/* Function prototypes, description below:
   DWORD : 32 bit unsigned integer.
   WINAPI : Calling convention for system functions.
   LPVOID : A pointer to any type.
   producer is a function design to input random numbers inside the buffer.
   consumer is a function design to retrieve those numbers from the buffer. */
DWORD WINAPI producer(LPVOID);
DWORD WINAPI consumer(LPVOID);

// CS is an object of type CRITICAL_SECTION.
static CRITICAL_SECTION CS;

// globa_Array is a global array of type int. Its size is 15 because BUFFER is defined as 15.
int global_Array[BUFFER];

int main()
{
	//Initializing the critical section before entering multi-threads section.
	InitializeCriticalSection(&CS);

	// Created an array called threadID which is of type DWORD.
	DWORD threadID[MAX_THREADS];

	// Created an array called hTHREADS, which is of type HANDLE.
	// HANDLE is a handle to an object.
	HANDLE hTHREADS[MAX_THREADS];

	/* The array hTHREADS has a size of MAX_THREADS. MAX_THREADS in this case is defined
	   as 2. Thus hTHREADS has a size of 2. CreateThread() is a function that creates a 
	   thread to execute within the virtual address space of the calling process. */
	hTHREADS[0] = CreateThread(NULL, 0, producer, global_Array, 0, &threadID[0]);

	hTHREADS[1] = CreateThread(NULL, 0, consumer, global_Array, 0, &threadID[1]);


	/* WaitForMultipleObjects function waits until one or all is specified objects are in
	   the signaled state or the time-out interval elpses. */
	WaitForMultipleObjects(MAX_THREADS, hTHREADS, TRUE, INFINITE);


	/* ClosedHandle closes an open object handle. In this case we are using a for 
	   loop and basically counting how many threads exist, then closing their handles. */
	for(int i = 0; i < MAX_THREADS; i++)
		CloseHandle(hTHREADS[i]);

	// Release system object when all operations finish.
	DeleteCriticalSection(&CS);

	system("pause");
	return 0;
}


/* The first thread is called producer. The producer objective is first to enter the critical section
   and run the random number generator. Once the numbers are generated the producer second objective is
   stores the numbers inside the global array as well as it's own output file called producer.txt.
   Once this operation is successful, the producer exits the critical Section. */
DWORD WINAPI producer(LPVOID x)
{
	EnterCriticalSection(&CS);
	srand(time(0));
	
	ofstream outputFile("producer.txt");
	int random;

	{
		for(int i = 0; i < BUFFER; i++)
		{
			random = rand() % BUFFER + 1;
			global_Array[i] = random;
			cout << "Producer stores number in buffer: " << global_Array[i] << endl;
			outputFile << "Producer stores number in buffer: " << global_Array[i] << endl;
		}
	}

	LeaveCriticalSection(&CS);

	return (DWORD)x;
}


/* The second thread is called consumer. The consumer objective is simply to retrieve the generated 
   numbers from the global array and print those number's inside its own ouput file called consumer.txt.
   The consumer CANNOT enter the critical section if the producer is currently in the critical section. 
   Once the producer finally exits the critcal section, then the consumer can enter the critical section 
   and retrieve the data. */
DWORD WINAPI consumer(LPVOID y)
{
	EnterCriticalSection(&CS);

	ofstream outputFile("consumer.txt");

	{
		for(int j = 0; j < BUFFER; j++)
		{
			cout << "Consumer retrives number from buffer: " <<global_Array[j] << endl;
			outputFile << "Consumer retrieves number from buffer: " <<global_Array[j] << endl;
		}
	}


	LeaveCriticalSection(&CS);

	return (DWORD)y;
}