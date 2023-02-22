class Solution {
public:
    bool isvalid(vector<int>&weights,int n,int days,int mid)
{
    int count=1;
    int sum=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=weights[i];
        if(sum>mid)
        {
            count++;
            sum=weights[i];
        }
        if(count>days)
            return false;
    }
    return true;        
}

int shipWithinDays(vector<int>& weights, int days) 
{
    int n=weights.size();
    int mx=0;
    int sum=0;
    for(int i=0;i<weights.size();i++)
    {
        sum+=weights[i];
        mx=max(mx,weights[i]);
    }
    
    int start=mx,end=sum;
    int res=-1;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isvalid(weights,n,days,mid))
        {
            res=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    
    return res;
}
};