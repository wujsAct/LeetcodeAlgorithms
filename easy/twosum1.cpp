/**
@time:2016/10/23
@funtion two sum
@need to attention£ºarray, or hash_table
**/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int lent = nums.size();
        bool succ = false;
        int i,j;
        for(i=0;i<lent;i++){
            for(j=i+1;j<lent;j++){
                if(nums[i]+nums[j]==target){
                    ans.insert(ans.end(),i);
                    ans.insert(ans.end(),j);
                    succ = true;
                    break;
                }
            }
            if(succ)
                break;
        }
        return ans;
    }
};