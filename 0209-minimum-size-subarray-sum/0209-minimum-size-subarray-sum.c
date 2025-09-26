int minSubArrayLen(int target, int* nums, int numsSize) {
    int prefix[numsSize + 1];
    prefix[0] = 0;

    // Build prefix sum array
    for (int i = 1; i <= numsSize; i++) {
        prefix[i] = prefix[i - 1] + nums[i - 1];
    }

    int minLength = numsSize + 1;

    for (int i = 0; i < numsSize; i++) {
        int required = target + prefix[i];

        // Binary search for the smallest j where prefix[j] >= required
        int low = i + 1, high = numsSize, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (prefix[mid] >= required)
                high = mid - 1;
            else
                low = mid + 1;
        }

        if (low <= numsSize)
            minLength = (low - i < minLength) ? (low - i) : minLength;
    }

    return (minLength == numsSize + 1) ? 0 : minLength;
}
