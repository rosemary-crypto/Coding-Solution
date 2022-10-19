/*You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.*/

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        std::vector<std::pair<int,std::string>> mapping;
        for(int i=0; i<names.size(); i++){
            mapping.push_back(std::make_pair(heights.at(i), names.at(i)));
        }
        std::sort(mapping.begin(),mapping.end(), [](const auto& x, const auto& y){return x.first > y.first;});
        std::vector<string> sorted;
        for(auto i:mapping){
            sorted.push_back(i.second);            
        }
        return sorted;

    }
};
