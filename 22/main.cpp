/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
containing over five-thousand first names, begin by sorting it into alphabetical
order. Then working out the alphabetical value for each name, multiply this
value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is
worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would
obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

void split_ref(const string &s, vector<string> &tokens,
               const string &delims = " ") {
    string::size_type lastPos = s.find_first_not_of(delims, 0);
    string::size_type pos = s.find_first_of(delims, lastPos);
    while (string::npos != pos || string::npos != lastPos) {
        tokens.push_back(s.substr(lastPos, pos - lastPos));
        lastPos = s.find_first_not_of(delims, pos);
        pos = s.find_first_of(delims, lastPos);
    }
}

std::vector<std::string> split(const std::string &str,
                               const std::string &delims = " ") {
    std::vector<std::string> output;
    auto first = std::cbegin(str);

    while (first != std::cend(str)) {
        const auto second = std::find_first_of(
            first, std::cend(str), std::cbegin(delims), std::cend(delims));

        if (first != second)
            output.emplace_back(first, second);

        if (second == std::cend(str))
            break;

        first = std::next(second);
    }
    return output;
}

std::vector<std::string_view> splitSV(std::string_view strv,
                                      std::string_view delims = " ") {
    std::vector<std::string_view> output;
    size_t first = 0;

    while (first < strv.size()) {
        const auto second = strv.find_first_of(delims, first);

        if (first != second)
            output.emplace_back(strv.substr(first, second - first));

        if (second == std::string_view::npos)
            break;

        first = second + 1;
    }

    return output;
}

// 归并排序
void merge(vector<string> &tokens, int left, int mid, int right) {
    vector<string> help(right - left + 1);
    int p1 = left, p2 = mid + 1, i = 0;
    while (p1 <= mid && p2 <= right) {
        help[i++] = tokens[p1] > tokens[p2] ? tokens[p2++] : tokens[p1++];
    }
    while (p1 <= mid) {
        help[i++] = tokens[p1++];
    }
    while (p2 <= right) {
        help[i++] = tokens[p2++];
    }
    for (int i = 0; i < right - left + 1; i++) {
        tokens[left + i] = help[i];
    }
}

void sorting(vector<string> &tokens, int left, int right) {
    if (left < right) {
        int mid = left + ((right - left) >> 1); //(left+right)/2
        sorting(tokens, left, mid);
        sorting(tokens, mid + 1, right);
        merge(tokens, left, mid, right);
    }
}
void mergeSort(vector<string> &tokens) {
    if (tokens.size() < 2)
        return;
    int left = 0, right = tokens.size() - 1;
    sorting(tokens, left, right);
}

int sumOneString(const string &val) {
    int sum = 0;

    return sum;
}

int main() {
    ifstream in("F:/gitrepos/svenzhang2016/myeular/22/p022_names.txt");
    assert(in.is_open());
    // int length;
    // in.seekg(0, std::ios::end);
    // length = in.tellg();
    // in.seekg(0, std::ios::end);
    // char *buffer = new char[length];
    // in.read(buffer, length);
    // in.close();

    // stringstream buffer;
    // buffer << in.rdbuf();
    // string str(buffer.str());

    string str((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    vector<string> tokens;
    split_ref(str, tokens, ",");
    // mergeSort(tokens);
    sort(tokens.begin(), tokens.end());
    long long int sum = 0;
    for (size_t i = 0; i < tokens.size(); ++i) {
        sum += (i + 1) * sumOneString(tokens[i]);
    }
    std::cout << "sum: " << sum;
}