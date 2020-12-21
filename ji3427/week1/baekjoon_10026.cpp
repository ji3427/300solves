#include <iostream>
#include <algorithm>
#include <string.h>
#include <unordered_map>
using namespace std;

char board[100][100];
bool visited[100][100];
int size;
unordered_map<char,int> um;

void check(int row,int col,int color){
	if(visited[row][col] == true) return;
	if(row >= size || row < 0 || col >= size || col < 0) return;
	if(color != um[board[row][col]] ) return;
	visited[row][col] = true;
	check(row + 1, col, color);
	check(row - 1, col, color);
	check(row, col + 1, color);
	check(row, col - 1, color);
}

int main(void){
	cin>>size;
	int normalResult = 0;
	int unnormalResult = 0;
	um.insert(make_pair('R',0));
	um.insert(make_pair('G',1));
	um.insert(make_pair('B',2));
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			cin>>board[i][j];
		}
	}
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(visited[i][j] == true) continue;
			normalResult++;
			check(i,j, um[board[i][j]]);
		}
	}
	memset(visited,0,sizeof(visited));
	um['G'] = 0;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(visited[i][j] == true) continue;
			unnormalResult++;
			check(i,j, um[board[i][j]]);
		}
	}
	cout<<normalResult<<" "<<unnormalResult<<endl;
}


