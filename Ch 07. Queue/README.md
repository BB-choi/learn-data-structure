#  Queue

## Queue의 이해

- 큐(Queue)는 선입선출의 자료구조 (First-In, First-Out)

## Queue의 ADT
- 핵심연산 :  `enqueue`, `dequeue` 
```c
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);
```

## Queue의 배열기반 구현

배열 기반의 큐에서는 '`원형 큐(circular queue)`'형태로 queue를 구현한다.

👉 큐의 머리(F, Front)와 큐의 꼬리(R, Rear)를 회전시켜서 큐를 구성하는 배열을 효율적으로 사용

### 원형 큐(Circular queue)

큐가 꽉 찬 경우나 텅 빈 경우 모두 F가 R보다 한 칸 앞선 위치를 가리키게 된다. 따라서, F와 R의 위치만으로는 큐가 꽉 찬 경우와 텅 빈 경우를 구별 할 수 없다.

✔ 배열의 길이가 N이라면, 데이터의 수가 `N - 1` 일 때, 꽉 찬 것으로 간주한다.


1. 큐가 `처음 생성`(Init)되어 텅 빈 경우에는 F와 R이 **같은 위치**를 가리킨다. 
2. 데이터를 추가(`enqueue`)하면, `R`이 가리키는 위치를 **한 칸 이동**시키고, `R`이 가리키는 위치에 데이터를 **저장**한다.
3. `dequeue` 연산시 `F`가 가리키는 위치를 **한 칸 이동**시킨 후, F가 가리키는 위치에 저장된 데이터를 **반환** 및 **소멸**한다.

<p align="center"><img src="./images/1.png" alt="원형 큐"><br>윤성우 저, 열혈 자료 구조</p>

👉 구현할 큐의 특성

- 원형 큐가 텅 빈 상태 : `F`와 `R`이 동일한 위치를 가리킨다.
- 원형 큐가 꽉 찬 상태 : `R`이 가리키는 위치의 앞을 `F`가 가리킨다.

### 원형 큐의 구현

[CirculularQueue.h](./files/CircularQueue.h) / 
[CirculularQueue.c](./files/CircularQueue.c) / 
[CirculularQueueMain.c](./files/CircularQueueMain.c)