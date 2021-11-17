#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0;  // 탐색 대상의 시작 인덱스 값
    int last = len - 1; // 탐색 대상의 마지막 인덱스 값
    int mid;

    while (first <= last)
    {
        mid = (first + last) / 2;   // 탐색 대상의 중앙 찾기
        if (target == ar[mid])  // 중앙에 저장된 것이 타겟이라면
        {
            return (mid); // 탐색 완료
        }
        else    // 타겟이 아니라면 탐색 대상을 반으로 줄인다.
        {
            // 값을 하나 빼거나 더해서 저장하지 않으면, mid에 저장된 인덱스 값의 배열 요소도 새로운 탐색의 범위에 포함됨
            if (target < ar[mid])
            {
                last = mid - 1;
            }
            if (target > ar[mid])
            {
                first = mid + 1;
            }
        }
    }
    return (-1);
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
    if(idx == -1)
    {
        printf("failed to search");
    }
    else
    {
        printf("index : %d\n", idx);
    }

    idx = BSearch(arr, sizeof(arr) / sizeof(int), 4);
    if(idx == -1)
    {
        printf("failed to search");
    }
    else
    {
        printf("index : %d\n", idx);
    }

    return (0);
}