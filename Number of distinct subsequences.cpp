const int MOD = 1e9+7;
class Solution{
public:
	int distinctSubsequences(string s) {
	    int n = s.length();
	    vector<int> dp(n + 1, 0);
	    vector<int> last(256, -1); //or a map
	    
	    dp[0] = 1;

	    for (int i = 1; i <= n; i++) {
	        char ch = s[i-1];
	        dp[i] = (2 * dp[i-1]) % MOD;  //include or exclude current character
	        if (last[ch] != -1) { //appeared before
	            dp[i] = (dp[i] - dp[last[ch] - 1] + MOD) % MOD;  // subtract non-distinct subsequences
	        }
	        last[ch] = i;  // update the last occurrence
	    }

	    return (dp[n]+ MOD) % MOD;
	}
};
