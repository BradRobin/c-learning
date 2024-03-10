#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::unordered_map<int, int> freqCounter;
        for (int num : nums) {
            freqCounter[num]++;
        }
        int maxFrequency = 0;
        for (const auto& entry : freqCounter) {
            maxFrequency = std::max(maxFrequency, entry.second);
        }
        int maxFreqElements = 0;
        for (const auto& entry : freqCounter) {
            if (entry.second == maxFrequency) {
                maxFreqElements++;
            }
        }
        int totalFrequency = maxFrequency * maxFreqElements;

        return totalFrequency;
    }
};

int main (){
    vector<int> nums;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter numbers in the array: ";
    for (int i = 0; i < n; i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution x;
    int totalFrequency = x.maxFrequencyElements(nums);
    cout << "Total frequency of maximum frequency elements: " << totalFrequency <<endl;
    return 0;
}
