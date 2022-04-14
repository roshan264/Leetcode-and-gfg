class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n = ratings.size();
        int left[n] , right[n];
        
        memset(left , 0,sizeof(left));
        memset(right , 0, sizeof(right));
        
        for(int i = 1 ; i < n ; i++)
        {
            if(ratings[i] > ratings[i-1])
            {
                left[i] = left[i-1] + 1;
            }
        }
        
       for(int i = n - 2 ; i >= 0 ; i--)
        {
            if(ratings[i] > ratings[i+1])
            {
                right[i] = right[i + 1] + 1;
            }
        }
        
        int ans = 0 ; 
        
        for(int i = 0 ; i < n ; i++)
        {
            ans = ans + max(left[i] , right[i]) + 1;
        }
        
        return ans;
    }
};

