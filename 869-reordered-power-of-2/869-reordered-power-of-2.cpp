class Solution {

// counting frequency 
    vector<int> freqCount(int n){
        vector<int>freq(10,0);
        while(n!=0){
            int rem = n%10;
            freq[rem]++;
            n=n/10;
        }
        return freq;
    }
    
	
	// checking frequency vectors of given number n and power of 2 are equal or not !!
    bool checkEqual(vector<int>freq1 , vector<int>freq2){
        for(int i=0;i<10;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool reorderedPowerOf2(int n) {
        vector<int>freqOfN = freqCount(n);
        for(int i=0;i<31;i++){
            int power = pow(2,i);
            vector<int>freqOfPowerOf2 = freqCount(power);
            
            if(checkEqual(freqOfPowerOf2,freqOfN)== true){
                return true;
            }
        }
        return false;
    }
};