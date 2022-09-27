class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<pair<char,int>> left(n);
        vector<pair<char,int>> right(n);
        char fall='.';
        int fall_val=INT_MAX;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='.' && fall=='R') {left[i]={fall,fall_val};continue;}
            left[i]={dominoes[i],-1};
            if(dominoes[i] != '.') { fall=dominoes[i]; fall_val=i;};
        }
        fall='.';
        fall_val = INT_MAX;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='.' && fall=='L') {right[i]={fall,fall_val};continue;}
            right[i]={dominoes[i],-1};
            if(dominoes[i] != '.') { fall=dominoes[i]; fall_val=i;};
        }
        string ans=dominoes;
        for(int i=0;i<n;i++){
            if(ans[i]=='.' && left[i].first!='.' && right[i].first!='.'){
                if(abs(left[i].second-i)==abs(right[i].second-i)) continue;
                else if(abs(left[i].second-i)<abs(right[i].second-i)) ans[i]=left[i].first;
                else ans[i]=right[i].first;
            }
            else if(ans[i]=='.' && left[i].first=='.') ans[i]=right[i].first;
            else if(ans[i]=='.' && right[i].first=='.') ans[i]=left[i].first;
        }
        return ans;
    }
};