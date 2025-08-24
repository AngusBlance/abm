#include "agent.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static inline float rand_float(float min, float max) {
    return min + ((float)rand() / RAND_MAX) * (max - min);
}

void create_agents(Agent agents[], int num_agents, float LengthBoard) {
    for (int i = 0; i < num_agents; i++) {
        agents[i].state = (i % 2 == 0) ? ACTIVE : INACTIVE;
        agents[i].likelihood = rand_float(0.0f, 1.0f);
        agents[i].legitimacy = rand_float(0.0f, 1.0f);
        agents[i].hardship = rand_float(0.0f, 1.0f);
        agents[i].grievance = agents[i].hardship * (1 - agents[i].legitimacy);
        agents[i].x = rand_float(0.0f, LengthBoard);
        agents[i].y = rand_float(0.0f, LengthBoard);
    }
}
void create_police(Agent police[], int num_police, float LengthBoard){
    for (int i = 0; i < num_police; i++){
        police[i].state = POLICE;
        police[i].x = rand_float(0.0f, LengthBoard);
        police[i].y = rand_float(0.0f, LengthBoard);
    }
}

const char* enum_to_str(AgentState s) {
    switch(s){
        case ACTIVE: return "A";
        case INACTIVE: return "I";
        case POLICE: return "P";
        default: return "UNKNOWN";
    }
}

void print_agent(Agent *agents, int agent_id, int num_agent, int num_police){
    for (int i = 0; i < num_agent; i++) {
        if (agent_id >= 0 && i != agent_id) continue;
        printf("Grievance: %.2f\n", agents[i].grievance);
        printf("Legitimacy: %.2f\n", agents[i].legitimacy);
        printf("Hardship: %.2f\n", agents[i].hardship);
        printf("Likelihood: %.2f\n", agents[i].likelihood);
        printf("State: %s\n", enum_to_str(agents[i].state));
        printf("Position: (%.2f, %.2f)\n\n", agents[i].x, agents[i].y);
    } 
}
