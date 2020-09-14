#include <iostream>
#include <stdio.h>
#include <string>
#include <exception>
#include <vector>

using namespace std;

/*
 Token:
    a sequence of characters that represents something we consider a unit,
    such as a number or an oeprator
 
    type(int or char)
    - used to define variables and hold values
 */

class Token{
public:
    char kind;
    double value;
    Token(char ch)
        :kind(ch), value(0){}
    Token(char ch, double val)
        :kind(ch), value(val){}
    
};

Token get_token();  //read a token from cin

vector<Token> tok;

void error (string s){
  throw runtime_error (s);
    //uncaught excepiton
    //throw (s);
}

int main(){
    double d;
    
    while(cin){
        Token t = get_token();
        tok.push_back(t);
    }
    
    
    for(int i = 0; i<tok.size(); ++i){
        if (tok[i].kind == '*'){
            d = tok[i-1].value * tok[i+1].value;
        }
        if (tok[i].kind == '+'){
            d = tok[i-1].value + tok[i+1].value;
        }
        if (tok[i].kind == '-'){
            d = tok[i-1].value - tok[i+1].value;
        }
        if (tok[i].kind == '/'){
            d = tok[i-1].value / tok[i+1].value;
        }
    }
    
    cout << "Result: " << d;
}




/*
int main(int argc, const char * argv[]) {
    cout << "Please enter expression (we can handle +,-,*, and /): ";
    int lval = 0;
    int rval;
    char op;
    
    cin >> lval;
    if(!cin) error("no first operand");
    
    while (cin >> op){
        cin >> rval;
        if(!cin) error ("no second operand");
        
        switch(op){
            case '+':
                lval += rval;
                break;
            case '-':
                lval -= rval;
                break;
            case '*':
                lval *= rval;
                break;
            case '/':
                lval /= rval;
                break;
            default:
                cout << "Result: " << lval <<'\n';
                return 0;
        }
    }
    error("bad expression");
    
}

*/
