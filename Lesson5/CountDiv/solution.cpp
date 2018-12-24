// This is a pretty straight forward problem the number of divisor of K in A,B is (B-A+1)/K if(A and B are divisible by K)
// Therefore, the idea is to get the nearest number divisble by K from A,B, . Then apply the formula


#include<algorithm>
#include<numeric>
#include<math.h>
int solution(int A, int B, int K) {
    // write your code in C++14 (g++ 6.2.0)

    int r=A%K;
    if(r)r=K-r;
    A+=r;
    r=B%K;
    B-=r;
    //cout<<A<<' '<<B<<endl;
  
    return ceil((double)(B-A+1)/K);
}
