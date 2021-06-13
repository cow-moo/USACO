#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;
    string functioncalled;
    string X, Y, Z;
    string word;
    string output = "";
    string temp;

    for (int i = 0; i < num; i++) {
        cin >> functioncalled;
        output = "";
        if (functioncalled == "formatHeight") {
            cin >> X;
            cin >> Y;
            output = X + "\'" + Y + "\"";
        }
        else if (functioncalled == "formatDate") {
            cin >> X;
            cin >> Y;
            cin >> Z;
            if (Y.length() == 1) {
                Y = '0' + Y;
            }
            if (Z.length() == 1) {
                Z = '0' + Z;
            }
            output = X + Y + Z;
        }
        else if (functioncalled == "concatenate") {
            cin.get();
            getline(cin, word);
            for (int i = 0; i < word.length(); i++) {
                if (word[i] == ' ') {
                    output += ',';
                }
                else {
                    output += word[i];
                }
            }
        }
        cout << output << endl;
    }
    return 0;
}
