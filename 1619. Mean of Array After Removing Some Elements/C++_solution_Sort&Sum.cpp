// Sort and Sum
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        double per = 0.05*n;
        double sum=0;
        
        for(int i=per; i<n-per;++i){
            sum+= arr[i];
        }
        return sum/(n-2*per);
    }
};