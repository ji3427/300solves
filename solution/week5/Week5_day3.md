# Week5_day3

## [programmers] 짝지어 제거하기

[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/12973)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK5/2017tipstown_1.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week5/programers_2017_tipstown_1.cpp)
## 풀이

- stack 문제
- 괄호 찾기 문제랑 유사함<br/>스택에 문자들을 push할 때 스택의 top과 비교해 문자가 같으면 스택에서 pop하고 그렇지 않으면 문자를 push함

---

## [programmers] 예상 대진표

[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/12985)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK5/2017tipstown_2.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week5/programers_2017_tipstown_2.cpp)

## 풀이

- 두 사람의 숫자가 같을 때까지 +1한 후에 2로 나눔

## 여담

- 이게 왜 레벨2지? (ji3427)
- 나는 두 사람의 숫자가 1차이가 날 때까지 비교를 했고, 이 과정에서 좌측 사람이 무조건 홀수여야 매칭이 되기 때문에 좌측 사람의 숫자가 낮도록 swap했는데 한번 더 2로 나누게 되면 굳이 위의 과정을 할 필요가 없게 된다. (jswww)

---

## [programmers] 단어 퍼즐

[문제 링크](https://programmers.co.kr/learn/courses/30/lessons/12983)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK5/2017tipstown_3.cpp)
- 지화영 Not solved

## 풀이

- DP로 풀이법
    - dp 배열을 INF로 초기화한다.
    - 주어진 문자열 t에서 인덱스 0부터 substring을 구한다.
        - (ex. t = apple, substring = a, ap, app, appl, apple)
    - 문자열 배열 strs가 t의 substring의 끝 문자열인지 확인한다.
        - (ex. t의 substring = app, strs = [app, ap, p, l, e, ple, pp]  일 경우 만족하는 strs = [app, p, pp])
    -  만약 strs가 substring과 일치한다면 dp[index] = 1로 초기화 시켜주고 그렇지 않다면 dp[index] = min(dp[index], dp[index-str.size()] + 1)로 값을 초기화 시킨다.
    -  dp 끝부분이 INF라면 -1, 아니라면 끝부분의 값을 반환한다.
- BFS 풀이법
    - 주어진 문자열 t에서 문자열 배열 strs의 원소 str을 찾았을 때 노드 안에 그 str의 시작부분과 끝부분의 인덱스를 담는다. 그리고 bfs를 통해 최단 경로를 구한다. 길이 없다면 -1을 반환한다. 
## 여담

- dfs로 풀었는데 시간초과 발생 (ji3427)
- bfs로 풀었는데 시간초과 발생 (jswww)
- 답은 DP였는데 DP같지 않는 문제 형태여서 DP는 고려도 안함
