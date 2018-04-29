INSTRUCTIONS FOR RUNNING THE LIBRARY.


1) Create a 1mfile using : truncate -s  1G 1mfile
2) Create a libmymem.o : g++ -c libmymem.cpp -o libmymem.o -std=c++11
3) Create a shared Library : g++ -Wall -Werror -fpic -c libmymem.o -I . libmymem.cpp -std=c++11
4) Link to shared library : g++ -shared -o libmymem.so libmymem.o
5) Export path : export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.
6) Running memutil.cpp : g++ -I . -L . -Wall -o memutil memutil.cpp -l mymem -lpthread -std=c++11
7) Running program :  ./memutil -n 5 -t 4
