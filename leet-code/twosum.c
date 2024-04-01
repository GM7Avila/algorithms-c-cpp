int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    
    *returnSize = 0;
    return result;
}

int main() {
    int nums[7] = {0, 2, 7, 11, 15, 13, 1};
    int target = 16;
    int returnSize;

    int* result = twoSum(nums, 7, target, &returnSize);

    if (returnSize == 2) {
        printf("Indices dos números que somam %d: %d e %d\n", target, result[0], result[1]);
    } else {
        printf("Nenhum par encontrado que some %d.\n", target);
    }

    free(result); 

    return 0;
}