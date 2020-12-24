#include <iostream>
#include <algorithm>

using namespace  std;

int board[16];
int N,answer = 0 ;
bool check(int level){
	for(int i = 0 ; i < level ; i++){
		if(board[i] == board[level] || abs(board[level] - board[i]) == level - i) return false;
	}
	return true;
}

void getAns(int x){
	if(x == N) answer++;
	else{
		for(int i = 0 ; i < N ; i++){
			board[x] = i;
			if(check(x)) getAns(x+1);
		}
	}
}


int main(void){
	cin>>N;
	getAns(0);
	cout<<answer;

}
