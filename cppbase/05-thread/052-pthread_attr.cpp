#include <iostream>
#include <unistd.h>
using namespace std;

int main(){
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    size_t stacksize = -1;
    void *stack_addr = nullptr;
    // 获取缺省的堆栈地址和大小
    pthread_attr_getstack(&attr, &stack_addr, &stacksize);
    cout << "default stack addr: " << stack_addr << endl;
    cout << "default stack size: " << stacksize << endl;
    
    void *stackAddr = nullptr;
    //获取linux页大小
    int paseSize = getpagesize();
    // 设置的堆栈大小
    int size = paseSize * 2;
    cout << "paseSize: " << paseSize << endl;
    posix_memalign(&stackAddr, paseSize, size);
    // 设置新的堆栈地址和大小
    pthread_attr_setstack(&attr, stackAddr, size);
    // 获取当前堆栈地址和大小
    pthread_attr_getstack(&attr, &stack_addr, &stacksize);
    cout << "new stack addr: " << stack_addr << endl;
    cout << "new stack size: " << stacksize << endl;
    
    pthread_attr_destroy(&attr);
    return 0;
}