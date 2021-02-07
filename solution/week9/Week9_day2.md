# Week9_day2

## [BOJ 9465] 스티커

문제 링크 [BOJ 9465](https://www.acmicpc.net/problem/9465)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK9/9465.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week9/baekjoon_9465.cpp)

## 풀이

- dp 문제
```cpp
    // 점화식
    dp[0][i] += max(dp[1][i-2], dp[1][i-1]);
    dp[1][i] += max(dp[0][i-2], dp[0][i-1]);
```
- 현재 위치에서 전전 대각선 위치와 전 대각선 위치를 비교해야 한다.

    1. 전 대각선

    |0|1|2|
    |-|-|-|
    |x|x|o|
    |x|a|x|

    2. 전전 대각선

    |0|1|2|
    |-|-|-|
    |x|x|o|
    |b|x|x|


## [BOJ 2263] 트리의 순회

문제 링크 [BOJ 2263](https://www.acmicpc.net/problem/2263)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK9/2263.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week9/baekjoon_2263.cpp)

## 풀이

- 트리 순회, 재귀 문제
- postorder의 맨 마지막은 트리의 루트이고, inorder에서 루트의 인덱스를 찾게 되면 그 인덱스로부터 왼쪽 서브트리와 오른쪽 서브트리로 나눌 수 있다.
  preorder는 V L R 순으로 트리를 순회하므로 트리의 루트를 출력 후 inorder를 통해 나눠진 왼쪽 서브트리, 오른쪽 서브트리 순으로 트리 순회를 재귀한다.

## 여담

- inorder에서 루트를 찾을 때 for문으로 찾지 말고 루트의 인덱스를 저장하는 배열을 만들어 찾게 되면 시간이 1200ms -> 90ms로 줄어든다.
