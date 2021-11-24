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
}
```
`head` : list의 시작 node를 가리키는 포인터 변수
`tail` : list의 마지막 node를 가리키는 포인터 변수
`node` : 다음 node를 가리키는 포인터 변수
`cur` : data search에 사용되는 포인터 변수
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
`cur`이 list의 `head`부터 `tail`까지 순차적으로 모든 노드를 가리키면서 Search ( index 접근은 불가 )
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
  //    delNode는 list의 시작부터
  Node * delNode = head;
  //    delNextNode는 delNode의 다음 노드부터
  Node * delNextNode = head->next;

  // 2. 삭제
  //    malloc으로 할당한 동적 메모리 공간이므로 free 사용해서 메모리 해제
  free(delNode);

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
>`delNode`가 가리키고 있는 노드를 삭제하고 나면 list에서 그 다음 노드를 순차적으로 삭제해야 하는데, 해당 노드가 삭제되면 `next` 포인터도 사라지므로 그 다음 노드를 찾을 수 없다.
>따라서 `delNextNode`가 다음 노드를 가리켜서 list의 끝까지 `delete`를 수행할 수 있도록 한다.

## 04 - 2. ADT

## 04 - 3. Sort Insert
