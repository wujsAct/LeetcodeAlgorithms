/***
*一个数字可以重复多次出现，所以判断条件中要把数组重复出现的数字给抛弃掉！
**/
class Solution {
private:
    vector<vector<int>> ret;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tempr;
        subcombinationSum(candidates,0,target,tempr);
        return ret;
    }
    void subcombinationSum(vector<int>& candidates,int index, int target,vector<int> &tempr){
        if(target==0){
            ret.push_back(tempr);
            return;
        }
        for(int i=index;i<candidates.size()&& target >= candidates[i];i++){
            if(i==0 || candidates[i-1]!=candidates[i]){
                tempr.push_back(candidates[i]);
                subcombinationSum(candidates,i,target-candidates[i],tempr);
                tempr.pop_back();
            }
        }
    }
    
};

/***
**数组的元素都只能使用一次
*处理方法：如果数组中当前的数字出现重复，在前面重复了k次，且临时结果数组中也包含了k个当前数字，那么当前的数字可以选择；否则就不选择当前数字
**/
class Solution {
private: 
    vector<vector<int>> ret;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> tempr;
        subcombinationSum2(candidates,0,target,tempr,0);
        return ret;
    }
    void subcombinationSum2(vector<int>& candidates,const int index,const int target,vector<int> &tempr,int times){
        if(target==0){
            ret.push_back(tempr);
            return;
        }
        for(int i=index;i<candidates.size() && target>=candidates[i];i++){
            if(i>0 && candidates[i]==candidates[i-1]) times++;
            else times=1;
            if(times==1||(tempr.size()>=times-1 && tempr[tempr.size()-times+1] == candidates[i]))
            {
                tempr.push_back(candidates[i]);
                subcombinationSum2(candidates,i+1,target-candidates[i],tempr,times);
                tempr.pop_back();
            }
        }
    }
};

