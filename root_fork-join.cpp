#include <thread>
#include <iostream>
#include <stdio.h>
#include <string>
#include <random>
#include <chrono>
#define size_of_array 100000000
using namespace std;
using namespace std::chrono;

void funcao_rodando_em_paralelo(int ID) {
    std::thread::id threadID = std::this_thread::get_id();
    std::cout << "Thread: " << ID;
    std::cout << std::endl;
}

void soma_vetor_seq(double *vec, int end, int start, double *result_parcial){
    for(int i = start; i < end; i++){
        *result_parcial += vec[i];
    }
}

int main() {
    unsigned long n_size_array = size_of_array;
    double *a = new double [size_of_array];
    unsigned int n = std::thread::hardware_concurrency();
    
    std::thread *thread_vector = new std::thread[n];
    double *result_vector = new double[n];

    
    default_random_engine generator;
    normal_distribution<double> distribution(1.0,5.0);
    for(unsigned long i = 0; i < n_size_array; i++){
        double value = distribution(generator); 
        a[i] = value;
    }

    high_resolution_clock::time_point t1_p = high_resolution_clock::now();

    int step = n_size_array/n;
    for(int id = 0; id < n; id++){
        int start = step*id;
        int end = (start+step);
        thread_vector[id] = std::thread (soma_vetor_seq, a, end, start, &result_vector[id]);
    }
    
    for(int id = 0; id < n; id++){
        thread_vector[id].join();
    }

    double final_result = 0;
    for(int j = 0; j < n; j++){
        final_result += result_vector[j];
    }
    high_resolution_clock::time_point t2_p = high_resolution_clock::now();   
    double duration_p = duration_cast<microseconds>( t2_p - t1_p ).count();

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    double final_result_seq = 0;
    for(int j = 0; j < n_size_array; j++){
        final_result_seq += a[j];
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();    
    double duration_s = duration_cast<microseconds>( t2 - t1 ).count();

    cout << "Paralelo: " << final_result << endl;
    cout << "Paralelo time: " << duration_p << endl;
    cout << "Sequencial: " << final_result_seq << endl;
    cout << "Sequencial time: " << duration_s << endl;

}
