// Last updated: 1/17/2026, 12:30:45 PM
class Solution {
public:
    int maxDiff(int n) {
          
 string s1=to_string(n);
      string s2=to_string(n);
     //min   check the first no which is not 1  store that digit in a
     char a='@',b='@';int ind=-1;
     for(int i=0;i<s1.size();++i){
        if(s1[i]!='1'&&s1[i]!='0'){
            ind=i;
            a=s1[i];break;
        }
     }
     for(int i=0;i<s1.size();++i){
        if(s1[i]==a&&ind!=0)s1[i]='0';
        else
        if(s1[i]==a)s1[i]='1';}


     // max check jo ki 9 nahi hai
    
     for(int i=0;i<s2.size();++i){
        if(s2[i]!='9'){
            b=s2[i];
            break;
        }
     }
     for(int i=0;i<s2.size();++i)if(s2[i]==b)s2[i]='9';
    int x=stoi(s1),y=stoi(s2);
    return abs(x-y); 
    }
};