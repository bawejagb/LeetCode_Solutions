class NumArray {
public:
    vector<int>seg;
    int size;
    
    void build(int ind,int low,int high,vector<int>&nums,vector<int>&seg){
        if(low==high){
            seg[ind] = nums[low];
            return;
        }
        int mid = low+(high-low)/2;
        build(2*ind+1,low,mid,nums,seg);
        build(2*ind+2,mid+1,high,nums,seg);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
    void updatesum(int ind,int low,int high,int val,vector<int>&seg,int index){
        if(low==high){
            seg[ind] = val;
            return;
        }
        int mid = low+(high-low)/2;
        if(index<=mid){
            updatesum(2*ind+1,low,mid,val,seg,index);
        }
        else{
            updatesum(2*ind+2,mid+1,high,val,seg,index);
        }
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
    int sum(int ind,int low,int high,int l,int r,vector<int>&seg){
        if(low>r || high<l){
            return 0;
        }
        if(low>=l && high<=r){
            return seg[ind];
        }
        int mid = low+(high-low)/2;
        int left = sum(2*ind+1,low,mid,l,r,seg);
        int right = sum(2*ind+2,mid+1,high,l,r,seg);
        return left+right;
    }
    
    NumArray(vector<int>& nums) {
        seg.resize(4*nums.size(),0);
        size = nums.size();
        build(0,0,nums.size()-1,nums,seg);
    }
    void update(int index, int val) {
        updatesum(0,0,size-1,val,seg,index);
    }
    
    int sumRange(int left, int right) {
        return sum(0,0,size-1,left,right,seg);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */