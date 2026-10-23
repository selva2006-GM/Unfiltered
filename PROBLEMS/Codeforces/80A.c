
#include <stdio.h>


bool prime(int n){

    if(n < 2) return false;
    if(n == 2)return true;
    if(n % 2 == 0)return false;

    for(int i = 3; i <= n / i; i += 2){
        if(n % i == 0){
            return false;
        }
    }

    return true;
}

int main(){

    int n;
    int m;

    scanf("%d %d", &n , &m);
    while(!prime(++n));
   
    printf((m == n) ?"YES" : "NO");
    return 0;


}