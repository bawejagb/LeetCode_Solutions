class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num=1;
        vector<int> res;
        for(int i = digits.size()-1; i >= 0; i--){
            num += digits[i];
            res.push_back(num%10);
            num /= 10;
        }
        if(num>0) res.push_back(num);
        reverse(res.begin(),res.end());
        return res;
    }
};