#include <stdio.h>

// 순차 탐색 알고리즘 적용된 함수
int Lsearch(int ar[], int len, int target)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (ar[i] == target)
            return i;   // 찾은 대상의 인덱스 값 반환
    }
    return  -1; // 찾지 못했음을 의미하는 값 반환
}

int main(void)
{
    int arr[] = {3, 5, 2, 4, 9};
    int idx;

    idx = Lsearch(arr, sizeof(arr) / sizeof(int), 4);
    if (idx == -1)
        printf("failed to search");
    else
        printf("index : %d \n", idx);
    
    idx = Lsearch(arr, sizeof(arr) / sizeof(int), 7);
    if (idx == -1)
        printf("failed to search");
    else
        printf("index : %d \n", idx);

    return 0;
}