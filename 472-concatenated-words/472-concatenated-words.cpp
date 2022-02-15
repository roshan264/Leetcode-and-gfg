class Solution {
public:
    
    class Node
    {
        public:
        
        Node* next[26];
        bool stop;
        
        Node()
        {
            for(int i = 0 ; i < 26 ; i++)
            {
                next[i] = NULL;
            }
            
            stop = false;
        }
    };
    
    Node* head;
    int findNumberWordsinString(string s , int i)
    {
        
        Node* p = head;
        
        int ans = 0;
        
        for(int j = i ; j < s.length() ; j++)
        {
            int ind = s[j] - 'a';
            
            if(p->next[ind] != NULL)
            {
                if(p->next[ind]->stop == true)
                {
                    if(j == s.length() - 1)
                    {
                        return max(ans , 1);
                    }
                    
                    int cnt = findNumberWordsinString(s , j + 1);
                    
                    if( cnt > 0)
                    {
                        ans = max(ans , cnt + 1);
                    }
                   
                }
                p = p->next[ind];
            }            
            else
            {
              //  cout<<s<<" "<<i<<" "<<j<<" "<<ans<<" *\n";
                return ans;
            }
        }
        //cout<<ans<<"\n";
        return ans;
    }
    
    void insertInTrie(string s)
    {
        Node* p = head;
        
        for(int i = 0 ; i < s.length() ; i++)
        {
            int ind = s[i] - 'a';
            
            if(p->next[ind] == NULL)
            {
                p->next[ind] = new Node();
               // cout<<p->next[ind]<<" "<<s[i]<<"\n";
            }
            
            p = p->next[ind];
        }
        
        p->stop = true;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        int n = words.size();
        
        head = new Node();
        
        for(int i = 0 ; i < n ; i++)
        {
            insertInTrie(words[i]);
        }
       
        vector<string> ans;
        
        for(int i = 0 ; i < n ; i++)
        {
            if( findNumberWordsinString(words[i] , 0)  > 1)
            {
                ans.push_back(words[i] );
            }
        }
        
        return ans;
    }
};