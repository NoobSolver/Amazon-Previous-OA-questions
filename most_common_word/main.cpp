#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {

    unordered_map<string, int> numbers_of_words;
    auto paragraph_len = paragraph.size();

    // find all words in the input line, convert then to lower case and same in a map
    // complexity O(N + S) where N is a number of characters in the input line and S is complexity
    // of the string.push_back which is amortized constant.
    auto i = 0;
    string s;
    while(i < paragraph_len) {

        while(i < paragraph_len && isalpha(paragraph[i])) {
            s.push_back(tolower(paragraph[i++]));
        }

        while(i < paragraph_len && !isalpha(paragraph[i])) { i++; }

        // complexity of adding a value to the unordered_map is constant in average case and
        // linear in number of container elements in worst case because of rebuilding of the hashes
        // generally it is an amortized constant
        if( ! s.empty()) {
            numbers_of_words[s]++;
            s.clear();
        }
    }

    // mark all banned words by 0
    // complexity O(1)
    for(auto & word: banned) { numbers_of_words[word] = 0; }

    auto count = 0;

    // find max number of unbanned word
    // complexity O(N) where N is a number of allowed words
    // it may be improved but it doesn't make sense because of it is the
    // only pass and the number of words is not big
    for(auto & pair: numbers_of_words) {
        if (pair.second > count) { s = pair.first, count = pair.second; }
    }
    return s;

    // General complexity is about O(N) where N is a number of characters in the input line
}


int main() {

    string paragraph("Bob hit a ball, the hit BALL flew far after it was hit.");
    vector<string> banned({"hit"});
    std::cout << "Expected output is: ball" << endl << "Actual output is: ";

    std::cout << mostCommonWord(paragraph, banned) << std::endl;
    return 0;
}
