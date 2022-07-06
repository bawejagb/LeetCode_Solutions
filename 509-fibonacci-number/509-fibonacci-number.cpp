class Solution {
public:
    int fib(int n) {
        int fb2, fb1 = 0;
        if(n == 0) return 0;
        if(n==1) return 1;
        fb2 = 1;
        for(int i =2; i <= n; i++){
            fb2 += fb1;
            fb1 = fb2-fb1;
        }
        return fb2;
    }
};