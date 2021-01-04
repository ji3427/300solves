#include <iostream>
#include <string>
#include <vector>

using namespace std;

int check_end(string& str, string& e) {
    int result = str.size() - e.size();
    
    for (int i = e.size() - 1; i >= 0; i--) {
		if (e[i] != str[i+result])
            return -1;
    }
    
    return result;
}

int solution(vector<string> strs, string t)
{
    int answer = 0;
    int dp[20001];
    string str = "";
    
    for (int i = 0; i < t.size(); i++) {
   		str += t[i];
        dp[i] = 1e9;
        
        for (auto e : strs) {
            if (str.size() < e.size()) continue;
            
            int idx = check_end(str, e);
            
            if (idx == -1) continue;
            
            if (idx == 0) {
                dp[i] = 1;
            } else {
               dp[i] = min(dp[i], dp[i-e.size()] + 1); 
            }
        }
    }
    
    answer = (dp[t.size()-1] == 1e9) ? -1 : dp[t.size()-1];

    return answer;
}