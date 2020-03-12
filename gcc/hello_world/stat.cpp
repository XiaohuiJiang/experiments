#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a, n, m;
    int count = 0;

    ofstream fout("data.tmp");

    cin >> n;
    while (n--) {cin >> a; fout << a << endl;}

    ifstream fin("data.tmp");
    cin >> m;
    while (fin >> a) {
        if (a < m) count++;
    }
    cout << count << endl;
    return 0;
}
