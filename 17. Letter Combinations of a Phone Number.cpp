class Solution {
public:
    void doit(string digits,vector<string>&dict,vector<string>&ans,string temp,int idx)
    {
     if(idx==digits.size())
     {
      ans.push_back(temp);
      return;
     }
     for(auto xx:dict[digits[idx]-'0'])
     {
      temp.push_back(xx);
      doit(digits,dict,ans,temp,idx+1);
      temp.pop_back();
     }
    }
    vector<string> letterCombinations(string digits) 
    { 
     vector<string>ans;
     int n=digits.size();
     if(n==0)
         return ans;
     vector<string>dict;
     dict.push_back("");
     dict.push_back("");
     dict.push_back("abc");
     dict.push_back("def");
     dict.push_back("ghi");
     dict.push_back("jkl");
     dict.push_back("mno");
     dict.push_back("pqrs");
     dict.push_back("tuv");
     dict.push_back("wxyz");
     //dict.push_back("");
     doit(digits,dict,ans,"",0);
     //cout<<ans.size();
     return ans;
    }
};
