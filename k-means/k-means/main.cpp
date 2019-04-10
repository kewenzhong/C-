//
//  main.cpp
//  k-means
//
//  Created by 阿昂 on 2018/6/27.
//  Copyright © 2018年 柯文钟. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
using namespace std ;

#define DIM 5
#define K   5

typedef vector<double> Tuple ;

//获取两个点之间的距离
double getDis( const Tuple& tuple1,const Tuple& tuple2 ){
    double sum = 0 ;
    for (int i = 0; i < DIM; ++i)
    {
        sum += pow(tuple1[i]-tuple2[i],2) ;
    }
    return sqrt(sum) ;
}


//判断一个点属于哪个簇
int clusterOfTuple( const Tuple& tuple,Tuple means[]){
    double dis = getDis(tuple,means[0]) ;
    int label = 0 ;
    
    for( int i = 1;i<K;i++ ){
        double d = getDis(tuple,means[i]) ;
        if( d < dis ){
            dis = d ;
            label = i ;
        }
    }
    return label ;
}


//获取给定簇的平方误差
double getVar( const std::vector<Tuple> clusters[],const Tuple means[] ){
    double sum = 0 ;
    for( int i = 0;i<K;i++ ){
        for( int j=0;j<clusters[i].size();j++ ){
            sum += getDis(clusters[i][j],means[i]) ;
        }
    }
    return sum ;
}

//获取簇的平均值
void getMeans(const std::vector<Tuple> clusters[],Tuple means[] ){
    
    for( int i = 0;i<K;i++ ){
        for(int t = 0;t<DIM;t++ ){
            double sum = 0 ;
            // cout<<i<<" "<<clusters[i].size()<<endl;
            for( int j =0;j<clusters[i].size();j++ ){
                sum += clusters[i][j][t] ;
            }
            sum /= clusters[i].size() ;
            means[i][t] = sum ;
        }
        
        // for( int j =0;j<DIM;j++ ){
        //     cout<<means[i][j]<< " " ;
        // }cout<<endl ;
    }
}

void print(std::vector<Tuple> clusters[] ){
    for (int i = 0; i < K; ++i)
    {
        cout<<"第"<<i<<"簇"<<endl ;
        for( int j=0;j<clusters[i].size();j++ ){
            cout<<j<<". (" ;
            for( int t=0;t<DIM;t++ ){
                cout<<clusters[i][j][t]<<"," ;
            }
            cout<<")"<<endl ;
        }
    }
}

//聚类方法
void KMeans( const vector<Tuple>& tuples){
    std::vector<Tuple> clusters[K];
    Tuple means[K] ;
    // cout<<(unsigned)time(NULL)<<endl ;
    //随机选取K个簇首
    srand( (unsigned)time(NULL) ) ;
    for( int i = 0 ;i < K ; ){
        int selected = rand() % tuples.size() ;
        if( means[i].size() == 0 ){
            for (int j = 0; j < DIM; ++j)
            {
                means[i].push_back(tuples[selected][j]) ;
//                means[i][j] = tuples[selected][j] ;
            }
            i++ ;
        }
    }
    
    //根据距离将每个点分配到不同的簇
    for (int i = 0; i < tuples.size(); ++i)
    {
        int label = clusterOfTuple(tuples[i],means) ;
        clusters[label].push_back(tuples[i]) ;
    }
    
    getMeans(clusters,means) ;
    
    double oldVar = -1 ;
    double newVar = getVar(clusters,means) ;
    
    int count = 0 ;
    
    while( fabs(newVar - oldVar) > 1 &&  count++ < 100 ){
        
        for (int i = 0; i < K; ++i)
        {
            clusters[i].clear() ;
        }
        
        //根据距离将每个点分配到不同的簇
        for (int i = 0; i < tuples.size(); ++i)
        {
            int label = clusterOfTuple(tuples[i],means) ;
            clusters[label].push_back(tuples[i]) ;
        }
        // for (int i = 0; i < K; ++i)
        // {
        //     // cout<<clusters[i].size()<<" " ;
        // }cout<<endl ;
        
        getMeans(clusters,means) ;
        oldVar = newVar ;
        newVar = getVar(clusters,means) ;
//        cout<<oldVar<<endl ;
        cout<<newVar<<endl ;
    }
    // print(clusters) ;
    
}


int main(){
    //读取文件
    fstream file("/Users/aang/Desktop/data.txt") ;
    if( !file.is_open() ){
        cout<<"file open exception!"<<endl ;
        return 0 ;
    }
    
    std::vector<Tuple> tuples ;
    
    string str ;
    int count = 0 ;
    
    while( !file.eof() ){
        getline(file,str) ;
        if( str != "" ){
            //cout<<str<<endl ;
            istringstream istr(str) ;
            
            Tuple tuple ;
            double t ;
            
            for( int i =0 ;i<DIM ;i++ )
            {
                istr>>t ;
                tuple.push_back(t) ;
                //cout<<t<<" " ;
            }
            tuples.push_back(tuple) ;
            count++ ;
            // cout<<endl ;
        }
//        cout<<count<<endl ;
    } //while
    
    //开始聚类
    KMeans(tuples) ;
    
    file.close() ;
    return 0 ;
}
