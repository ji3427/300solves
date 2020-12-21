#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int board[1001][1001];
int dist[1001];
queue<int> q;

int main(void){
	memset(board,0,sizeof(board));
	int city_size, info_size;
	int row,col,value;
	int start,end;
	cin>>city_size>>info_size;
	for(int i = 0 ; i <= city_size ; i++){
		dist[i] = 1000000000;
	}
	for(int i = 0 ; i <= city_size ; i++){
		for(int j = 0 ; j <= city_size ; j++){
			board[i][j] = -1;
		}
	}
	for(int i = 0 ; i < info_size ; i++){
		cin>>row>>col;
		cin>>value;
		if(board[row][col] == -1 || board[row][col] > value) board[row][col] = value;
	}
	cin>>start>>end;
	dist[start] = 0 ;
	q.push(start);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int i = 1 ; i <= city_size ; i++){
			if(board[cur][i] == -1) continue;
			if(dist[cur] + board[cur][i] > dist[i]) continue;
			dist[i] = dist[cur] + board[cur][i];
			q.push(i);
		}
	}
	cout<<dist[end]<<endl;
}
