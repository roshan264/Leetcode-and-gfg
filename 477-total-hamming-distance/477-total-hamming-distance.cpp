class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
     
        int cnt1[64] , n = nums.size();
        
        memset(cnt1 , 0 , sizeof(cnt1));
        
        for(int i = 0 ; i < n ; i++)
        {
            int ind = 0;
            
            while(nums[i] > 0)
            {
                if(nums[i] % 2 == 1)
                {
                    cnt1[ind]++;        
                }
                
                ind++;
                nums[i] = nums[i] / 2;
            }
        }
        
        int ans = 0;
        for(int i = 0 ; i < 64 ; i++)
        {
            ans = ans + cnt1[i] * (n - cnt1[i]);
        }
        
        return ans;
    }
};