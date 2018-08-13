#include <random>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define tamanho 10000000

double v[tamanho];

double some_positivos(double *a, int n){
    double soma = 0;
	for (int i=0; i<n; i++){
        if(a[i] > 0){
            soma += a[i];
        }
	}
    return soma;
}

double some_positivos(double *a, int n){
    double soma = 0;
	for (int i=0; i<n; i++){
        if(a[i] > 0){
            soma += a[i];
        }
	}
    return soma;
}

int main(){
    int n = tamanho;
    double result;
    default_random_engine generator;
    uniform_int_distribution<double> distribution(-10,10);
    for(int i = 0; i < n; i++){
        double value = distribution(generator); 
        v[i] = value;
    }
    
    //measure time of function
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    result = some_positivos(v, n);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    double duration = duration_cast<microseconds>( t2 - t1 ).count();
    cout << duration;

    return 0;
}
