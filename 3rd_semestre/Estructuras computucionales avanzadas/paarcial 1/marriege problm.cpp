#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

// Function to perform the Stable Marriage algorithm
void stableMarriage(const vector<vector<string>>& menPrefs, const vector<vector<string>>& womenPrefs,
                    const vector<string>& men, const vector<string>& women) {
    int n = menPrefs.size();  // Number of men and women

    // Initialize maps to store current matches
    map<string, string> menMatches;  // man -> woman
    map<string, string> womenMatches;  // woman -> man

    // Initialize maps to keep track of proposals
    map<string, int> menProposals;
    map<string, map<string, int>> womenProposals;

    // Create maps to store rankings for faster access
    map<string, map<string, int>> womenRankings;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            womenRankings[women[i]][womenPrefs[i][j]] = j;
        }
    }

    // Initialize men as unmatched
    for (const auto& man : men) {
        menMatches[man] = "";
        menProposals[man] = 0;
    }

    // While there are unmarried men
    int unmarriedCount = n;
    while (unmarriedCount > 0) {
        string man;
        for (const auto& m : men) {
            if (menMatches[m] == "") {
                man = m;
                break;
            }
        }

        // Find the first woman on the man's list that he has not proposed to
        string woman;
        for (int i = 0; i < n && menMatches[man] == ""; ++i) {
            woman = menPrefs[distance(men.begin(), find(men.begin(), men.end(), man))][i];
            if (womenProposals[woman][man] == 0) {
                womenProposals[woman][man] = 1;
                menProposals[man]++;
                if (womenMatches[woman] == "") {
                    menMatches[man] = woman;
                    womenMatches[woman] = man;
                    unmarriedCount--;
                } else {
                    if (womenRankings[woman][man] < womenRankings[woman][womenMatches[woman]]) {
                        string prevMan = womenMatches[woman];
                        menMatches[prevMan] = "";
                        menMatches[man] = woman;
                        womenMatches[woman] = man;
                    }
                }
            }
        }
    }

    // Print the stable matches
    cout << "Stable Matches:" << endl;
    for (const auto& man : men) {
        cout << "Man " << man << " matches with Woman " << menMatches[man] << endl;
    }
}

int main() {
    int n;  // Number of men and women
    cout << "Enter the number of men and women: ";
    cin >> n;

    vector<string> men(n);
    vector<string> women(n);

    cout << "Enter the names of the men:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> men[i];
    }

    cout << "Enter the names of the women:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> women[i];
    }

    vector<vector<string>> menPrefs(n, vector<string>(n));
    vector<vector<string>> womenPrefs(n, vector<string>(n));

    cout << "Enter men's preferences (names):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Preferences for " << men[i] << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> menPrefs[i][j];
        }
    }

    cout << "Enter women's preferences (names):" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Preferences for " << women[i] << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> womenPrefs[i][j];
        }
    }

    stableMarriage(menPrefs, womenPrefs, men, women);
    return 0;
}
