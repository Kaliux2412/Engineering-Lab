#include <iostream>

template <typename T>
T maximum (T a, T b){
    return a>b?a:b;
};

int main(){
    int res;
    double resD;
    res =  maximum(3,2);
    resD = maximum(3.6,3.2);
    std::cout<<"The maximum is "<< res<<std::endl;
    std::cout<<"The maximum is "<< resD<<std::endl;
}