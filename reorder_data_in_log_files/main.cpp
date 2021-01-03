#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
Position of this solution on leetcode.com
Runtime: 8 ms, faster than 98.31% of C++ online submissions for Reorder Data in Log Files.
Memory Usage: 11.7 MB, less than 100.00% of C++ online submissions for Reorder Data in Log Files.
*/

using namespace std;

    static bool compare(const string & a, const string & b) {
        auto second_word1 = a.find(' ');
        auto second_word2 = b.find(' ');
        bool is_digit_log1 = isdigit(a[second_word1 + 1]);
        bool is_digit_log2 = isdigit(b[second_word2 + 1]);
        if(is_digit_log1) {
            // a is a digit log, b is a letter log, a > b
            // or a and b are both digit logs so keep their original order
            // in both cases return false is correct.
/*
    From stl_algo.h:
    The relative ordering of equivalent elements is preserved, so any two
    elements @p x and @p y in the range @p [__first,__last) such that
    @p __comp(x,y) is false and @p __comp(y,x) is false will have the same
    relative ordering after calling @p stable_sort().
    So it doesn't matter what kind of the second argument.
    To preserve relative ordering of equivalent elements it is enough to return false if the first argument is a digit log.
*/
            return false;
        }
        else {
            if (is_digit_log2) {
                return true;        // a is a letter log, b is a digit log, a < b
            }
            else {
                auto res = a.compare(second_word1, a.size(), b, second_word2, b.size());

                if (0 > res) {
                    // a and b are both letter logs and a > b
                    return true;
                }
                else {
                    if (0 == res) {
                        //If string parts are the same then compare key
                        auto key_res = a.compare(0, second_word1, b, 0, second_word2);
                        return 0 > key_res;
                    }
                    // a and b are both letter logs and a < b
                    return false;
                }
            }
        }
    }


    vector<string> reorderLogFiles(vector<string>& logs) {
        //The order of equal elements is guaranteed to be preserved in stable_sort.
        stable_sort(logs.begin(), logs.end(), compare);
        return logs;
    }


int main() {

    // Input:
    vector<string> logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};

    // Output:
    vector<string> output = {"let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"};

    std::cout << "Input: " << std::endl;
    for (auto s: logs) {
        std::cout << '"' << s << "\" ";
    }

    std::cout << std::endl;

    std::cout << "Expected output: " << std::endl;
    for (auto s: output) {
        std::cout << '"' << s << "\" ";
    }

    std::cout << std::endl;

    vector<string> res = reorderLogFiles(logs);

    std::cout << "Actual output: " << std::endl;
    for (auto s: res) {
        std::cout << '"' << s << "\" ";
    }

    std::cout << std::endl;


    return 0;
}
