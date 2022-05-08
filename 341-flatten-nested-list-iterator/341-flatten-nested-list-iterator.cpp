/**
 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
 class NestedInteger {
 *  public:
 *   	// Return true if this NestedInteger holds a single integer, rather than a nested list.
 *    bool isInteger() const;
 *
 *   	// Return the single integer that this NestedInteger holds, if it holds a single integer
 *   	// The result is undefined if this NestedInteger holds a nested list
 *    int getInteger() const;
 *
 *   	// Return the nested list that this NestedInteger holds, if it holds a nested list
 *   	// The result is undefined if this NestedInteger holds a single integer
 *const vector<NestedInteger> &getList() const;
 *};
 */

class NestedIterator
{
    vector<int> flatten;
    int cur;
    void preprocess(vector<NestedInteger> &nestedList)
    {
        for (NestedInteger &val: nestedList){
            if (val.isInteger()) 
                flatten.push_back(val.getInteger());
            else
                preprocess(val.getList());
        }
    }
    public:
        NestedIterator(vector<NestedInteger> &nestedList)
        {
            cur = 0;
            preprocess(nestedList);
        }

    int next()
    {
        return flatten[cur++];
    }

    bool hasNext()
    {
        return cur < flatten.size();
    }
};

/**
 *Your NestedIterator object will be instantiated and called as such:
 *NestedIterator i(nestedList);
 *while (i.hasNext()) cout << i.next();
 */