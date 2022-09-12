class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0, maxScore=0;
        sort(tokens.begin(), tokens.end());
        int i=0,j=tokens.size()-1;
        while(i<=j){
            if(tokens[i]<= power){
                power -= tokens[i];
                i++, score++;
                maxScore = max(maxScore, score);
            }
            else if(score>0){
                power+= tokens[j];
                j--;
                score--;
            }
            else
                break;
        }
        return maxScore;
    }
};