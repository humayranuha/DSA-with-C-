#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string pattern, string text) {
    int m = pattern.length();
    int n = text.length();
    
    // Pattern hash
    int pHash = 0;
    for (int i = 0; i < m; i++)
        pHash = pHash * 10 + (pattern[i] - 'A');
    
    // Check each window
    for (int i = 0; i <= n - m; i++) {
        // Compute hash for this window
        int tHash = 0;
        for (int j = 0; j < m; j++)
            tHash = tHash * 10 + (text[i + j] - 'A');
        
        // Compare
        if (pHash == tHash)
            cout << "Found at index " << i << endl;
    }
}

int main() {
    rabinKarp("CDD", "ABCCDDAEFG");
    return 0;
}