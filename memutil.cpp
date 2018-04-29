#include <thread>
#include <time.h>
#include <chrono>
#include "libmymem.hpp"



void threadmain(vector<int> objectlist, int iterations, int id)
{
	for(int i = 0; i < iterations; i++)
	{
        // randomly generating a size to be allocated
		int a = rand()%12;
		int size = objectlist[a];
        printf("Thread : %d calling mymalloc..allocating size %d \n", id, size);
		void* ptr = mymalloc(size);
        memset(ptr,'1',size);
		int sleepTime = rand() % 1000 + 1; // get random CS Time
		this_thread::sleep_for(chrono::milliseconds(sleepTime)); // simulate a thread executing in CS

        printf("Thread : %d calling myfree.. freeing size %d\n", id, size);
		myfree(ptr);
	}
}

/* This functions take command line argument as the no of threads and the no of iterations 
for which each thread would allocate a random generated size, sleep for random time and free
 the allocated memory */
int main(int argc, char* argv[])
{
    if(argc != 5)
    {
        cout << "The no of arguments specified is incorrect"<< endl;
        exit(1);
    }

    /* n denotes the number of iterations of alloc-write-sleep-free per each thread.
     and t denotes the no of thread*/
    int n,t;
    n = atoi(argv[2]);
    t = atoi(argv[4]);
	srand(time(NULL));
    

    thread threads[t];
    vector <int> obsizelist;
    // creating an objectsizelist containing values ranging from 4B to 8192B
    for(int i = 0; i < 12; i++)
    	obsizelist.push_back(pow(2, i + 2));
    for(int i = 0; i < t; i++)
    {
    	threads[i] = thread(threadmain, obsizelist, n,i); 
    }

    for(int i = 0;i<t;i++)
		threads[i].join();

	return 0;
  


}