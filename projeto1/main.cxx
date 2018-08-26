#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h> 
using namespace std;

int main(){
    int i = 0;
    //simulation variables
    double dt = 0.01;
    int N;
    //board variables
    double W, H, mu, alpha_w, alpha_b;
    //ball variables
    struct ball{
        int id;
        double radius; 
        double mass;
        double x;
        double y;
        double vx;
        double vy;
    };
    
    //read input
    cin >> W >> H >> N;
    cin >> mu >> alpha_w >> alpha_b;
    ball *ball_arrayA = new ball[N];
    ball *ball_arrayB = new ball[N];

    //read params
    while(i < N){
        ball curr_ball;
        cin >> curr_ball.id >> curr_ball.radius >> curr_ball.mass >> curr_ball.x >> curr_ball.y >> curr_ball.vx >> curr_ball.vy;
        ball_arrayA[i] = curr_ball;
        ball_arrayB[i] = curr_ball;
        i++;
    }
    //main loop
    ball *current = ball_arrayA;
    ball *next = ball_arrayB;
    i = 0;
    while(i < 100){
        //move
        for(int j = 0; j < N; j++){
            //calculate new position
            next[j].x = current[j].x + current[j].vx * dt;
            next[j].y = current[j].y + current[j].vy * dt;

            cout <<"id:" << current[j].id << " " << current[j].x << ',' << current[j].y << endl;
            cout <<"id:" << next[j].id << " " << next[j].x << ',' << next[j].y << endl << endl;
        }
        //collision
        for(int j = 0; j < N; j++){
            //wall collision
            if(next[j].x - next[j].radius <= 0){
                next[j].x  = current[j].x;
                next[j].vx = -current[j].vx;
                current[j].vx = -current[j].vx;
                cout << next[j].id << " bateu na esquerda " << endl;
            }else if(next[j].x + next[j].radius >= W){
                next[j].x  = current[j].x;
                next[j].vx = -current[j].vx;
                current[j].vx = -current[j].vx;
                cout << next[j].id << " bateu na direita " << endl;
            }else if(next[j].y - next[j].radius <= 0){
                next[j].y  = current[j].y;
                next[j].vy = -current[j].vy;
                current[j].vy = -current[j].vy;
                cout << next[j].id << " bateu em baixo " << endl;
            }else if(next[j].y + next[j].radius >= H){
                next[j].y  = current[j].y;
                next[j].vy = -current[j].vy;
                current[j].vy = -current[j].vy;
                cout << next[j].id << " bateu em cima " << endl;
            }
            //ball collision
            for (int k = j+1; k < N; k++){
                double distance = sqrtf(pow(fabs(next[j].x - next[k].x), 2.0) + pow(fabs(next[j].y - next[k].y), 2.0));
                double min_distance = next[j].radius + next[k].radius;
                //has collided?
                if(distance <= min_distance){
                    cout << next[j].id << " bateu em: " << next[k].id << endl;
                }
            }
        }

        //collision

        //swap current x next
        if(current == ball_arrayA){
            current = ball_arrayB;
            next = ball_arrayA;
        }else{
            current = ball_arrayA;
            next = ball_arrayB;
        }
        i++;
    }




    return 0;
}