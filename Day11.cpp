// Day 11 :>


//Problem 1 : Max value of the equation
 
 class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        int ans=INT_MIN;
        priority_queue<pair<int,int>> pq;
        pq.push({pts[0][1]-pts[0][0], pts[0][0]});
        
        for(int i=1;i<pts.size();i++){
            int sum = pts[i][0]+pts[i][1];
            
            while(!pq.empty() && pts[i][0]- pq.top().second > k) pq.pop();
            
            if(!pq.empty()) ans = max(ans, sum + pq.top().first);
            pq.push({pts[i][1]-pts[i][0], pts[i][0]});
        }
        return ans;
    }
};


//Problem 2 : Insert Delete GetRandom O(1) - Duplicates allowed (Multiset)

class RandomizedCollection {
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> mp;
public:
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        auto result = mp.find(val) == mp.end();
        
        mp[val].push_back(nums.size());
        nums.push_back({val, mp[val].size()-1});
        
        return result;
    }
    
    bool remove(int val) {
        auto result = mp.find(val) != mp.end();
        
        if(result){
            auto last = nums.back();
            mp[last.first][last.second] = mp[val].back();
            nums[mp[val].back()] = last;
            mp[val].pop_back();
            
            if(mp[val].empty()) mp.erase(val);
            
            nums.pop_back();
        }
        return result;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Problem 3 :  Largest Rectangle in Histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int area=0;
        stack<int> st;
        
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int h = heights[st.top()]; 
                st.pop();
                int l = st.empty() ? -1 : st.top();
                area = max(area, h*(i-l-1));
            }
            st.push(i);
        }
        return area;
    }
};

// Problem 4 :  Max value of the equation

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        int ans=INT_MIN;
        priority_queue<pair<int,int>> pq;
        pq.push({pts[0][1]-pts[0][0], pts[0][0]});
        
        for(int i=1;i<pts.size();i++){
            int sum = pts[i][0]+pts[i][1];
            
            while(!pq.empty() && pts[i][1]-pq.top().second > k) pq.pop();
            
            if(!pq.empty()) ans = max(ans, pq.top().first + sum);
            pq.push({pts[i][1]-pts[i][0], pts[i][0]});
        }
        return ans;
    }
};

