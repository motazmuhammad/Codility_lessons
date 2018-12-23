/* The problem is really trivial no need to explain the algorithm*/
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int>ps(A.size(),0);// a vector to keep track of the partial sum values
    partial_sum(A.begin(),A.end(),ps.begin());// calculate the partial sum
    long long sum=0;// calculate the number of passing cars
    for( int i=0;i<ps.size();i++)
    {
        if(A[i]==0)// if there is a car moving east
        {
         sum+=ps[ps.size()-1]-ps[i];   // count the number of the cars passing by it
        }
    }
    return sum<=1000000000?sum:-1;// this condition is from the problem describtion
    
}
