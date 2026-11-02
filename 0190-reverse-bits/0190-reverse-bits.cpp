class Solution {
public:
    int reverseBits(int n)
    {
        string nums = "";
        while(n>0)
        {
            nums += (n&1)+'0';
            n >>= 1;
        }
        for(int i=nums.length(); i<=32; i++)
        {
            nums+='0';
        }
        cout<<nums<<endl;
        int answer=0;
        for(int i=0; i<32; i++)
        {
            if(nums[i]=='1') answer+=(1<<(31-i));
        }
        return answer;
    }
};