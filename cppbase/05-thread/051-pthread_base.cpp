#include <iostream>
#include <unistd.h>

using namespace std;

void *func(void *t)
{
    int arg = *((int *)t);
    cout << "Sleeping in thread " << endl;
    sleep(1);
    cout << "Thread with arg: " << arg << endl;
}

int main()
{
    int arg = 10;
    pthread_t thread;

    int result = pthread_create(&thread, nullptr, func, (void *)&arg);
    if (result)
    {
        cout << "unable to create thread: " << result << endl;
        exit(-1);
    }

    // 阻塞主线程，等待子线程执行结束
    pthread_join(thread, nullptr);
    cout << "Main: program exiting." << endl;
    return 0;
}
