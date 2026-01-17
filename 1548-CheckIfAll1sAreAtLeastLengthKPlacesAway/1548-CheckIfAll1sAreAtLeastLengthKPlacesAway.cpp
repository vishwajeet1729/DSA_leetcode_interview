// Last updated: 1/17/2026, 12:30:43 PM
class Solution {
public:
    bool kLengthApart(vector<int>& v, int k) {
          int n=v.size();

    int last=-1;
// int k=2;
    for(int i=0;i<n;++i){
        if(v[i]==1){
            if(last==-1)last=i;
            else {
                 int dist=i-last-1;
                 if(dist>=k)last=i;
                 else {
                    cout<<"0"<<endl;
                    return 0;
                 }
            }
        }
    }
cout<<1<<endl;
return 1;
    }
};