#ifndef AGENT_H
#define AGENT_H

typedef enum {
    ACTIVE,
    INACTIVE,
    POLICE,
    ARREST,
} AgentState;

typedef struct {
    AgentState state;
    float x;
    float y;
    float likelihood;
    float grievance;
    float legitimacy;
    float hardship;
} Agent;

void create_agents(Agent agents[], int num_agents, float LengthBoard);
void create_police(Agent police[], int num_police, float LengthBoard);
void print_agent(Agent *agents, int agent_id, int num_agents, int num_police);
const char* enum_to_str(AgentState state);
float rand_float(float min, float max);
void arrest(Agent agent[], Agent police[],int num_police, int num_agent, float vision);
void move(Agent *agent, int num_agent, float move_dist);

#endif
