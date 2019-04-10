#include<iostream>
#include<string>
#include<vector>
using namespace std ;

int n[100] = {0};

void NextVal(string p)
{
    int pLen = p.size();
    int i = 0, j = -1;
    n[0] = -1;
    while(i < pLen - 1){
        if(j == -1 || p[i] == p[j]){
            ++i;
            ++j;

            if(p[i] != p[j])
                n[i] = j;
            else
                n[i] = n[j];
        }
        else
            j = n[j];
    }
}

int KMP(string s, string p)
{
    int sLength = s.size();
    int pLength = p.size();
    int next[100] = {0};
    NextVal(p);

    for( auto i:next ){
        cout<<i<<' ' ;
    }cout<<endl ;

    int i = 0, j = 0;
    while(i < sLength && j < pLength){
        if(j == -1 || s[i] == p[j]){
            ++i;
            ++j;
        }
        else
            j = next[j];
    }
    if(j == pLength)
        return i - j;
    return -1;
}

int main(){
    string str,p ;
    str = "abcdabcd" ;
    p = "da" ;
    int res = KMP(str,p) ;

    cout<<res<<endl ;
    return 0 ;

}