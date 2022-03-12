#include "header.h"
#include <string>

bool isRed(Suit_t s){
    switch (s){
        case DIAMONDS:
        case HEARTS:
            return true;
            break;
        case CLUBS:
        case SPADES:
            return false;
            break;
        default:
            assert(0);
            break;
    }
}
const std::string suitname[]={"clubs","diamonds","hearts","spades"};

int main(){
    Suit_t suit=DIAMONDS;
    cout<<"suit is "<<suitname[suit]<<endl;
    if (isRed(suit)){
        cout<<"Is Red"<<endl;
    }else{
        cout<<"Not Red"<<endl;
    }
    return 0;
}
