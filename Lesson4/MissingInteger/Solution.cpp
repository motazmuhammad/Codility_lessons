/* this is the solution for the problem described in problem.md tested against codility test cases

Algorithm hash the positive numbers of A in a hashtable say m, then go over the integers one by one starting from 1 if you don't find an integer return it
otherwise return the size of the hashmap.

One can prove it works by induction. Exercise to the reader.
*/


#include<algorithm>
#include<vector>
#include <numeric>
#include<unordered_map>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int,int> m;
    for(auto & x:A)
    {
        if(x>0)m[x]++;
    }
    for(int i=1;i<=m.size();i++)
    {
        if(m[i]==0) return i;
    }
    return m.size()+1;
    //return 1;
    
}
