// Last updated: 1/17/2026, 12:30:46 PM
class Solution {
public:
    int numOfWays(int n) {
   long long MOD=1e9+7;
        long long n1=6,n2=6;

        for(int i=1;i<n;++i){

        long long n3=(3*n1+2*n2)%MOD;
        long long n4=(2*n1+2*n2)%MOD;
        n1=n3;
        n2=n4;
        }
    return (n1+n2)%MOD;

    }
};