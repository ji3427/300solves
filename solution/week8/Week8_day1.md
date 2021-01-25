# Week8_day1

## [BOJ 1504] 특정한 최단 경로

문제 링크 [BOJ 1504](https://www.acmicpc.net/problem/1504)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK8/1504.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week8/baekjoon_1504.cpp)

## 풀이
- 최단경로 문제
- M,N이 주어졌을때 시작 - M(N), M(N) - N(M), N(M) - 끝의 최단거리의 합을 구하면 됨
- 플로이드 와샬 또는 다익스트라를 이용

---

## [BOJ 1865] 웜홀

문제 링크 [BOJ 1865](https://www.acmicpc.net/problem/1865)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK8/1865.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week8/baekjoon_1865.cpp)

## 풀이
- 최단거리 알고리즘 (음수 가중치)
- 벨만 포드 알고리즘을 이용하여 음의 사이클이 존재하는지 확인
- 1번 정점이 고립되고 나머지 정점에서 음의 사이클이 존재할 때 정점의 거리가 INF 이더라도 값을 갱신시켜야함 (그렇지 않으면 나머지 정점에서 음의 사이클의 존재 여부를 파악 불가)

## 여담
- 최단거리는 계속 잊어버린다.
