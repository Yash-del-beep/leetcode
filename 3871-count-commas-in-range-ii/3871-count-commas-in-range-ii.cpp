class Solution {
public:
    long long countCommas(long long n) {
        long long curr=1000;
        long long res=0;
        while(curr<=n){
            res+=n-curr+1;
            curr*=1000;
        }
        return res;
    }
}; 