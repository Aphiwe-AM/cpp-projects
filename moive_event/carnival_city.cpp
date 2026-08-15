#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cassert>

using namespace std;

// Class to hold individual client details
class Client {
private:
    string surname;
    string name;
    string movieTitle;
    string movieType;
    string seatNumber;
    double moviePrice;
    string refNumber;

public:
    // Constructors
    Client() : moviePrice(0.0) {}

    Client(string sName, string fName, string mTitle, string mType, 
           string seat, double price, string ref)
        : surname(sName), name(fName), movieTitle(mTitle), movieType(mType),
          seatNumber(seat), moviePrice(price), refNumber(ref) {}

    // Getters
    string getSurname() const { return surname; }
    string getName() const { return name; }
    string getMovieTitle() const { return movieTitle; }
    string getMovieType() const { return movieType; }
    string getSeatNumber() const { return seatNumber; }
    double getMoviePrice() const { return moviePrice; }
    string getRefNumber() const { return refNumber; }

    // Mutator to replace the first two digits of reference number
    void replaceFirstTwoDigitsRef(const string& newPrefix) {
        if (refNumber.length() >= 2) {
            refNumber = newPrefix + refNumber.substr(2);
        }
    }
};

// Class to manage movie reservation operations and file handling
class MovieReservationSystem {
private:
    vector<Client> clients;
    string inputFileName;
    string outputFileName;

    // Helper method to strip whitespace surrounding fields
    string trim(const string& str) const {
        size_t first = str.find_first_not_of(" \t\r\n");
        if (string::npos == first) return "";
        size_t last = str.find_last_not_of(" \t\r\n");
        return str.substr(first, (last - first + 1));
    }

public:
    void setFileName(const string& inFile, const string& outFile) {
        inputFileName = inFile;
        outputFileName = outFile;
    }

    // Read client data line-by-line / character-by-character validation
    bool loadClientsFromFile() {
        ifstream file(inputFileName);
        if (!file.is_open()) {
            cout << "Error: Could not open file " << inputFileName << endl;
            return false;
        }

        clients.clear();
        string line;

        // Reading client data line-by-line
        while (getline(file, line)) {
            if (trim(line).empty()) continue; // Skip empty lines

            // Reading character-by-character to parse fields separated by commas
            stringstream ss(line);
            string token;
            vector<string> fields;

            while (getline(ss, token, ',')) {
                fields.push_back(trim(token));
            }

            // Validating that the record contains all 7 expected fields
            if (fields.size() == 7) {
                try {
                    string surname = fields[0];
                    string name = fields[1];
                    string title = fields[2];
                    string type = fields[3];
                    string seat = fields[4];
                    double price = stod(fields[5]);
                    string ref = fields[6];

                    clients.push_back(Client(surname, name, title, type, seat, price, ref));
                } catch (...) {
                    // Skip invalid numeric conversion lines
                    continue;
                }
            }
        }

        file.close();
        return true;
    }

    // Function to count the number of lines in an input file
    int countLines() {
        ifstream file(inputFileName);
        if (!file.is_open()) return 0;

        int lineCount = 0;
        string line;
        while (getline(file, line)) {
            lineCount++;
        }
        file.close();
        return lineCount;
    }

    // Function to count the number of words in the file
    int countWords() {
        ifstream file(inputFileName);
        if (!file.is_open()) return 0;

        int wordCount = 0;
        char ch;
        bool inWord = false;

        // Reading character-by-character
        while (file.get(ch)) {
            if (isspace(ch) || ch == ',') {
                if (inWord) {
                    inWord = false;
                }
            } else {
                if (!inWord) {
                    inWord = true;
                    wordCount++;
                }
            }
        }
        file.close();
        return wordCount;
    }

    // Function that opens file, counts char occurrences (case-insensitive), and closes file
    int countCharOccurrences(char targetChar) {
        ifstream file(inputFileName);
        if (!file.is_open()) return 0;

        int count = 0;
        char ch;
        char lowerTarget = tolower(targetChar);

        while (file.get(ch)) {
            if (tolower(ch) == lowerTarget) {
                count++;
            }
        }
        file.close();
        return count;
    }

    // Function to prompt user for a character search
    void promptAndSearchCharacter() {
        char answer;
        do {
            cout << "Enter a character to search for: ";
            char targetChar;
            cin >> targetChar;

            int count = countCharOccurrences(targetChar);
            cout << "Character '" << targetChar << "' appeared " << count << " times in the file.\n";

            cout << "Do you wish to search for another character? (y/n): ";
            cin >> answer;
            answer = tolower(answer);

            // Assert check ensuring user entered 'y' or 'n'
            assert(answer == 'y' || answer == 'n');

        } while (answer == 'y');
    }

    // Function to replace the first two digits of reference numbers
    void replaceReferencePrefix(const string& newPrefix) {
        for (auto& client : clients) {
            client.replaceFirstTwoDigitsRef(newPrefix);
        }
        cout << "First two characters of all reference numbers successfully replaced with '" 
             << newPrefix << "'.\n";
    }

    // Function to count the number of a specific movie type
    int countMovieType(const string& type) const {
        int count = 0;
        for (const auto& client : clients) {
            if (client.getMovieType() == type) {
                count++;
            }
        }
        return count;
    }

    // Function to calculate the total amount of a specific movie type
    double calculateTotalForMovieType(const string& type) const {
        double total = 0.0;
        for (const auto& client : clients) {
            if (client.getMovieType() == type) {
                total += client.getMoviePrice();
            }
        }
        return total;
    }

    // Function to calculate total amount of all movie reservations
    double calculateTotalAllReservations() const {
        double total = 0.0;
        for (const auto& client : clients) {
            total += client.getMoviePrice();
        }
        return total;
    }

    // Write to report output file sorted by Surname in descending order
    bool generateReport() {
        ofstream outFile(outputFileName);
        if (!outFile.is_open()) {
            cout << "Error opening output file " << outputFileName << endl;
            return false;
        }

        // Make a copy of clients vector to sort
        vector<Client> sortedClients = clients;

        // Sort descending by Surname
        sort(sortedClients.begin(), sortedClients.end(), [](const Client& a, const Client& b) {
            return a.getSurname() > b.getSurname();
        });

        // Totals per movie type
        double actionTotal = calculateTotalForMovieType("Action");
        double horrorTotal = calculateTotalForMovieType("Horror");
        double animTotal = calculateTotalForMovieType("Animation");
        double grandTotal = calculateTotalAllReservations();

        outFile << "==============================================================\n";
        outFile << "                 CARNIVAL CITY MOVIE REPORT                  \n";
        outFile << "==============================================================\n";
        outFile << "SURNAME\t\tNAME\t\tMOVIE TYPE\tREF NUMBER\n";
        outFile << "--------------------------------------------------------------\n";

        for (const auto& client : sortedClients) {
            outFile << client.getSurname() << "\t\t"
                    << client.getName() << "\t\t"
                    << client.getMovieType() << "\t\t"
                    << client.getRefNumber() << "\n";
        }

        outFile << "\n==============================================================\n";
        outFile << "                   SUMMARY & TOTAL AMOUNTS                    \n";
        outFile << "==============================================================\n";
        outFile << "Total Amount for Action Movies:    R " << actionTotal << "\n";
        outFile << "Total Amount for Horror Movies:    R " << horrorTotal << "\n";
        outFile << "Total Amount for Animation Movies: R " << animTotal << "\n";
        outFile << "--------------------------------------------------------------\n";
        outFile << "TOTAL AMOUNT ALL RESERVATIONS:     R " << grandTotal << "\n";
        outFile << "==============================================================\n";

        outFile.close();
        cout << "Report successfully exported to " << outputFileName << endl;
        return true;
    }
};

int main() {
    MovieReservationSystem systemManager;
    string inFile, outFile;

    // Prompt user for file names
    cout << "Enter the input file name: ";
    cin >> inFile;
    cout << "Enter the output file name (movie_report.txt): ";
    cin >> outFile;

    systemManager.setFileName(inFile, outFile);

    if (!systemManager.loadClientsFromFile()) {
        cout << "Failed to process the input file. Program terminating." << endl;
        return 1;
    }

    int choice;
    do {
        cout << "\n==========================================\n";
        cout << "   CARNIVAL CITY MOVIE RESERVATION SYSTEM \n";
        cout << "==========================================\n";
        cout << "1. Count total lines in input file\n";
        cout << "2. Count total words in input file\n";
        cout << "3. Search occurrence of a character\n";
        cout << "4. Replace first two digits of reference numbers\n";
        cout << "5. Count occurrences of a specific movie type\n";
        cout << "6. Display total amount by movie type\n";
        cout << "7. Display total amount of all reservations\n";
        cout << "8. Generate sorted report file (" << outFile << ")\n";
        cout << "9. Exit\n";
        cout << "Select an option (1-9): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Total lines in file: " << systemManager.countLines() << endl;
                break;

            case 2:
                cout << "Total words in file: " << systemManager.countWords() << endl;
                break;

            case 3:
                systemManager.promptAndSearchCharacter();
                break;

            case 4: {
                string newPrefix;
                cout << "Enter new 2-character prefix (e.g., XX): ";
                cin >> newPrefix;
                systemManager.replaceReferencePrefix(newPrefix);
                break;
            }

            case 5: {
                string type;
                cout << "Enter movie type (Action, Horror, Animation): ";
                cin >> type;
                cout << "Total reservations for '" << type << "': " 
                     << systemManager.countMovieType(type) << endl;
                break;
            }

            case 6: {
                cout << "Total Action:    R " << systemManager.calculateTotalForMovieType("Action") << endl;
                cout << "Total Horror:    R " << systemManager.calculateTotalForMovieType("Horror") << endl;
                cout << "Total Animation: R " << systemManager.calculateTotalForMovieType("Animation") << endl;
                break;
            }

            case 7:
                cout << "Total for ALL reservations: R " << systemManager.calculateTotalAllReservations() << endl;
                break;

            case 8:
                systemManager.generateReport();
                break;

            case 9:
                cout << "Exiting system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid option. Please choose between 1 and 9." << endl;
        }

    } while (choice != 9);

    return 0;
}