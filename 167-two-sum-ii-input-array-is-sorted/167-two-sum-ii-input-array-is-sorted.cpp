class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> ans;
        int l=0, r= num.size()-1;
        while(l<r){
            if(num[l]+num[r]<target) l++;
            else if(num[l]+num[r]> target) r--;
            else{
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
        }
        return ans;
    }
};