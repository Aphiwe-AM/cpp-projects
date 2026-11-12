#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//function declarations
string studentResults(int maxGrade);
void studentResults(int maxGrade, int minGrade, double average);

//gradebook class
class gradebook{
    int numOfStudents; //number of students in a the class
    vector<int> grades; //store all grades 

public:
    gradebook(int numOfStudents,  vector<int>& grades){
        this->numOfStudents = numOfStudents;
        this->grades = grades;
        
    }
    
    //create a method to find the maximum grade
    int isMaximum(){
        double maxGrade = grades[0]; //variable to store max score
        //iterate through the vector of grade
        for(int grade : grades){
            //find the maximum grade
            if( grade > maxGrade){
                maxGrade = grade;
            }
        
        }
        //return the maximum grade in the vector of grades
        return maxGrade;
    }
    //create a method to find the minimum grade in the class
    int isMinGrade(){
        int minGrade = grades[0];
        //iterate in grades vector to find the smallest amount
        for(int grade : grades){
            //find the smallest grade
            if(grade < minGrade){
                minGrade = grade;
            }
        }
        //return the smallest amount in the grades vector
        return minGrade;
    }

    //create a method to find the average grade
    double isAverage(){
        int sumGrades = 0;
        for(double grade : grades){
            sumGrades += grade;
        }
    
        //calculate the average and return 
         double average = sumGrades / numOfStudents;
         return average;

    }

    
};

int main(){
    //variables used
    int numOfStudents;
    //prompt the lecturer to input the number of students
    cout << "Enter number of student in the class: ";
    cin >> numOfStudents;
    
    //create a vector to store the grades
    vector<int> grades;
    //iterate through the vector and input students grades
    for(int i = 0; i < numOfStudents; i++){
        int grade;
        cout << "Enter grade for student " << i + 1 << ": ";
        cin >> grade;
        grades.push_back(grade);
    }

    //create a gradebook object
    gradebook studentPerformance(numOfStudents, grades);

    //genarate results with function overloading
   // cout << fixed << setprecision(2);
    cout << studentResults(studentPerformance.isMaximum());
    studentResults(studentPerformance.isMaximum(), studentPerformance.isMinGrade(), studentPerformance.isAverage());

    
}
//function to display results  overloaded function 1
string studentResults(int maxGrade){

    cout << "processing.............\n";//displaying to create buffer from the promtps 
    string message =  "The maximum  grade is : " + to_string(maxGrade) + "%\n";
    cout << endl;
    return message;
    
}
//function to display a detailed results overloaded function 2
 void studentResults(int maxGrade, int minGrade, double average){
    cout << "===================\n";
    cout << "Max Grade: " << maxGrade << "%"<< endl;
    cout << "Min Grade: " << minGrade << "%" <<endl;
    cout << "Grade average: " << average << "%" << endl;
    cout << "===================\n";
 }
