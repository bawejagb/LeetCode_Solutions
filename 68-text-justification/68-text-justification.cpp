class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int word_len = 0, start = 0, i = 0, num  = words.size();
        string curr;
        while (i < words.size()){
            if (word_len + words[i].size() + i - start <= maxWidth){
                word_len += words[i++].size();
            }else{
                int wordNum = i - start;
                int spaceWidth = (wordNum > 1) ? (maxWidth - word_len) / (wordNum - 1) : 0;
                int spaceRemain = (wordNum > 1) ? (maxWidth - word_len) % (wordNum - 1) : 0;
                int oneMoreSpace = start + spaceRemain;
                for (int j = start; j < oneMoreSpace; j++){
                    curr += (words[j] + string(spaceWidth + 1, ' '));
                }
                for (int j = oneMoreSpace; j < i - 1; j++){
                    curr += (words[j] + string(spaceWidth, ' '));
                }
                curr += (words[i - 1] + (wordNum == 1 ? string(maxWidth - words[i - 1].size(), ' ') : ""));
                ans.push_back(curr);
                start = i;
                word_len = 0;
                curr = "";
            }
        }
        for (int j = start; j < words.size() - 1; j++){
            curr += (words[j] + " ");
            word_len++;
        }
        curr += words[num - 1] + (maxWidth - word_len > 0 ? string(maxWidth - word_len, ' ') : "");
        ans.push_back(curr);
        return ans;
    }
};