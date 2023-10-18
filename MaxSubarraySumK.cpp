#include <iostream>
#include <vector>

int maxSubarraySum(const std::vector<int>& arr, int k) {
    if (arr.size() < k) {
        std::cerr << "Invalid input: Array size is smaller than k." << std::endl;
        return -1; // Error code
    }

    int maxSum = 0;
    int currentSum = 0;

    // Calculate the sum of the first 'k' elements
    for (int i = 0; i < k; i++) {
        currentSum += arr[i];
    }

    maxSum = currentSum;

    // Slide the window and update the sum
    for (int i = k; i < arr.size(); i++) {
        currentSum = currentSum - arr[i - k] + arr[i]; // Remove the first element of the window and add the next element

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    std::vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int result = maxSubarraySum(arr, k);
    if (result != -1) {
        std::cout << "Maximum sum of a subarray of size " << k << " is: " << result << std::endl;
    }
    return 0;
}
