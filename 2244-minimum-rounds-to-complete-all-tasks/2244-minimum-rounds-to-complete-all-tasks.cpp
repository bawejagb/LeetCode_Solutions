class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int cnt=1, num=tasks[0], res=0;
        for(int i=1; i<tasks.size();i++){
            if(tasks[i]!=tasks[i-1]){
                int val = cnt/3;
                cnt %=3;
                if(cnt==0)
                    res += val;
                else if(cnt==2)
                    res+= val+1;
                else if(val>0)
                    res += val+1;
                else return -1;
                cnt=0;
            }
            cnt++;
        }
        int val = cnt/3;
        cnt %=3;
        if(cnt==0)
            res += val;
        else if(cnt==2)
            res+= val+1;
        else if(val>0)
            res += val+1;
        else return -1;
        return res;
    }
};