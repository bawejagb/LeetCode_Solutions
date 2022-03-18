class Solution {
    
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> v;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            while(v.size()>0&&v.back()<=arr[i]){
                if(v.size()>1&&v[v.size()-2]<arr[i])
                    sum += v[v.size()-1]*v[v.size()-2];
                else
                    sum += v.back()*arr[i];
                v.pop_back();
            }
            v.push_back(arr[i]);
        }
        for(int i=v.size()-2;i>=0;i--)
            sum += v[i]*v[i+1];
        return sum;
    }
};