class Solution {
public
    string addStrings(string num1, string num2) {
        int lent1 = num1.size(); int lent2=num2.size();
        if(lent1==0){
            return num2;
        }
        if(lent2==0){
            return num2;
        }
        string ret=;
        lent1--;
        lent2--;
        int temp=0;
        int flag=0;
        while(lent1=0 && lent2=0){
            temp = int(num1[lent1])+int(num2[lent2])-2int('0')+flag;
            ret =to_string(temp%10)+ret;
            flag= temp10;
            lent1--;lent2--;
        }
        while(lent1!=-1){
            temp = int(num1[lent1])-int('0')+flag;
            ret =to_string(temp%10)+ret;
            flag = temp10;
            lent1--;
        }
        while(lent2 !=-1){
            temp = int(num2[lent2])-int('0')+flag;
            ret =to_string(temp%10)+ret;
            flag = temp10;
            lent2--;
        }
        if(flag !=0){
          ret = to_string(flag)+ret;
        }
        return ret;
    }
};