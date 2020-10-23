class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l =s.length();
        
        for(int i=1;i<= l/2;++i){
            if(l%i!=0)  continue;
            
            int p1=0, p2=i;
            while(p2<l){
                if(s[p1]!=s[p2])
                    break;
                ++p1, ++p2;
            }
            if(p2==l)    return true;
        }
        return false;
        
    }
};