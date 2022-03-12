#ifndef ADD_H
#define ADD_H
#include <iostream>
#include <ostream>
using std::cin;
using std::cout;
using std::endl;
int min(int a,int b){
    if (a>b) {
        return b;
    }else{
        return a;
    }
}
int max(int a,int b){
    if (a<b) {
        return b;
    }else{
        return a;
    }
}
#endif

