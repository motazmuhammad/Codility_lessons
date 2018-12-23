/* This is the solution of the problem described in problem.md

The idea is quite simple we need to find out of the numbers in array A span all the numbers between 1 and n exactly or not.

Therefore we xor them together and xor the result with the numbers of 1 to n. Then result should be 0 */

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n=A.size();
    int myxor[]={n,1,n+1,0};// calculate xor of the numbers of 1 to n according to https://www.geeksforgeeks.org/calculate-xor-1-n/
    return ((accumulate(A.begin(),A.end(),0,[](int a, int b){return a^b;})^myxor[n%4])==0);// calculate xor(A[i],i=0...n-1) and xor the resutl with xor(i,i=1:n) and compare it to 0
    
}
