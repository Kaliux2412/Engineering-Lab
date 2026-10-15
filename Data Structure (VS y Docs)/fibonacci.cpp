#include <iostream>
using namespace std;

long fibonacci(long n){
     if (n == 0 || n==1){
        return 1;
    }
    else{
        return fibonacci(n-2)+ fibonacci(n - 1);

    };
}

int main(){
    long resultado;
    resultado = fibonacci(50);
    std::cout<<"The fibonacci is "<< resultado<<std::endl;
}