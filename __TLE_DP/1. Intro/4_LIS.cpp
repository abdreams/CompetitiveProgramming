//https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int solve(int ind, int prev, vector<int>& nums,vector<vector<int>>&dp) {
        int n = nums.size();
        if (ind == n) {
            return 0;
        }
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];

        int take = 0;
        int nottake = solve(ind + 1, prev, nums,dp);

        if (prev == -1 or nums[ind] > nums[prev]) {
            take = 1 + solve(ind + 1, ind, nums,dp);
        }

        return dp[ind][prev+1]=max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0, -1, nums,dp);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back())
                temp.push_back(nums[i]);
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }
};

