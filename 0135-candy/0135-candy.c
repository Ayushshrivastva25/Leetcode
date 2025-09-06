int candy(int* ratings, int ratingsSize) {
    if (ratingsSize == 0) return 0;

    // Step 1: Allocate candies array and give each child 1 candy
    int* candies = (int*)malloc(sizeof(int) * ratingsSize);
    for (int i = 0; i < ratingsSize; i++) {
        candies[i] = 1;
    }

    // Step 2: Left to Right Pass
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 3: Right to Left Pass
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
            candies[i] = candies[i + 1] + 1;
        }
    }

    // Step 4: Sum up total candies
    int total = 0;
    for (int i = 0; i < ratingsSize; i++) {
        total += candies[i];
    }

    // Free the dynamically allocated memory
    free(candies);

    return total;
}
