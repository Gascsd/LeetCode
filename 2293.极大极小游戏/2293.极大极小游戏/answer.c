#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/min-max-game/
int Max(int a, int b)
{
    return a > b ? a : b;
}
int Min(int a, int b)
{
    return a < b ? a : b;
}

int minMaxGame(int* nums, int numsSize)
{
    if (numsSize == 1)
        return nums[0];
    else
    {
        numsSize /= 2;
        int* newNums = (int*)malloc(sizeof(int) * numsSize);
        assert(newNums);
        for (int i = 0; i < numsSize; i += 2)
        {
            newNums[i] = Min(nums[2 * i], nums[2 * i + 1]);
        }
        for (int i = 1; i < numsSize; i += 2)
        {
            newNums[i] = Max(nums[2 * i], nums[2 * i + 1]);
        }
        return minMaxGame(newNums, numsSize);
    }
}