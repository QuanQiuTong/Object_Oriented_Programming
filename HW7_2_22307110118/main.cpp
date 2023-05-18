#include <iostream>
#include <algorithm>

#include "Str.h"

using std::cin;
using std::cout;
using std::endl;

Str words[100000];
int main()
{
    cout << "Enter some text: ";
    size_t count = 1, maxlen = 0;
    for (; cin >> words[count]; ++count)
        maxlen = std::max(maxlen, words[count].size());
    std::sort(words, words + count);
    size_t i = 1, rep = 1;
    for (; i < count; ++i)
    {
        if (words[i] == words[i - 1])
            rep++;
        else if (i > 1)
            cout << words[i - 1] << Str(maxlen + 1 - words[i - 1].size(), ' ') << rep << endl, rep = 1;
    }
    cout << words[i - 1] << Str(maxlen + 1 - words[i - 1].size(), ' ') << rep << endl;
    return 0;
}