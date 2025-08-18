#include <stdio.h>

typedef enum{
    CIVILIAN,
    RIOTER
}AgentState;

typedef struct{
    AgentState state;
    float likelihood;
    float grievance;
    int x;
    int y;
}Agent;

void create_agents(Agent agents[], int num_agents) {
    for (int i = 0; i < num_agents; i++) {
        agents[i].state = (i % 2 == 0) ? CIVILIAN : RIOTER;  // alternating states
        agents[i].likelihood = 0.1f * (i + 1);              // 0.1, 0.2, ...
        agents[i].grievance = 0.2f * (i + 1);               // 0.2, 0.4, ...
        agents[i].x = i;
        agents[i].y = i * 2;
    }
}

void print_agent(Agent *agents, int agent_id){
    int num_agents = sizeof(agents) / sizeof(agents[0]);

    if (agent_id == -1){
        for (int agent_num; agent_num < num_agents; agent_num++){
            printf("ID: %d\n", agents[agent_num].grievance);
            printf("Likelihood: %.2f\n", agents[agent_num].likelihood);
            printf("State: %c\n", agents[agent_num].state);
            printf("Position: (%d, %d)\n", agents[agent_num].x, agents[agent_num].y);
        }
    }
}


int main(){
    Agent agents[5];
    int agent_id = -1;
    create_agents(agents, agent_id);

    printf("%u\n", agents[0].x);

    return 0;
}

void print_agent(Agent *agents, int agent_id){
    int num_agents = sizeof(agents) / sizeof(agents[0]);

    if (agent_id == -1){
        for (int agent_num; agent_num < num_agents; agent_num++){
            printf("ID: %d\n", agents[agent_num].grievance);
            printf("Likelihood: %.2f\n", agents[agent_num].likelihood);
            printf("State: %c\n", agents[agent_num].state);
            printf("Position: (%d, %d)\n", agents[agent_num].x, agents[agent_num].y);
        }
    }
}