#include "header.h"
#include <math.h>

bool is_triangle(int num){
    int n;
    n=std::sqrt(num*2);
    int expected=n*(n+1);
    if (expected==num*2) {
        return true;
    } else {
        return false;
    }
}
bool is_power(int num){
    int n = 2;
    float pow_num=float(1)/float(n);
    float res_num=pow(num,pow_num);
    while (res_num>=2) {;
        if (res_num-int(res_num)<1e-3) {
            return true;
        }
        n++;
        pow_num=float(1)/float(n);
        res_num=pow(num,pow_num);
    }
    return false;
}

int cal_socs(int m, int n){
   int sum_m = (2*m-1)*(m-1)*m/6;
   int sum_n = (2*n+1)*n*(n+1)/6;
   int res = sum_n-sum_m;
   return res;
}

bool is_socs(int num){
    for (int m=1; m<=sqrt(double(num)); m++) {
        for (int n=m+1; n<=sqrt(double(num)); n++) {
            int sum = cal_socs(m, n);
            if (sum==num) {
                return true;
            }
        }
    }
    return false;
}

bool is_abundant(int num){
    int sum=1;
    for (int i = 2; i <= num/2; ++i) {
       float divided;
       divided=float(num)/float(i);
       if (divided-int(divided)<1e-10) {
           sum+=i;
       }
    }
    if (sum>num) {
        return true;
    }else{
        return false;
    }
}

int main(int argc, char *argv[])
{
    int num, property;
    cin>>num>>property;
    bool pass;
    switch (property) {
        case 1: pass=is_triangle(num);break;
        case 2: pass=is_power(num);break;
        case 3: pass=is_socs(num);break;
        case 4: pass=is_abundant(num);break;
        default: break;
    }
    cout<<pass<<endl;
}
