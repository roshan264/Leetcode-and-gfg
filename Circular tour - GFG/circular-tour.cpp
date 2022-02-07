// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int strt = 0 , petrol = 0 , distance = 0 , final = 0 , ans;
       int cnt = 2 * n +4;
       while(final < n && cnt)
       {
           cnt--;
           petrol += p[strt].petrol - p[strt].distance;
           final++;
           if(petrol < 0)
           {
               petrol = 0;
               final = 0;
               ans = (strt+ 1)%n;
           }
           strt++;
           strt = strt % n;
       }
       if(cnt == 0)
       {
           return -1;
       }
       return ans;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends