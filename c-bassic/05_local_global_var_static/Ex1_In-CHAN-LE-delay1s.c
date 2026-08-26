#include <stdio.h>
#include <time.h>

void delay(int number_of_seconds)
{
	// Converting time into milli_seconds
	int milli_seconds = 1000 * number_of_seconds;

	// Storing start time
	clock_t start_time = clock();

	// looping till required time is not achieved
	while (clock() < start_time + milli_seconds)
		;
}

void printChanLe(void)
{
    static int count = 0;
    count = 1 - count;// Nếu = 0, in ra 1; Nếu = 1 in ra 0
    
    if(count == 0)
    {
        printf("CHAN\n");
    }
    
    else
    {
        printf("LE\n");
    }
}

int main ()
{
    while(1)
    {
        printChanLe();
        delay(1);
    }
}