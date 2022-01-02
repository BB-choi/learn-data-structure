# 12. 탐색(Search) - AVL Tree
이진 탐색 트리의 단점 : **균형이 맞지 않을수록** 탐색 성능이 나빠짐  



➡️ **균형 잡힌 이진 트리**로 해결!
- [AVL 트리](#avl-트리)
- 2-3 트리
- 2-3-4 트리
- Red-Black 트리
- B 트리

### AVL 트리
노드가 추가/삭제될 때 트리의 균형상태를 파악해서 스스로 그 구조를 변경하여 구조를 잡는 트리

- 리밸런싱 `rebalancing` : 균형을 잡기 위한 트리 구조의 재조정
- 균형 인수 `Balance Factor` : 균형의 정도를 표현하기 위해 사용하는 값  
`균형 인수 = 왼쪽 서브 트리의 높이 - 오른쪽 서버 트리의 높이`  

---
## 12 - 1. 리밸런싱(rebalancing)
균형 인수의 절댓값이 클수록 트리의 균형이 무너진 상태 ➡️ 절댓값이 2 이상인 경우에 리밸런싱

### 👩‍🏫 첫번째 상태 : LL상태 - LL회전
- LL상태 : 자식 노드 **두 개가 왼쪽**으로 연이어 연결된 상태 (균형 인수 +2)  
- LL회전 : LL상태에서 균형을 잡기 위한 회전  


**how to**
> 균형 인수가 +2인 노드를 균형 인수가 +1인 노드의 **오른쪽 자식 노드**가 되게 함  

<p align=center><img src="https://user-images.githubusercontent.com/31379392/147873055-d89fe558-f373-4ad9-9df3-3c69938c5ce6.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>

💡 `cNode`의 오른쪽 서브 트리가 존재하는 경우?  
> `cNode`의 오른쪽 자식 노드 자리는 `pNode`에게 양보하고,  
> 해당 서브 트리는 **`pNode`의 왼쪽 서브 트리**가 된다.


### 👩‍🏫 두번째 상태 : RR상태 - RR회전
LL상태/회전과의 차이점 : 방향 ➡️ **오른쪽**  

<p align=center><img src="https://user-images.githubusercontent.com/31379392/147873060-9dc8d07b-cfe2-4bef-8f00-5c286e1916ea.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>

**how to**
> `pNode`를 `cNode`의 **왼쪽 자식 노드**가 되게 함.  
>> ➡️ `cNode`의 왼쪽 자식 노드가 이미 존재하는 경우에는 LL회전과 동일한 방식으로 진행(방향 반대)  


### 👩‍🏫 세번째 상태 : LR상태 - LR회전
- LR샹태 : 자식노드가 왼쪽으로 하나, 이어서 오른쪽으로 하나 달린 상태(균형 인수 +2)

**how to**  
LR상태는 한 번의 회전으로 균형을 잡을 수 없음 ➡️ 부분 RR회전 + LL회전: LL상태 이용  
>1. 일부를 떼어서 RR회전 : LR상태 ➡️ LL상태로 변경됨  
>2. LL회전으로 트리의 균형을 잡음  

<p align=center><img src="https://user-images.githubusercontent.com/31379392/147873385-920000bc-089c-4a5d-b5a0-6c274dd650bc.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>


### 👩‍🏫 네번째 상태 : RL상태 - RL회전
LR상태/회전과의 차이점 : 방향  

<p align=center><img src="https://user-images.githubusercontent.com/31379392/147873387-b028a413-458e-4019-a554-ff44d3cc094d.jpg" width = "500"><br>윤성우 저, 열혈 자료 구조</p>

**how to**  
> 부분 LL회전 + RR회전
---
