#include <bits/stdc++.h>

using namespace std;
struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()

{
    string ty;
    int err_pos=0;
    stack <Bracket> o_st;
    string txt;
    cin>>txt;
    for (int pos =0 ; pos< txt.length(); pos++){
        char next= txt[pos];
        if (next=='('|| next=='['||next=='{'){
                Bracket br(next,pos);
                o_st.push(br);
            }
        if (next == ')' || next == ']' || next == '}'){
            if (o_st.empty()){
                cout<<pos+1<<endl;
                return 0;
            }
            if (o_st.top().Matchc(next)){
                o_st.pop();
            }
            else {
                cout<<pos+1<<endl;
                return 0;
            }
            }
        }

    if (o_st.empty())
        cout<<"Success"<<endl;

        else {
            cout<<o_st.top().position+1<<endl;
        }

    }


