class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // int len = 0;
        // int maxLen = 0;
        // for(int i = 0; i < n; i++){
        //     int hash[256] = {0};
        //     for(int j = i; j < n; j++){
        //         if(hash[s[j]] == 1) break;
        //         len = j - i + 1;
        //         maxLen = max(len, maxLen);
        //         hash[s[j]] = 1;
        //     }
        // }
        // return maxLen;

        
        
        
        //(Slidind window approach)
        int n = s.size();
        int hash[256];
        for(int i = 0; i < 256; i++) {
            hash[i] = -1;
        }
        int l = 0, r = 0, len = 0, maxLen = 0;
        while(r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            }
            len = r-l+1;
            maxLen = max(len, maxLen);
            hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};
