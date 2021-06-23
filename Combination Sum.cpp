// 39. Combination Sum

class Solution {
public:
    void doit(vector<int>&candidates,vector<int>vv,vector<vector<int>>&ans,int idx,int sum,int tar)
    {
     if(idx>=candidates.size() || sum>tar)
         return;
     if(sum==tar)
     {
      ans.push_back(vv);
      return;
     }
     vv.push_back(candidates[idx]);
     doit(candidates,vv,ans,idx,sum+candidates[idx],tar);
     vv.pop_back();
     doit(candidates,vv,ans,1+idx,sum,tar);
     
     
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
      int n=candidates.size();
      sort(candidates.begin(),candidates.end());
      vector<vector<int>>ans;
      vector<int>vv;
      doit(candidates,vv,ans,0,0,target);
      return ans;
      
    }
}; //--> The time complexity is O(k * 2^N) , where k is the average length of each possible solution.

// 40. Combination Sum II

// 1st method

class Solution {
public:
    void doit(vector<int>&candidates,vector<int>res,set<vector<int>>&ss,int tar,int sum,int idx)
    {
     if(sum>tar)
         return;
     if(sum==tar)
     {
      ss.insert(res);
      return;
     }
     for(int i=idx;i<candidates.size();i++)
     {
     res.push_back(candidates[i]);
     doit(candidates,res,ss,tar,sum+candidates[i],i+1);
     res.pop_back();
     }
         
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
     vector<int>res;
     vector<vector<int>>ans;
     sort(candidates.begin(),candidates.end());
     set<vector<int>>ss;
     doit(candidates,res,ss,target,0,0);
     for(auto xx:ss)
         ans.push_back(xx);
     return ans;
    }
};


// 2nd method


class Solution {
public:
    void doit(vector<int>&candidates,vector<int>res,vector<vector<int>>&ans,int tar,int sum,int idx)
    {
     if(sum>tar)
         return;
     if(sum==tar)
     {
      ans.push_back(res);
      return;
     }
     for(int i=idx;i<candidates.size();i++)
     {
     if(i>idx && candidates[i]==candidates[i-1])// for not storing duplicate answer(i.e-[1,2,2,2,5] and tar=5, so not storing {1,2,2} 2 times)
          continue;
     res.push_back(candidates[i]);
     doit(candidates,res,ans,tar,sum+candidates[i],i+1);
     res.pop_back();
     }
         
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
     vector<int>res;
     vector<vector<int>>ans;
     sort(candidates.begin(),candidates.end());
     doit(candidates,res,ans,target,0,0);
     return ans;
    }
};

// 216. Combination Sum III

class Solution {
public:
    void doit(vector<int>&candidates,vector<int>res,vector<vector<int>>&ans,int k,int tar,int idx)
    {
     if(tar<0)
         return;
     if(tar==0 && res.size()==k)
     {
      ans.push_back(res);
      return;
     }
     for(int i=idx;i<candidates.size();i++)
     {
      res.push_back(candidates[i]);
      doit(candidates,res,ans,k,tar-candidates[i],i+1);
      res.pop_back();
     }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
     vector<int>candidates;
     for(int i=1;i<=9;i++)
         candidates.push_back(i);
     vector<int>res;
     vector<vector<int>>ans;
     doit(candidates,res,ans,k,n,0);
     return ans;
    }
};

// 377. Combination Sum IV

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
     int n=nums.size();
     if(target==0)
         return 1;
     if(n==0)
         return 0;
     unsigned int dp[target+1];
     for(int i=0;i<=target;i++)
         dp[i]=0;
     dp[0]=1;
     for(int i=1;i<=target;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(i-nums[j]>=0)
           dp[i]+=dp[i-nums[j]];
      }
     }
     return dp[target];
    }
};


