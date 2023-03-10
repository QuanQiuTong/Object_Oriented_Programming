#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::max;
using std::string;
using std::vector;
typedef string::size_type str_sz;

char lower(char ch)
{
    return 'A' <= ch && ch <= 'Z' ? ch - 'A' + 'a' : ch;
}
bool equal(const string &a, const string &b)
{
    if (a.length() != b.length())
        return false;
    for (str_sz i = 0; i < a.length(); ++i)
        if (lower(a[i]) != lower(b[i]))
            return false;
    return true;
}
struct Word
{
    string word;
    size_t cnt = 0;
};
vector<Word> count(const vector<string> &wd)
{
    if (wd.empty())
        throw domain_error("No words entered. Please try again!");
    vector<Word> result;
    for (auto &&i : wd)
    {
        Word cur;
        for (auto &&j : result)
            if (equal(i, j.word))
            {
                j.cnt++;
                goto loop;
            }
        cur.word = i;
        cur.cnt = 1;
        result.push_back(cur);
    loop:;
    }
    return result;
}

int main()
{
    cout << "Enter some English words:" << endl;
    vector<string> words;
    str_sz maxlen = 0;
    for (string word; cin >> word;) // Unnecessary to be a function I guess...
    {
        words.push_back(word);
        maxlen = max(maxlen, word.length());
    }

    vector<Word> answer;
    try
    {
        answer = count(words);
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
        return 1;
    }
    cout << "number of the words: " << words.size() << endl;

    // Print the word in the form of the first encountered.
    for (auto &&i : answer)
    {
        cout << i.word;
        for (str_sz j = maxlen - i.word.size() + 1; j--;)
            cout << ' ';
        cout << i.cnt << endl;
    }

    return 0;
}

// C++ is a General Purpose Programming Language created by Bjarne Stroustrup as an extension of the C programming language
