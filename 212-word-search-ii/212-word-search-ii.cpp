class Solution {
    struct trinode{
        string word="";
        struct trinode* children[26]={NULL};
    };
    
    struct trinode* buildtree(vector<string> &words){
        struct trinode* root = new trinode();
        for(int j =0; j<words.size(); j++){
            string word= words[j];
            struct trinode* curr =root ;
            for(int i =0; i<word.length(); i++){
                int index = word[i]-'a';
                if(curr->children[index]==NULL){
                    curr->children[index] = new trinode();
                }
                curr = curr->children[index];
            }
            curr->word = word;
        }
        return root;
    }
    
    void dfs(int i , int j ,vector<vector<char>>& board ,struct trinode* root, vector<string>&res){
        char c= board[i][j];
        if(c=='#' || (root->children[c-'a']==NULL) ){return;}
        int n = board.size();
        int m = board[i].size();
        root= root->children[c-'a'];
        if((root->word).size()>0){
            res.push_back(root->word);
            root->word = "";
        }
        //do
        board[i][j] ='#';
        //recure
        if(i+1<n){dfs(i+1,j,board,root,res);}
        if(i-1>=0){dfs(i-1,j,board,root,res);}
        if(j+1<m){dfs(i,j+1,board,root,res);}
        if(j-1>=0){dfs(i,j-1,board,root,res);}
        //undo 
        board[i][j] = c;
    }
public:
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        struct trinode*root = buildtree(words);
        vector<string> res;
        for(int i = 0; i<board.size(); i++){
            for(int j =0; j<board[i].size(); j++){
                dfs(i,j,board,root,res);
            }
        }
        return res;
    }
};