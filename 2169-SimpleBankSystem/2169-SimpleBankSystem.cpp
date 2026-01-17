// Last updated: 1/17/2026, 12:29:50 PM
#include <bits/stdc++.h>
using namespace std;

class Bank {
public:
  
vector<long long>account_balance;
int n;
   
    Bank(vector<long long>& balance) {
      n=balance.size();
     account_balance=balance; 
    }
    bool cond(int account){
        return account>=1&&account<=n;
    }
    bool transfer(int account1, int account2, long long money) {
        if(account1>=1&&account1<=n&&account2>=1&&account2<=n&&account_balance[account1-1]>=money){
            account_balance[account1-1]-=money;
            account_balance[account2-1]+=money;
            return 1;
        }
        return 0;
    }
    
    bool deposit(int account, long long money) {
        if(!cond(account))return 0;
        account_balance[account-1]+=money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        if(!cond(account)||account_balance[account-1]<money)return 0;
        account_balance[account-1]-=money;
        return 1;
    }
};
