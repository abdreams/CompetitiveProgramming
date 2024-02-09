class Solution {
public:
    int f(int ind,int amount,vector<int>& coins,vector<vector<int>>&dp){
        if(ind==0) {
            if(amount%coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];

        int take=1e9;
        if(amount>=coins[ind]) take=1+f(ind,amount-coins[ind],coins,dp);

        int notTake=f(ind-1,amount,coins,dp);
        return dp[ind][amount]=min(take,notTake);


    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,0));
        // int ans= f(n-1,amount,coins,dp);
        // if(ans==1e9) return -1;
        //  return ans;
        for(int rem=0;rem<=amount;rem++){
            if((rem%coins[0])==0) dp[0][rem]=rem/coins[0];
            else dp[0][rem]=1e9;
        }

        for(int index=0;index<n;index++){
            for(int rem=0;rem<=amount;rem++){
                int take=1e9;
                
                if(rem>=coins[index]) take=1+dp[index][rem-coins[index]];
                
                int notTake=dp[index-1][rem];

                dp[index][rem]=min(take,notTake);
            }

        }
        int ans=dp[n-1][amount];
        if(ans==1e9) return -1;
        else return ans;
    }
};