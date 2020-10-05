#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

long long pow(long long n) {return (long long)n*n;};

unordered_set<int> um;

void make_list(long long min, long long max) {
	for(long long i = 2 ; i*i <= max ; i++){
		long long start = min / pow(i);
		long long result;
		while(1){
			result = pow(i) * start;
			start++;
			if(result > max) break;
			if(result < min) continue;
			um.insert(result);
		}
	}
}

int main(void){
	long long min,max;
	cin>>min>>max;
	make_list(min, max);
	cout<<max - min + 1 - um.size()<<endl;
}
