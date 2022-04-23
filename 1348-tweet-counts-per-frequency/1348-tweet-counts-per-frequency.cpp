class TweetCounts {
    unordered_map<string,set<pair<int,int>>> tmap;
    int itr;
public:
    TweetCounts() {
        itr = 0;
    }
    
    void recordTweet(string tweetName, int time) {
        tmap[tweetName].insert({time,itr++});
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int div;
        if(freq[0] == 'm') div = 60;
        else if(freq[0] == 'h') div = 3600;
        else div = 86400;
        auto vec = tmap[tweetName];
        int num = (endTime-startTime)/div;
        vector<int> res(num+1,0);
        auto t = vec.lower_bound({startTime,0});
        while(t != vec.end() && (*t).first<= endTime){
            res[((*t).first-startTime)/div]++;
            t++;
        }
        return res;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */