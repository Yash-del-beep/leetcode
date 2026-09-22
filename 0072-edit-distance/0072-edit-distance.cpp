class Solution {
public:
int solve(int i,int j,string& word1,string& word2,vector<vector<int>>&dp){
    if(i==word1.size()) return  word2.size()-j;
    if(j==word2.size()) return word1.size()-i;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(word1[i]==word2[j]){
         return dp[i][j]=solve(i+1,j+1,word1,word2,dp);
    }
    int insertOp=1+solve(i,j+1,word1,word2,dp);
    int deleteOp=1+solve(i+1,j,word1,word2,dp);
    int ReplaceOp=1+solve(i+1,j+1,word1,word2,dp);

    return dp[i][j]=min({insertOp,deleteOp,ReplaceOp});
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,word1,word2,dp);
        
    }
};