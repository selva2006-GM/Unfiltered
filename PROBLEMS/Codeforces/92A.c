#include <stdio.h>

int main(){

    int n;
    int chips;

    scanf("%d %d", &n, &chips);

    while(true){
        for(int i = 1; i <= n ;i++){
            if(chips < i || chips == 0){
                printf("%d", chips);
                return 0;
            }
            chips -= i;
        }
    }
    return 0;
}