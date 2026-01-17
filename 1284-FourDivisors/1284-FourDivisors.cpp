// Last updated: 1/17/2026, 12:31:12 PM
class Solution {
public:
    
vector<int>fac(int n){
      vector<int>ans;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){ans.push_back(i);
          if(n/i!=i)ans.push_back(n/i);
        }

    }

    return ans;

}

    int sumFourDivisors(vector<int>& v) {
        //   vector<int>v={21,4,7};

    int n=v.size();
   int sum=0;
    for(int i=0;i<n;i++){
        
        vector<int>factors=fac(v[i]);
        if(factors.size()==4){
            sum+=factors[0]+factors[1]+factors[2]+factors[3];
        }
    }
return sum;
    // cout<<sum<<endl;

    }
};