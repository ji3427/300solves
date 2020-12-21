#include <iostream>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

struct node{
	int num;
	string ops;
};

int op_D(int n){
	return (n * 2) % 10000;
}

int op_S(int n){
	int ans = n -1;
	return ans == 0 ? 9999 : ans;
}

int op_L(int a){
	int m = a/1000;
	a = (a % 1000) * 10 + m;
	return a;
}

int op_R(int a){
	int m = (a % 10) * 1000;
	a = (a / 10) + m;
	return a;
}
void queue_clear(queue<node> &q){
	while(!q.empty()) q.pop();	
}

int main(void) {
	int tc;
	cin>>tc;
	bool visited[10001] = {0,};
	for(int t = 0 ; t < tc ; t++){
		int src,dest;
		memset(visited , 0, sizeof visited);
		cin>>src>>dest;
		queue<node> q;
		node temp;
		temp.num = src;
		temp.ops = "";
		q.push(temp);
		while(!q.empty()){
			temp = q.front();
			q.pop();
			if(temp.num == dest){
				cout<<temp.ops<<"\n";
				q = queue<node>();
				break;
			}
			int next = op_D(temp.num);
			if(visited[next] == false){
				visited[next] = true;
				q.push({next, temp.ops + "D"});
			}
			next = op_S(temp.num);
			if(visited[next] == false){
				visited[next] = true;
				q.push({next, temp.ops + "S"});
			}
			next = op_L(temp.num);
			if(visited[next] == false){
				visited[next] = true;
				q.push({next, temp.ops + "L"});
			}
			next = op_R(temp.num);
			if(visited[next] == false){
				visited[next] = true;
				q.push({next, temp.ops + "R"});
			}
		}
	}
}
