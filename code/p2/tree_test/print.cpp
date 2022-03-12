#include "header.h"
#include <list>

void print_list(std::list<int> mylist){
    std::list<int> copylist(mylist);
    std::list<int>::iterator p;
    for (p = copylist.begin(); p!=copylist.end(); p++) {
        cout<<*p<<" ";
    }
    cout<<endl;
}

