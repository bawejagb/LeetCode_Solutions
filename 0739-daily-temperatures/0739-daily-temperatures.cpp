class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>answer(n,0);
        int maxTemp = 0;
        for(int currDay=n-1;currDay>=0;currDay--){
            int currTemp = temperatures[currDay];
            if(currTemp>=maxTemp){
                maxTemp=currTemp;
                continue;
            }
            int days = 1;
            while(currTemp>=temperatures[currDay+days])
                days+=answer[currDay+days];
            answer[currDay]=days;
        }
        return answer;
    }
};