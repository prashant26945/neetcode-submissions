class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, int> m;
        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
        }

        for(int i = 0; i < t.length(); i++){
            char ch = t[i];
            if(m.find(ch) != m.end()){
                m[ch]--;
                if(m[ch] == 0) m.erase(ch);
            }
            else return false;
        }

        if(m.size() > 0) return false;
        return true;
    }
};
