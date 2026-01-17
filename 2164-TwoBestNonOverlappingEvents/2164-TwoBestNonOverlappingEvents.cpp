// Last updated: 1/17/2026, 12:29:51 PM
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
         
// vector<vector<int>>events={{1,3,2},{4,5,2},{2,4,3}};
 
sort(events.begin(),events.end());
vector<vector<int>>by_start=events;

vector<vector<int>>by_end;
sort(events.begin(),events.end(),[]( vector<int>&a, vector<int>&b){
  return a[1]<b[1];
});
by_end=events;


int ans=0;
int j=0;
int i=0;
int n=events.size();
int best=0;
while(i<n){
     
  int start=by_start[i][0];
  
  while(j<n&&by_end[j][1]<start){
   best=max(best,by_end[j][2]);
   j++;
  }
  ans=max(ans,by_start[i][2]+best);
  i++;
}
return ans;
cout<<ans<<endl;

    }
};