class Solution {
    vector<double> generateComb(double a, double b){
        vector<double> res = {a+b, a-b, b-a, a*b};
        if(a) res.push_back(b/a);
        if(b) res.push_back(a/b);
        return res;
    }
    bool check24(vector<double> lst){
        if(lst.size()==1)
            return abs(lst[0]-24) <= 0.1;
        int n = lst.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<double> temp;
                for(int k=0;k<n;k++)
                    if(k!=i&&k!=j) temp.push_back(lst[k]);
                for(double val : generateComb(lst[i],lst[j])){
                    temp.push_back(val);
                    if(check24(temp)) return true;
                    temp.pop_back();
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> lst(cards.begin(),cards.end());
        return check24(lst);
    }
};