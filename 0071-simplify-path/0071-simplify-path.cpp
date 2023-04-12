class Solution {
public:
    string simplifyPath(string path) {
        string buff, res;
        istringstream s(path);
        while(getline(s,buff,'/')){
            if(buff==".."){
                if(res.size()){
                    while(res.back() !='/') res.pop_back();
                    res.pop_back();
                }
            }
            else if(buff.size() && buff != ".")
                res += "/"+buff;
        }
        if(!res.size()) res = "/";
        return res;
    }
};