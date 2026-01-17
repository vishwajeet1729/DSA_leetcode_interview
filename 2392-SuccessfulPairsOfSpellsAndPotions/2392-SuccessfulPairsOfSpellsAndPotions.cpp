// Last updated: 1/17/2026, 12:29:15 PM
// #define long long int
class Solution {
public:
vector<int>ans;
bool check(int mid,vector<int>& potions,int spells,long long  success){
       return 1LL*potions[mid]*spells>=success;  
}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         #include<bits/stdc++.h>
// using namespace std;

vector<int>ans;

// bool check(int mid,vector<int> potions,int spells,int success){
//        return potions[mid]*spells>=success;  
// }
// void solve(vector<int>spells,vector<int>potions,int success){
     int n=spells.size();
     int m=potions.size();
     sort(potions.begin(),potions.end());
     for(int i=0;i<n;++i){
          
        int l=0,r=m-1;

        while(l<=r){
            int mid=(l+r)/2;
             if(check(mid,potions,spells[i],success))r=mid-1;
             else l=mid+1;
        }
             ans.push_back(m-l);
     }

// }


/*int main(){
    vector<int>spells={5,1,3};
    vector<int>potions={1,2,3,4,5};
    sort(potions.begin(),potions.end());
    int success=7;
solve(spells,potions,success);
for(auto it:ans)cout<<it<<" ";
cout<<endl;
}*/
return ans;
    }
};