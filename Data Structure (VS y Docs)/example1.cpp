#include <iostream>

int maximum(int a, int b){
    return a>b? a:b;
};
double maximum(double a, double b){
    return a>b? a:b;
};
int main(){
    int res;
    double resD;
    res = maximum(3,2);
    resD = maximum(3.6,3.2);
};