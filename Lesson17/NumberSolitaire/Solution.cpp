/* The idea is pretty straight forward.
For each location. Loop over all the locations you could have come from, and take the maximum so far
important pitfalls.

Due to the fact that the result can be negative. one has to initialize the dp array with the least possible negative value
*/

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    const int faces=6;
    const long long min_el=-10000;
    const long long max_tot_size=100000;
    vector<long long>dp(A.size(),min_el*max_tot_size-1);
    dp[0]=A[0];
    for(int i=1;i<A.size();i++)
    {
        for(int j=1;j<=faces;j++)
        {
            if(i-j>=0)
            {
                dp[i]=max(dp[i],dp[i-j]+A[i]);
            }
        }
    }
    return dp[A.size()-1];
}
