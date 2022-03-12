#include "header.h"
#include <utility>

int anInt::get_value(){
    return v;
}
void anInt::set_value(int newVal){
    v=newVal;
}



int IntSet::indexOf(int v){
   for(int i=0; i<numElts; i++){
        if (elts[i]==v) return i;
   }
   return MAXELTS;
}
bool IntSet::query(int v){
    return (indexOf(v)!=MAXELTS);
}
void IntSet::insert(int v){
    if (indexOf(v)==MAXELTS){
        if (numElts==MAXELTS) throw MAXELTS;
        elts[numElts++]=v;
    }
}
int IntSet::size(){
    return numElts;
}
void IntSet::remove(int v){
    int victim=indexOf(v);
    if (victim!=MAXELTS){
        elts[victim]=elts[numElts-1];
        numElts--;
    }
}
IntSet::IntSet():numElts(0){}
void add_one(anInt *ip){
    ip->set_value(ip->get_value()+1);
}
int main(){
    IntSet set1;
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.query(2);
    int numOfSet;
    numOfSet=set1.size();
    set1.remove(2);
}
