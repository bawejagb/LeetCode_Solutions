class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int> alpha;
        for(int i = 0; i < order.size(); i++)
            alpha[order[i]] = i; 
        for(int i = 1; i < words.size();i++){
            int a = 0;
            while(a < min(words[i].size(), words[i-1].size())){
                if(alpha[words[i][a]] > alpha[words[i-1][a]]) break;
                else if(alpha[words[i][a]] == alpha[words[i-1][a]]) a++;
                else return 0;
            }
            if(a == min(words[i].size(), words[i-1].size())){
                if(words[i].size() < words[i-1].size()) return 0;
            }
        }
        return 1;
    }
    
};