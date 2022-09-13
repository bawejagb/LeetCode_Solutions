class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numBytesProcess = 0;
        int mask1 = 1<<7;
        int mask2 = 1<<6;
        for(int i=0;i<data.size();i++){
            if(numBytesProcess==0){
                int mask = 1<<7;
                while((mask&data[i])!=0){
                    numBytesProcess++;
                    mask = mask >> 1;
                }
                if(numBytesProcess==0) continue;
                if(numBytesProcess>4 || numBytesProcess==1) return false;
            }
            else{
                if((data[i]&mask1)==0 || (mask2&data[i])!=0) return false;
            }
            numBytesProcess--;
        }
        return numBytesProcess==0;
    }
};