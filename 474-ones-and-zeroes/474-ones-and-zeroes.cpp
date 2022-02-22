class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
     
        int dp[m + 1][n + 1]; // m = zero
        
        memset(dp , 0 , sizeof(dp));
        
        for(int i = 0 ; i < strs.size() ; i++)
        {
            int cnt0 = 0 , cnt1 = 0;
            
            for(int j = 0 ; j < strs[i].length() ; j++)
            {
                if(strs[i][j] == '0')
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
            }
            
            
            for(int row = m ; row >= 0 ; row--)
            {
                for(int col = n ; col >= 0 ; col--)
                {
                    if(col - cnt1 >= 0 && row - cnt0 >= 0)
                    {
                        dp[row][col] = max(dp[row][col] , 1 + dp[row - cnt0][col - cnt1]);
                    }
                }
            }
        }
       // return 0;
        return dp[m][n];
    }
};