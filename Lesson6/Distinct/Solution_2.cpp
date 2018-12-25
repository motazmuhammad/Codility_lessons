//This is a sorting based solution to go with the theme of the problem the idea is quite simple, sort the array initialize a counter
//whenever you find a new element increase the counter.

#include <algorithm>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size()==0) return 0;
    sort(A.begin(),A.end());
    int cnt=1;
   
    for(int i=1;i<A.size();i++)
    {
        if(A[i]!=A[i-1]) cnt++;   
  
    }
    return cnt;
}
