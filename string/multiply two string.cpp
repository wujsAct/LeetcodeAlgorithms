#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string addstring(string num1,string num2){
        int len1 = num1.size(),len2 = num2.size();
        if(len1==0) {return num2;}
        if(len2==0) {return num1;}
        len1--;len2--;
        string ret="";
        int temp=0,flag=0;
        while(len1>-1 && len2>-1){
            temp = int(num1[len1]) + int(num2[len2])-2*int('0')+flag;
            ret = to_string(temp%10)+ret;
            flag = temp/10;
            len1--;len2--;
        }
        while(len1>-1){
            temp = int(num1[len1]) - int('0')+flag;
            ret = to_string(temp%10)+ret;
            flag = temp/10;
            len1--;
        }
        while(len2>-1){
            temp = int(num2[len2]) - int('0')+flag;
            ret = to_string(temp%10)+ret;
            flag = temp/10;
            len2--;
        }
        if(flag!=0){
          ret = to_string(flag)+ret;
        }
        return ret;
    }
    string multiply(string num1, string num2) {
        string temp="";
        //按照乘法的规律，必须长的内外层循环，短的为外层循环！
        if(num1.size() < num2.size()){
          temp = num1;
          num1 = num2;
          num2 =temp;
        }
        int len1 = num1.size(),len2 = num2.size();
        string ret="",tempstr="";
        int n1=0, n2=0, flag=0, tempint=0,k=0;
        for(int j=len2-1,k=0;j>=0;j--,k++){
            n1 = int(num2[j])-int('0'); //c++中只能用这种方式将数字的字符串转成数值型。
            cout<<"n1:"<<n1<<endl;
            flag=0;
            tempstr="";
            for(int ki=k;ki>0;ki--){
                tempstr = '0'+tempstr;
            }
            for(int i=len1-1;i>=0;i--){
                n2 = int(num1[i])-int('0');
                tempint = n1*n2+flag;
                tempstr=to_string(tempint%10)+tempstr;
                flag = tempint/10;
            }
            if(flag!=0){
                tempstr=to_string(flag)+tempstr;
            }
            cout<<"tempstr:"<<tempstr<<endl;
            ret = addstring(ret,tempstr);
            cout<<"ret:"<<ret<<endl;
        }
        k=0;
        while(ret[k]=='0' and k<ret.size()-1){
          k++;
          cout<<"k:"<<k<<endl;
        }
        return ret.substr(k,ret.size());
    }
};
int main(){
  Solution* sol = new Solution();
  cout<<sol->multiply("123","456")<<endl;
  return 1;
}
