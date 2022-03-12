#include "header.h"
int plus_one(int x){
	return (x+1);
}

int plus_two(int x){
	return (plus_one(x)+1);
}

int main(){
	int result=0;
	cin>>result;
	result=plus_two(result);
	cout<<result<<endl;
	return 0;
}
