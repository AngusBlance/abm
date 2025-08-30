#include <math.h>
#include "agent.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_float(float min, float max) {
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

void arrest(Agent agent[], Agent police[], int num_police, int num_agent, float vision) {

    for (int po = 0; po < num_police; po++) {
        for (int ag = 0; ag < num_agent; ag++) {
            float dx = police[po].x - agent[ag].x;
            float dy = police[po].y - agent[ag].y;
            float distance = sqrt(dx * dx + dy * dy);

            if (distance < vision && enum_to_str(agent[ag].state)[0] == 'A') {
                agent[ag].state = ARREST;
            }
        }
    }
}

const char* enum_to_str(AgentState s) {
    switch(s){
        case ACTIVE: return "A";
        case INACTIVE: return "I";
        case POLICE: return "P";
	case ARREST: return "Arrest";
        default: return "UNKNOWN";
    }
}

void print_agent(Agent *agent, int agent_id, int num_agent, int num_police){
    //if ((char) enum_to_str(agent->state) == "A" || (char) enum_to_str(agent->state) == "I" )
        for (int i = 0; i < num_agent; i++) {
            if (agent_id >= 0 && i != agent_id) continue;
            printf("Grievance: %.2f\n", agent[i].grievance);
            printf("Legitimacy: %.2f\n", agent[i].legitimacy);
            printf("Hardship: %.2f\n", agent[i].hardship);
            printf("Likelihood: %.2f\n", agent[i].likelihood);
            printf("State: %s\n", enum_to_str(agent[i].state));
            printf("Position: (%.2f, %.2f)\n\n", agent[i].x, agent[i].y);
        } 
    num_police++;
    num_police--;
}

void move(Agent *agent, int num_agent, float move_dist){
	for (int i = 0; i < num_agent; i++){
		float angle =  rand_float(0.0f , 360.0f); 
		float rad = angle * (M_PI/180.0f);	
		agent[i].x += move_dist*cos(rad);
		agent[i].y += move_dist*sin(rad);
	}	
}














