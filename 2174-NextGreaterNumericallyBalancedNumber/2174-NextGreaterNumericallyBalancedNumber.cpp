// Last updated: 1/17/2026, 12:29:48 PM
class Solution {
public:
bool check(int n){
      vector<int>freq(10,0);
      if(n==0)return 0;
      while(n){
        if(n==0)return 0;
        freq[n%10]++;
        n=n/10;
      }  
       for(int i=0;i<10;++i){
        if(freq[i]==0)continue;
        if(freq[i]!=i)return 0;
       }
       return 1;

}
    int nextBeautifulNumber(int n) {
           for(int i=n+1;i<=1e7;++i){
         if(check(i)){
           return i;
         }
    }
   return 122333;
    }    
};