class Twitter {
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int id;
public:
    Twitter() {
        id=0;
    }
    
    void postTweet(int userId, int tweetId) {
        id++;
        if(tweets[userId].size()==10)
            tweets[userId].erase(tweets[userId].begin());
        tweets[userId].push_back({id,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(int user: following[userId]){
            for(auto tweet: tweets[user])
                pq.push(tweet);
        }
        for(auto tweet: tweets[userId])
            pq.push(tweet);
        vector<int> res;
        int cnt = 10;
        while(cnt-->0 && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following[followerId].find(followeeId)!=following[followerId].end())
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */