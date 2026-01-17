// Last updated: 1/17/2026, 12:31:23 PM
class Solution {
    
    long long base = 31, MOD=1e11+19;
    
public:
    string longestDupSubstring(string s) {
        
        int n = s.size();
        int l=0, r=n;
        int mx=0,idx=0;
        
        while(l<r){
            
            int mid = l+ceil((r-l)/(2*1.0));
            
            unordered_set<long long> currHash;
            long long hash=0, d=1;
            bool found = false;
            for(int i=0; i<n; i++){
                hash = (hash*base + s[i]-'a'+1)%MOD;
                if(i>=mid){
                    hash = (MOD + hash - d*(s[i-mid]-'a'+1)%MOD)%MOD;
                }else{
                    d = d*base%MOD;
                }
                
                if(i>=mid-1){
                    if(currHash.count(hash)){
                        idx = i-mid+1;
                        found = true;
                        break;
                    }
                    currHash.insert(hash);
                }
            }
            
            if(!found)
                r = mid-1;
            else l = mid;
        }
        string ans = "";
        
        
        for(int i = idx; i<(idx+l); i++){
            ans += s[i];
        }
        
        return ans;
    }
};