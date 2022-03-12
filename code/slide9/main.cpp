#include "header.h"

int main(){
    int (*foo)(int,int);
    int result1,result2;
    foo=min;
    result1=foo(1,5);
    foo=max;
    result2=foo(2,6);
    return 0;
}
