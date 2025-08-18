#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "agent.h"

int main() {
    srand(time(0));
    int num_agents = 5;
    int agent_id = -1;
    float LengthBoard = 10.0f;
    Agent agents[num_agents];

    create_agents(agents, num_agents, LengthBoard);
    print_agent(agents, agent_id, num_agents);

    return 0;
}
