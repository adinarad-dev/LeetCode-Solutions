class Solution {
    unordered_map<int, int>mp;
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        if(a.first!=b.first){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int> > v;
        for(auto it: nums){
            mp[it]++;
        }
        
        for(auto it: mp){
            v.push_back({it.second, it.first});
        }
        
        sort(v.begin(), v.end(), compare);
        
        vector<int> ans;
        for(auto &it: v){
            for(int i=0; i<it.first ; ++i){
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};