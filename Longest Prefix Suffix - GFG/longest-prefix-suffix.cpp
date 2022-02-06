// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int index[s.length()];
	    
	    memset(index , 0 , sizeof(index));
	    
	    int i = 0 , ans = 0;
	    
	    for(int j = 1 ; j < s.length() ; j++)
	    {
	        if(s[i] == s[j])
	        {
	            index[j] = i + 1;
	            i++;
	        }
	        else
	        {
	            if(i != 0)
	            {
	                i = index[i-1];
	                j--;
	            }
	            else
	            {
	                index[j] = 0;
	            }
	        }
	        
	        ans = max(ans , index[j]);
	        //cout<<index[j]<<" ";
	    }
	    
	    return index[s.length()-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends