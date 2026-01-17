// Last updated: 1/17/2026, 12:25:14 PM
class Solution {
public:
    int maximumSum(vector<int>& a) {
          vector<int> b=a;
        vector<int> u,v,w;

        for(int i:b){
            if(i%3==0) u.push_back(i);
            else if(i%3==1) v.push_back(i);
            else w.push_back(i);
        }

        sort(u.rbegin(),u.rend());
        sort(v.rbegin(),v.rend());
        sort(w.rbegin(),w.rend());

        int z=0;

        if(u.size()>=3) z=max(z,u[0]+u[1]+u[2]);
        if(v.size()>=3) z=max(z,v[0]+v[1]+v[2]);
        if(w.size()>=3) z=max(z,w[0]+w[1]+w[2]);
        if(!u.empty()&&!v.empty()&&!w.empty()) z=max(z,u[0]+v[0]+w[0]);

        return z;
    }
};