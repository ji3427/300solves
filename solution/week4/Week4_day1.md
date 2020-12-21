# Week4_day1

## [BOJ 1753] 최단경로

문제 링크 [BOJ 1753](https://www.acmicpc.net/problem/1753)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK4/1753.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week4/baekjoon_1753.cpp)

## 풀이

- 우선순위 큐와 벡터를 이용한 다익스트라 풀이

    - 일반 큐 사용 시 시간초과
    - 배열로 연결관계 표현 시 메모리초과, int array[20000][20000] => 1.6GB
    - 그래프 입력을 vector<vector<pair<int, int>>> 로 받아 메모리 최적화
        - 연결 관계가 존재하는 정점들만 벡터에 저장
            ```
            row = 현재 정점
            array[row][col].first -> 다음 정점
            array[row][col].second -> 거리
            ```
    - 중복되는 연결관계가 존재함
        ```
        ex) start-end-cost => 1-3-10, 1-3-20
        이미 우선순위 큐에서 뽑힌 최단 거리값(10)으로 dist가 계산됨.
        그 이후 우선순위 큐에서 나오는 거리값(20)으로 dist를 계산하려 할 경우 continue로 넘김.
        ```
## 새로배운 지식

- vector의 size와 capacity
    - size: vector의 원소의 개수
    - capacity: 실제 vector가 차지하는 메모리 공간의 크기, 2배씩 증가한다.  
        ```
        for (int i = 0; i < 5; i++) {
            v.push_back(i);
        }
         
        size : 5, capacity : 8
        => v의 capacity는 8이기 때문에 v[6] 접근 가능
        ```
     
- vector의 resize와 reserve
    - resize(value): size와 capacity 둘 다 value로 변경
    - reserve(value): capacity만 value로 변경
    - 예시
        - reserve
            ```
            v.reserve(3);
            for (int i = 0 ; i < 5 ; i++) {
                v.insert(i);
                cout << v.size() << " " << v.capacity() << endl;
            }

            출력값
            1 3
            2 3
            3 3
            4 6
            5 6
            ```

        - resize
            ```
            v.resize(3);
            for (int i = 0 ; i < 5 ; i++) {
                v.insert(i);
                cout << v.size() << " " << v.capacity() << endl;
            }
                
            출력값
            4 6
            5 6
            6 6
            7 12
            8 12
            ```
