class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minLen = n+1;
        int i = 0;
        int j = 0;
        while(j < n){
            sum += nums[j];
            while(sum >= target){
                int len = j - i + 1;
                minLen = min(minLen, len);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        if(minLen == (n+1)) return 0;
        else return minLen;
    }
};