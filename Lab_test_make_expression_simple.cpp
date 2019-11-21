///input: a+b-(-c+d)+(e+f)
///output: a+b+c-d+e+f

#include<bits/stdc++.h>
using namespace std;
string simp;
string ex;
int i;

int make_simple(int index)
{

    string s;
    while(1)
    {
        if(ex[index]==')')
        {
            return index;
        }
        else
        {
            if(ex[index]=='+')
                simp+="-";
            else if(ex[index]=='-')
                simp+="+";
            else
                simp+=ex[index];
        }
        index++;
    }
}
int main()
{

    cin>>ex;
    for(i=0; ex[i]; i++)
    {
        if(ex[i]=='(' && ex[i-1]=='-')
        {
            if(ex[i+1]=='-')
            {
                simp[simp.length()-1]='+';
                i=make_simple(i+2);
            }
            else
                i=make_simple(i+1);
        }
        else if(ex[i]!='(' && ex[i]!=')')
            simp+=ex[i];
    }
    cout<<simp;

}
