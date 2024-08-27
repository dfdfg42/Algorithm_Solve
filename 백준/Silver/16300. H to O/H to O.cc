#include <iostream>
#include <map>
#include <climits>
#include <string>
using namespace std;

map<char, int> parseMolecule(string molecule) {
    map<char, int> elementCount;
    int len = molecule.length();
    for (int i = 0; i < len; ++i) {
        char element = molecule[i];
        int count = 0;

        // Check if the next characters are digits
        while (i + 1 < len && isdigit(molecule[i + 1])) {
            count = count * 10 + (molecule[++i] - '0');
        }

        if (count == 0) count = 1;  // No number means 1 atom

        elementCount[element] += count;
    }
    return elementCount;
}

int main() {
    string inputMolecule;
    int k;
    string outputMolecule;

    cin >> inputMolecule >> k;
    cin >> outputMolecule;

    map<char, int> inputCounts = parseMolecule(inputMolecule);
    map<char, int> outputCounts = parseMolecule(outputMolecule);

    for (auto& pair : inputCounts) {
        pair.second *= k;
    }

    int maxOutputMolecules = INT_MAX;

    for (auto& pair : outputCounts) {
        char element = pair.first;
        int requiredCount = pair.second;

        if (inputCounts[element] == 0) {
            maxOutputMolecules = 0;
            break;
        }
        else {
            maxOutputMolecules = min(maxOutputMolecules, inputCounts[element] / requiredCount);
        }
    }

    cout << maxOutputMolecules << endl;

    return 0;
}
