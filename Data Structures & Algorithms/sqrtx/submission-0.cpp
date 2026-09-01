class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0;
        long long hi = x;
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            long long y = (long long)x;
            if(mid * mid == y) return mid;
            else if(mid * mid > y) hi = mid - 1;
            else lo = mid + 1;   
        }
        return hi;
    }
};