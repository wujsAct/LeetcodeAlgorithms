class Solution {
public:
    int myAtoi(string str) {
        int strlen = str.size();
        long long final=0;
        cout<<strlen<<endl; 
        int i=0;
        int flag=1;
        #É¾³ý¶àÓàµÄ¿Õ¸ñ
        while(true){
            if(str[i]==' ')
                i++;
            else
                break;
        }
        if(str[i] =='-'){
            flag = -1;
            i+=1;
            if(str[i]=='+' or str[i]=='-')
                return 0;
        }
        else if(str[i] =='+'){
            flag = 1;
            i+=1;
            if(str[i]=='+' or str[i]=='-')
                return 0;
        }
        while(true){
            if(str[i]=='0')
                i++;
            else
                break;
        }
        if(i >=strlen)
            return 0;
        else{
            int start = i;
            cout<<"i\t"<<i<<"\tstr[i]"<<str[i]<<endl;
            cout<<"flag\t"<<flag<<endl;
            int Maxint = 2147483647;
            string minint = "2147483648";
            for(;i<strlen;i++){
                if(int(str[i])-int('9')<=0 and str[i]-'0' >= 0){
                    final = final*10 + int(str[i])-'0';
                    if(final > INT_MAX){
                        if(flag==1)
                            return INT_MAX;
                        else
                            return INT_MIN;
                    }
                }
                else
                    break;
            }
            return flag*final;
        }
    }
};