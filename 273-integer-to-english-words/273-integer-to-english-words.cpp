class Solution {
public:
       string one(int num){
       switch(num){
           case 1: return "One";
           case 2: return "Two";
           case 3: return "Three";
           case 4: return "Four";
           case 5: return "Five";
           case 6: return "Six";
           case 7: return "Seven";
           case 8: return "Eight";
           case 9: return "Nine";
       }
           return "";
    }
       string lessThan20(int num){
       switch(num){
           case 10: return "Ten";
           case 11: return "Eleven";
           case 12: return "Twelve";
           case 13: return "Thirteen";
           case 14: return "Fourteen";
           case 15: return "Fifteen";
           case 16: return "Sixteen";
           case 17: return "Seventeen";
           case 18: return "Eighteen";
           case 19: return "Nineteen";
       }
           return "";
    }
       string ten(int num){
       switch(num){
            case 2: return "Twenty";
           case 3: return "Thirty";
           case 4: return "Forty";
           case 5: return "Fifty";
           case 6: return "Sixty";
           case 7: return "Seventy";
           case 8: return "Eighty";
           case 9: return "Ninety";
       }
           return "";
    }
   string two(int num){
        if(num==0){
            return " ";
        }
        if(num<10){
            return one(num);
        }
        if(num<20){
            return lessThan20(num);
        }
        int tenner=num/10;
        int rest=num%10;
        if(tenner!=0 && rest!=0){
            return ten(tenner)+" "+one(rest);
        }
        if(tenner!=0){
            return ten(tenner);
        }
        if(rest!=0){
            return one(rest);
        }
       return "";
    }
 
    string three(int num){
        if(num==0) return "";
        int hundred=num/100;
        int rest=num%100;
        if(rest!=0 && hundred !=0){
            return one(hundred)+" Hundred "+two(rest);
        }
        else if(rest==0){
            return one(hundred)+" Hundred";
        }
        else{
       return two(rest);
        }
        return "";
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        int billion=num/1000000000;
        num%=1000000000;
        int million=num/1000000;
        num%=1000000;
        int thousand=num/1000;
        num%=1000;
        string res="";
        if(billion!=0){
            res+=three(billion)+" Billion";
        }
        if(million!=0){
             if(res.length()!=0){
                res+=" ";
            }
            res+=three(million)+" Million";
        }
        if(thousand!=0){
             if(res.length()!=0){
                res+=" ";
            }
            res+=three(thousand)+" Thousand";
        }
        if(num!=0){
             if(res.length()!=0){
                res+=" ";
            }
            res+=three(num);
        }
        return res;  
    }
};