#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#define MAX_LENGTH 1000

using namespace std;

void getZarr(const string &str, int *z) {
    int n = str.length();
    int l = 0, r = 0, k = 0;
    for (int i = 1; i < n; ++i) {
        if (i > r) {
            l = r = i;
            while (r < n && str[r - l] == str[r])
                r++;
            z[i] = r - l;
            r--;
        } else {
            k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else {
                l = i;
                while (r < n && str[r - l] == str[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }
}

void search(const string &text, const string &pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();
    string concat = pattern + "$" + text;
    int l = concat.length();
    int z[l];
    getZarr(concat, z);
    int patternFound = 0;
    for (int i = 0; i < l; ++i) {
        if (z[i] == patternLength) {
            cout << "Pattern found at index: " << i - patternLength - 1 << endl;
            patternFound = 1;
        }
    }
    if (!patternFound) {
        cout << "Pattern Not Found" << endl;
    }
}

int main() {
    char filename[MAX_LENGTH], pattern[MAX_LENGTH];
    string text;

    cout << "Enter the filename: ";
    cin.getline(filename, MAX_LENGTH); // Use cin.getline for C++ string input

    ifstream file(filename); // Open the file
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    cout << "Enter the pattern: ";
    cin.getline(pattern, MAX_LENGTH);

    // Read the text from the file
    getline(file, text);
    file.close();

    search(text, pattern);
    return 0;
}

