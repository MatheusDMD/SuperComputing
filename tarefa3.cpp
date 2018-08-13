#include <random>
#include <iostream>
#include <string>
#include <chrono>
#include <stdio.h>
#include "funcs.cpp"
#define size_of_array 100000000
#define size_of_times 20
using namespace std;
using namespace std::chrono;

int main(){
    unsigned long n = size_of_array;
    double indexes[size_of_times];
    double durations[size_of_times];
    double durations_array[size_of_times][size_of_times];
    double *a = new double [size_of_array];
    double *b = new double [size_of_array];
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0,100);
    cout << "SIMD Report Program\n";
    cout << "Initializing Random Array\n\n";
    for(unsigned long i = 0; i < n; i++){
        double value = distribution(generator); 
        a[i] = value;
    }
    for(unsigned long i = 0; i < n; i++){
        double value = distribution(generator); 
        b[i] = value;
    }
    int index = 0;
    double x;

    //inner_prod
    cout << "Inner Product\n"; 
    cout << "Calculating Mean\n";
    for(int t = 0; t < size_of_times; t++){
        index = 0;
        for(unsigned long s = 100000; s <= size_of_array; s = s*10){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            inner_prod(a, b, s);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();   
            double duration = duration_cast<microseconds>( t2 - t1 ).count();
            durations[index] = duration;
            indexes[index] = s;
            index++;
        }
        for(int i = 0; i < index; i++){
            durations_array[t][i] = durations[i];
            cout << durations[i];
            cout << ',';
        }
        cout << '\n';
    }
    for(int t = 0; t < size_of_times; t++){
        durations[t] = 0;
        for(int h = 0; h < size_of_times; h++){
            durations[t] += durations_array[h][t];
        }
        durations[t] /= size_of_times;
    }
    cout << "\nINNER PRODUCT:\n";
    for(int i = 0; i < index; i++){
        cout << durations[i];
        cout << ',';
    }
    cout << "\nPaste values in the Google Sheets at: http://bit.ly/2P3IcCI ";
    cout << "\n\n";

    //sum_positive
    cout << "Sum Positive\n";
    cout << "Calculating Mean\n";
    for(int t = 0; t < size_of_times; t++){
        index = 0;
        for(unsigned long s = 100000; s <= size_of_array; s = s*10){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            sum_positive(a, s);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();   
            double duration = duration_cast<microseconds>( t2 - t1 ).count();
            durations[index] = duration;
            indexes[index] = s;
            index++;
        }
        for(int i = 0; i < index; i++){
            durations_array[t][i] = durations[i];
            cout << durations[i];
            cout << ',';
            
        }
            cout << '\n';
    }
    for(int t = 0; t < size_of_times; t++){
        durations[t] = 0;
        for(int h = 0; h < size_of_times; h++){
            durations[t] += durations_array[h][t];

        }
        durations[t] /= size_of_times;
    }
    cout << "\nSUM POSITIVE:\n";
    for(int i = 0; i < index; i++){
        cout << durations[i];
        cout << ',';
    }
    cout << "\nPaste values in the Google Sheets at: http://bit.ly/2P3IcCI ";
    cout << "\n\n";
    index = 0;

    //sqrt_element
    cout << "SQRT Element\n";
    cout << "Calculating Mean\n";
    for(int t = 0; t < size_of_times; t++){
        index = 0;
        for(unsigned long s = 100000; s <= size_of_array; s = s*10){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            sqrt_element(a, s);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();   
            double duration = duration_cast<microseconds>( t2 - t1 ).count();
            durations[index] = duration;
            indexes[index] = s;
            index++;
        }
        for(int i = 0; i < index; i++){
            durations_array[t][i] = durations[i];
            cout << durations[i];
            cout << ',';
            
        }
            cout << '\n';
    }
    for(int t = 0; t < size_of_times; t++){
        durations[t] = 0;
        for(int h = 0; h < size_of_times; h++){
            durations[t] += durations_array[h][t];

        }
        durations[t] /= size_of_times;
    }
    cout << "\nSQRT ELEMENT:\n";
    for(int i = 0; i < index; i++){
        cout << durations[i];
        cout << ',';
    }
    cout << "\nPaste values in the Google Sheets at: http://bit.ly/2P3IcCI ";
    cout << "\n\n";
    index = 0;

    //exp_element
    cout << "Exp Element\n";
    cout << "Calculating Mean\n";
    for(int t = 0; t < size_of_times; t++){
        index = 0;
        for(unsigned long s = 100000; s <= size_of_array; s = s*10){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            exp_element(a, s);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();   
            double duration = duration_cast<microseconds>( t2 - t1 ).count();
            durations[index] = duration;
            indexes[index] = s;
            index++;
        }
        for(int i = 0; i < index; i++){
            durations_array[t][i] = durations[i];
            cout << durations[i];
            cout << ',';
            
        }
            cout << '\n';
    }
    for(int t = 0; t < size_of_times; t++){
        durations[t] = 0;
        for(int h = 0; h < size_of_times; h++){
            durations[t] += durations_array[h][t];

        }
        durations[t] /= size_of_times;
    }
    cout << "\nEXP ELEMENT:\n";
    for(int i = 0; i < index; i++){
        cout << durations[i];
        cout << ',';
    }
    cout << "\nPaste values in the Google Sheets at: http://bit.ly/2P3IcCI ";
    cout << "\n\n";
    index = 0;

    //log_element
    cout << "Log Element\n";
    cout << "Calculating Mean\n";
    for(int t = 0; t < size_of_times; t++){
        index = 0;
        for(unsigned long s = 100000; s <= size_of_array; s = s*10){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            log_element(a, s);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();   
            double duration = duration_cast<microseconds>( t2 - t1 ).count();
            durations[index] = duration;
            indexes[index] = s;
            index++;
        }
        for(int i = 0; i < index; i++){
            durations_array[t][i] = durations[i];
            cout << durations[i];
            cout << ',';
            
        }
            cout << '\n';
    }
    for(int t = 0; t < size_of_times; t++){
        durations[t] = 0;
        for(int h = 0; h < size_of_times; h++){
            durations[t] += durations_array[h][t];

        }
        durations[t] /= size_of_times;
    }
    cout << "\nLOG ELEMENT:\n";
    for(int i = 0; i < index; i++){
        cout << durations[i];
        cout << ',';
    }
    cout << "\nPaste values in the Google Sheets at: http://bit.ly/2P3IcCI ";
    cout << "\n\n";
    index = 0;

    //gauss
    cout << "Gauss Element\n";
    cout << "Calculating Mean\n";
    for(int t = 0; t < size_of_times; t++){
        index = 0;
        for(unsigned long s = 100000; s <= size_of_array; s = s*10){
            high_resolution_clock::time_point t1 = high_resolution_clock::now();
            gauss(a,b, s);
            high_resolution_clock::time_point t2 = high_resolution_clock::now();   
            double duration = duration_cast<microseconds>( t2 - t1 ).count();
            durations[index] = duration;
            indexes[index] = s;
            index++;
        }
        for(int i = 0; i < index; i++){
            durations_array[t][i] = durations[i];
            cout << durations[i];
            cout << ',';
            
        }
            cout << '\n';
    }
    for(int t = 0; t < size_of_times; t++){
        durations[t] = 0;
        for(int h = 0; h < size_of_times; h++){
            durations[t] += durations_array[h][t];

        }
        durations[t] /= size_of_times;
    }
    
    cout << "\nGAUSS ELEMENT:\n";
    for(int i = 0; i < index; i++){
        cout << durations[i];
        cout << ',';
    }
    cout << "\nPaste values in the Google Sheets at: http://bit.ly/2P3IcCI ";
    cout << "\n\n";

    return 0;
}