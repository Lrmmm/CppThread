#include <iostream>
#include <stdio.h>
#include <pthread.h>
using namespace std;

void* factor(void* x)
{
    int n = *(int*)x;
    cout << n << endl;
    int res = 1;
    while (n != 0)
        res *= (n--);
    
    return new int(res);

}

int main() {


    pthread_t myThread;
    int n;
    cin >> n ;
    void *p;
    pthread_create(&myThread,NULL,factor,(void*)&n);

    pthread_join(myThread,&p);
    cout <<"The result = " <<*(int*)p<<endl;

    return 0;
}