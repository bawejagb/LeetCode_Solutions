class Solution {
public:
    string fractionToDecimal(int n, int d) {
        string res = "";
        if((n<0 and d>0) or (n>0 and d<0))
            res += '-';
        long a = abs(n);
        long b = abs(d);
        long num = abs(a/b);
        res += to_string(num);
        long rem = abs(a%b);
        if(rem==0)
            return res;
        res += '.';
        string dec = "";
        unordered_map<int,int> hmap;
        while(rem){
            if(hmap.find(rem)==hmap.end()){
                hmap[rem] = dec.size();
                dec += to_string(rem*10/b);
                rem = (rem*10)%b;
            }
            else{
                int index = hmap[rem];
                string rep = dec.substr(index);
                dec.erase(index);
                dec += '('+rep+')';
                break;
            }
        }
        res += dec;
        return res;
    }
};