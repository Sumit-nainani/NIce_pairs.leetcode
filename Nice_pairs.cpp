// You are given an array nums that consists of non-negative integers. Let us define rev(x) as
//  the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. 
//  A pair of indices (i, j) is nice if it satisfies all of the following conditions:
// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

/*
 approach:
     problem is like this:
         nums[i]-rev(nums[i])==nums[j]-rev(nums[j])
         so will store nums[i]-rev(nums[i]) for each index in map and the count of each index's value will give total pair
            for this index,like if count is ct then total pair=ct*(ct-1)/2=v
            final answer will be all v values of each index.
*/
#define ll long long 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<ll,ll> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ll rev = 0;
            int x=nums[i];
            // algo for reversing the number
            while(x > 0){
                int r = x % 10;
                rev = rev * 10 + r;
                x = x / 10;
            }   
            m[nums[i]-rev]++;
        }
        int ans(0);
        for(auto&it:m){
            ans = (ans%1000000007 + ((it.second)*1LL*(it.second-1)/2)%1000000007)%1000000007;
        }
        return ans;
    }
};