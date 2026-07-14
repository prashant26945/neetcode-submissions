class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() == 0)
            return string(1, char(258));

        string separator = string(1, char(257));

        string ans = "";

        for(string s : strs){
            ans += s;
            ans += separator;
        }

        ans.pop_back();

        return ans;
    }

    vector<string> decode(string s) {
        if(s == string(1, char(258)))
            return {};

        string separator = string(1, char(257));

        vector<string> ans;

        string temp="";

        for(char c:s){

            if(c==separator[0]){
                ans.push_back(temp);
                temp="";
            }
            else
                temp+=c;
        }

        ans.push_back(temp);

        return ans;
    }
};
