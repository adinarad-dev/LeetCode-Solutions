class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& mat) {
        int m= mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<int> rank(n+m, 0);
        
        map<int, vector<pair<int, int>> >mpp;
        
        for(int i=0;i<m;++i){
            for(int j =0;j<n;++j){
                mpp[mat[i][j]].push_back({i, j});
            }
        }
        
        for(auto &it: mpp){
            vector<int> par(m+n, 0);
            iota(par.begin(), par.end(), 0);
            
            for(auto coord: it.second){
                int i=coord.first, j = coord.second;
                int ri= find(i, par);
                int rj = find(j+m, par);
                
                par[ri] = rj;
                rank[rj] = max(rank[rj], rank[ri]);
            }
            
            vector<int> tmp_rank(rank.begin(), rank.end());
            for(auto coord: it.second){
                int i=coord.first, j = coord.second;
                int root = find(i, par);
                ans[i][j] = rank[root]+1;
                tmp_rank[i] = tmp_rank[j+m] = rank[root]+1;
            }
            
            swap(rank, tmp_rank);
        }
        return ans;
    }

    int find(int a, vector<int>&par){
        if(par[a]!=a){
            par[a] = find(par[a], par);
        }
        return par[a];
    }
};