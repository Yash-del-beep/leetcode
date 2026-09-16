class Solution {
public:

    int solve(string &s, int i, int n,vector<int>& dp) {

        if (i == s.size()) {
            return 1;
        }

        if (s[i] == '0') {
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        
        int one_char = solve(s, i + 1, n,dp);

        int two_char = 0;

        if (i < n - 1) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                two_char = solve(s, i + 2, n,dp);
            }
        }

        return  dp[i]=one_char + two_char;
    }

    int numDecodings(string s) {
        int n = s.size();
       vector<int> dp(n,-1);

        return solve(s, 0, n,dp);
    }
};