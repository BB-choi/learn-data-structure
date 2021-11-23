#include <stdio.h>
#include "ArrayList.h"

void ListInit(List* plist)
{
    (plist -> numOfData) = 0;   // 리스트에 저장된 데이터 수 0
    (plist -> curPosition) = -1;    // 현재 아무 위치도 가리키고 있지 않다
}
void LInsert(List* plist, LData data)
{
    if (plist->numOfData >= LIST_LEN)   // 더이상 저장할 공간이 없다면
    {
        puts("저장이 불가능합니다.");
        return;
    }
    plist -> arr[plist -> numOfData] = data; // 데이터 저장
    (plist -> numOfData)++; // 저장된 데이터 수 증가
}

int LFirst(List* plist, LData* pdata)   // 첫 번째 조회
{
    if (plist -> numOfData == 0)    // 저장된 데이터가 하나도 없다면
        return FALSE;
    (plist -> curPosition)=0;   // 참조 위치 초기화 (첫번째 데이터의 참조)
    *pdata = plist->arr[0];     // pdata가 가리키는 공간에 데이터 저장
    return TRUE;
}

int LNext(List* plist, LData* pdata)    // 두번째 이후의 조회
{
    if(plist -> curPosition >= (plist -> numOfData) - 1)    // 더이상 참조할 데이터가 없다면
        return FALSE;
    (plist->curPosition)++;
    *pdata = plist->arr[plist->curPosition];
    return TRUE;
}

LData LRemove(List* plist)  // 최근 조회가 이루어진 데이터를 삭제한다.
{
    int rpos = plist -> curPosition;    // 삭제할 데이터의 인덱스 값 참조
    int num = plist -> numOfData;
    int i;
    LData rdata = plist -> arr[rpos];   // 삭제할 데이터를 임시로 저장

    // 삭제를 위한 데이터의 이동을 진행
    for (i = rpos; i<num - 1; i++)
    {
        plist -> arr[i] = plist -> arr[i + 1];

    }

    (plist -> numOfData)--;     // 데이터의 수 감소
    (plist -> curPosition)--;   // 참조 위치를 하나 되돌린다.
    return rdata;               // 삭제된 데이터의 반환
}

int LCount(List* plist)
{
    return plist -> numOfData;
}