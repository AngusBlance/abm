#include <stdio.h>

typedef enum{
    CIVILIAN,
    RIOTER
}AgentState;

typedef struct{
    AgentState state;
    float likelyhood;
    float Grievence;
    int x;
    int y;
}Agent;

int main(){
    Agent agents[1];
    agents[0].state = CIVILIAN;
    agents[0].likelyhood = 0.2f;
    agents[0].Grievence = 0.1f;
    agents[0].x = 1;
    agents[0].y = 0;
    printf("agents");

    return 0;
}