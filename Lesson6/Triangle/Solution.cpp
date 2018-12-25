// This solution is tested by codility test cases.
// The algorithm is pretty simple the array size has to be greater than or equal to three otherwise it can not form a triangle.
// Then a triangle side has to be greater than 0, then after sorting if there is a way to form a triangle then three consecutive number have 
// to be able to form one. The proof of this is quite simple and left as an exercise to the reader( please note that the three inequalities
// as well as the fact that the array is sorted is needed to complete the proof.
#include<algorithm>
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size()<3) return 0;// sanity check
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-2;i++)
    {
        if(A[i]<=0) continue;// there is no triangle side that is less than or equal to zero
        long long a=A[i];//long long is used to avoid overflow when the additions is done
        long long b=A[i+1];// from a programming point of view it is better to pull those three lines on a function by their own
        long long c=A[i+2];
        if((a+b)>c)return 1;
    }
    return 0;
}
