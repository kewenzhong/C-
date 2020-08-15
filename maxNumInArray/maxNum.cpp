/***
 * 一个先递增后递减的数组，求最大值
***/

#include <iostream>
#include <vector>
using namespace std ;

int maxNum( const vector<int>& array,int L,int R ){
    if( L==R ){
        return array[L] ;
    }

    if( (L<=0 || array[L]>array[L-1]) && (R>=array.size()-1 || array[R]>array[R+1]) ){
        int mid = (L+R)/2 ;
        return max(maxNum(array,L,mid),maxNum(array,mid+1,R)) ;
    }
    else{
        return array[0]-1 ;
    }
}



int main(){
    vector<int> vec(5, 1);
    auto it = vec.begin() + 3;
    for (int i = 0; i < 10; ++i)
    {
        vec.insert(it, i);
    }
    return 0 ;
}


