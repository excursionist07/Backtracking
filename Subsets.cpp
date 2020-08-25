// 78. Subsets(Distinct elements)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
      vector<vector<int>>ans;
      int n=nums.size();
      for(int i=0;i<(1<<n);i++)
      {
       vector<int>vv;
       for(int j=0;j<n;j++)
       {
         if(i & (1<<j))
             vv.push_back(nums[j]);
       }
        ans.push_back(vv);
      }
     return ans;
    }
}

// 90. Subsets II(Duplicate elements also present)

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
     int n=nums.size();
     vector<vector<int>>ans;
     sort(nums.begin(),nums.end());
     set<vector<int>>ss;
     for(int i=0;i<(1<<n);i++)
     {
      vector<int>vv;
      for(int j=0;j<n;j++)
      {
       if(i & (1<<j))
           vv.push_back(nums[j]);
      }
      ss.insert(vv);
     }
     for(auto xx:ss)
         ans.push_back(xx);
     return ans;
    }
};
