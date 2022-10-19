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
