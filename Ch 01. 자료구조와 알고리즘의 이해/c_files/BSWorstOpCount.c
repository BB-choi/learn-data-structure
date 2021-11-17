#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0;
    int last = len - 1;
    int mid;
    int opCount = 0;    // 비교 연산의 횟수를 기록

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (target == ar[mid])
        {
            return (mid);
        }
        else
        {
            if (target < ar[mid])
            {
                last = mid - 1;
            }
            else
            {
                first = mid + 1;
            }
            opCount++;  // 비교연산 횟수 1 증가
        }
    }
    printf("count : %d\n", opCount);    // 탐색 실패시 연산 횟수 출력
    return (-1);
}

int main(void)
{
    // 모든 요소 0으로 배열 초기화
    int arr1[500] = {0, };
    int arr2[5000] = {0, };
    int arr3[50000] = {0, };
    int idx;

    // 배열 arr1을 대상으로, 저장되지 않은 정수 1 찾기
    idx = BSearch(arr1, sizeof(arr1) / sizeof (int), 1);
    if (idx == -1)
    {
        printf("failed to search\n\n");
    }
    else
    {
        printf("idx : %d\n", idx);
    }

    // 배열 arr2을 대상으로, 저장되지 않은 정수 2 찾기
    idx = BSearch(arr2, sizeof(arr2) / sizeof (int), 2);
    if (idx == -1)
    {
        printf("failed to search\n\n");
    }
    else
    {
        printf("idx : %d\n", idx);
    }

    // 배열 arr3을 대상으로, 저장되지 않은 정수 3 찾기
    idx = BSearch(arr3, sizeof(arr3) / sizeof (int), 3);
    if (idx == -1)
    {
        printf("failed to search\n\n");
    }
    else
    {
        printf("idx : %d\n", idx);
    }
    return (0);
}