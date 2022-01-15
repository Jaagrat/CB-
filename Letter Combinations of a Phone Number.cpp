class Solution {
    vector<string> v;
    char keypad[10][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void generate_names(char* s,char* out,int i,int j){
        //base case
        if(s[i]=='\0'){
            out[j]='\0';
            string str="";
            for(int p=0;out[p]!='\0';p++)
                str+=out[p];
            if(str!="")
            v.push_back(str);
            return;
        }
        
        //rec case
        int digit = s[i]-'0';
        if(digit==0 or digit==1){
            generate_names(s,out,i+1,j);
        }
        
        for(int k=0;keypad[digit][k]!='\0';k++){
            out[j]= keypad[digit][k];
            generate_names(s,out,i+1,j+1);
        }
        
        return;
    }
    
    
public:
    
    vector<string> letterCombinations(string digits) {
        char s[100];
        int i;
        for(i=0;i<digits.length();i++){
            s[i]=digits[i];
        }
        s[i]='\0';
        char out[100];
        generate_names(s,out,0,0);
        return v;
    }
};