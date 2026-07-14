#include <stdio.h>

int main(void){
    /*int age;

    printf("May i ask how old you are?  : ");
    scanf("&d", &age);*/

    // elementary(8-13) / middle(14-16) / high (17-19)
    // if / else if/ else
    
    /*if (age >= 8 && age <=13){
        printf("you are a elementary school student");
    }
    else if (age >= 14 && age <= 16){
        printf("you are a middle school student");
    }
    else if (age >= 17 && age <= 19){
        printf("you are a high school student");
    }
    else {
        printf("you are no longer a student");
    }*/


    // break / continue
    // 1번부터 30번까지 있는 반에서 1번에서 5번까지 조별발표

    for (int i=1;i<=30;i++){
        if (i>=6){
            printf("나머지 학생은 come back 하세요.^,^\n");
            break;
        }
        printf("%d번 학생은 조별 발표를 준비하세요.\n", i);
    }




    return 0;
}