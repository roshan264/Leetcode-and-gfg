// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    
    bool isMatching(int cnt[] , int flag[])
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            if(flag[i] > cnt[i])
            {//cout<<false;
                return false;
            }
        }
        
        return true;
    }
    string smallestWindow (string s, string p)
    {
        int flag[26] , cnt[26], total = 0 , ansLen = INT_MAX;
        string ans = "-1";
        
        memset(flag , -1 , sizeof(flag));
        memset(cnt , 0 , sizeof(cnt));
        
        
        for(int i = 0 ; i < p.length() ; i++)
        {
           if(flag[p[i] - 'a'] == -1)
           {
               flag[p[i] - 'a'] = 1;
           }
           else
           {
               flag[p[i] - 'a']++;
           }
        }
        
        int strt = -1;
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(flag[s[i] - 'a'] == -1)
            {
                continue;
            }
            
            cnt[s[i] - 'a']++;
            
            if(isMatching(cnt , flag))
            {
                while(isMatching(cnt , flag) && strt < i)
                {
                    int l = i - strt;
                    if(ansLen > l )
                    {
                        ansLen = l;
                        ans = s.substr(strt + 1 , l);
                    }
                    strt++;
                    if(flag[s[strt] - 'a'] == -1)
                    {
                        continue;
                    }
                    
                    cnt[s[strt] - 'a']--;
                }
            }
            
        }
        
        return ans;
    }
};

//"timetopractice"

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends