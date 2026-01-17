// Last updated: 1/17/2026, 12:34:33 PM
class Solution {
public:
    string minWindow(string s, string t) {
            
            unordered_map<char,int>t_map,window;
            for(char c:t)t_map[c]++;
            int left=0,right=0,valid=0,min_length=INT_MAX,start=0;

            while(right<s.size()){
                    char c=s[right];
                    right++;
                    if(t_map.count(c)){
                          window[c]++;
                          if(window[c]==t_map[c])valid++;
                    }

                    while(valid==t_map.size()){
                           
                           if(right-left<min_length){
                                
                                min_length=right-left;
                                start=left;

                           }
                           char d=s[left];
                           left++;
                         if(t_map.count(d)){
                                 if(window[d]==t_map[d])valid--;
                                 window[d]--;

                         }


                    }

            }

            return min_length==INT_MAX?"":s.substr(start,min_length);


    }
};