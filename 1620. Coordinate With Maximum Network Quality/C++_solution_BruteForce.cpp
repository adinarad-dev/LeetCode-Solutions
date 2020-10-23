class Solution {
public:
    double dist(int i, int j, int a, int b){
        return sqrt((double)(i-a)*(i-a) + (j-b)*(j-b));
    }
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int x=0, y=0;
        int ans=0;
        for(int i=0;i<51;++i){
            for(int j=0;j<51;++j){
                int qual=0;
                for(auto &it: towers){
                    double d = dist(i, j, it[0], it[1]);
                    
                    if(d<=(double)radius){
                        qual += it[2]/(d+1);
                    }
                }
                
                if(qual>ans){
                    x=i, y=j;
                    ans=qual;
                }
                else if(qual==ans && (i<x || (x==i && j<y))){
                    x=i, y=j;
                }
            }
        }
        return vector<int>({x, y});
    }
};