#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;

    ofstream fout("data.tmp");

    cin >> n;
    while (n--) {cin >> s; fout << s << endl;}

    return 0;
}
