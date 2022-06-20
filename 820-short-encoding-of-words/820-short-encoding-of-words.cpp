class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        for(auto &word: words){
            reverse(word.begin(), word.end());
        }
        sort(words.begin(), words.end());
        int i;
        int n = words.size();
        string str = words[0];
        int count = 0, size;
        for(i=1;i<n;i++){
            size = str.size();
            if(words[i].compare(0, size, str)){
                count += 1 + size;
            }
            str = words[i];
        }
        count += str.size()+1;
        return count;
    }
};