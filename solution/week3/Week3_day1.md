# Week3_day1

## [BOJ 11404] 플로이드

문제 링크 [BOJ 11404](https://www.acmicpc.net/problem/11404)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK3/11404.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week3/baekjoon_11404.cpp)

## 풀이

- 플로이드-와샬 알고리즘

## 주의할 점
- 3중 for문에서 중간 정점을 맨 위에 둬야 한다. 중간 정점을 기준으로 모든 경로의 값을 업데이트 시켜주어야 하기 때문이다.

```c++
for (int mid = 1; mid <= n; mid++) {
    for (int start = 1; start <= n; start++) {
        for (int end = 1; end <= n; end++) {
            g[start][end] = min(g[start][end], g[start][mid] + g[mid][end]);
        }
    }
}
```
