#include <stdio.h>

int main(void){
    int age;

    printf("May i ask how old you are?  : ");
    scanf("&d", &age);

    // if (조건) {  ...  }  else {   ...   }
    // if (age >= 20){
    //     printf("일반인 입니다.");
    // }

    // else{
    //     printf("학생입니다");
    // }

    // elementary(8-13) / middle(14-16) / high (17-19)
    // if / else if/ else
    
    if (age >= 8 && age <=13){
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
    }


    return 0;
}