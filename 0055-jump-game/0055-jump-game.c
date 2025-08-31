#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int farthest = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > farthest) {
            return false;  // can't even reach this index
        }
        // update farthest reachable index
        if (i + nums[i] > farthest) {
            farthest = i + nums[i];
        }
        if (farthest >= numsSize - 1) {
            return true;   // can reach the last index
        }
    }

    return true;
}
