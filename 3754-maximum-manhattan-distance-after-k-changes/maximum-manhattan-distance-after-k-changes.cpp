class Solution {
public:
    int maxDistance(string s, int k) {
     int n=s.size();

   map<char,int>ct;
// int k=0;
// cin>>k;

       
int mx=0;
//   int x=0,y=0;
int pp=k;
map<char,int>m;
for(int i=0;i<n;++i){m[s[i]]++;
    k=pp;
    int a=min(m['N'],m['S']);
    int b=max(m['N'],m['S']);

    int x=min(m['E'],m['W']);
    int y=max(m['E'],m['W']);
         
    int N=0,S=0,E=0,W=0;
    if(a<=k){k-=a;b+=a;a=0;}
    else {
       
        a-=k;b+=k; k=0;
    }
    if(x<=k){k-=x;;y+=x;x=0;}
    else {
       
        x-=k;y+=k; k=0;
    }
    //  cout<<a<<" "<<x<<endl;
     mx=max(mx,abs(a-b)+abs(x-y));}
// cout<<mx<<endl;
return mx;
    }
};