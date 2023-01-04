class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> hmap;
        for(int num : tasks)
            hmap[num]++;
        int cnt,val,res=0;
        for(auto p : hmap){
            cnt = p.second;
            val = cnt/3;
            cnt %=3;
            if(cnt==0)
                res += val;
            else if(cnt==2)
                res+= val+1;
            else if(val>0)
                res += val+1;
            else return -1;
        }
        return res;
    }
};