class TweetCounts {
    map<string,multiset<int>> tmap;
    unordered_map <string, int> freqEnum;
public:
    TweetCounts() {
        freqEnum["minute"] = 60;
        freqEnum["hour"] = 60 * freqEnum["minute"];
        freqEnum["day"] = 60 * freqEnum["hour"];
    }
    
    void recordTweet(string tweetName, int time) {
        tmap[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int div;
        div = freqEnum[freq];
        auto vec = tmap[tweetName];
        int num = (endTime-startTime)/div;
        vector<int> res(num+1,0);
        auto start = vec.lower_bound(startTime);
        auto end = vec.upper_bound(endTime);
        while(start != end){
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