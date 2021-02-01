// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)

    int cnt = 0;
    int cntOnes = 0;
    int mx=0;
    while(N)
    {
        if(N&1)
        {
            cntOnes++;
            if(cntOnes>=2)
                mx= max(mx,cnt);
            cnt = 0;
        }
        else
        {
             if(cntOnes)
                cnt++;   
        }
        N/=2;
    }
    return mx;

}
