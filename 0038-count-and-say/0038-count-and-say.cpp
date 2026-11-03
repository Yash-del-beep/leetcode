class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string res="";
        string ans=countAndSay(n-1);
        int count=0;
        for(int i=0;i<ans.size();i++){
            if(i==0){
                count=1;
            }
            else if(ans[i]==ans[i-1]){
                count++;
            }
            else{
                res += to_string(count);   
                res += ans[i-1];           
                count=1;
            }
        }
        res+=to_string(count);
        res+=ans[ans.size()-1];
        return res;
    }
};