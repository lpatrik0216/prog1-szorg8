#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Dog {
    string type, name, color;
    int age;
};

class DogDatabase {
private:
    vector<Dog> dogs;

public:
    bool load(string fileName) {
        ifstream file(fileName);
        if (!file) {
            cerr << "Nem sikerult megnyitni a fajlt!\n";
            return false;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Dog d;
            string ageStr;
            getline(ss, d.type, ',');
            getline(ss, d.name, ',');
            getline(ss, ageStr, ',');
            getline(ss, d.color, ',');
            d.age = stoi(ageStr);
            dogs.push_back(d);
        }
        return true;
    }

    vector<Dog> search(string name) {
        vector<Dog> matches;
        for (Dog& d : dogs)
            if (d.name == name) matches.push_back(d);
        return matches;
    }

    void startSearch() {
        while (true) {
            cout << "Add meg a kutya nevet (kilepeshez 'exit'): ";
            string name;
            cin >> name;
            if (name == "exit") break;

            vector<Dog> found = search(name);
            cout << "\n";
            if (found.empty()) {
                cout << "Nem talaltam ilyen nevu kutyat!\n";
            } else {
                for (Dog& d : found) {
                    cout << "Nev: " << d.name << "\n"
                         << "Fajta: " << d.type << "\n"
                         << "Kor: " << d.age << "\n"
                         << "Szin: " << d.color << "\n\n";
                }
            }
        }
    }
};

int main() {
    DogDatabase db;
    if (!db.load("menhely.txt")) return 1;

    db.startSearch();
    return 0;
}