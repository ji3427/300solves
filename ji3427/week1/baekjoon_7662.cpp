#include <iostream>
#include <set>
#include <queue>
using namespace std;

int main(void){
	int size;
	cin>>size;
	for(int i = 0 ; i < size ; i++){
		int inputSize;
		cin>>inputSize;
		multiset<int> queue;
		for(int s = 0 ; s < inputSize ; s++){
			char op;
			int num;
			cin>>op>>num;
			if(op == 'I') {
				queue.insert(num);
				continue;
			}
			if(queue.empty()) continue;
			if(num == -1){
				queue.erase(queue.begin());
				continue;
			}
			multiset<int>::iterator it = queue.end();
			it--;
			queue.erase(it);
		}
		
		if(queue.empty()) {
			cout<<"EMPTY"<<endl;
			continue;
		}
		multiset<int>::iterator it = queue.end();
		it--;
		cout<<*it<<" "<<*queue.begin()<<endl;
	}
}



