
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<unordered_map>
#include<algorithm>
#include<numeric>
using namespace std;
int solution(int X, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int,int> m;
    //for(int i=0;i<A.size();i++)m[A[i]]=-1;
    for(int i=0;i<A.size();i++)
    {
     //   if(m[A[i]]==-1) m[A[i]]=i;
   //     else m[A[i]]=min(m[A[i]],i);
        m[A[i]]=i;
     // cout<<m[A[i]]<<' '<<i<<endl;
         if(m.size()==X)
        {
            auto mx=* max_element(m.begin(),m.end(),[](pair<int,int> p1, pair<int,int> p2){ return p1.second<p2.second;});
            return mx.second;
        }
   

    }
   //  for(auto &x:m) cout<<x.first<<' '<<x.second<<endl;

//    cout<<"why"<<endl;
    return -1;
}
