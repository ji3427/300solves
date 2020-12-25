# Week5_day2

## [BOJ 12851] 숨바꼭질2

문제 링크 [BOJ 12851](https://www.acmicpc.net/problem/12851)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK5/12851.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week5/baekjoon_12851.cpp)
## 풀이

- bfs 문제
- bfs에서는 불필요한 연산을 피하기 위해 큐에 push한 후에 visited 배열로 방문 기록을 남긴다. 하지만 이 문제 같은 경우에는 예를 들면 1 + 1 = 2 와 1 * 2 = 2 같이 과정은 다르지만 결과가 같은 경우가 나오게 되고 이것을 이미 방문했던 것으로 처리하여 오답을 내게 된다. 이 문제를 해결하는 방법은 2가지가 있다. <br/><br/>첫 번째는 visited 배열에 boolean 값이 아닌 현재 노드까지의 거리값을 저장하고 결과가 같고 거리값이 다르면 중복처리하고 거리값이 같다면 큐에 push하여 문제를 해결한다.<br/><br/>두 번째는 큐에 push하고 visited에 기록하는 것이 아닌 큐에서 pop하고 visited에 기록을 하게되면 연산에 대한 중복된 결과들을 큐에 저장할 수 있게 된다.

- 기존 bfs 문제에서는 최적화를 위해서 다음에 올 연산 결과값과 기대값을 비교하여 실행을 종료할지 말지를 결정하는데 이번 문제에서는 방법의 수를 구해야하기때문에 기존 문제처럼 하게되면 1 + 1과 1 * 2를 동일시 하게된다. <br/>이번 문제에서는 반대로 현재값과 기대값을 비교하는 방법으로 이러한 문제를 해결할 수 있다. 항상 현재값과 비교하면 메모리 초과, 시간초과가 발생해서 틀린 풀이라고 생각한 방법을 활용 할 수 있다는것을 배웠다.

## 여담

- n과 k가 같을 경우 처리를 생각하지 못했다. 기본적인 테스트케이스를 잘 처리해야 할 것 같다. (jswww)
- 단순한 BFS 풀이라고 생각을 해서 쉽게 풀릴 줄 알았는데 안풀려서 결국 답을 찾아보게 되었다. (ji3427)



## [BOJ 12865] 평범한 배낭

문제 링크 [BOJ 12865](https://www.acmicpc.net/problem/12865)

## 코드

- 조성원 [Solved](https://github.com/ji3427/300solves/blob/master/JSWww/WEEK5/12865.cpp)
- 지화영 [Solved](https://github.com/ji3427/300solves/blob/master/ji3427/week5/baekjoon_12865.cpp)

## 풀이

- dp, 0-1 knapsack 문제
- 2차원 배열을 이용하여 풀이, N번째 물건까지의 최대값을 저장하여 N+1번째 물건에서의 최대값을 구하는 DP 문제
- 1차원 배열로도 풀이 가능(극한의 최적화)

    ```cpp
    int dp[100001];

    int main()
    {
        int n, k, w, v;

        cin >> n >> k;

        while (n--) {
            cin >> w >> v;

            for (int i = k; i >= w; i--) {
                if (dp[i-w] + v > dp[i]) {
                    dp[i] =  dp[i-w] + v;
                }
            }
        }
    }

    ```

## 여담

- knapsack 문제는 몇번을 풀어도 기억이 잘 안 나는것 같다... dp는 어려워(jswww, ji3427)
