class Solution {
    int factorial(int num){
        if(num==0) return 1;
        int ans=1;
        for(int i=1;i<=num;i++)
            ans *= i;
        return ans;
    }
public:
    string getPermutation(int n, int k) {
        string res="";
        vector<int> digit(n);
        for(int i=1; i<=n;i++)
            digit[i-1] = i;
        int start = 0;
        int size = factorial(n);
        while(n>1){
            size /= n;
            int idx = 0;
            for(int i = start+size; i<k; i+= size)
                idx++;
            res.push_back('0'+digit[idx]);
            digit.erase(digit.begin()+idx);
            n--;
            start += (idx*size);
        }
        res.push_back('0'+digit[0]);
        return res;
    }
};