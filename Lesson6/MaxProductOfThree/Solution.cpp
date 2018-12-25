/* The idea is quite simple, First, sort the array, the the maximum occurs at either the multiplication of the three last element or the first two and the last 
#include<algorithm>
using namespace std;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(),A.end());
    return max(A[0]*A[1]*A[A.size()-1],A[A.size()-3]*A[A.size()-2]*A[A.size()-1]);
}
