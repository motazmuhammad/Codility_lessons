/* this is the solution after cleaning it is more concise, easy to understand, and shorter */

#include<vector>
#include<algorithm>
#include<numeric>
#include <unordered_map>

void update_solution(const vector<int> &nucletids_indices,const int which_nucletid,const int range_start,const int range_end,vector<int> &sol, bool &is_updated)
{
    auto mn=lower_bound(nucletids_indices.begin(),nucletids_indices.end(),range_start);

    if(mn!=nucletids_indices.end())
    {
        if(*mn<=range_end)
        {
            sol.push_back(which_nucletid);
            is_updated=true;;
        }
    }
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    const int number_of_nucletides=4;// given by the problem statement
    vector<vector<int>> nucletides_indices(number_of_nucletides);// a vector to save the indices of each nucletide
    for(auto x:nucletides_indices) x.reserve(S.length());// to make push_back take O(1) instead of O(log(N))
    unordered_map<char ,int> map_nucletides_to_integers={{'A',0},{'C',1},{'G',2},{'T',3}};// mapping of the nucletides to numbers for ease of use
    for(auto& nucletide:S)nucletides_indices[map_nucletides_to_integers[nucletide]].push_back(i);
    vector<int> sol;// the return vector as specified by the problem
    sol.reserve(S.length());
    bool is_updated;// to halt when the solution is updated
    for(int i=0;i<P.size();i++)
    {
       for(int j=0;j<number_of_nucletides;j++)
       {
            is_updated=false;
            update_solution(nucletides_indices[j],j+1,P[i],Q[i],sol,is_updated);
            if(is_updated==true) break;
       }
    }
    return sol;
}
