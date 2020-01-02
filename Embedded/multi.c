#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> //for number_of_processors
#include <time.h> //for clock_t
#include <semaphore.h>

struct counter {
        int count;
        sem_t a;
        sem_t b;
        pthread_mutex_t lock;
        pthread_cond_t above_zero;
};


void increment(struct counter *c){
        pthread_mutex_lock(&c->lock);
        int n = c->count;
        c->count = n+1;
        if(c->count > 0) {
                pthread_cond_signal(&c->above_zero);
        }
        pthread_mutex_unlock(&c->lock);
}

void decrement(struct counter *c){
        pthread_mutex_lock(&c->lock);
        int n = c->count;
        c->count = n - 1;
        pthread_mutex_unlock(&c->lock);
}

void print_val(struct counter * c){
        pthread_mutex_lock(&c->lock);
        while(c->count <= 0) {
                pthread_cond_wait(&c->above_zero, &c->lock);
        }
        printf("Value = %d\n",c->count);
        pthread_mutex_unlock(&c->lock);
}

/* thread function for multi-threading
        order of execution: T1, T3, T2
 */
void* T1(void* arg){
        struct counter *tmp_c = arg;
        printf("T1\n");

        increment(tmp_c);

        sem_post(&(tmp_c->a));

        pthread_exit(NULL);
        return NULL;
}

void* T2(void* arg){
        struct counter *tmp_c = arg;


        sem_wait(&(tmp_c->b));
        printf("T2\n");

        print_val(tmp_c);

        pthread_exit(NULL);
        return NULL;
}

void* T3(void* arg){
        struct counter *tmp_c = arg;


        sem_wait(&(tmp_c->a));
        printf("T3\n");

        increment(tmp_c);

        sem_post(&(tmp_c->b));

        pthread_exit(NULL);
        return NULL;
}



void main(){
        struct counter x;
        x.count = -1;

        //Thread scheduling
        sem_init(&(x.a),1,0); //adddress, shared/notshared, value
        sem_init(&(x.b),1,0); //adddress, shared/notshared, value

        long number_of_processors = sysconf(_SC_NPROCESSORS_ONLN);

        pthread_t threads[number_of_processors];

        // creating 4 threads
        //for (int i = 0; i < THREAD_MAX; i++)
        pthread_create(&threads[0], NULL, T1,(void*)&x);
        pthread_create(&threads[1], NULL, T2,(void*)&x);
        pthread_create(&threads[2], NULL, T3,(void*)&x);

        // joining all 4 threads
        for (int i = 0; i < 3; i++)
                pthread_join(threads[i], NULL);

}
