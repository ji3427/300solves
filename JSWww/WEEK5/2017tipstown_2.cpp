#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
   	int answer; 
    
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    
	for (answer = 1; ; answer++) {
        if (b - a == 1 && a % 2 == 1) break;
        
   		a = (a + 1) / 2; 	    
   		b = (b + 1) / 2; 	    
    }

    return answer;
}