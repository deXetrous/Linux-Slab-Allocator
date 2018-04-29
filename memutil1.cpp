#include <thread>
#include <time.h>
#include <chrono>
#include "libmymem.hpp"

/* This functions take command line argument as the no of iterations for which we have
to allocate a random generated size, sleep for random time and free the allocated memory*/
int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "The no of arguments specified is incorrect"<< endl;
        exit(1);
    }
    int n;
    n = atoi(argv[2]);
	srand(time(NULL));

    for(int i = 0;i < n ;i++)
    {
        // randomly generate a size to be allocated ranging from 1-8192
        int sizeGen = rand() % 8192 + 1;

        printf("Calling mymalloc..allocating %d \n", sizeGen);
        // allocating the size
        void* ptr = mymalloc(sizeGen);
        memset(ptr,'1',sizeGen);

        //randomly generated time to sleep between allocation and free
		int sleepTime = rand() % 1000 + 1;
		this_thread::sleep_for(chrono::milliseconds(sleepTime)); // simulate a thread executing in CS

        printf("Calling myfree..deallocating %d \n", sizeGen);
        // deallocating the pointer
		myfree(ptr);

    }
  
	return 0;

}