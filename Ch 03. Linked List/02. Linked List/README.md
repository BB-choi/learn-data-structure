# 04. LinkedList

## 04 - 1. LinkedList의 개념적인 이해

**필요할 때마다 Node를 생성해서 data를 저장하고 배열처럼 연결(next) => `동적 할당 배열`**

### 👩‍🏫 Node
LinkedList에서 사용되는 변수 형태 (구조체)
```
typedef struct _node
{
  int data;             // data 공간
  struct _node * next;  // 다음 변수의 주소
} Node;
```

- `head` : list의 시작 node를 가리키는 포인터 변수
- `tail` : list의 마지막 node를 가리키는 포인터 변수
- `node` : 다음 node를 가리키는 포인터 변수
- `cur` : data search에 사용되는 포인터 변수  
( 초기 상태에서는 모두 `NULL`을 가리킴 )

### 👩‍🏫 Data Insert
`newNode`가 list의 마지막에 들어가는 상황
1. 노드 생성 및 초기화 `newNode`
2. if 첫번째 노드, `head` -> `newNode`
3. 기존 마지막 노드의 `next` -> `newNode`
4. `tail` -> `newNode`

```
while(1)
{
  // 1-1. 노드 생성(메모리 동적 할당)
  newNode = (Node*)malloc(sizeof(Node));
  // 1-2. 초기화 (데이터 저장 / next -> NULL)
  newNode->data = realData;
  newNode->next = NULL:

  // 2. 첫번째 노드라면 head -> 새로 생성한 노드
  if(head == NULL)  // 이전에 생성된 노드가 없었다면 head -> NULL인 상태
    head = newNode;

  // 3. 마지막 노드의 next -> 새로 생성한 노드
  //    (마지막 노드는 tail이 가리키고 있는 상태)
  else
    tail->next = newNode;

  // 4. tail->마지막 노드(새로 생성한 노드)
  tail = newNode;
}
```
### 👩‍🏫 Data Search
**`cur = cur->next;`**

`cur`이 list의 `head`부터 `tail`까지 순차적으로 모든 노드를 가리키면서 Search

```
if(head != NULL)
{
  // 1. head부터 시작
  cur = head;

  while(cur->next != NULL)    // 다음 노드가 존재하면
  {
    // 2. 다음 노드 조회
    cur = cur->next;
  }
}
```
### 👩‍🏫 Data Delete
list 전체를 삭제하는 상황 (`head`부터 `tail`까지 순차적으로 삭제)

1. delete에 사용할 포인터 변수 선언  
    `delNode` : 삭제할 노드를 가리키는 포인터 변수  
    `delNextNode` : 삭제할 노드의 다음 노드를 가리키는 포인터 변수  
2. `delNode`는 `head`부터 `tail`까지 순차적으로 삭제 (`free`)  
  `delNextNode`는 다음에 삭제할 노드를 가리킴

```
if(head == NULL)   // 삭제할 list 없음
  return 0;
else
{
  // 1. 포인터 변수 선언
  Node * delNode = head;            // list의 시작부터
  Node * delNextNode = head->next;  // delNode의 다음부터

  // 2. 삭제
  free(delNode);                    // malloc으로 할당한 동적 메모리 공간이므로 free 사용해서 메모리 해제

  // 3. 다음 노드가 존재한다면 list가 끝날때까지 순차적으로 삭제
  while(delNextNode != NULL)
  {
    delNode = delNextNode;            // 삭제할 노드
    delNextNode = delNextNode->next;  // 그 다음 노드
    free(delNode);
  }
}
```

- **`delNextNode`의 존재 이유**
> `delNode`가 가리키고 있는 노드를 삭제하고 나면 list에서 그 다음 노드를 순차적으로 삭제해야 하는데,  
> 해당 노드가 삭제되면 `next` 포인터도 사라지므로 그 다음 노드를 찾을 수 없다.  
> 따라서 `delNextNode`가 다음 노드를 가리켜서 list의 끝까지 `delete`를 수행할 수 있도록 한다.


data를 insert / search / delete 할 때, 해당 노드가 첫번째 노드이냐 아니냐에 따라 방법에 차이가 있었음을 기억해라!

## 04 - 2. ADT
### Singly Linked List
연결 형태가 **한쪽 방향**으로 전개되고 **시작과 끝**이 분명히 존재하는 **Linked List**

### 정렬 기능이 추가된 list 자료구조의 ADT (Ch.03)
```
// LinkedList의 정렬 기준을 지정하기 위한 함수
void setSortRule(List *plist, int (*comp)(Ldata d1, LData d2));
```
### 새 노드를 추가할 때 head vs tail
**head**  
`장점` 포인터 변수 tail이 불필요  
`단점` 저장된 순서를 유지하지 않음(앞에서부터 하나씩 다 밀림)  

**tail**  
`장점` 저장된 순서가 유지됨  
`단점` 포인터 변수 tail이 필요   

### 👩‍🏫 Dummy Node 기반의 Singly Linked List
*insert / search / delete 시, 해당 노드가 첫번째냐 아니냐에 따라 방법이 달라지는 단점을 극복하고자 함*
#### how to
> - 노드를 `head`에서부터 채워넣음 => `tail`이 없어짐
> - list 맨 앞에 `Dummy node` 존재

**`Dummy node`: 유효한 data를 지니지 않는 빈 노드**  
빈 노드를 list 맨 앞에 넣어두면 구조상 유효한 노드들이 두번째부터 시작되므로, insert / search / delete 과정을 일관된 형태로 구성 가능.

#### Linked List 구조체
```
typedef struct _linkedList
{
  Node * head;                      // dummy node를 가리킴
  Node * cur;                       // 참조 및 삭제를 도움
  Node * before;                    // 삭제를 도움
  int numOfData;                    // 저장된 데이터의 수를 기록
  int (*comp)(LData d1, LData d2);  // 정렬의 기준을 등록
} LinkedList;
```
**구조체를 사용해야 하는 이유**  
구조체를 사용하지 않는다면 list마다 head, cur 포인터 변수를 별도로 선언해줘야함.  
만약 다수의 list가 필요한 상황이라면 매번 필요한 포인터 변수를 선언해야하므로 불편하다.

#### 👩‍🏫 Initialize

`head`와 `head`가 가리키는 `dummynode`까지 생성된 상태
```
void ListInit(List * plist)
{
  plist->head = (Node*)malloc(sizeof(Node));  // dummy node 생성
  plist->head->next = NULL;
  plist->comp = NULL;                         // NULL로 초기화
  plist->numOfData = 0;                       // 0으로 초기화
}
```
#### 👩‍🏫 Insert  
정렬기준(`comp`)이
- 없다면 => `head`에 노드 추가 => `FInsert`
- 있다면 => 정렬기준에 맞춰서 노드 추가 => `SInsert`

**FInsert 함수**  
*list의 맨 앞에 노드를 추가하는 함수 (`dummynode` 제외)*
##### how to
>1. insert할 `newNode` 생성
>2. `newNode`에 data 저장
>3. `newNode`가 list의 첫노드를 가리키게 함(`dummy node` 제외)
>4. `dummy node`가 `newNode`를 가리키게 함
>5. list의 노드 갯수 증가시킴
```
void FInsert(List * plist, LData data)
{
  // 1. 생성 2. 데이터 저장
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  // 3. 포인터 정리
  newNode->next = plist->head->next;
  plist->head->next = newNode;

  // 4. 노드 갯수 증가
  (plist->numOfData)++;
}
```

#### 👩‍🏫 Search
`cur` : 현재 노드를 가리키는 포인터 변수  
`before` : `cur`보다 하나 이전의 노드를 기리키는 포인터 변수 (delete시에 필요함)  

**LFirst 함수**  
*`cur`이 list의 첫번째 노드를 가리키게 하는 함수 (`dummy node` 제외)*  
```
plist->before = plist->head;    // before : dummy node 가리킴
plist->cur = plist->head->next; // cur : 유효한 첫번째 노드 가리킴
```
**LNext 함수**  
*`cur`이 다음 노드를 가리키게 하는 함수*  
```
plist->before = plist->cur;     // before : cur가 가리키던 것을 가리킴
plist->cur = plist->cur->next;  // cur : 다음 노드 가리킴
```

#### 👩‍🏫 Delete
**LRemove 함수**  
*`cur`이 가리키고 있는 데이터를 삭제하는 함수*   

`rpos` : 소멸대상의 주소(`cur`이 가리키고 있는 노드의 주소)  
`rdata` : 소멸대상의 데이터(`cur`이 가리키고 있는 노드의 데이터)  

**how to**  
>1. 소멸대상인 노드를 `rpos`에 저장  
>2. `cur`이 가리키고 있는 노드를 리스트에서 제거 (연결된 포인터를 끊는 방식)  
>3. `cur`의 위치를 제거된 노드 이전 위치로 재조정 (`before` 사용!)  
>4. `rpos` 노드 소멸(`free`), 노드 수 감소(`numOfData`)  

## 04 - 3. Sort Insert
1. 정렬 기준을 `comp`에 등록 (`setSortRule` 함수 호출)  
2. `SInsert` 함수에서 `comp`에 등록된 정렬기준대로 `data`를 정렬하여 저장  

### 👩‍🏫 SInsert
**how to**  
1. 새 노드 생성 후 데이터 저장  
    - `newNode` : 생성된 새 노드  
    - `pred` : 새 노드가 들어갈 위치의 이전 노드를 가리킴  
2. `comp`에 저장된 정렬기준에 따라 `newNode`가 들어갈 위치 찾음 (`pred`를 이동시킴)  
3. 해당 위치에 `newNode` 삽입 (포인터로 list 연결)  
4. list의 노드 수 증가 (`numOfData`)  


*`pred`가 가리키는 노드를 `dummy node`처럼 취급하면, `SInsert`의 작동방식은 `newNode`를 list의 처음에 삽입하는 것이라고 생각할 수 있다.*  

#### 정렬 기준에 따른 `newNode` 삽입 위치 찾기
```
//     1. list가 안끝났고     2. newNode가 들어갈 위치를 못찾았으면
while(pred->next != NULL && plist->comp(data, pred->next->data) != 0)
{
  pred = pred->next;   // 이 위치가 아니니 다음 노드로 이동
}
```
1. `pred->next != NULL` : `pred`가 마지막 노드를 가리키는게 아닌지
2. `plist->comp(data, pred->enxt->data) != 0` : `newNode`와 `pred`의 다음 노드의 우선순위 비교  
    - `comp == 0`  
        : **newNode**가 **pred의 다음 노드**보다 **앞**에 위치해야함
    - `comp == 1`  
        : **newNode**가 **pred의 다음 노드**보다 **뒤**에 위치해야함
