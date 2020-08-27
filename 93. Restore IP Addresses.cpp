class Solution {
public:
    bool IsValid(string str)
    {
     vector<string>vv;
     string temp="";
     int idx=0;
     while(idx<str.length())
     {
      if(str[idx]=='.')
      {
       vv.push_back(temp);
       temp="";
      }
      else
          temp+=str[idx];
      idx++;
     }
     vv.push_back(temp);
     for(int i=0;i<vv.size();i++)
     {
      if(vv[i].size()>3 || stoi(vv[i])>255)
          return false;
      if(vv[i].size()>1 && vv[i][0]=='0')
          return false;
     }
     return true;
    }
    
    void doit(string s,vector<string>&ans)
    {
     int n=s.length();
     string temp=s;
     for(int i=1;i<n-2;i++)
     {
      for(int j=i+1;j<n-1;j++)
      {
       for(int k=j+1;k<n;k++)
       {
        temp=temp.substr(0,k)+"."+temp.substr(k,n-k);
        temp=temp.substr(0,j)+"."+temp.substr(j,n-j+1);// after above step temp size increases by 1 due to 1 dot
        temp=temp.substr(0,i)+"."+temp.substr(i,n-i+2);// after above two steps temp size increases by 2 due to 2 dot
        if(IsValid(temp))
            ans.push_back(temp);
        temp=s;
       }
      }
     }
    }
    
    vector<string> restoreIpAddresses(string s)
    {
     vector<string>ans;
     int n=s.length();
     if(n<4 || n>12)
         return ans;
     doit(s,ans);
     return ans;
    }
};
