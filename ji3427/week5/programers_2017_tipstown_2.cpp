#include <iostream>

using namespace std;

int getNext(int num){
    if(num % 2 == 1) num++;
    return num/2;
}

int solution(int n, int a, int b)
{
    int round = 0;
    while(!(a == b)){
        a = getNext(a);
        b = getNext(b);
        round++;
    }
    return round;
}