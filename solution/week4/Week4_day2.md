# Week4_day2

## [BOJ 1916] 최단경로

문제 링크 [BOJ 1916](https://www.acmicpc.net/problem/1916)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/jswww/WEEK4/1916.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/ji3427/week4/baekjoon_1916.cpp)

## 풀이

- bfs를 이용하여 최단 거리를 찾았음
- 다익스트라를 이용하여 풀이 가능

## 여담

- 다익스트라 우선순위 큐 사용유무에 따른 차이점
    - dist 배열 전체 탐색 시: log(n^2)
    - 우선순위 큐 사용 시: nlog(n)
