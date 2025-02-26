class Solution {
public:
    void setZeroes(vector<vector<int>>& v) {
         int n=v.size(),m=v[0].size();
        bool row=false,col=0;
        if(v[0][0]==0){row=1,col=1;}
        for(int i=0;i<m;++i)if(v[0][i]==0)row=1;
        for(int i=0;i<n;++i)if(v[i][0]==0)col=1;
       for(int i=1;i<m;++i){
          if(v[0][i]==0)continue;
          for(int j=1;j<n;++j){
             if(v[j][i]==0){
                v[0][i]=0;
                break;
             }
          }
       }

         for(int i=1;i<n;++i){
              
              if(v[i][0]==0)continue;
              for(int j=1;j<m;++j){
                   if(v[i][j]==0){v[i][0]=0;break;}


              }
         }  

          for(int i=1;i<m;++i){
              
              if(v[0][i]==0)for(int j=0;j<n;++j)v[j][i]=0;
          }

          for(int i=1;i<n;++i){
               if(v[i][0]==0)for(int j=0;j<m;++j)v[i][j]=0;
          }
           if(row)for(int i=0;i<m;++i)v[0][i]=0;
           if(col)for(int i=0;i<n;++i)v[i][0]=0;
             
        

    }
};