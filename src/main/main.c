#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "agent.h"

int main() {
    srand(time(0));
    int num_agents = 5;
    int num_police = 5;
    int agent_id = -1;
    float LengthBoard = 10.0f;
    Agent *agents = malloc(num_agents * sizeof(Agent));
    Agent *police = malloc(num_police * sizeof(Agent));

    create_police(police, num_police, LengthBoard);
    create_agents(agents, num_agents, LengthBoard);
    print_agent(agents, agent_id, num_agents, num_police);
    print_agent(police, agent_id, num_agents, num_police);

    free(agents);
    free(police);
    return 0;
}
