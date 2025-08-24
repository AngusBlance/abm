#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "agent.h"

int main() {
    srand(time(0));
    int num_agents = 1;
    int num_police = 1;
    int agent_id = -1;
    float LengthBoard = 10.0f;
    float vision = 5;
    Agent *agents = malloc(num_agents * sizeof(Agent));
    Agent *police = malloc(num_police * sizeof(Agent));

    police[0].state = POLICE;
    police[0].x = rand_float(0.0f, LengthBoard);
    police[0].y = rand_float(0.0f, LengthBoard);

    agents[0].state = ACTIVE;
    agents[0].likelihood = rand_float(0.0f, 1.0f);
    agents[0].legitimacy = rand_float(0.0f, 1.0f);
    agents[0].hardship = rand_float(0.0f, 1.0f);
    agents[0].grievance = agents[0].hardship * (1 - agents[0].legitimacy);
    agents[0].x = rand_float(0.0f, LengthBoard);
    agents[0].y = rand_float(0.0f, LengthBoard);

    print_agent(agents, agent_id, num_agents, num_police);
    print_agent(police, agent_id, num_agents, num_police);
    arrest(agents, police, num_police, num_agents, vision);
    print_agent(agents, agent_id, num_agents, num_police);
    print_agent(police, agent_id, num_agents, num_police);
    free(agents);
    free(police);
    return 0;
}

