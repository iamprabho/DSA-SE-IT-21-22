#include<iostream>
#include<stack>
using namespace std;
int prec(char c){
    if(c=='+' || c=='-'){
        return 0;

    }
    else if(c=='*' || c=='/'){
        return 1;

    }
    else{
        return 2;

    }

    
}
string infixtoPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') ){
            res+=s[i];

        }
        else if(s[i]=='('){

        
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while ( !st.empty() && st.top()!='(' )
            {
             
             res+=st.top();
             st.pop();

            }
            if(!st.empty()){
                st.pop();

            }

            
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res+=st.top();

                st.pop();

            }
            st.push(s[i]);

        }
        

    }
    while(!st.empty()){
        res+=st.top();
        st.pop();

    }
    return res;
   


}







string infixtoPrefix(string s){
    reverse(s.begin(),s.end());
    stack<char>st;
    string res;
    for( int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
            res+=s[i];

        }
        else if(s[i]==')'){
            st.push(s[i]);

        }
        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
            res+=st.top();
            st.pop();
            }
            if(!st.empty()){
                st.pop();

            }

        }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i])){
                res+=st.top();
                st.pop();

            }
            st.push(s[i]);

        }

    }
    while(!st.empty()){
        res+=st.top();

        st.pop();

    }
    reverse(res.begin(),res.end());
    return res;

}
int main(){
    cout<<infixtoPrefix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infixtoPostfix("(a-b/c)*(a/k-l)")<<endl;

}

