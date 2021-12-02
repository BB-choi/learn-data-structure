# 06. Stack

## 👩‍🏫 Stack
**후입선출 방식의 자료구조**  
- **LIFO** : **L**ast **I**n **F**irst **O**ut  
- `top`: stack의 가장 위를 가리키는 포인터 변수 (가장 최근에 저장된 data를 가리킴)
## 👩‍🏫 ADT
- `StackInit` : stack의 초기화
- `IsEmpty` : stack이 비었으면 1 / 아니면 0
- `Push` : stack에 **data 저장**
- `Pop` : stack의 `top`이 가리키는 **data 반환**(반환된 data는 stack에서 **제거**됨)
- `Peek` : stack의 `top`이 가리키는 **data 반환**(stack에서 삭제하지 않음)


## 👩‍🏫 배열 기반의 Stack
배열의 0번 인덱스가 스택의 바닥이 됨  
- `Push` : `top`을 한 칸 위로 올리고, `top`이 가리키는 위치에 **data 저장**
- `Pop` : `top`이 가리키는 **data를 반환**하고, `top`을 아래로 한 칸 내림

## 👩‍🏫 연결 리스트 기반의 Stack
data의 추가와 삭제가 list의 head에서 이루어짐  
- `Push` : list의 첫부분에 newNode 추가 (추가된 newNode를 head가 가리키게 함)
- `Pop` : head가 가리키는 노드를 반환하고 삭제

💡*배열과 리스트 모두 선형 자료구조이기 때문에 기능적인 부분만 고려한다면 서로 교체가 가능하다*  

## 👩‍🏫 수식의 표기법
> - 중위 표기법 (infix notation) : ( 1 + 2 ) * 7
> - 전위 표기법 (prefix notation) : * + 1 2 7
> - 후위 표기법 (postfix notation) : 1 2 + 7 *

ex) 계산기 프로그램  
계산기 사용자 : 중위 표기법으로 수식 입력  
계산기 : 수식을 전위 표기법 또는 후위 표기법으로 변환하여 계산  

### 전위 / 후위 표기법을 사용하는 이유
1. 연산자의 우선순위 알 필요가 없음
2. 소괄호 처리 불필요
=> 계산기 구현이 훨씬 수월함!
