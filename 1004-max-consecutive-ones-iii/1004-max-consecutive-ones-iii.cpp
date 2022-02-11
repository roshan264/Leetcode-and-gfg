class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int ans = 0 , strt = -1 , end = 0;
        
        for(int end = 0 ; end < nums.size() ; end++)
        {
            if(nums[end] == 0)
            {
                if(k > 0)
                {
                    k--;
                }
                else
                {
                    
                    while(k <= 0 && strt < end)
                    {
                        strt++;
                        if(nums[strt] == 0)
                        {
                            k++;
                        }
                    }
                    
                    k--;
                }
            }
            
            ans = max(ans , end - strt);
        }
        
        return ans;
    }
};