class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& v) {
        int n=9;
        vector<set<char>>row(n),col(n);
         map<pair<int,int>,set<char>>m;
        for(int i=0;i<n;++i){
      //rows;
      for(int j=0;j<n;++j){
        if(v[i][j]=='.')continue;
        if(row[i].find(v[i][j])==row[i].end())row[i].insert(v[i][j]);
        else {
            // cout<<0<<endl;
            return 0;
        }
      }
}

  
for(int j=0;j<n;++j){
     for(int i=0;i<n;++i){
        if(v[i][j]=='.')continue;
        if(col[j].find(v[i][j])==col[j].end())col[j].insert(v[i][j]);
        else {
            return 0;
            // cout<<0<<endl;return;
        }
     }
}
//  map<pair<int,int>,set<char>>m;
for(int i=0;i<n;++i){
     for(int j=0;j<n;++j){
        if(v[i][j]=='.')continue;
          int a=i/3,b=j/3;
         if(m[{a,b}].find(v[i][j])==m[{a,b}].end())m[{a,b}].insert(v[i][j]);
         else {
            // cout<<0<<endl;
            return 0;
         }
     }
}


    //  cout<<1<<endl;
    return 1;
    }
};