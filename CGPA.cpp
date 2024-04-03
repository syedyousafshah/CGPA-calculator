#include <iostream>
using namespace std;

const int MAX_SEMESTERS = 7;
const int MAX_SUBJECTS = 7;

// Function to calculate GPA for a semester
float calculateSemesterGPA(int subjects) {
    float credits[MAX_SUBJECTS], gradePoints[MAX_SUBJECTS], totalCredits = 0, totalGradePoints = 0;
    const float AP = 4.0, A = 3.70, BP = 3.40, B = 3.00, CP = 2.00, C = 1.50, F = 0.00;
    
    for (int j = 0; j < subjects; j++) {
        cout << "Enter marks for Subject " << j+1 << ": ";
        cin >> credits[j];
        cout << "Enter credit hours for Subject " << j+1 << ": ";
        cin >> gradePoints[j];
        
        if (credits[j] >= 84.50 && credits[j] <= 100)
            gradePoints[j] = AP;
        else if (credits[j] < 84.50 && credits[j] >= 79.50)
            gradePoints[j] = A;
        else if (credits[j] < 79.50 && credits[j] >= 74.50)
            gradePoints[j] = BP;
        else if (credits[j] < 74.50 && credits[j] >= 69.50)
            gradePoints[j] = B;
        else if (credits[j] < 69.50 && credits[j] >= 59.50)
            gradePoints[j] = CP;
        else if (credits[j] < 59.50 && credits[j] >= 54.50)
            gradePoints[j] = C;
        else
            gradePoints[j] = F;

        totalGradePoints += gradePoints[j];
        totalCredits += credits[j];
    }
    return totalGradePoints / totalCredits;
}

int main() {
    int semesters;
    float cgpa = 0;

    cout << "Enter Number of Semesters: ";
    cin >> semesters;

    if (semesters > MAX_SEMESTERS || semesters <= 0) {
        cout << "Invalid number of semesters." << endl;
        return 1;
    }

    for (int i = 0; i < semesters; i++) {
        int subjects;
        cout << "Enter Total Number of Subjects for Semester " << i + 1 << ": ";
        cin >> subjects;

        if (subjects > MAX_SUBJECTS || subjects <= 0) {
            cout << "Invalid number of subjects." << endl;
            return 1;
        }

        float semesterGPA = calculateSemesterGPA(subjects);
        cgpa += semesterGPA;

        cout << "GPA for Semester " << i + 1 << ": " << semesterGPA << endl;
    }

    cgpa /= semesters;
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}

