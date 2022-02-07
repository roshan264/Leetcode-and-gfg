class Solution {
public:
    
   
    long long numberOfWeeks(vector<int>& milestones) {
        
        long long int maxNum = INT_MIN , sum = 0;
        
        for(int i = 0 ; i < milestones.size() ; i++)
        {
            sum += milestones[i];
            if(milestones[i] > maxNum)
            {
                maxNum = milestones[i];
            }
        }
             
        if(maxNum > (sum - maxNum))
        {
            return 2 * (sum - maxNum) + 1;
        }
        cout<<maxNum<<" "<< (sum - maxNum);
        return sum;
    }
};