
# 11. 탐색(Search)

## 11 - 1. 보간 탐색 (Interpolation Search)
탐색대상이 앞쪽에 있으면 앞쪽에서 탐색을 시작하는 알고리즘 ➡️ 이진 탐색의 비효율성을 개선!  

**이진 탐색의 비효율성?**
> - 이진 탐색 : 탐색대상의 중앙부터 시작해서 탐색대상을 반씩 줄여나가며 탐색을 진행하는 알고리즘 (정렬된 대상을 기반으로 하는 탐색)  
> ➡️ 찾는 대상의 위치에 관계없이 중앙을 기준으로 탐색  
> ➡️ 찾는 대상의 위치에 따라 탐색의 효율에 차이가 발생

- 탐색 키 `Search Key`  
  : 탐색의 기준(대상)이 되는 값 ➡️ key value는 `unique`하고 `NULL`을 허용하지 않음.
- 탐색 데이터 `Search Data`  
  : `Search Key`와 묶여있는 값

### 구현 : 탐색 위치
**이진 탐색 vs 보간 탐색** ➡️ 기준 : 탐색 위치를 선정하는 방법  
- 이진 탐색에서 탐색 위치를 계산하는 방법
```c
mid = (first+last) / 2;
```
- 보간 탐색에서 탐색 위치를 계산하는 방법
```c
mid = ((double)(target-ar[first]) / (ar[last]-ar[first]) * (last-first)) + first;
```

### 구현 : 탈출 조건
```c
if(ar[first]>target || ar[last]<target)
  return -1;
```
탐색 대상이 존재하지 않을 경우, 탐색 대상의 값은 탐색 범위의 값을 넘어선다!

---
## 11 - 2. 이진 탐색 트리 (Binary Search Tree)
**데이터의 저장 규칙**에 맞춰 생성된 **이진 트리**  

<p align=center><img src="https://user-images.githubusercontent.com/31379392/147735196-ab57a9b6-826e-4bcd-900a-2a82937ccefa.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>

**이진 탐색 트리가 되기 위한 조건**  
>1. 이진 탐색 트리의 노드에 저장된 `key`는 `unique`  
>2. 왼쪽 서브 트리의 모든 `key` < 루트 노드의 `key` < 오른쪽 서브 트리의 모든 `key`  
>3. 왼쪽과 오른쪽 서브 트리도 이진 탐색 트리이다.

💡이진 탐색 트리는 `왼쪽 자식 노드의 key < 부모 노드의 key < 오른쪽 자식 노드의 key`를 어느 위치에서든 만족한다.  

---

### 구현 : 삽입과 탐색
**how to**
> 1. 작으면 왼쪽으로, 크면 오른쪽으로!  
> 2. 비교대상이 더이상 없을 때까지 내려간다.  

```c
FUN BSTInsert()
{
  BTreeNode * pNode; // parent node
  BTreeNode * cNode; // current node

  1. new node가 추가될 위치 탐색
  while(비교대상이 없을 때까지) {
    if(key가 중복되면) return;
    else {
      if 작으면 왼쪽 서브 트리
      else if 크면 오른쪽 서브트리

      pNode = cNode;
    }
  }

  2. new node 생성해서
  3. pNode의 자식 노드로 new node를 추가
}
```
탐색은 삽입과 같은 맥락으로 이루어짐!

### 구현 : 삭제
임의의 노드가 삭제된 후에도 이진 탐색 트리가 유지되도록 빈 자리를 채워야함.  

#### 상황1 : 삭제할 노드가 단말 노드인 경우
<p align=center><img src="https://user-images.githubusercontent.com/31379392/147870757-f18604f9-225f-4a49-a2ed-4544295033f6.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>

**how to**  
> 삭제 대상인 단말 노드 삭제 (빈 자리 채우는 과정 필요 없음)

#### 상황2 : 삭제할 노드가 하나의 자식 노드(하나의 서브 트리)를 갖는 경우
<p align=center><img src="https://user-images.githubusercontent.com/31379392/147870772-c6e98416-c518-49be-b288-33b82ad52416.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>

**how to**
> 1. 삭제 대상인 단말 노드 삭제  
> 2. 부모 노드와 자식 노드 연결 (삭제한 노드를 대신하여 빈 자리 채우기)

#### 상황3 : 삭제할 노드가 두 개의 자식 노드(두개의 서브 트리)를 갖는 경우
<p align=center><img src="https://user-images.githubusercontent.com/31379392/147870812-70452e97-119b-434e-a67e-2c9c76eba83d.jpg" width = "350"><br>윤성우 저, 열혈 자료 구조</p>

**how to**
> 1. 삭제 대상인 단말 노드 삭제  
> 2. 빈 자리를 대체할 노드 선택 ➡️ **왼쪽 서브 트리의 max** vs **오른쪽 서브 트리의 min**
> 3. 대체할 노드에 저장된 값을 삭제할 노드에 대입 (새로운 연결 만드는 것 아님)  
> 4. 대체할 노드의 부모 노드와 자식 노드를 연결 (중간에 낀 노드는 연결이 끊어졌으므로 트리에서 사라짐)

#### 상황4 : 삭제할 노드가 루트 노드인 경우
<p align=center><img src="https://user-images.githubusercontent.com/31379392/147871145-20ad787e-7309-436a-b40f-89b2bb3455b3.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>

**how to**  
> 루트 노드(R)를 자식으로 두는 가상의 루드 노드(V)를 생성해서 삭제 과정 내내 유지  
>     ➡️ 삭제 후 부모와 자식을 연결시키는 과정을 수행해야 하는데, 가상의 루트 노드를 두어서 루트 노드를 삭제하는 경우의 예외적인 흐름 없이 삭제 과정을 일반화하기 위함. 

---
