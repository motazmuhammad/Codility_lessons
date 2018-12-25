// this is one way to solve the problem described in problem.md even though it defeats the purpose of the exercise. I wanted to include
//it because it is elegant

#include<unordered_map>

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int,int> m;
    for(auto&x:A)m[x]++;
    return m.size();
    
}
