class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int left = 0, right = people.size()-1, res=0;
        while(left<=right){
            if(people[right]>=limit || people[right]+people[left]>limit)
                right--;
            else{
                left++;
                right--;
            }
            res++;
        }
        return res;
    }
};