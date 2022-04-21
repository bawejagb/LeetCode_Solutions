class UndergroundSystem {
    unordered_map<int,pair<string,int>> inTime;
    unordered_map<string,vector<int>> routeTime;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inTime[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string route = inTime[id].first+" "+stationName;
        routeTime[route].push_back(t-inTime[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double res=0.0;
        string route = startStation+" "+endStation;
        for(int t : routeTime[route])
            res += t;
        return res/routeTime[route].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */