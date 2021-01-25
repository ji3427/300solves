# Week9_day1

## [BOJ 1918] 후위 표기식

문제 링크 [BOJ 1918](https://www.acmicpc.net/problem/1918)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK9/1918.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week9/baekjoon_1918.cpp)

## 풀이
- stack 문제

### infix -> postfix 변환 방법
1. 피연산자는 바로 출력
2. 연산자를 만나면 아래의 조건에 맞게 스택연산을 수행함
    - 여는 괄호인 경우는 무조건 스택에 넣어준다.
    - 닫는 괄호인 경우는 여는 괄호를 만날 때까지 스택에서 pop을 수행한다.
    - 연산자 우선순위에 따라서 스택에서 자신의 우선순위보다 높거나 같은 것을 모두 pop하고 자신을 push한다.
