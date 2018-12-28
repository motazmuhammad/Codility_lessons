/* this is pretty straight forward check if the open brackets have their corresponding close brackets by a stack */


#include<queue>
#include<deque>
#include<algorithm>
#include<stack>

bool is_matching(const char c1, const char c2, const vector<char> &open_bracket,const vector<char> &close_bracket)
{
 
    auto itc1=find(open_bracket.begin(),open_bracket.end(),c1);
    
    auto itc2=find(close_bracket.begin(),close_bracket.end(),c2);

    int ret= (itc1-open_bracket.begin())==(itc2-close_bracket.begin());
    return ret;
}
inline bool is_open_bracket(const char c,const vector<char> &open_bracket )
{
    return (find(open_bracket.begin(),open_bracket.end(),c)!=open_bracket.end());
}
inline bool is_close_bracket(const char c,const vector<char> &close_bracket )
{
    return (find(close_bracket.begin(),close_bracket.end(),c)!=close_bracket.end());
}

int solution(string &S) {
    stack<char> q;
    vector<char> open_bracket={'{','[','('};
    vector<char> close_bracket={'}',']',')'};
    for(auto&s:S)
    {
        
        if(is_open_bracket(s,open_bracket))
        {
            q.push(s);
        }
        if(is_close_bracket(s,close_bracket))
        {
            if(q.size()==0) return 0;
            char c=q.top();
            if( !is_matching(c,s,open_bracket,close_bracket) )
            {
                return 0;
            }
            q.pop();
        }
        
    }
    return q.size()==0;
    // write your code in C++14 (g++ 6.2.0)
}
