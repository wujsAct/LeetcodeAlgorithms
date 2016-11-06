/**
**@2016/11/6
**hash_map也可以使用的！
**string 类型支持hash，但是string类却没有重载比较运算符
**所以标准的hash_compare仿函数还是无法正常的工作，需要继续重写less仿函数
*/

/***
for example:
struct string_less : public binary_function<const string, const string, bool>  
{   
public:   
    result_type operator()(const first_argument_type& _Left, const second_argument_type& _Right) const   
    {   
        return(_Left.compare(_Right) < 0 ? true : fase);   
    }   
};  
hash_map<string, int, hash_compare<string, string_less> > StringHash;  
StringHash["a"] = 123;  
StringHash["b"] = 456;  
string strKey = "a";  
int val = CharHash[strKey]; 
*/

class Solution {
public:
    struct stringHash{
        int hash[26];
        stringHash(const string& str){
            fill(hash, hash+26, 0);
            for(auto& c:str){
                hash[c-'a']+=1;
                cout<<c-'a'<<"\t";
            }
            cout<<endl;
        }
        
        bool operator<(const stringHash&sh) const{
            for(size_t i=0;i<26;++i){
                if(this->hash[i] <sh.hash[i])
                    return true;
                else if(this->hash[i]>sh.hash[i])
                    return false;
            }
            return false;
        }
    };
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<stringHash, vector<vector<string>::iterator>> hash_map;
        
        for(auto iter=begin(strs);iter!=end(strs);iter++){
            cout<<(*iter)<<endl;
            hash_map[stringHash(*iter)].push_back(iter);
        }
        
        vector<vector<string>> ret;
        for(auto hsm:hash_map){
            cout<<"hsm.second.size()"<<hsm.second.size()<<endl;
            vector<string> temp;
            for(auto i:hsm.second)
                temp.push_back((*i));
            ret.push_back(temp);
        }
        
        return ret;
    }
};