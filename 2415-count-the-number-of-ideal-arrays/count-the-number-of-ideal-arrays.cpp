const int mod=1e9+7, N=10015;
bitset<101> sieve=0;
array<int, 25> prime;
constexpr void sieve100(){
    if (sieve[0]) return;
    sieve[0]=sieve[1]=1;
    int sz=0;
    for(int p=2; p<10; p++){
        if (!sieve[p]){
            prime[sz++]=p;
            for(int j=p*p ; j<100; j+=p)
                sieve[j]=1;
        }
    }
    for(int i=11; i<100; i+=2)
        if (!sieve[i]) prime[sz++]=i;
    //cout<<prime.size()<<endl;
}

int C[N][15]={{0}};

constexpr void Pascal(){// using Pascal triangle
    if (C[0][0]==1) return;// once
    C[0][0]=1;
    for(int i=1; i<N; i++){
        C[i][0]=1;
        int i0=min(14, i);
        for(int j=1; j<=i0; j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if (C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}

// prime factorization & count how many ways
constexpr long long factor(int x, const int n){
//    cout<<"\n"<<x<<",";
    if (x<=1) return 1;
    long long cnt=1;
    if (x<100 && !sieve[x])
        return n;// C(n, 1)

    int x0=x, x_sqrt=sqrt(x);
    int pz=0;
    for(int p: prime){
    //    cout<<p<<", x0="<<x0<<", ";
        if (p>x_sqrt) break;
        if (x0%p!=0) continue;
        int exp=0;
        while(x0%p==0){
        //    cout<<p<<",";
            exp++;
            x0/=p;
        }
        cnt*=C[n-1+exp][exp];
        cnt%=mod;
    //    cout<<p<<" exp="<<exp<<", ";
    } 
    if (x0>1) {
    //    cout<<x0<<" exp="<<1<<endl;
        cnt=(cnt*n)%mod;
    } 
    return cnt;
}

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        sieve100();
        Pascal();
        long long ans= 0;
        for (int x=1; x<=maxValue; x++) {
            long long ways=factor(x, n);
            ans=(ans+ways)%mod;
        }
        return ans;
    }
};