#include <stdio.h>

// from 위치에 있는 원반을 by를 거쳐서 to로 이동
void HanoiTowerMove(int num, char from, char by, char to)
{
    if (num == 1)   // 이동할 원반의 수가 1개인 경우
    {
        printf("원반 1을 %c에서 %c로 이동 \n", from, to);
    }
    else
    {
        HanoiTowerMove(num - 1, from, to, by); // 1단계
        printf("원반 %d를(을) %c에서 %c로 이동\n", num, from, to);  // 2단계
        HanoiTowerMove(num - 1, by, from, to);  // 3단계
    }
}

int main(void)
{
    // 막대 A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기
    HanoiTowerMove(3, 'A', 'B', 'C');
    return (0);
}