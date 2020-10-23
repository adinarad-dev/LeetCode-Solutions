// Mapping Alien Dictionary to Normal Order Dictionary
class Solution {
    unordered_map<char, char> mpp;
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char ch='a';
        for(auto &it: order){
            mpp[it]=ch++;
        }
        
        for(int i=1;i<words.size(); ++i){
            if(!check(words[i-1], words[i]))
                return false;
        }
        return true;
    }
    
    bool check(string s, string t){
        int slen=s.length(), tlen=t.length();
        
        for(int i=0; i<slen && i<tlen; ++i){
            if(mpp[s[i]]!=mpp[t[i]])
                return mpp[s[i]]<mpp[t[i]];
        }
        return slen<=tlen;
    }
};