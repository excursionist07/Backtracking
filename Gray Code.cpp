// 89. Gray Code

// The gray code is a n bits binary numeral system where two successive values differ in only one bit.

class Solution {
public:
    vector<int> grayCode(int n) 
    {
     vector<string>ans;
     vector<int>res;   
     if(n==0)
     {
      res.push_back(0);
      return res;
     }
     ans.push_back("0");
     ans.push_back("1");
     for(int i=1;i<n;i++)
     {
      int zz=ans.size();
      for(int j=zz-1;j>=0;j--)
          ans.push_back(ans[j]);
      for(int p=0;p<zz;p++)
          ans[p]="0"+ans[p];
      for(int q=zz;q<2*zz;q++)
          ans[q]="1"+ans[q];
     }
     
     for(int i=0;i<(1<<n);i++)
         res.push_back(stoi(ans[i],0,2));// converts binary string to decimal number
     return res;
     
    }
};
