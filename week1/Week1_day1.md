# Week1_day1

## [BOJ 7662] 이중 우선순위 큐

문제 링크 [BOJ 7662](https://www.acmicpc.net/problem/7662)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/jswww/7662.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/ji3427/week1/baekjoon_7662.cpp)

## 풀이

- multiset 사용
    - 가장 간단한 방법
    - set 구조체 자체가 tree 구조로 정렬되어 들어가기 때문에 추가,삭제,조회 연산 모두 O(logN)의 시간복잡도를 가짐
- deletable queue 구조체 생성
    - 두개의 우선순위 큐를 사용하는 방법(결론적으로는 총 4개의 큐가 필요함)
    - 동일한 정렬방법을 가진 2개의 큐를 맴버로 갖는 하나의 새로운 클래스를 생성, 이를 bigQueue라고 정의함
         ```
            class bigQueue {
                private Heap data
                private Heap deleted
            }
        ```
    - 추가 연산 시 min_bigQueue와 max_bigQueue의 data heap에 값을 추가
    - 삭제 연산 시 min_bigQueue와 max_bigQueue의 delete heap에 값을 추가
    - top 연산 시 data heap의 최상위 값과 delete heap의 최상위값을 비교하여 같은 경우 삭제된 값이므로 무시, 같지 않은 data heap의 최상위 값이 유효한 값
- 데이터 유효성 검사
    - min heap, max heap 와 데이터가 유효한지 확인하는 vector를 이용
    - 데이터는 min heap 또는 max heap 중 하나에서만 삭제되고, 삭제된 데이터는 더 이상 유효하지 않음을 해당 데이터값을 index로 하는 vector에 저장
    - vector 사용 시 백만 개(k <= 1,000,000)를 잡아야 하므로 map을 사용하면 크기를 줄일 수 있음
    - unorder_map 사용 시 O(1)의 시간복잡도로 연산 가능
