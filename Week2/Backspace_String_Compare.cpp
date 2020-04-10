#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
class Solution {
public:
    stack<char> cleanString(string S)
    {
        stack <char> st;
        for(char c: S)
        {
            if(c=='#')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(c);
            }
        }
        return st;
        
    }
    bool backspaceCompare(string S, string T) 
    {
        
        stack <char> Ss=cleanString(S);
        stack <char> Ts=cleanString(T);
        int Ssize=Ss.size();
        if(Ssize!=Ts.size())
        {
            return false;
        }
        for(int i=0;i<Ssize;i++)
        {
            if(Ss.top()!=Ts.top())
            {
                return false;
            }
            Ss.pop();
            Ts.pop();
        }
        return true;
    }
};

int main()
{
	Solution solve;
        string S;
        string T;
        cin>>S;
        cin>>T;
        cout<<solve.backspaceCompare(S,T)<<endl;
	return 0;
}
