class Solution {
public:
    long long int  ans;
    long long int dp[50][50][51];
     long long int helper(int i,int j,int r,int c,int maxmove)
     {
         if(maxmove<0)
             return 0;
         
         if(i>=r||j>=c||j<0||i<0)
         {
            return 1;
         }
         if(dp[i][j][maxmove]!=-1)
             return dp[i][j][maxmove];
         
    dp[i][j][maxmove]=(helper(i,j+1,r,c,maxmove-1)+
        helper(i,j-1,r,c,maxmove-1)+
        helper(i-1,j,r,c,maxmove-1)+
        helper(i+1,j,r,c,maxmove-1))%(1000000007);
         
         return dp[i][j][maxmove];
             
     }
    
    long long int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
                for(int k=0;k<51;k++)
                    dp[i][j][k]=-1;
      return helper(startRow,startColumn,m,n,maxMove);
    
    }
};