#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int board[16][16];
int move_col[7] = {1,0,1,0,1,1,1};
int move_row[7] = {0,1,0,1,1,1,1};
int N;
int ans = 0;
typedef struct pos
{
    pair<int,int> current;
    int state;
}pos;

int main(void){
    cin>>N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
        }
    }
    queue<pos> q;
    pos temp;
    temp.current = make_pair(0,1);
    temp.state = 0;
    q.push(temp);
    while(!q.empty()){
        pair<int,int> current = q.front().current;
        int state = q.front().state;
        q.pop();
        for(int i = 0 ; i < 7 ; i++){
            if(state == 0 && (i != 0 && i != 4)) continue;
            else if(state == 1 && (i != 1 && i != 5)) continue;
            else if(state == 2 && (i != 2 && i != 3 && i != 5)) continue;
            pair<int,int> next = current;
            next.first += move_row[i];
            next.second += move_col[i];
            if(next.first < 0 || next.second < 0 || next.first >= N || next.second >= N) continue;
            if(board[next.first][next.second] != 0) continue;
            if((i >3 && (board[next.first -1][next.second] != 0 || board[next.first][next.second - 1] != 0))) continue;
            if(next.first == N-1 && next.second == N-1) {
                ans++;
                continue;
            }
            temp.current = make_pair(next.first, next.second);
            if(i == 0 || i == 2) temp.state = 0;
            else if(i == 1 || i == 3) temp.state = 1;
            else temp.state = 2;
            q.push(temp);
        }
    }

    cout<<ans<<endl;
}