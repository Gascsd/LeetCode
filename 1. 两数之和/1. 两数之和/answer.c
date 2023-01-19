#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/two-sum/description/

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* tmp = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    assert(tmp);
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (target == nums[i] + nums[j]) {
                tmp[0] = i;
                tmp[1] = j;
                //printf("%d %d",tmp[0], tmp[1]);
                return tmp;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}