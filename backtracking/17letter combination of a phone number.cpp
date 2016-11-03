class Solution {
public:
    //注意vecotr string的优化
    const vector<string> keyborad {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinations(string digits) {
       if(digits=="") return {};
       vector<string> ret;
       dfs(digits,0,"",ret);
       return ret;
    }
    void dfs(const string& digits,int k,string path,vector<string>& ret){
        if(k==digits.size()){
            ret.push_back(path);
            return ;
        }
        //有没有的for循环呢？
        for(auto c : keyborad[digits[k]-'0']){
            dfs(digits,k+1,path+c,ret);
        }
    }
};




//自己的demo文件
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<char> > letterCombinations(vector< vector<char> >& strs, vector< vector<char> >& ret, vector<char> & temp,int k, int length) {
        int i=0;
        if(k==length){
	    ret.push_back(temp);
 	    for(i=0;i<temp.size();i++){
	        cout<<temp[i]<<"\t";
            }
            cout<<endl;
	    return ret;
	}
        for(i=0; i<strs[k].size(); i++){
            cout<<"k:"<<k<<"\ti:"<<i<<endl;
  	    temp.push_back(strs[k][i]);
	    letterCombinations(strs,ret,temp,k+1,length);
	    temp.pop_back();
	}
	return ret;
    }
};

int main(){
    Solution* sol = new Solution();
    vector< vector<char> > str;
    vector<char> temp;
    temp.push_back('a');temp.push_back('b');temp.push_back('c');
    str.push_back(temp);
    vector<char> temp1;
    temp1.push_back('d');temp1.push_back('e');temp1.push_back('f');
    str.push_back(temp1);
    vector<char> temp2;
    temp2.push_back('g');temp2.push_back('h');temp2.push_back('i');temp2.push_back('j');
    str.push_back(temp2);
    int length = str.size();
    for(int i=0;i<length;i++){
        for(int j=0;j<str[i].size();j++){
            cout<<str[i][j]<<"\t";
    	}
        cout<<endl;
    }
    vector< vector<char> > ret;
    vector<char> temp3;
    cout<<"-------------------------------------------"<<endl;
    ret = sol->letterCombinations(str,ret,temp3,0,length);
     for(int i=0;i<ret.size();i++){
          for(int j=0;j<ret[i].size();j++){
              cout<<ret[i][j]<<"\t";
          }
         cout<<endl;
     }

    return 0;
}
