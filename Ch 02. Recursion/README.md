# 02. 재귀(Recursion)

## 02 - 1. 함수의 재귀적 호출의 이해

### 👩‍🏫 재귀함수

함수 내에서 자기 자신을 다시 호출하는 함수

```
void Recursive(void)
{
  printf("Recursive call! \n");
  Recursive();    // 나 자신을 재호출
}
```

-   **호출 구조** : 함수가 호출되면 해당 함수의 복사본을 만들어서 실행

#### 재귀함수의 탈출조건

재귀함수의 탈출조건이 성립되면 복사본 생성을 멈추고 함수가 반환하기 시작

```
void Recursive(int num)
{
  if (num <= 0)   // 탈출조건이 없으면 재귀를 빠져나오지 못함
    return;
  printf("Recursive calll! %d \n", num);
  Recursive(num-1);
}
```
***
## 02 - 2. 재귀의 활용

### 👩‍🏫 피보나치 수열: Fibonacci Sequence

수열의 n번째 값 = 수열의 n-1번째 값 + 수열의 n-2번째 값
```
0 1 1 2 3 4 8 13 21 34 55 89 144 233 ...
```
### 👩‍🏫 이진 탐색 알고리즘의 재귀적 구현
**반복 패턴**
1. 탐색 범위의 중앙에 목표값이 저장되었는지 확인
2. 저장되지 않았다면 탐색 범위를 반으로 줄여서 다시 탐색 시작 => `재귀`

**탐색 실패 (탈출 조건)**

`first > last`
- first : 탐색의 시작범위
- last : 탐색의 끝

```
int BSearchRecur(int ar[], int first, int last, int target)
{
  int mid;
  if(first > last)            // 탈출 조건
    return -1;                // 탐색 실패

  // 1. 탐색 범위의 중앙에 목표값이 저장되었는지 확인

  mid = (first + last) / 2;   // 탐색 대상의 중앙 찾음
  if(ar[mid] == target)
    return mid;               // 탐색된 타켓의 인덱스

  // 2. 저장되지 않았다면 탐색 범위를 반으로 줄여서 다시 탐색 => 재귀

  else if(target < ar[mid])
    return BSearchRecur(ar, first, mid-1, target);
  else
    return BSearchRecur(ar, mid+1, last, target);
}
```
***
## 02 - 3. 하노이 타워 : The Tower of Hanoi
하나의 막대(A)에 쌓여있는 원반을 다른 하나의 원반(C)에 그대로 옮기는 방법

> - 원반은 한번에 하나씩만 옮길 수 있다.
> - 작은 원반의 위에 큰 원반이 올라갈 수 없다.

**반복 패턴 및 해결법**

```
// num개의 원반을 by(B)를 거쳐서 from(A)에서 to(C)로 이동한다
void HanoiTower(int num, char from, char by, char to)
{
  ....
}
```

1. 작은 원반 n-1를 A에서 B로 이동
`HanoiTowerMove(num-1, from, to, by);`
2. 큰 원반 1개를 A에서 C로 이동
`printf("원반 %d을 %c에서 %c로 이동\n", num, from, to);`
3. 작은 원반 n-1개를 B에서 C로 이동
`HanoiTowerMove(num-1, by, from, to);`
