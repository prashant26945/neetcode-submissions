class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> v(26, 0);
        for(int i = 0; i < s.size(); i++){
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }

        for(auto count: v){
            if(count != 0) return false;
        }
        return true;
    }
};
