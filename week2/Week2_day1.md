# Week2_day1

## [BOJ 1016] 제곱 ㄴㄴ 수

문제 링크 [BOJ 1016](https://www.acmicpc.net/problem/1016)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/jswww/WEEK2/1016.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/ji3427/week2/baekjoon_1016.cpp)

## 풀이

- 에라토스테네스의 체 문제

## 최적화
- unordered_set 대신 배열 사용 => 제곱수의 배수 값에 min 값을 빼서 배열의 index로 사용하였다.
- unordered_set의 연산들이 시간복잡도가 O(1)이라고 해도 배열을 이길 수는 없었다...
- 모든 제곱수를 찾는 경우 메모리 초과가 발생한다. min 값보다 작은 최대 제곱수의 배수를 찾아야한다.
- [min, max] 범위값에서 set(제곱수의 배수들)의 size를 빼면 되는거였는데 굳이 for문을 돌렸다.

## 여담
- 화영 
    - 제곱수의 max값을 포함시키지 않아서 계속 틀린답이 나왔다. = 차이 하나때문에 많은 시간을 낭비하여 항상 =이 들어가는 조건문을 잘 살펴야겠다.
- 성원
    - 제곱수의 배수를 구할 때 min 값보다 작은 경우를 제외하는 것을 생각 못하고 있었다. 😅😅
