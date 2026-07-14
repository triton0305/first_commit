#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
    
    /* 나이 받기
    int age;

    printf("May i ask how old you are?  : ");
    scanf("%d", &age);
    */

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

    /*switch(age)
    {
        case 8 : 
        case 9 :
        case 10 :
        case 11 :
        case 12 :
        case 13 : printf("초등학생입니다\n"); break;
        case 14 :
        case 15 :
        case 16 : printf("중학생입니다\n"); break;
        case 17 :
        case 18 :
        case 19 : printf("고등학생입니다\n"); break;
        default : printf("학생이 아닌가봐요\n"); break;

    }
    */


    // 가위바위보
    /* srand(time(NULL));
    int i = rand() %3; // 0~2 반환
    
    switch(i)
    {
        case 0:printf("바위"); break;
        case 1:printf("가위"); break;
        case 2:printf("보"); break;
        default :printf("몰라요\n"); break;
    }

    */


    // up & down

    srand(time(NULL));

    int num = rand() %100 +1; // 1~100
    printf("숫자 : %d\n", num);
    int answer = 0; //정답
    int chance = 5; //기회
    while (chance >0)
    {
        printf("남은 기회 %d 번\n", chance--);
        printf("숫자를 맞춰보세요 (1~100) : ");
        scanf("%d", &answer);

        if (answer > num)
        {
            printf("DOWN ↓\n\n");
        }
        else if(answer < num)
        {
            printf("UP ↑\n\n");
        }
        else if(answer == num)
        {
            printf("정답입니다 ! \n\n");
            break;
        }
        else
        {
            printf("알 수 없는 오류가 발생했어요.\n\n");
        }

        if(chance == 0)
        {
            printf("아쉽게도~~ 기회를 다 사용하셨네요~~\n\n");
            break;
        }
    }




    return 0;
}