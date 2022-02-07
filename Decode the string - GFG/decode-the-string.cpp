// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:

string mul( string str , string r)
{
    string ans = "";
    
    int rep = stoi(r);
    while(rep--)
    {
        ans = ans + str;
    }
    
    return ans;
}
    string decodedString(string s){
        // code here
        
        stack<string>st;
        
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                int len = 0 , j  = i;
                string dig = "";
                while(s[i] >= '0' && s[i] <= '9')
                {
                    len++;
                    i++;
                }
                i--;
                st.push(s.substr(j , len));
            }
            else if(s[i] == ']')
            {
                string prev = "";
                while(st.top() != "[")
                {
                    prev =  st.top() + prev;
                    st.pop();
                }
                st.pop();
                
                string temp = mul(prev , st.top());
                st.pop();
                st.push(temp);
                
            }
            else
            {
                st.push(s.substr( i , 1));
            }
        }
        
        string prev = "";
                while( !st.empty() )
                {
                    prev =  st.top() + prev;
                    st.pop();
                }
        
        return prev;
    }
};

 //3 [a3[b]1[ab]]
 


// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends