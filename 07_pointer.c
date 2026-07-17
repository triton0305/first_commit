#include <stdio.h>

void swap (int *a, int *b);
void changeArray(int *ptr);
int main(void)
{
    /*
    // 포인터 기본
    int minsu = 1234; // 암호
    int *missionMan; // 포인터 변수
    missionMan = &minsu;
    printf("미션맨이 방문하는 곳 주소 : %d, 암호 %d \n", missionMan, *missionMan);

    *missionMan = *missionMan *3;
    printf("미션맨이 방문하는 곳 주소 : %d, 바꾼 암호 %d \n", missionMan, *missionMan);
    printf("미션맨의 주소: %d", &missionMan);
    */

    /*
    //배열과 포인터
    int arr [3] = {5, 10, 15};
    int * ptr = arr;
    for (int i = 0; i<3;i++)
    {
        printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
    }
        for (int k = 0; k<3;k++)
    {
        printf("포인터 ptr[%d] 의 값 : %d\n", k, ptr[k]);
    }

    ptr[0] = 100;
    ptr[1] = 200;
    ptr[2] = 300;

        for (int i = 0; i<3;i++)
    {
        printf("배열 arr[%d] 의 값 : %d\n", i, *(arr + i)); // == printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
    }
        for (int k = 0; k<3;k++)
    {
        printf("포인터 ptr[%d] 의 값 : %d\n", k, *(ptr + k)); // ==printf("포인터 ptr[%d] 의 값 : %d\n", k, ptr[k]);
    }

    printf("arr 자체의 값 : %d \n", arr);
    printf("arr[0]의 주소 : %d\n", &arr[0]);

    printf("arr 자체의 값이 가지는 주소의 실제 값 : %d\n", *arr); // *(arr +0)
    printf("arr[0]의 실제 값 : %d\n", *&arr[0]); // 
    // *& 는 아무것도 없는 것과 같다. &는 주소이며, *는 그 주소의 값이기 때문에
    */

    /*
    // swap 하기
    int a = 10;
    int b = 20;
    printf("a의 주소 : %d\n", &a);
    printf("b의 주소 : %d\n", &b);

    printf("Swap 함수 전 => a : %d, b : %d \n", a, b);
    swap(&a, &b);

    printf("Swap 함수 후 => a : %d, b : %d \n", a, b);
    */

    int arr2[3] = {10, 20 ,30};
    changeArray(&arr2[0]); //changeArray(arr2);
    for (int i = 0; i<3 ; i++)
    {
        printf("%d\n", arr2[i]);
    }

    return 0;

    
}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    
    printf("Swap 함수 내 => a : %d, b : %d \n", *a, *b);
}

void changeArray(int *ptr)
{
    ptr[2] = 50;
}