#include <stdio.h>
#include <time.h>
// 다시해야함..

int main(void)
{
    /*
    float arr_f[5] = {1.0f, 2.0f, 3.0f};
    for (int i = 0 ; i < 5; i++)
    {
        printf("%.2f\n", arr_f[i]);
    }
    */
    /*  string
    char c = 'A';
    printf("%c\n", c);

    //문자열 끝에는 '끝'을 의미하는 NULL 문자 '\0'이 포함되어야 함. [\0]
    //아니면 이상한 문자가 출력되어 버림
    //char str[6] = "coding"; // [c][o][d][i][n][g]
    char str[7] = "string";
    printf("%s\n", str);

    char stri[] = "coding";
    printf("%s\n", stri);
    printf("%d\n", sizeof(stri));
    */

    srand(time(NULL));
    printf("\n\n === 아빠는 대머리 게임 === \n\n");
    int answer; // 사용자 입력값
    int treatment = rand() %4 ; // 발모제 선택 (0~3)
    int cntShowBottle = 0; // 이번 게임에 보여줄 병 갯수
    int prevCntShowBottle = 0; // 앞 게임에 보여준 병 갯수
    // 서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음에 2개 -> 다음엔 3개 ...)

    // 3번의 기회 (3번의 발모제 투여 시도)
    for (int i=1; i<=3; i++)
    {   
        int bottle[4] = { 0, 0, 0, 0};//4개의 병
        do{
            cntShowBottle = rand() %2 +2; // 보여줄 병 갯수 (0~1, +2 -> 2, 3)
        } while (cntShowBottle == prevCntShowBottle);
        prevCntShowBottle = cntShowBottle;
        int isIncluded = 0; // 보여줄 병 중에 발모제가 포함되었는지 여부
        printf("> %d 번째 시도 : ", i);
        // 보여줄 병 종류를 선택
        for (int j=0; j<cntShowBottle; j++)
        {
            int randBottle = rand() %4; //0~3

            // 아직 선택되지 않은 병이면, 선택처리
            if (bottle[randBottle] == 0)
            {
                bottle[randBottle] = 1;
                if (randBottle == treatment)
                {
                    isIncluded = 1;
                }
            }
            // 이미 선택된 병이면, 중복이므로 다시 선택
            else
            {   
                j--;
            }

        }
         for (int k = 0; k<4; k++)
        {
        if (bottle[k] == 1)
        {
                printf(" >> 성공 ! 머리가 났어요 !!\n");
        }
        else
        {
                printf(" >> 실패 ! 머리가 나지 않았어요.. ㅠㅠ \n");
        }
        getchar();
        }
    }


    printf("\n\n 발모제는 몇 번일까요? ");
    scanf("%d", &answer);
    if (answer == treatment+1)
    {
        printf("\n >>> 정답입니다!!\n");
    }
    else
    {
        printf("\n >>> 실패했습니다 정답은 %d 입니다.\n", treatment+1);
    }


    return 0;
}