class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a1="";
        string a2="";
        for(int i=0; i<word1.size(); i++){
            a1+=word1[i];
        }
        for(int i=0; i<word2.size(); i++){
            a2+=word2[i];
        }
        int j=0;
        int n1=a1.length();
        int n2=a2.length();
        while(a1[j]!='\0' && a2[j]!='\0'){
            if(n1!=n2) return false;
            if(a1[j]!=a2[j]) return false;
            j++;
        }
        return true;
    }
};