# Week1_day3

## [BOJ 10026] 적록색약

문제 링크 [BOJ 10026](https://www.acmicpc.net/problem/10026)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/jswww/WEEK1/10026.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/ji3427/week1/baekjoon_10026.cpp)

## 풀이

- dfs,bfs 문제
- R, G, B가 있는 board에서 그래프를 탐색하면서 G을 R로 바꾼다. 그리고 다시 그래프를 탐색하면 R과 B만 있는 board에서 그래프를 탐색하게 된다. (성원)
- 각각의 색을 숫자와 맵핑한 후 비적록색약인 경우에 dfs를 이용하여 그래프를 탐색하여 값을 구하고 적록색약인 경우 맵핑된 값은 적색과 초록색이 같게 한 후 dfs를 이용하여 그래프 탐색을 하였다.(화영)

## 여담
- 개인적인 생각이지만 비적록색약용,적록색약용 dfs/bfs 코드를 나누어 짜는건 코드가 많이 중복되기 때문에 비효율적이라고 생각한다. 
