// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
#include<numeric>
#include<vector>
//#include<priority_queue>
using namespace std;
void perform(int N,int operation,vector<int>&res,int &mx,int &prev_mx)
{
    if(operation>=1&&operation<=N)
    {
        if(res[operation-1]<prev_mx)
        {
           res[operation-1]=prev_mx; 
        }
        res[operation-1]++;
        mx=max(mx,res[operation-1]);
    }
    else{
    prev_mx=mx;
    }

}
vector<int> solution(int N, vector<int> &A) {
    vector<int>ret(N,0);
    int mx=0;
    int prev_mx=0;
    for(auto operation:A)
    {
        perform(N,operation,ret,mx,prev_mx);
       // for(auto x:ret) cout<<x<<' ';
    //    cout<<mx<<endl;
    }
    for(auto& x:ret) x=max(x,prev_mx);
    return ret;
    // write your code in C++14 (g++ 6.2.0)
}
