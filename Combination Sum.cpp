// 39. Combination Sum

class Solution {
public:
    vector<vector<int>>ans;
    void combination(vector<int>& candidates,int target,int sum,int index,vector<int>&res)
    {
     if(sum==target)
     {
      ans.push_back(res);
      return;
     }
     if(candidates.size()==index || candidates[index]+sum>target)
         return;
     res.push_back(candidates[index]);
     combination(candidates,target,sum+candidates[index],index,res);
     res.pop_back();
     combination(candidates,target,sum,index+1,res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
     vector<int>res;
     sort(candidates.begin(),candidates.end());
     combination(candidates,target,0,0,res);
     return ans;
    }
};

// 40. Combination Sum II

// 1st method

class Solution {
public:
    set<vector<int>>ss;
    void doit(vector<vector<int>>&ans,vector<int>&res,vector<int>&candidates,int tar,int idx)
    {
     if(tar<0)
         return;
     if(tar==0)
     {
      //ans.push_back(res);
      ss.insert(res);
      return;
     }
     for(int i=idx;i<candidates.size();i++)
     {
      //if(i>idx && candidates[i]==candidates[i-1])
         // continue;
      res.push_back(candidates[i]);
      doit(ans,res,candidates,tar-candidates[i],i+1);
      res.pop_back();
     }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
     ss.clear();
     int n=candidates.size();
     vector<vector<int>>ans;
     vector<int>res;
     if(n==0)
         return ans;
     sort(candidates.begin(),candidates.end());
     doit(ans,res,candidates,target,0);
     for(auto xx:ss)
         ans.push_back(xx);
     return ans;
    }
};

// 2nd method

class Solution {
public:
    void doit(vector<vector<int>>&ans,vector<int>&res,vector<int>&candidates,int tar,int idx)
    {
     if(tar<0)
         return;
     if(tar==0)
     {
      ans.push_back(res);
      return;
     }
     for(int i=idx;i<candidates.size();i++)
     {
      if(i>idx && candidates[i]==candidates[i-1])// for not storing duplicate answer(i.e-[1,2,2,2,5] and tar=5, so not storing {1,2,2} 2 times)
          continue;
      res.push_back(candidates[i]);
      doit(ans,res,candidates,tar-candidates[i],i+1);
      res.pop_back();
     }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
     int n=candidates.size();
     vector<vector<int>>ans;
     vector<int>res;
     if(n==0)
         return ans;
     sort(candidates.begin(),candidates.end());
     doit(ans,res,candidates,target,0);
     return ans;
    }
};


