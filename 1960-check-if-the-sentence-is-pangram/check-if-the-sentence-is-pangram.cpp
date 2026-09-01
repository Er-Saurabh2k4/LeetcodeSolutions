class Solution {
public:
    bool checkIfPangram(string sentence) {
        //set stores unique element
        set<char>s(sentence.begin(),sentence.end());
        return s.size()==26;
    }
};