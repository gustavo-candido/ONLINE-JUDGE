#include <bits/stdc++.h>
using namespace std;

int main()
{
    double y;
    string num, n;
    map<int, string> roman;
    roman[1] = "I";
    roman[2] = "II";
    roman[3] = "III";
    roman[4] = "IV";
    roman[5] = "V";
    roman[6] = "VI";
    roman[7] = "VII";
    roman[8] = "VIII";
    roman[9] = "IX";
    roman[10] = "X";
    roman[20] = "XX";
    roman[30] = "XXX";
    roman[40] = "XL";
    roman[50] = "L";
    roman[60] = "LX";
    roman[70] = "LXX";
    roman[80] = "LXXX";
    roman[90] = "XC";
    roman[100] = "C";
    roman[200] = "CC";
    roman[300] = "CCC";
    roman[400] = "CD";
    roman[500] = "D";
    roman[600] = "DC";
    roman[700] = "DCC";
    roman[800] = "DCCC";
    roman[900] = "CM";
    roman[1000] = "M";

    cin >> n;

    for(int i=0; i<(int)n.size(); i++) {
        y = (n[i]-'0')*pow(10, (n.size()-1)-i);
        num+=roman[y];
    }
    cout << num << endl;
}
