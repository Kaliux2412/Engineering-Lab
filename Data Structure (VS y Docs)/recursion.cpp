#include <iostream>

int longfactorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        return n *longfactorial(n - 1);

    };
};

int main(){
    int resultado;
    resultado = longfactorial(5);
    std::cout<<"The factorial is "<< resultado<<std::endl;

}
