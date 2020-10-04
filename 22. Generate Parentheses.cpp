class Solution {
public:
    void printparenthesis(int n,int open,int close,string str,vector<string>&ans)
    {
     if(close==n)
     {
         ans.push_back(str);
         return;
     }
     else
     {
      if(open>close)
        printparenthesis(n,open,close+1,str+')',ans);
      
      if(open<n)
        printparenthesis(n,open+1,close,str+'(',ans);
      
     }
    }
    vector<string> generateParenthesis(int n)
    {
      vector<string>ans;
      if(n==0)return ans;
      printparenthesis(n,0,0,"",ans);
      return ans;
    }
};

/*
Time Complexity: O(2^n).
For every index there can be two options ‘{‘ or ‘}’. So it can be said that the upperbound of time complexity is O(2^n) or it has exponential time complexity.
Space Complexity: O(n).
The space complexity can be reduced to O(n) if global variable or static variable is used to store the output string.
*/
