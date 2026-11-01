class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minnum = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            minnum = min(minnum, nums[i]);
        }
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            cnt += nums[i] - minnum;
        }
        return cnt;
    }
};