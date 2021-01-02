#include <iostream>
#include <deque>

using namespace std;
bool visited[100001];

typedef struct pos
{
    int current;
    int count;
}pos;

int main(void){
    int N,K;
    cin>>N>>K;
    deque<pos> q;
    int answer = 1e9;
    pos temp;
    temp.count = 0;
    temp.current = N;
    q.push_back(temp);
    visited[N] = true;
    while (!q.empty())
    {
        int current = q.front().current;
        int count = q.front().count;
        q.pop_front();

        if(current == K){
            answer = count;
            cout<<answer<<endl;
            return 0;
        }

        for(int next : {current * 2, current - 1, current + 1}){
            if(next < 0 || next > 100000) continue;
            if(visited[next]) continue;
            temp.current = next;
            if(next != current * 2) {
                temp.count = count + 1;
                q.push_back(temp);
            }
            else {
                temp.count = count;
                q.push_front(temp);
            }
            visited[next] = true;
        }
    }
    return 0;
}