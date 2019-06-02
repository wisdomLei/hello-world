/*
    This is a CPG project. It can be used to robot joint contral.
*/
#include<stdio.h>
#include<math.h>
#define JOINT_N 3
#define DT 0.0001
#define PI 3.14159265358979323846 

typedef struct oscillator{
    float phase;
    float amplitude;
    float frequent;
    float in_amp;
    float time_para;
    float out;
} osi;

osi joint[JOINT_N * 2] = {
        {0,0,2,0.6,10,0},
        {0,0,2,0.75,10,0},
        {0,0,2,0.9,10,0},
        {0,0,2,0.6,10,0},
        {0,0,2,0.75,10,0},
        {0,0,2,0.9,10,0}
    };
static float weight[JOINT_N * 2][JOINT_N * 2];
static float phase_bias[JOINT_N * 2][JOINT_N * 2];

static int calculate(int);

int main(void){
    int time = 0,i;
    for(time = 0;time < 10;++time){
        calculate(time);
    }
    for(i = 0;i < JOINT_N * 2;++i){
        printf("%f\n",joint[i].out);
    }
    return 0;
}


static int weight_init(){
    int i,j;
    for(i = 0;i < JOINT_N * 2;++i){
        for(j = 0;j < JOINT_N * 2;++j){
            if(j == i){
                weight[i][j] = 0;  //parallel coupling.
            }else if(j - i == 1 || i - j == 1){
                weight[i][j] = 10;  //up*down coupling.
            }else{
                weight[i][j] = 0;
            }
        }
    }
    return 0;
}

static int phase_bias_init(){
    int i,j;
    for(i = 0;i < JOINT_N * 2;++i){
        for(j = 0;j < JOINT_N * 2;++j){
            if(j - i == 1 && j != JOINT_N){
                phase_bias[i][j] = PI/4;    //down coupling phase bias.
            }else if(j - i == -1 && i != JOINT_N){
                phase_bias[i][j] = -PI/4;   //up coupling phase bias.
            }else{
                phase_bias[i][j] = 0;
            }
        }
    }
    return 0;
}
static int calculate(int time){
    weight_init();
    phase_bias_init();
    int i,j;
    float add = 0;
    float time_start,time_stop ;
    for(time_start = time * 0.02,time_stop = (time + 1) * 0.02;time_start < time_stop;time_start += DT){
        for(i = 0;i < JOINT_N * 2;++i){
            joint[i].amplitude += (joint[i].time_para * (joint[i].time_para / 4 * (joint[i].in_amp - joint[i].amplitude / DT))) * DT * DT;
       }
       for(i = 0;i < JOINT_N * 2;++i){
           for(j = 0;j < JOINT_N * 2;++j){
               if(j != i){
                   add += joint[i].amplitude * weight[i][j] * sin(joint[j].phase - joint[i].phase - phase_bias[i][j]);
               }
           }
           joint[i].phase += (2 * PI * joint[i].frequent + add) * DT;
       }
    }
    for(i = 0;i < JOINT_N * 2;++i){
           joint[i].out = joint[i].amplitude * (1 + cos(joint[i].phase));
    }
    return 0;
}
