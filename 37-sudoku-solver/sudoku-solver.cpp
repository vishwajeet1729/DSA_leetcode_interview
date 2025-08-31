class Solution {
public:
    bool f(vector<vector<char>>& a,vector<set<char>>& r,vector<set<char>>& c,map<pair<int,int>,set<char>>& b){
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(a[i][j]=='.'){
            for(char x='1';x<='9';x++)if(!r[i].count(x)&&!c[j].count(x)&&!b[{i/3,j/3}].count(x)){
                a[i][j]=x;r[i].insert(x);c[j].insert(x);b[{i/3,j/3}].insert(x);
                if(f(a,r,c,b))return 1;
                a[i][j]='.';r[i].erase(x);c[j].erase(x);b[{i/3,j/3}].erase(x);
            }
            return 0;
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& a){
        vector<set<char>> r(9),c(9);map<pair<int,int>,set<char>> b;
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(a[i][j]!='.'){
            r[i].insert(a[i][j]);c[j].insert(a[i][j]);b[{i/3,j/3}].insert(a[i][j]);
        }
        f(a,r,c,b);
    }
};
