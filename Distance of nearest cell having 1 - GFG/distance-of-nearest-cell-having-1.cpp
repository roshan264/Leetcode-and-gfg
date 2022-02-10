// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    if(grid.size() == 0)
	    {
	        return grid;
	    }
	    vector<vector<int>> ans(grid.size() , vector<int> (grid[0].size() , 1000));
	    	
	    int r = grid.size() , c = grid[0].size();
        for(int i = 0 ; i < r; i++)
        {
            for(int j = 0 ; j < c ; j++)
            {
                if(grid[i][j] == 1)
                {
                    ans[i][j] = 0;
                    continue;
                }
                
                if(i > 0)
                {
                    ans[i][j] = min(ans[i - 1][j] + 1 , ans[i][j]);   
                }
                
                if( j > 0)
                {
                    ans[i][j] = min(ans[i][j] , ans[i][j - 1] + 1);
                }
            }
        }
        
        
        for(int i = r - 1 ; i >= 0 ; i--)
        {
            for(int j = c - 1 ; j >= 0 ; j--)
            {
                if(grid[i][j] == 1)
                {
                    ans[i][j] = 0;
                    continue;
                }
                
                if(i < r - 1)
                {
                    ans[i][j] = min(ans[i + 1][j] + 1 , ans[i][j]);   
                }
                
                if( j < c - 1)
                {
                    ans[i][j] = min(ans[i][j] , ans[i][j + 1] + 1);
                }
            }
        }
        
        return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends