#include <iostream>
#include <queue>
using namespace std;

int dist[20001];
vector<vector<pair<int,int>>> board;
#define INF 100000000
priority_queue<pair<int,int>> q;
int main(void){
	int edgeSize, vertexSize;
	cin>>vertexSize>>edgeSize;
	for(int i = 0 ; i < vertexSize ; i++){
		vector<pair<int,int>> temp;
		board.push_back(temp);
	}
	int start;
	cin>>start;
	for(int i = 0 ; i <= vertexSize ; i++){
		dist[i] = INF;
	}
	
	for(int i = 0 ; i < edgeSize ; i++){
		int row,col,value;
		cin>>row>>col>>value;
		board[row].push_back(make_pair(value,col));
	}
	
	dist[start] = 0;
	q.push(make_pair(0,start));
	while(!q.empty()){
		int cost = -q.top().first;
		int here = q.top().second;
		q.pop();
		if(dist[here] < cost) continue;
		
		for(int i = 0 ; i < board[here].size() ; i++){
			int next = board[here][i].second;
			int nextDist = board[here][i].first + cost;
			if(dist[next] > nextDist){
				dist[next] = nextDist;
				q.push(make_pair(-nextDist, next));
			}
		}
	}
	for(int i = 1 ; i <= vertexSize ; i++){
		if(dist[i] == INF) cout<<"INF"<<"\n";
		else cout<<dist[i]<<"\n";
	}
}
