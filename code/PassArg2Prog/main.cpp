#include "header.h"
#include <cstdlib>

int main(int argc, char *argv[]){
    int sum=0;
    for (int i=1; i<argc; i++) {
        sum+=atoi(argv[i]);
    }
    cout<<sum<<endl;
    return 0;
}
