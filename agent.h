#ifndef AGENT_H
#define AGENT_H

typedef enum {
    ACTIVE,
    INACTIVE
} AgentState;

typedef struct {
    AgentState state;
    float likelihood;
    float grievance;
    float legitimacy;
    float hardship;
    float x;
    float y;
} Agent;

void create_agents(Agent agents[], int num_agents, float LengthBoard);
void print_agent(Agent *agents, int agent_id, int num_agents);
const char* enum_to_str(AgentState state);

#endif
