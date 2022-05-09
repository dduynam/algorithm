#include <bits/stdc++.h>

std::vector<int> in{3, 5, 2, 4, 2, 1, 1, 2, 1};

int bruteforce(std::vector<int> &in, int index, int count)
{
    static int ret = INT_MAX;

    for (int i = 1; i <= in[index]; i++)
    {
        if (index + i < in.size()-1){
            bruteforce(in, index+i, count+1);
        }
        else
        {
            ret = std::min(count+1, ret);
            break;
        }
    }
    return ret;
}

// bruteforceII
int minJump(std::vector<int>&, int);

int bruteforceII(std::vector<int> &nums)
{
    return minJump(nums,0);
}

/*highlight note*/
int minJump(std::vector<int> &nums, int start)
{
    if (start == nums.size()-1)
        return 0;
    if(nums[start] == 0)
        return -1;
    int minStep = 1500;
    int farthestJump = std::min((int)nums.size()-1, start+nums[start]);
    for (int i = start+1; i <= farthestJump; i++)
    {
        int tmp = minJump(nums,i);
        if (tmp != -1 && tmp + 1 < minStep)
            minStep = tmp +1;
    }
    
    return minStep;
}

// greedy
int greedy(std::vector<int> &in)
{
    int step = 0;

    // bien l va r dung de luu khoang vi tri cua moi lan nhay
    // sau moi lan duyet khoang vi tri tu l den r, tang bien step them 1

    for (int l = 0, r = 0; r < in.size()-1; step++)
    {
        int farthestJump = 0;
        for (int i = l; i <= r; i++)
        {
            farthestJump = std::max(farthestJump, i+in[i]);
        }
        
        // Sau khi xac dinh duoc farthestJump, update lai tap vi tri cho lan nhay ke tiep
        // Gan vi tri toi thieu l=r+1 de chac chan vi tri cho la nhay ke tiep la chua duoc duyet
        // update vi tri toi da r = farthestJump
        l = r + 1;
        r = farthestJump;
    }

    return step;
}

int main()
{
    std::cout << bruteforce(in, 0, 0) << std::endl;
    std::cout << greedy(in) << std::endl;
    return 0;
}