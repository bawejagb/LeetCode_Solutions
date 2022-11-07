class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digits;
        int temp = num;
        while(temp>0){
            digits.push_back(temp%10);
            temp/=10;
        }
        temp = 0;
        bool fg=0;
        for(int i = digits.size()-1;i>=0;i--){
            if(fg and digits[i]==6)
                temp = temp*10+6;
            else
                temp = temp *10+9;
            if(digits[i]==6) fg = true;
        }
        return temp;
    }
};