#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
    // ArrayList의 생성 및 초기화
    List list;
    int data;
    Listinit(&list);

    // 5개의 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d\n", LCount(&list));

    if(LFirst(&list, &data))    // 첫 번째 데이터 조회
    {
        printf("%d", data);
        
        while(LNext(&list, &data))  // 두번째 이후의 데이터를 변수 data에 저장
        {
            printf("%d", data);
        }
    }
}