/**
*2016/11/3 回溯法的递归解法！
*深刻了解递归的过程非常重要呢！
*/
class Solution {
public:
    vector<vector<int>> subpermute(vector<int>& nums,vector<vector<int>>& ret, int k, int length){
        int i=0;
        if(k==length){
            ret.push_back(nums);
            return ret;
        }
        for(i=k;i<length;i++){
            swap(nums[i],nums[k]);
            subpermute(nums,ret,k+1,length);
            swap(nums[i],nums[k]);
        }
        return ret;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int>> ret;
        return subpermute(nums,ret,0,length);
    }
};