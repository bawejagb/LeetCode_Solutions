class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> tset, hset(bank.begin(),bank.end());
        if(hset.find(end)==hset.end()) return -1;
        queue<string> qt;
        int cnt = 0;
        char choice[4] = {'A','C','G','T'};
        qt.push(start);
        tset.insert(start);
        while(!qt.empty()){
            int size = qt.size();
            cnt++;
            while(size--){
                string st = qt.front();
                qt.pop();
                for(int j=0;j<4;j++){
                    for(int i=0;i<st.size();i++){
                        char temp = st[i];
                        st[i] = choice[j];
                        if(st == end) return cnt;
                        if(tset.find(st)==tset.end() and hset.find(st)!=hset.end()){
                            tset.insert(st);
                            qt.push(st);
                        }
                        st[i] = temp;
                    }
                }
            }
        }
        return -1;
    }
};