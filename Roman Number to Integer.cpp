class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        int n = str.size();
        unordered_map<char,int>m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans = 0;
        ans+=m[str[str.size()-1]];
        for(int i = str.size()-2;i>=0;i--){
            if(m[str[i]]>=m[str[i+1]]) ans+=m[str[i]];
            else ans-=m[str[i]];
        }
        return ans;
        
        
    }
};
