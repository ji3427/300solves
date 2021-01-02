# Week6_day1

## [BOJ 13549] 숨바꼭질 3

문제 링크 [BOJ 13549](https://www.acmicpc.net/problem/13549)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK6/13549.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week6/baekjoon_13549.cpp)

## 풀이

- 0-1 bfs 문제
    - 일반적인 bfs는 모든 간선의 가중치가 동일하다는 전제조건 필요, 위의 문제 같은 경우는 가중치가 0, 1로 다르기 때문에 일반적인 bfs 적용 불가
- 다익스트라 풀이법
    - priority_queue를 이용하여 최단거리를 구한다.
- deque를 활용해서 풀이
    - +를 하는 경우에는 deque의 push_back
    - *를 하는 경우에는 deque의 push_front
    - *의 결과값들을 우선적으로 처리한 후 더하기가 실행되므로 *의 결과값의 제한을 두면 더 적은 연산으로 답에 접근할 수 있음

## 여담
- 연산의 결과값들 중 * 연산의 결과값을 찾기위해 ```x(기존값) == nx(결과값) / 2``` 로 조건문을 주었는데 x가 0인 경우 + 연산을 한 경우와 * 연산을 한 경우가 동일해지기 때문에 틀린 답이 나왔음 (ji3427)
- 일반적인 bfs의 경우 가중치가 같아야만 한다는 것을 처음 알게 되었다. (jswww)

---

## [BOJ 17070] 파이프 옮기기 1

문제 링크 [BOJ 17070](https://www.acmicpc.net/problem/17070)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK6/17070.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week6/baekjoon_17070.cpp)

## 풀이
- 조건문이 많은 bfs 문제
- Queue에 좌표와 방향을 가진 객체를 넣어주어야 함
- 현재 방향에 따라서 조건문을 사용하여 다음 이동 방향과 이동 가능 여부등을 체크하여 Queue에 넣어주어야 함

## 여담

- 문제를 잘 읽자!
