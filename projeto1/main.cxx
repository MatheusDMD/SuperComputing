#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
#include "ball.hxx"


int main(){
    int i = 0;
    double W, H, N, mu, alpha_w, alpha_b;
    int id;
    double radius, mass, x0, y0, vx0, vy0;
    cin >> W >> H >> N;
    cin >> mu >> alpha_w >> alpha_b;
    ball *ball_array = new ball [N];

    while(i < N){
        //ler params
        ball_array[i] = ball();
        i++;
    }
    read_file();

    // while (not stopped) time_step
        // simulate_interactions
        // 




    return 0;
}