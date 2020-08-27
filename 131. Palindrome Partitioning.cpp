class Solution {
public:
    bool IsPal(string s,int start,int end)
    {
     while(start<=end)
     {
      if(s[start++]!=s[end--])
          return false;
     }
     return true;
    }
    void doit(string s,vector<string>temp,vector<vector<string>>&ans,int idx)
    {
     if(idx==s.length())
     {
      ans.push_back(temp);
      return;
     }
     for(int i=idx;i<s.length();i++)
     {
      if(IsPal(s,idx,i))
      {
       temp.push_back(s.substr(idx,i-idx+1));
       doit(s,temp,ans,i+1);
       temp.pop_back();
      }
     }
    }
    vector<vector<string>> partition(string s) 
    {
     vector<vector<string>>ans;
     int n=s.length();
     if(n==0)
         return ans;
     vector<string>temp;
     doit(s,temp,ans,0);
     return ans;
    }
};

// time complexity = O(n* (2^n))
