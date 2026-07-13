#include <stdio.h>

int main(void){
   
    int n;
    printf("층수를 입력하세요 : ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        for(int j = n; j>i; j--){
            printf(" ");
        }
        for(int k = 1; k <= i*2 - 1;k++){
            printf("*");
        }
        printf("\n");
    }
    
    
    return 0;
}