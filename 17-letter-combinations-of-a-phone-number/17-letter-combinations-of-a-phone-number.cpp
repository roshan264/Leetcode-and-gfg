class Solution {
public:
    vector<string>ans;
    string numToChar[10];
    void findCombinations(int indDigit ,  string digits , string tempAns)
    {
        if(indDigit == digits.length())
        {
            if(tempAns != "")
            ans.push_back(tempAns);
            return;
        }
        int digit = digits[indDigit] - '0';
        string letters = numToChar[digit];
    
        for(int i = 0 ; i < letters.length() ; i++)
        {
            findCombinations(indDigit + 1,digits , tempAns + letters[i]);
        }
        
    }
    vector<string> letterCombinations(string digits) {
       
        numToChar[2] = "abc";
        numToChar[3] = "def";
        numToChar[4] = "ghi";
        numToChar[5] = "jkl";
        numToChar[6] = "mno";
        numToChar[7] = "pqrs";
        numToChar[8] = "tuv";
        numToChar[9] = "wxyz";
        
        ans.clear();
        findCombinations(0,digits,"");
        return ans;
    }
};