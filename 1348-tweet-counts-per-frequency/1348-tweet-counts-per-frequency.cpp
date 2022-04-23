class TweetCounts {
    map<string,multiset<int>> tmap;
public:
    TweetCounts() {
    }
    
    void recordTweet(string tweetName, int time) {
        tmap[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int div;
        if(freq[0] == 'm') div = 60;
        else if(freq[0] == 'h') div = 3600;
        else div = 86400;
        auto vec = tmap[tweetName];
        int num = (endTime-startTime)/div;
        vector<int> res(num+1,0);
        auto start = vec.lower_bound(startTime);
        auto end = vec.upper_bound(endTime);
        while(start != end && *start<= endTime){
            res[(*start-startTime)/div]++;
            start++;
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