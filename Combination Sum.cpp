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
