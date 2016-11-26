/***
*һ�����ֿ����ظ���γ��֣������ж�������Ҫ�������ظ����ֵ����ָ���������
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
**�����Ԫ�ض�ֻ��ʹ��һ��
*����������������е�ǰ�����ֳ����ظ�����ǰ���ظ���k�Σ�����ʱ���������Ҳ������k����ǰ���֣���ô��ǰ�����ֿ���ѡ�񣻷���Ͳ�ѡ��ǰ����
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

