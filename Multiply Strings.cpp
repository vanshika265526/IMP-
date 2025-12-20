
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
  */
class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        vector<int> result(m+n,0); //max result after multiplication size can be m+n only

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int mul=(num1[i]-'0') * (num2[j]-'0');
                int sum=mul+result[i+j+1];
                result[i+j+1]=sum%10;
                result[i+j]=result[i+j]+(sum/10);
            }
        }
        string r="";
        for(int num:result){
            if(!(r.empty() && num==0)){
                r=r+to_string(num);
            }

        }
        return r.empty()?"0":r;
    }
};
