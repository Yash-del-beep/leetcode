class Solution {
public:
   vector<vector<int>> ans;
void solve(int i,int target,vector<int> & curr,vector<int>& candidates){
    if(target==0){
        ans.push_back(curr);
        return ;
    }
    if(i==candidates.size()){
        return ;
    }
    if(candidates[i]<=target){
         curr.push_back(candidates[i]);
         solve(i,target-candidates[i],curr,candidates);
         curr.pop_back();

    }
    solve(i+1,target,curr,candidates);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve( 0,target,curr,candidates);
        return ans;
        
    }
};