#ifndef ADD_H
#define ADD_H
#include <iostream>
#include <ostream>
using namespace std;
const int MAXELTS=100;

class IntSet{
    int elts[MAXELTS];
    int numElts;
    int indexOf(int v);
    public:
        IntSet();
        void insert(int v);
        void remove(int v);
        bool query(int v);
        int size();
};

class anInt{
    int v;
    public:
        int get_value();
        void set_value(int newVal);
};
#endif

