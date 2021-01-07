# Week7_day1

## [BOJ 17144] 미세먼지 안녕!

문제 링크 [BOJ 17144](https://www.acmicpc.net/problem/17144)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK7/17144.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week7/baekjoon_17144.cpp)

## 풀이

- 완전 시뮬레이션 문제
- 먼지 퍼트리는 함수, 공기 청정기로 배열을 움직이는 함수 두 개를 구현하면 됨

## 여담

- 좌, 우로 회전할 때 queue를 이용하여 처리함 (jswww)
- 회전할때 전에 사용하던 값을 저장하여 활용함 (ji3427)

---

## [BOJ 1043] 거짓말

문제 링크 [BOJ 1043](https://www.acmicpc.net/problem/1043)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK7/1043.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week7/baekjoon_1043.cpp)

## 풀이

- union-find, bfs
- 진실을 언젠가는 알게되는 사람의 집합과 진실을 절대 알 수 없는 사람의 집합으로 구분짓는다. 같은 집합으로 묶는 것은 union, 같은 집합에 속해있는지의 판별은 find를 이용한다.
- 기존 풀이에서는 해당 파티에 속한 사람들의 번호만을 이용해서 풀었는데, 해당 사람이 속한 파티의 배열을 만들면 코드를 조금 더 깔끔하게 쓸 수 있음

## 여담

- bfs는 어디에나 존재한다...
- union-find도 몇 번은 봤던 내용인데 볼 때마다 까먹는 것 같다. (jswww)
