/* This solution solves the problem of MaxCounters desribed in problem.md the solution keeps track of the maximum element so far,
and how many increments are needed per element and does the process at the end*/
#include<algorithm>
#include<numeric>
#include<vector>
//#include<priority_queue>
using namespace std;
void perform(int N,int operation,vector<int>&res,int &mx,int &prev_mx)
{
    if(operation>=1&&operation<=N)// if the current operation is increment 1
    {
        //note this if statment is equivalent to (res[operation-1]=max((res[operation-1],prev_mx) )
        if(res[operation-1]<prev_mx)// if this element has not been increased yet
        {
           res[operation-1]=prev_mx; // increase it to previous maximum
        }
        res[operation-1]++;//perform the increment dectated by the increment operation
        mx=max(mx,res[operation-1]);//update the current maximum
    }
    else{// if the operation is to set the array with the maximum
    prev_mx=mx;//update the previous maximum
    }

}
vector<int> solution(int N, vector<int> &A) {
    vector<int>ret(N,0);//an empty vector for return 
    int mx=0;// the maximum element so far
    int prev_mx=0;//the maximum element until the last N+1 operation
    for(auto operation:A)//loop over all the operations
    {
        perform(N,operation,ret,mx,prev_mx);//decodes and performs the current operation
    }
    for(auto& x:ret) x=max(x,prev_mx);//generates the actual output array from the current state.
    return ret;
    // write your code in C++14 (g++ 6.2.0)
}
