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
