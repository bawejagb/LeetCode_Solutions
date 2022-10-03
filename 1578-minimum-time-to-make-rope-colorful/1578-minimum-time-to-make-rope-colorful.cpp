class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int tot,temp,res=0;
        temp = 0;
        tot=0;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                tot += neededTime[i-1];
                temp = max(temp,neededTime[i-1]);
                temp = max(temp,neededTime[i]);
            }
            else if(temp!=0){
                tot += neededTime[i-1];
                res += tot-temp;
                tot = temp = 0;
            }
        }
        if(temp!=0){
            tot += neededTime.back();
                res += tot-temp;
                tot = temp = 0;
        }
        return res;
    }
};