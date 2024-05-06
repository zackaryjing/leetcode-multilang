/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* ans = malloc(sizeof(int) * 2);
    for (int i=0;i<numsSize;i++){
        int t = target - nums[i];
        for (int j = 0;j < numsSize;j++){
            if (j != i && nums[j] == t){
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                return ans;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main(){
    int nums[4] = {2,7,11,15};
    int target = 9 ,a = 2;
    int *returnSize; 
    returnSize = &a;
    int *t = twoSum(nums,4,target,returnSize);
    printf("%d %d\n",t[0],t[1]);
    printf("%d",a);
    free(t);
    return 0;
}