/*while this solution passes the test cases of codility, I really don't like it. I will try to improve it and update it.*/
#include<vector>
#include<algorithm>
#include<numeric>
enum nucletids{A,C,G,T};

void update_solution(const vector<int> &nucletids_indices,const int which_nucletid,const int range_start,const int range_end,vector<int> &sol, bool &is_updated)
{
    auto mn=lower_bound(nucletids_indices.begin(),nucletids_indices.end(),range_start);
   // auto mx=find_lower(nucletids_indices.begin(),nucletids_indices.end(),range_end);
    if(mn!=nucletids_indices.end())
    {
        if(*mn<=range_end)
        {
            sol.push_back(which_nucletid);
            is_updated=true;;
            return;
        }
    }
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> A_indices;
    vector<int> C_indices;
    vector<int> G_indices;
    vector<int> T_indices;
    A_indices.reserve(S.length());
    C_indices.reserve(S.length());
    G_indices.reserve(S.length());
    T_indices.reserve(S.length());
    for(int i=0;i<S.length();i++)
    {
        switch(S[i])
        {
            case('A'):A_indices.push_back(i);break;
            case('C'):C_indices.push_back(i);break;
            case('G'):G_indices.push_back(i);break;
            case('T'):T_indices.push_back(i);break;
        }
            
    }vector<int> sol;
    sol.reserve(S.length());
    bool is_updated;
    for(int i=0;i<P.size();i++)
    {
        //for(auto&x:sol) cout<<x<<' ';
        //cout<<endl;
        is_updated=false;
        update_solution(A_indices,1,P[i],Q[i],sol,is_updated);
        if(is_updated==true) continue;
        is_updated=false;
        update_solution(C_indices,2,P[i],Q[i],sol,is_updated);
        if(is_updated==true) continue;
        is_updated=false;
        update_solution(G_indices,3,P[i],Q[i],sol,is_updated);
        if(is_updated==true) continue;
        is_updated=false;
        update_solution(T_indices,4,P[i],Q[i],sol,is_updated);
        if(is_updated==true) continue;
       
        
        
    }
    return sol;
}
