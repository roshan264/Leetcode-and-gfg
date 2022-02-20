class Solution {
public:
    int findSubstringInWraproundString(string p) {
        
        int maxLen[26];
        memset(maxLen , 0 , sizeof(maxLen));
        
        int next = p[p.length() - 1] - 'a' , cnt = 1;
        maxLen[next] = 1;
        
        for(int i = p.length() - 2 ; i >= 0 ; i--)
        {
            int curr = p[i] - 'a';
            
            if( (curr+1 )% 26 == next)
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            maxLen[curr] = max(maxLen[curr] , cnt);
            next = curr;
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++)
        {
            //cout<<maxLen[i]<<" ";
            
            ans = ans + maxLen[i];
        }
        
        return ans;
    }
};



