#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{
    ACTIVE,
    INACTIVE
}AgentState;

typedef struct{
    AgentState state;
    float likelihood;
    float grievance;
    float legitimacy;
    float hardship;
    float x;
    float y;
}Agent;

const char* enum_to_str(AgentState state);

void create_agents(Agent agents[], int num_agents, float LengthBoard) {
    for (int i = 0; i < num_agents; i++) {
        

        agents[i].state = (i % 2 == 0) ? ACTIVE : INACTIVE;
        agents[i].likelihood = (float) (rand()) / RAND_MAX;
        agents[i].legitimacy = (float) (rand()) / RAND_MAX;
        agents[i].hardship = (float) (rand()) / RAND_MAX;
        agents[i].grievance = (float) agents[i].hardship * (1 - agents[i].legitimacy);
        agents[i].x = ((float) rand() / RAND_MAX) * LengthBoard;
        agents[i].y = ((float) rand() / RAND_MAX) * LengthBoard;
    }
}

void print_agent(Agent *agents, int agent_id, int num_agents){
    //int num_agents = sizeof(agents) / sizeof(agents[0]);

    if (agent_id == -1){
        for (int agent_num = 0; agent_num < num_agents; agent_num++){
            printf("Gerievance: %.2f\n", agents[agent_num].grievance);
            printf("Legitamacy: %.2f\n", agents[agent_num].legitimacy);
            printf("hardship: %.2f\n", agents[agent_num].hardship);
            printf("Likelihood: %.2f\n", agents[agent_num].likelihood);
            printf("State: %s\n", enum_to_str(agents[agent_num].state));
            printf("Position: (%.2f, %.2f)\n", agents[agent_num].x, agents[agent_num].y);
            printf("\n");
        }
    }
}

const char* enum_to_str(AgentState s){
    switch(s){
        case ACTIVE: return "A";
        case INACTIVE: return "I";
        default: return "UNKNOWN";
    }
}

int main(){
    srand(time(0));
    Agent agents[5];
    int num_agents = 5;
    int agent_id = -1;
    int LengthBoard = 10;
    create_agents(agents, num_agents, LengthBoard);

    //printf("%u\n", agents[0].x);
    print_agent(agents, agent_id, num_agents);
    return 0;
}
