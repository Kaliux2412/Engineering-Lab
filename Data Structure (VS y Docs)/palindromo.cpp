#include <iostream>

bool palindrome(, int i, int f){
    int l = sizeof(str);
    int i = 0;
    int f = l;
    if (str[i] != str[f]){
        return false;
    }else{
        palindrome(str,i-1,f-1);
    }
};

int main(){
    int resultado;
    resultado = palindrome("radar",1,5);
    std::cout<<"palindromo "<< resultado<<std::endl;

}
