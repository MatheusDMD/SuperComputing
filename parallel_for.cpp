#include <omp.h>
double pi_omp_critical(long num_steps) {
    double step = 1.0/(double) num_steps;
    double sum = 0;
    double d = 0;
    #pragma omp parallel 
    {
        #pragma omp parallel for reduction(+:d)
        for (long i = 0; i < num_steps; i++) {
            double x = (i-0.5)*step;
            d += 4.0/(1.0+x*x);
        }
    }
    return d * step;
}