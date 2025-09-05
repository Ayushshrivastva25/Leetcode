int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0, totalCost = 0;
    int start = 0;      
    int tank = 0;       

    for (int i = 0; i < gasSize; i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    
    if (totalGas < totalCost) {
        return -1;
    }

    return start;
}
