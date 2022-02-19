class Solution {
public:
    
    vector<int> getMinLenOfTargetedSum(vector<int>arr , int target)
    {
        int n = arr.size();
        vector<int>minLeft(n , INT_MAX);
        
        int left = -1 , sum = 0;
  
        for(int right = 0 ; right < n ; right++)
        {
            sum = sum + arr[right];
            if(sum == target)
            {
                if(right == 0)
                {
                    minLeft[right] = (right - left);
                }
                else
                {
                    minLeft[right] = min(right - left , minLeft[right - 1]);
                }
            }
            else if(sum > target)
            {
                while(left < right && sum > target)
                {
                    left++;
                    sum = sum - arr[left];
                }
                
                if(left != right)
                {
                    sum = sum - arr[right];
                    right--;
                }
                else
                {
                    if(right > 0)
                    {
                        minLeft[right] = minLeft[right - 1];
                    }
                }
            }
            else
            {
                if(right > 0)
                {
                    minLeft[right] = minLeft[right - 1];
                }
            }
        }
        
       /* for(int i = 0 ; i < n ; i++)
        {
            cout<<minLeft[i]<<" ";
        }
        cout<<"\n";*/
        return minLeft;
    }
    int minSumOfLengths(vector<int>& arr, int target) {
        
        int n = arr.size();
        vector<int>minLeft , minRight;
        
        minLeft = getMinLenOfTargetedSum(arr , target);
        
        reverse(arr.begin() , arr.end());
        
        minRight = getMinLenOfTargetedSum(arr , target);
        
        reverse(minRight.begin() , minRight.end());
        
        int ans = INT_MAX;
        
        for(int i = 0 ; i < n - 1 ; i++)
        {
            
            if(minLeft[i] < 1000000 && minRight[i + 1] < 1000000)
            ans = min(ans , minLeft[i] + minRight[i + 1]);
        }
        if(ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};