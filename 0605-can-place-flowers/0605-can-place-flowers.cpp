class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool canPlace = 1;
        int k = flowerbed.size();
        for(int i=0;i<k;i++){
            if(canPlace and flowerbed[i]==0){
                if(i+1!=k and flowerbed[i+1]==0){
                    canPlace=0;
                    n--;
                }
                else if(i+1==k){
                    canPlace=0;
                    n--;
                }
            }
            else if(flowerbed[i]==0){
                canPlace=1;
            }
            else
                canPlace=0;
        }
        return n<= 0;
    }
};