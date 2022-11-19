class Solution {
public:
	int angle(vector<int>& A, vector<int>& B, vector<int>& C){
	return ( (B[0]-A[0])*(C[1]-B[1]) - (C[0]-B[0])*(B[1]-A[1])) ;
}
vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
	int n=trees.size();
	if(n<=3)return trees;
	sort(trees.begin(), trees.end());
	//upper hull
	vector<vector<int>>up;
	up.push_back(trees[0]);
	up.push_back(trees[1]);
	for(int i=2; i<n; i++){
		int s=up.size();
		while(s>=2 and angle(up[s-2],up[s-1],trees[i])>0){
			up.pop_back();
			s--;
		}
		up.push_back(trees[i]);
	}
	//lower hull
	vector<vector<int>>down;
	down.push_back(trees[trees.size()-1]);
	down.push_back(trees[trees.size()-2]);
	for(int i=n-3; i>=0; i--){
		int s=down.size();
		while(s>=2 and angle(down[s-2],down[s-1],trees[i])>0){
			down.pop_back();
			s--;
		}
		down.push_back(trees[i]);
	}

	// remove duplicates
	for(int i = 0; i < down.size(); i++)
		up.push_back(down[i]);
	sort(up.begin(), up.end());
	up.erase(unique(up.begin(), up.end()), up.end());
	return up;
}
};