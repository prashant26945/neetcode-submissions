class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int> pre(n);
        // vector<int> suf(n);
        // vector<int> ans(n);

        // pre[0] = 1;
        // for(int i = 1; i < n; i++){
        //     pre[i] = nums[i-1]*pre[i-1];
        // }

        // suf[n-1] = 1;
        // for(int i = n-2; i >= 0; i--){
        //     suf[i] = nums[i+1]*suf[i+1];
        // }

        // for(int i = 0; i < n; i++){
        //     ans[i] = pre[i]*suf[i];
        // }
        // return ans;




        // (Only using one array)
        int n = nums.size();
        vector<int> pre(n);

        int p = nums[0];
        pre[0] = 1;
        for(int i = 1; i < n; i++){
            pre[i] = p;
            p *= nums[i];
        }

        p = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            pre[i] *= p;
            p *= nums[i];
        }

        return pre;

    }
};
