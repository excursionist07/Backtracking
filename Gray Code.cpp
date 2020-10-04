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

/*
1) Let the list of (n-1)-bit Gray codes be L1. Create another list L2 which is reverse of L1. 
2) Modify the list L1 by prefixing a ‘0’ in all codes of L1. 
3) Modify the list L2 by prefixing a ‘1’ in all codes of L2. 
4) Concatenate L1 and L2. The concatenated list is required list of n-bit Gray codes.
For example, following are steps for generating the 3-bit Gray code list from the list of 2-bit Gray code list. 
L1 = {00, 01, 11, 10} (List of 2-bit Gray Codes) 
L2 = {10, 11, 01, 00} (Reverse of L1) 
Prefix all entries of L1 with ‘0’, L1 becomes {000, 001, 011, 010} 
Prefix all entries of L2 with ‘1’, L2 becomes {110, 111, 101, 100} 
Concatenate L1 and L2, we get {000, 001, 011, 010, 110, 111, 101, 100}
*/
