#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> getIntersection(const vector<string>& set1, const vector<string>& set2) {
    unordered_set<string> intersection(set1.begin(), set1.end());
    vector<string> result;

    for (const auto& language : set2) {
        if (intersection.find(language) != intersection.end()) {
            result.push_back(language);
        }
    }

    return result;
}

int minTranslators(const vector<vector<string>>& languages, int person1, int person2) {
    vector<string> commonLanguages = getIntersection(languages[person1], languages[person2]);

    if (commonLanguages.empty()) {
        return -1;  
    }

    unordered_set<int> translatorSet;
    for (int i = 0; i < languages.size(); ++i) {
        if (i != person1 && i != person2) {
            vector<string> personLanguages = languages[i];
            vector<string> commonWithPerson1 = getIntersection(personLanguages, languages[person1]);
            vector<string> commonWithPerson2 = getIntersection(personLanguages, languages[person2]);

            if (!commonWithPerson1.empty() && !commonWithPerson2.empty()) {
                translatorSet.insert(i);
            }
        }
    }

    cout << "Common languages between Person " << person1 + 1 << " and Person " << person2 + 1 << ": ";
    for (const auto& language : commonLanguages) {
        cout << language << " ";
    }
    cout << endl;

    cout << "Translators needed: ";
    for (const auto& translator : translatorSet) {
        cout << "Person " << translator + 1 << " ";
    }
    cout << endl;

    return translatorSet.size();
}

int main() {
  
    vector<vector<string>> languages = {
        {"Hindi", "English", "Gujarati"},
        {"Hindi", "Odia"},
        {"Tamil", "English"},
        {"Odia", "Spanish"},
        {"Gujarati", "Tamil"},
        {"Tamil", "Odia"},
        {"Telugu", "English"},
        {"Telugu", "Hindi"},
        {"Marathi", "Hindi"},
        {"English", "Spanish"}
    };

    int person1, person2;
    cout << "Enter the index of Person 1 (1-10): ";
    cin >> person1;

    cout << "Enter the index of Person 4 (1-10): ";
    cin >> person2;

    person1 -= 1;
    person2 -= 1;

    int numTranslators = minTranslators(languages, person1, person2);

    if (numTranslators == -1) {
        cout << "No common languages. Communication not possible." << endl;
    } else {
        cout << "Total translators needed: " << numTranslators << endl;
    }

    return 0;
}
