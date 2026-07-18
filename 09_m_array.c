#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// 10마리의 서로 다른 동물 ( 각 카드 2장씩 )
// 사용자로부터 2개의 입력값을 받아서 -> 같은 동물 찾으면 카드 뒤집기
// 모든 당물 쌍을 찾으면 게임 종료
// 총 실패 횟수 알려주기

int arrayAnimal[4][5];  // 전체 카드 20장
int checkAnimal[4][5];  // 뒤집혔는지 여부 확인
char *strAnimal[10];  /// 10개의 공간 배열을 만드는데 거기에 들어가는 게 포인터라는 거


void initAnimalArray();
void initAnimalname();
void shuffleAnimal();
int getEmptyPosition();
int conv_pos_x(int x);
int conv_pos_y(int y);
void printAnimals();
void printQuestion();
int foundAllAnimals();
int main(void)
{
    srand(time(NULL));

    initAnimalArray();
    initAnimalname();

    shuffleAnimal();

    int failCount = 0; // 실패횟수

    while(1)
    {
        int select1 = 0;  // 사용자가 선택한 수 1
        int select2 = 0;  // 사용자가 선택한 수 1

        printAnimals(); // 동물 위치 출력
        printQuestion(); // 문제 출력( 카드 지도 )
        printf("뒤집을 카드를 2개 고르세요 : ");
        scanf("%d %d", &select1, &select2);

        if (select1==select2) // 같은 카드 선택시 무효
        { 
            continue;
        }

        //.. 좌표에 해당하는 카드를 뒤집어 보고 같은지 안같은지 확인
        int firstSelect_x = conv_pos_x(select1);
        int firstSelect_y = conv_pos_y(select1);

        int secondSelect_x = conv_pos_x(select2);
        int secondSelect_y = conv_pos_y(select2);

        if ((checkAnimal[firstSelect_x][firstSelect_y]==0)
            && (checkAnimal[secondSelect_x][secondSelect_y]==0) // 카드가 뒤집히지 않았는지 && 두 동물이 같은지
        && (arrayAnimal[firstSelect_x][firstSelect_y]==arrayAnimal[secondSelect_x][secondSelect_y]))
        {
            printf("\n\n빙고!  :  %s 발견 \n\n", strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            checkAnimal[firstSelect_x][firstSelect_y] = 1;
            checkAnimal[secondSelect_x][secondSelect_y] = 1;
        }
        else
        {
            printf("\n\n땡!(틀렸거나, 이미 뒤집힌 카드입니다)\n\n");
            printf("%d : %s\n", select1, strAnimal[arrayAnimal[firstSelect_x][firstSelect_y]]);
            printf("%d : %s\n", select2, strAnimal[arrayAnimal[secondSelect_x][secondSelect_y]]);
            printf("\n\n");
            failCount++;  // line(31)
        }
        if (foundAllAnimals()==1)
        {
            printf("\n\n 축하합니다 ! 모든 동물을 다 찾았네요 \n");
            printf("지금까지 총 %d 번 실수하셨습니다", failCount);
            break;
        }
    }

    return 0;
}



void initAnimalArray()
{
    for (int i = 0; i < 4; i++)
    {   for (int j = 0; j < 5; j++)
        {
            arrayAnimal[i][j] = -1;
        }
    }
}

void initAnimalname()
{
    strAnimal[0] = "원숭이";
    strAnimal[1] = "하마";
    strAnimal[2] = "강아지";
    strAnimal[3] = "고양이";
    strAnimal[4] = "돼지";

    strAnimal[5] = "코끼리";
    strAnimal[6] = "기린";
    strAnimal[7] = "낙타";
    strAnimal[8] = "타조";
    strAnimal[9] = "호랑이";
}

void shuffleAnimal()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int pos = getEmptyPosition();
            int x = conv_pos_x(pos);
            int y = conv_pos_y(pos);
            
            arrayAnimal[x][y] = i;
        }
    }
}

// 좌표에서 빈공간 찾기
int getEmptyPosition()
{
    while(1)
    {
        int randPos = rand() % 20; // 0~19 사이의 숫자 반환
        int x = conv_pos_x(randPos);
        int y = conv_pos_y(randPos);

        if (arrayAnimal[x][y] == -1)
        {
            return randPos;
        }
    }
    return 0;
}

//  ㅁ ㅁ ㅁ ㅁ ㅁ        0  1  2  3  4
//  ㅁ ㅁ ㅁ ㅁ ㅁ        5  6  7  8  9
//  ㅁ ㅁ ㅁ ㅁ ㅁ        10 11 12 13 14 
//  ㅁ ㅁ ㅁ ㅁ ㅁ        15 16 17 18 19

int conv_pos_x(int x)
{
    return x / 5;
}
int conv_pos_y(int y)
{
    return y % 5 ;
}

void printAnimals()
{   
    printf("\n===== 이건 비밀인데.. 몰래 보여줍니다 ====\n\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0 ; j < 5 ; j++)
        {   // 8 byte 의 공간 확보
            printf("%s\t", strAnimal[arrayAnimal[i][j]]);  // arrayAnimal 에는 0~9까지의 수가 2개씩 저장되어있다. void shuffleAnimal()
        }
        printf("\n");
    }
    printf("\n==============================\n\n");
}
void printQuestion()
{
    printf("\n\n(문제)\n\n");
    int seq = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0 ; j < 5 ; j++)
        {   
            if(checkAnimal[i][j] != 0) // 카드를 뒤집어서 정답을 맞혔으면 '동물 이름'
            {
                printf("%s\t", strAnimal[arrayAnimal[i][j]]);
            }
            else  // 아직 뒤집지 못했으면 (정답을 못맞혔으면) 뒷면 - > 위치를 나타내는 숫자
            {
                printf("%d\t", seq); 
            }
            seq++;
        }
        printf("\n");

    }
}
int foundAllAnimals()
{
    for (int i= 0 ; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (checkAnimal[i][j]==0)
            {
                return 0;
            }
        }
    }
    return 1; //다 찾음
}
