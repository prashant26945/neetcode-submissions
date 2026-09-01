class Solution {
public:
    int findLeftMost(vector<int>& nums, int target, int n){
        int lo = 0;
        int hi = n - 1;
        int first = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                    first = mid;
                    hi = mid - 1;;
            }
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return first;
    }
    int findRightMost(vector<int>& nums, int target, int n){
        int lo = 0;
        int hi = n - 1;
        int last = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                    last = mid;
                    lo = mid + 1;
            }
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = findLeftMost(nums, target, n);
        int r = findRightMost(nums, target, n);
        
        return {l,r};
    }
};