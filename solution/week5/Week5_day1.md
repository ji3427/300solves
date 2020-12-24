# Week5_day1

## [BOJ 9251] LCS(최장 공통 부분 수열)

문제 링크 [BOJ 9251](https://www.acmicpc.net/problem/9251)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK5/9251.cpp)
- 지화영 Not solved

## 풀이

- dp문제
- ABCG와 ABDG에서 뒤에서부터 비교한다고 하면 G는 같기때문에 최장 공통 부분 수열은 G이전까지의 수열의 길이 + 1이 된다.<br/>C와 D는 다르기때문에 앞에 방식처럼은 불가능하고 각각을 따로 비교해주어야한다.
- `dp[1001][1001]`로 선언한 2차원 배열에서 좌, 상, 좌상 이 3개의 값만 쓰이므로 `dp[2][1001]`로 배열을 선언하고 값을 계속 덮어씌우면서 메모이제이션 해주면 메모리를 덜 사용할 수 있다.

## 여담

- dp는 처음보는 유형은 손도 못대는거같다. (ji3427)
- 예전에 풀었던 기억이 나서 풀 수 있었던 것 같다. (jswww)

---

## [BOJ 9663] N-Queen

문제 링크 [BOJ 9663](https://www.acmicpc.net/problem/9663)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK5/9663.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week5/baekjoon_9663.cpp)

## 풀이

- 백트래킹, 브루트포스 문제
- 원래는 2차원 배열을 이용해서 실제 체스판처럼 가능한부분, 불가능한부분을 표시해가면서 일일이 했더니 시간초과 발생 -> 1차원 배열과 수식을 통해서 간단하게 해결 가능

## 여담

- 일차원 배열을 비교하는 거를 이중 for문으로 중복 검사하여 시간초과가 났었다. 다음부터 잘 생각해야겠다. (jswww)
