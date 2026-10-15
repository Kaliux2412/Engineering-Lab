#include <iostream>

int longpower(int base, int n){
    if (n==0){
        return 1;
    }
    else{
        return base * longpower(base,n-1);
    };
}

int main(){
    int power;
    power = longpower(2,6);
    std::cout<<"The long power is "<< power<<std::endl;

}