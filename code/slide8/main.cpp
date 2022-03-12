#include "header.h"

int fibo(int x){
    if (x>2){
        return(fibo(x-1)+fibo(x-2));
    }else{
        return 1;
    }
}
int fibo3(int x){
    if (x>3){
        return(fibo3(x-1)+fibo3(x-2)+fibo3(x-3));
    }else{
        return 1;
    }
}

int main(){
    int result=0;
    result=fibo3(5);
    cout<<result<<endl;
    return result;
}
