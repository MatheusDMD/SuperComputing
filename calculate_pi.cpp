/*
This program will numerically compute the integral of
                  4/(1+x*x) 
				  
from 0 to 1.  The value of this integral is pi -- which 
is great since it gives us an easy way to check the answer.
The is the original sequential program.  It uses the timer
from the OpenMP runtime library
History: Written by Tim Mattson, 11/99.
         Updated by Luciano Soares
*/
#include <stdio.h>
#include <omp.h>

double pi_seq(long steps){
    double x, pi, sum = 0.0;
    double step = 1.0/(double) steps;

    for (int i=1;i<= steps; i++) {
        x = (i-0.5)*step;
        sum = sum + 4.0/(1.0+x*x);
    }
    pi = step * sum;
    return pi;
}

double pi_par1(long steps){
    int n = omp_get_max_threads();
    double step = 1.0/(double) steps;
    int chunk_size = (steps/n);
    double sum_final = 0;
    #pragma omp parallel 
    {
        int id = omp_get_thread_num();
        long start = chunk_size * id + 1;
        long end = start+chunk_size;
        double sum = 0;
        for (long i= start;i <= end; i++) {
            double x = (i-0.5)*step;
            sum += 4.0/(1.0+x*x);
        }
        #pragma omp atomic
        sum_final += sum;
    }
    return step * sum_final;;
}

int main () {
    static long num_steps = 1000000000;


    double start_time = omp_get_wtime();
    double pi = pi_par1(num_steps);
    double run_time = omp_get_wtime() - start_time;
    printf("\n pi with %ld steps is %.12lf in %lf seconds\n ",num_steps,pi,run_time);

    double start_time_seq = omp_get_wtime();    
    double pi_seq_value = pi_seq(num_steps);
    double run_time_seq = omp_get_wtime() - start_time;
    printf("\n pi with %ld steps is %.12lf in %lf seconds\n ",num_steps,pi_seq_value,run_time_seq);
    return 0;
}