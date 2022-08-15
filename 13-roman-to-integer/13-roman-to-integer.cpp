class Solution {
public:
    int romanToInt(string s) {
        int num,sum = 0;
        for(int i = 0; i < s.size(); i++){
            num = 0;
            if(i+1 < s.size()){
                if(s[i] == 'I'){
                    if(s[i+1] == 'V'){
                        num = 4;
                        i++;
                    }
                    else if(s[i+1] == 'X'){
                        num = 9;
                        i++;
                    }
                }
                else if(s[i] == 'X'){
                    if(s[i+1] == 'L'){
                        num = 40;
                        i++;
                    }
                    else if(s[i+1] == 'C'){
                        num = 90;
                        i++;
                    }
                }
                else if(s[i] == 'C'){
                    if(s[i+1] == 'D'){
                        num = 400;
                        i++;
                    }
                    else if(s[i+1] == 'M'){
                        num = 900;
                        i++;
                    }
                }
            }
            if(num == 0){
                if(s[i] == 'I') num = 1;
                else if(s[i] == 'V') num = 5;
                else if(s[i] == 'X') num = 10;
                else if(s[i] == 'L') num = 50;
                else if(s[i] == 'C') num = 100;
                else if(s[i] == 'D') num = 500;
                else if(s[i] == 'M') num = 1000;
            }
            sum += num;
        }
        return sum;
    }
};