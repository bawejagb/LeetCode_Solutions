class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        if(stamp==target)
            return {0};
        bool canStamp=true,stamped;
        vector<int> ans;
        int targetLength=target.size()-stamp.size()+1,i,j;
        while(canStamp)
        {
            canStamp=false;
            for(i=0;i<targetLength;i++)
            {
                for(j=0,stamped=false;j<stamp.size();j++)
                {
                    if(target[i+j]=='*')
                        continue;
                    else if(target[i+j]!=stamp[j])
                        break;
                    else
                        stamped=true;
                }
                if(stamped&&j==stamp.size())
                {
                    for(j=i;j<stamp.size()+i;j++)
						   target[j]='*';
					canStamp=true;
                    ans.push_back(i);
                }
           }
        }
        for(i=0;i<target.size();i++)
            if(target[i]!='*')
                return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};