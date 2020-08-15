#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#pragma comment(lib, "pthreadVC2.lib")     //必须加上这句
sem_t empty;  //控制盘子里可放的水果数
sem_t apple;  //控制苹果数
sem_t orange ;

pthread_mutex_t work_mutex;                    //声明互斥量work_mutex
void *put(void *arg) //放水果
{ 
    while(1){
       sem_wait(&empty);     //占用一个盘子空间，可放水果数减1
       pthread_mutex_lock(&work_mutex);     //加锁
       printf("放入一个苹果!\n");
       sem_post(&apple);     //释放一个apple信号了，可吃苹果数加1
       pthread_mutex_unlock(&work_mutex);   //解锁
       sleep(1);
    }
}

void *eat(void *arg)  //吃水果
{ 
    while(1){
        sem_wait(&apple);
        pthread_mutex_lock(&work_mutex);     //加锁
        printf("吃了一个苹果!\n");
        sem_post(&empty);
        pthread_mutex_unlock(&work_mutex);   //解锁
        sleep(3);
    }
}

void *test(void *arg){
    while(1){
        printf("test\n") ;
    }
}

int main()
{ 
    pthread_t father;  //定义线程
    pthread_t mother;
    pthread_t child ;

    sem_init(&empty, 0, 3);  //信号量初始化
    sem_init(&apple, 0, 0);
    sem_init(&orange, 0, 0);
    pthread_mutex_init(&work_mutex, NULL);   //初始化互斥量

    pthread_create(&father,NULL,put,NULL);  //创建线程
    pthread_create(&mother,NULL,eat,NULL);
    pthread_create(&child,NULL,test,NULL);

    sleep(1000000000);
    return 0 ;
}