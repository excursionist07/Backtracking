// 46. Permutations

class Solution {
public:
    void permute(vector<int>& nums,int idx,vector<vector<int>>& ans)
    {
     if(idx==nums.size())
     {
      ans.push_back(nums);
      return;
     }
     for(int i=idx;i<nums.size();i++)
     {
      swap(nums[i],nums[idx]);
      permute(nums,idx+1,ans);
      swap(nums[i],nums[idx]); // reset/backtrack
       
     }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
     int n=nums.size();
     vector<vector<int>>ans;
     permute(nums,0,ans);
     return ans;
     
     
    }
};
// using STL

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
      vector<vector<int>>ans;
      int n=nums.size();
      if(n==0)
          return ans;
      sort(nums.begin(),nums.end());
      do{
         ans.push_back(nums);
      }while(next_permutation(nums.begin(),nums.end()));
      return ans;
    }
};

// 47. Permutations II

class Solution {
public:
    vector<vector<int>>permuteUnique(vector<int>& nums)
    {
     int n=nums.size();
     vector<vector<int>>ans;
     set<vector<int>>ss;
     if(n==0)
         return ans;
     sort(nums.begin(),nums.end());
     do{
        ss.insert(nums);
     }while(next_permutation(nums.begin(),nums.end()));
     
     for(auto xx:ss)
         ans.push_back(xx);
     return ans;
    }
};

// 31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
     int n=nums.size();
     int idx=-1,i=n-2;
     for(i=n-2;i>=0;i--)
     {
      if(nums[i]<nums[i+1])
      {
       idx=i;
       break;
      }
     }
     if(i==-1)
         reverse(nums.begin(),nums.end());
     else
     {
     int minn=INT_MAX,idx1;
     for(int i=idx+1;i<n;i++)
     {
      if(nums[i]>nums[idx] && nums[i]<minn)
      {
       minn=nums[i];
       idx1=i;
      }
     }
      swap(nums[idx],nums[idx1]);
      sort(nums.begin()+idx+1,nums.end());
     }
     
     
    }
};
