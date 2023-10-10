#include <iostream>
#include <stdlib.h>
#include <thread>
#include <pthread.h>
#include <vector>

using namespace std;

/**
  9   template<class InputIt, class Function>
 10    inline Function parallel_fun(InputIt first, InputIt last, Function f)
 11    {
 12         pthread_t threads[4];
 14       for (int i=0; first != last; ++first) {
 16          pthread_create(&threads[i], nullptr,f , nullptr);
 18           i++;
 19        }
 21      for (int i=0; i<4;i++) {
 23          pthread_join(threads[i],nullptr);
 26        }
 31    return f;
 32   }
*/
template<class InputIt, class Function>
Function parallel_fun(InputIt first, InputIt last, Function f)
{
    thread threads[4];
    for (int i=0; first != last; ++first)
    {
        threads[i] = thread(f);
        i++;
    }
    for (int i=0; i<4;i++)
    {
        threads[i].join();
    }
    return f;
}


int main()
{
    int z=90;
    vector<int> a(4);
    a[0]=1; a[1]=2;
    [&]() { cout<< "test" << z << endl;};
    // parallel_fun(a.begin(), a.end(), [&]() { cout<< "test" << z << endl;} );
}