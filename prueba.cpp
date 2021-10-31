#include <iostream>
#include <pthread.h>
using namespace std;

void *printHola(void* a){
    cout << "Hola desde la funcion creada" << (intptr_t)a <<endl;
    pthread_exit(NULL);
    return 0;
}

int main()
{
    cout << "hola" << endl;
    long a = 5;
    pthread_t thread;
    int status = pthread_create(&thread,NULL,printHola, (void *)(intptr_t)a);
    if (status != 0)
    {
        cout << "F la weaita"<< endl;
    }
    else
    {
        cout << "funciono la weaita"<< endl;
    }
    pthread_join(thread,NULL);
    string g;
    cout << "input para comprobar que el codigo funciona" << endl;
    cin>> g;

    
    return 0;
}


//compilar:
//    g++ prueba.cpp -o prueba -std=c++11 -pthread