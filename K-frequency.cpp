/*Given an array of strings words and an integer k, return the k most frequent strings.

Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

 

Example 1:

Input: words = ["i","love","leetcode","i","love","coding"], k = 2
Output: ["i","love"]
Explanation: "i" and "love" are the two most frequent words.
Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:

Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
Output: ["the","is","sunny","day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 

Constraints:

1 <= words.length <= 500
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
k is in the range [1, The number of unique words[i]]
 

Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        std::map<std::string, int> frequency;
        std::vector<std::string> most;
        for(auto i:words){
            if (frequency.find(i) == frequency.end()) {
                frequency[i] = 1;
            }
            else{
                frequency[i] += 1;
            }
        }
        std::vector<std::pair<std::string, int>> frequencyV(frequency.begin(), frequency.end());
        std::sort(frequencyV.begin(), frequencyV.end(), [](const auto& x, const auto& y){return (x.second!=y.second) ? x.second>y.second : x.first<y.first; });
        int count = 0;
        for(auto i:frequencyV){
            most.push_back(i.first);
            count++;
            if(count>=k){
                break;
            }
        }
        return most;
    }
};
