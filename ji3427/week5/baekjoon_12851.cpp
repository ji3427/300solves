#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int ansSize = 0;
bool visited[100010] = {0,};
int fastTime = 100010;
int main(void){
    int N,M;
    queue<pair<int,int> > q;
    cin>>N>>M;
    q.push(make_pair(0,N));
    while(!q.empty()){
       pair<int,int> current = q.front();
       q.pop();
       visited[current.second] = true;
       if(current.first <= fastTime && current.second == M) { 
           fastTime = current.first; 
           ansSize++; 
           continue;
       }
       if(current.second + 1 <= 100000 && !visited[current.second + 1])q.push( make_pair(current.first+1, current.second + 1) );
       if(current.second - 1 >= 0 && !visited[current.second - 1])q.push( make_pair(current.first+1, current.second - 1) );
       if(current.second * 2 <= 100000 && !visited[current.second * 2])q.push( make_pair(current.first+1, current.second * 2) );
    }
    cout<<fastTime<<endl<<ansSize;
    return 0;
}