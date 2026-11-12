#include <iostream>
#include <iomanip>
using namespace std;
class StudentScores
{
private:
 int numStudents;
 int *scores;
public:
 // Constructor
 StudentScores(int n)
 {
 numStudents = n;
 scores = new int[numStudents];
 }
 // Destructor
 ~StudentScores()
 {
 delete[] scores;
 }
 // Function to input scores
 void inputScores()
 {
 cout << "\nEnter the scores of the students:\n";
 for (int i = 0; i < numStudents; i++)
 {
 cout << "Student " << i + 1 << ": ";
 cin >> scores[i];
 }
 }
 // Function to find maximum score
 int getMaximum()
 {
 int max = scores[0];
 for (int i = 1; i < numStudents; i++)
 {
 if (scores[i] > max)
 max = scores[i];
 }
 return max;
 }
 // Function to find minimum score
 int getMinimum()
 {
 int min = scores[0];
 for (int i = 1; i < numStudents; i++)
 {
 if (scores[i] < min)
 min = scores[i];
 }
 return min;
 }
 // Function to calculate average
 double getAverage()
 {
 int total = 0;
 for (int i = 0; i < numStudents; i++)
 {
 total += scores[i];
 }
 return (double)total / numStudents;
 }
 // Overloaded function (Basic View)
 void displayResults()
 {
 cout << "\n========== BASIC VIEW ==========\n";
 cout << "Maximum Score : " << getMaximum() << endl;
 }
 // Overloaded function (Detailed View)
 void displayResults(bool detailed)
 {
 if (detailed)
 {
 cout << "\n========== DETAILED REPORT ==========\n";
 cout << "Maximum Score : " << getMaximum() << endl;
 cout << "Minimum Score : " << getMinimum() << endl;
 cout << fixed << setprecision(2);
 cout << "Average Score : " << getAverage() << endl;
 }
 }
};
int main()
{
 int students;
 cout << "=====================================\n";
 cout << " Student Performance Management\n";
 cout << "=====================================\n";
 cout << "Enter the number of students: ";
 cin >> students;
 StudentScores performance(students);
 performance.inputScores();
 // Basic View
 performance.displayResults();
 // Detailed View
 performance.displayResults(true);
    return 0;
}