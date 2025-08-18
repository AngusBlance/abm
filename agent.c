#include <stdio.h>

typedef enum{
    ACTIVE,
    INACTIVE
}AgentState;

typedef struct{
    AgentState state;
    float likelihood;
    float grievance;
    int x;
    int y;
}Agent;

const char* enum_to_str(AgentState state);

void create_agents(Agent agents[], int num_agents) {
    for (int i = 0; i < num_agents; i++) {
        agents[i].state = (i % 2 == 0) ? ACTIVE : INACTIVE;
        agents[i].likelihood = 0.1f * (i + 1);
        agents[i].grievance = 0.2f * (i + 1);
        agents[i].x = i;
        agents[i].y = i * 2;
    }
}

void print_agent(Agent *agents, int agent_id, int num_agents){
    //int num_agents = sizeof(agents) / sizeof(agents[0]);

    if (agent_id == -1){
        for (int agent_num = 0; agent_num < num_agents; agent_num++){
            printf("gerievance: %.2f\n", agents[agent_num].grievance);
            printf("Likelihood: %.2f\n", agents[agent_num].likelihood);
            printf("State: %s\n", enum_to_str(agents[agent_num].state));
            printf("Position: (%d, %d)\n", agents[agent_num].x, agents[agent_num].y);
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
    Agent agents[5];
    int num_agents = 5;
    int agent_id = -1;
    create_agents(agents, num_agents);

    //printf("%u\n", agents[0].x);
    print_agent(agents, agent_id, num_agents);
    return 0;
}
