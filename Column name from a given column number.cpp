class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        string ans = "";
        
        while(n > 0) {
            int rem = (n-1)%26;
            ans = char(rem + 'A') + ans;
            n = (n-1)/26;
        }
        
        return ans;
    }
};
