# 배열을 이용한 리스트

리스트 `!=` 연결리스트

## 리스트

-   **순차 리스트**

    배열을 기반으로 구현된 리스트

-   **연결 리스트**

    메모리의 동적 할당을 기반으로 구현된 리스트

-   리스트 자료구조의 특성

    > ✔ 데이터를 나란히 저장 <br>
    > ✔ 중복된 데이터의 저장을 막지 않는다.

## 리스트의 ADT

리스트의 ADT : 리스트 자료구조가 제공해야할 기능들

`void ListInit(List* plist);`

-   초기화 할 리스트의 주소 값을 인자로 전달, 리스트 생성 후 가장 먼저 호출되어야 하는 함수

`void LInsert(List* plist, LData data);`

-   리스트에 데이터를 저장, 매개변수 data에 전달된 값을 저장

`int LFirst(List* plist, LData* pdata);`

-   첫 번째 데이터가 pdata가 가리키는 메모리에 저장
-   데이터의 참조를 위한 초기화 진행
-   성공 TRUE(1), 실패 FALSE(0) 반환

`int LNext(List* plist, LData* pdata);`

-   참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
-   순차적인 참조를 위해서 반복호출 가능
-   참조 새로 시작 시 LFirst함수 호출
-   성공 TRUE(1), 실패 FALSE(0) 반환

`LData LRemove(List* plist);`

-   LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제
-   삭제된 데이터를 return
-   마지막 반환 데이터를 삭제하므로 연이은 반복호출을 허용하지 않는다.

`int LCount(List\* plist);`

-   리스트에 저장되어 있는 데이터의 수를 반환

## 리스트의 ADT를 기반으로 정의된 main 함수

[ListMain.c](./files/ListMain.c)

### LNext와 LFirst

`LNext` 함수를 호출시 다음에 저장된 데이터를 얻을 수 있다.

-   리스트 내에서 '데이터의 참조위치'를 기록한다.
-   처음부터 참조를 새롭게 시작하기 위해서는 '데이터의 참조위치'의 초기화가 필요하다.

👉 `LFirst`를 호출해야 한다.

👉 모든 데이터의 참조 : LFirst → LNext → LNext → LNext ....

### LRemove

삭제를 위해서는 탐색이 선행되어야 한다.

-   `LRemove`가 호출되면, 직전에 참조된 데이터(`LFirst` 혹은 `LNext`의 호출로 참조된 데이터)가 삭제된다.

## 배열 기반으로 리스트 구현하기 : ArrayList.h

[ArrayList.h](./files/ArrayList.h)

### 구조체 ArrayList

-   데이터 저장공간이 배열로 선언 : `LData arr[LIST_LEN];`

-   저장된 데이터수를 기록하기 위한 멤버
-   참조 위치 기록 : `LFirst`,`LNext`, `LRemove`
-   `typedef` 선언 : 다양한 종류의 데이터 저장

```
typedef int LData;  // 리스트에 int형 데이터 저장
typedef ArrayList List; // List 👉 배열기반 리스트
```

> ✔ `typedef int LData;`의 변경으로 int형 대신 구조체 정보, 구조체 변수의 주소 값을 저장하는 리스트 생성 가능<br>
> ✔ `typedef ArrayList List;`<br>
> ArrayList라는 이름에 typedef 선언을 해 놓으면 `typedef LinkedList List`(List는 연결 기반 리스트) 처럼 List에 다른 이름을 부여함으로서 사용하는 리스트의 종류를 바꿀 수 있다.

## ArrayList.h에 선언된 함수 정의하기

[ArrayList.c](./files/ArrayList.c)

### 삽입과 조회

-   `void ListInit(List* plist);` : 초기화
    -   구조체 ArrayList의 멤버 `curPorsition`에는 배열의 인덱스 값이 저장
    -   이 값을 통해서 LFirst와 LNext가 참조해야할 배열의 위치를 알 수 있으므로 curPosition은 `-1`로 초기화
-   `void LInsert(List* plist, LData data);` : 데이터 저장

-   `int LFirst(List* plist, LData* pdata);`: 첫번째 조회
-   `int LNext(List* plist, LData* pdata);` : 두번째 이후의 조회

> ✔ LFirst : `(plist -> curPosition)=0;`<br>
> curPosition에 저장된 값을 0으로 재설정하여 데이터의 참조가 앞에서부터 다시 진행되게 한다.<br>
> ✔ LNext : `(plist->curPosition)++;`<br>
> curPosition 값을 증가시켜 순서대로 데이터를 참조할 수 있도록 한다.

### 삭제

-   `LData LRemove(List* plist);`

```
if (LFirst(&list, &data))
{
    if (data == 22)  // 앞서 LFirst함수가 참조한 데이터 삭제
        LRemove(&list);
    while(LNext(&list, &data))
    {
        if (data == 22)
            LRemove(&list); // 앞서 LNext함수가 참조한 데이터 삭제
    }
}
```

-   `LRemove`함수는 `LFirst`함수나 `LNext`함수의 호출을 통해 바로 직전에 참조가 이뤄진 데이터를 삭제한다.

    👉 `LRemove`함수가 호출되면 리스트의 멤버 `curPosition`을 확인해서, 조회가 이뤄진 `데이터의 위치`를 확인한 후에, **그 데이터를 삭제**한다.

    👉 중간에 데이터가 삭제되면, **뒤에 저장된 데이터를 한 칸씩 앞으로 이동**시켜 빈 공간을 메워야 한다.

**삭제 구현시 주의사항**

-   삭제할 데이터의 위치를 참조하는 방식
-   삭제를 위한 데이터의 이동과정

`(plist -> curPosition)--;`**이 삽입된 이유**

-   `curPosition`은 최근에 참조가 이뤄진 데이터의 인덱스 정보를 담고 있어야 한다.

    👉 삭제로 인해 비는 공간을 메우기 위해 데이터를 한 칸씩 앞으로 이동하면 curPosition은 아직 참조가 이뤄지지않은 데이터를 가리키게 되므로 curPosition을 한 칸 왼쪽으로 이동시켜야 한다.

---

## 배열의 장단점

연결 기반 리스트를 대상으로 비교한 장단점

### 장점

    ✔ 데이터의 참조가 쉽다 : 인덱스 기준으로 한번에 참조가 가능

### 단점

    ✔ 배열의 길이가 초기에 결정되어야 한다. (변경 불가능)
    ✔ 삭제 과정에서 데이터의 이동(복사)가 빈번히 일어난다.

-   리스트 `!=` 연결 기반 리스트
    배열 기반 리스트도 각종 자료구조 구현에 중요한 도구
