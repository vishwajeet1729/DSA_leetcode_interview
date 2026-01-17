// Last updated: 1/17/2026, 12:31:30 PM
class Solution {
public:
    int smallestRepunitDivByK(int k) {
          
    // int k=13;

    int len=1;
    int cur=1%k;
    map<int,int>m;
    while(cur!=0){
           
        cur=(cur*10+1)%k;

        if(m.find(cur)!=m.end()){
            return -1;
        }
        len++;
        m[cur]++;

    }
    return len;

    }
};