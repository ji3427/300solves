# Week1_day2

## [BOJ 9019] DSLR

문제 링크 [BOJ 9019](https://www.acmicpc.net/problem/9019)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/jswww/WEEK1/9019.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/ji3427/week1/baekjoon_9019.cpp)

## 풀이

- 대표적인 bfs 문제


## 오류
- 메모리 초과
    - 큐에 추가시 check 변수를 활용하여 중복된 값이 들어가지 않도록 함
    - 큐에서 pop 하고 나서 check하지 말고 큐에 push 할 때 check 해야됨
    ```cpp
    queue<int> q;
    bool check[10];

    // bad
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        check[n] = true;
    }

    // good
    while (!q.empty()) {
        ...

        if (!check[n]) {
            q.push(n);
            check[n] = true;
        }
    }
    ```     
- 시간 초과
    - 매번 큐에 집어넣을 string값을 복사하여 처리하였더니 시간 초과 문제 발생 -> 기존 값을 이용하여 큐에 추가
    ```c++
    // bad
     next = current;
     next.operators += "D"
  
    // good
    queue.push({new_value, current.operators + "D"}) 
    ```
## 여담
- queue 초기화
    - ` while(!queue.empty()) queue.pop(); //OK `
    - ` queue = queue<template>() //OK `
