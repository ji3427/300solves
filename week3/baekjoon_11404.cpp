#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int board[100][100];
int city,bus;
void print(){
	for(int i = 0 ; i < city ; i++){
		for(int j = 0 ; j < city ; j++){
			if(board[i][j] >= 100000000 || i == j){ cout<<0<<" "; continue;}
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(void){
	cin>>city>>bus;
	for(int i = 0 ; i < city ; i++){
		for(int j = 0 ; j < city ; j++){
			board[i][j] = 100000000;
		}
	}
	for(int i = 0 ; i < bus ; i++){
		int a,b,cost;
		cin>>a>>b>>cost;
		if(board[a-1][b-1] > cost){
			board[a-1][b-1] = cost;	
		}
		
	}
	for(int mid = 0 ; mid < city ; mid++){
		for(int start = 0 ; start < city ; start++){
			for(int end = 0 ; end < city ; end++){
				board[start][end] = min(board[start][end], board[start][mid] + board[mid][end]);
			}
		}
	}
	print();
}

