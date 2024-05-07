#include "TextQuery.h"


int main()
{
    TextQuery tq;
    tq.readFile("china_daily.txt");
    cout << "please input a query word:" << endl;

    string word;
    while(cin >> word)
    {
        tq.query(word);
    }

    return 0;
}

