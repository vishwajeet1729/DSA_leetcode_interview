class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wor) {
             int n=wor.size();
             unordered_map<string,int>m;
             for(int i=0;i<n;++i)m[wor[i]]++;

             //bfs
        queue<pair<string,int>>q;
        q.push({begin,1});

        while(!q.empty())
        {
                string s=q.front().first;
               
                 int cost=q.front().second;
                  if(s==end)return cost;
                q.pop();

                int len=s.size();
               
                for(int i=0;i<len;++i){
                   char c=s[i];        
                        for(int j=0;j<26;++j){
                           s[i]=(char)((int)'a'+j); 

                           if(m.count(s)){
                             q.push({s,cost+1});
                             m.erase(s);
                           }

                        }
                        s[i]=c;

                }
                 

        }
        return 0;


    }
};