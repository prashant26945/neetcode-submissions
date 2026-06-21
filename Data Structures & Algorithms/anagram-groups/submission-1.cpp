class Solution {
public:

    string generate(string &word){
        int arr[26] = {0};

        for(char ch: word){
            arr[ch-'a']++;
        }
        
        string new_word = "";
        for(int i = 0; i < 26; i++){
            int freq = arr[i];
            if(freq > 0){
                new_word += string(freq, i+'a');
            }
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // vector<vector<string>> ans;
        // unordered_map<string, vector<string>> mp;

        // for(string s: strs){
        //     string lexo = s;
        //     sort(lexo.begin(), lexo.end());

        //     if(mp.find(lexo) == mp.end()){
        //         vector<string> v;
        //         v.push_back(s);
        //         mp[lexo] = v;
        //     }
        //     else{
        //         mp[lexo].push_back(s);
        //     }
        // }

        // for(auto x: mp){
        //     vector<string> v = x.second;
        //     ans.push_back(v);
        // }
        // return ans;


        // Optimal approach(0(n*k))
        int n = strs.size();
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++){
            string word = strs[i];

            string new_word = generate(word);

            mp[new_word].push_back(word);
        }

        for(auto &it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
