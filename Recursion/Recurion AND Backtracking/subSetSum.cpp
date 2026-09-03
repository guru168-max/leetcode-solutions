#include<bits/stdc++.h>
using namespace std;
bool subSetSum(vector<int>& arr, int index, int sum, int n, int target)
{
    // If the current sum becomes equal to the target,
    // we have found a valid subset.
    if(sum == target)
        return true;

    // If we have reached the end of the array,
    // there are no more elements to process.
    if(index == n)
        return false;

    // PICK
    // Add the current element to the current sum.
    sum += arr[index];

    // Recursively explore the PICK branch.
    bool pick = subSetSum(arr, index + 1, sum, n, target);

    // UNDO
    // Remove the current element before exploring
    // the NOT-PICK branch.
    sum -= arr[index];

    // NOT PICK
    // Recursively explore the branch where
    // the current element is not selected.
    bool not_pick = subSetSum(arr, index + 1, sum, n, target);

    // If either the PICK branch or the NOT-PICK branch
    // finds a valid subset, return true to the parent.
    return pick || not_pick;
}

int main()
{
    vector<int> arr = {2, 3, 7, 8, 10};
    int n = arr.size();
    int target = 22;
    int sum = 0;
    bool ans = subSetSum(arr, 0, sum, n, target);
    cout << "Answer = " << ans << endl;
}
