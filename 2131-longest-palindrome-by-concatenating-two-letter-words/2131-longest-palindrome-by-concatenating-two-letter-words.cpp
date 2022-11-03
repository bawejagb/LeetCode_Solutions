class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        bool flag = false;
        int ans = 0;

        for(auto& it : words){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second > 0){
                string temp = it.first;
                reverse(temp.begin(), temp.end());

                if(temp == it.first){
                    int cnt = mp[temp];
                    if(cnt%2 != 0){
                        flag = true;
                    }
                    ans += (cnt/2) * 4;
                    mp[temp] = 0;
                }
                else if(mp.find(temp) != mp.end() && mp[temp] > 0){
                    int cnt = min(mp[temp],it.second);
                    ans += cnt*4;
                    mp[temp] = 0;
                    mp[it.first] = 0;
                }
            }
        }

        if(flag) {
            ans += 2;
        }
        return ans;
    }
};