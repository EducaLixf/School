#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct student{
        string studentName;//student Name
        int studentScore[5]; //array to store the 5 test scores for the students
        float average;

        };

    struct student structArray[10]; //array of Struct Student (10 students each with 5 test scores)
    int totalStudents , totalTests, sum, temp;
    string tempName;
    //float average;
    totalStudents = 10; //total students in the class are 10
    totalTests = 5; // total test for each student

    cout << "*****C++ program of the grading system of a Class*****\n";
    cout<<"\nThere are total of 10 student in the class\nand each student has taken 5 tests, where each test is worth 100 points\n";

    //using for-loop for getting each student's details
    for (int i = 0; i < totalStudents; i++)
    {
    cout << "\nFor student #" << i + 1;
    cout<<"\nInput student #" << i + 1 <<" name: ";
    cin >> structArray[i].studentName; // stores the name of each student in the struct student array

    cout<<"\nNow, enter each of the 5 marks:\n";

    sum = 0;
    //using inner for-loop to get 5 test scores for each student
    for (int j = 0; j < totalTests; j++)
        {
            cout << "Input test #" << j + 1 << " score: ";
            cin >> structArray[i].studentScore[j];
            sum = sum + structArray[i].studentScore[j];
        }
    structArray[i].average = (float) sum / totalTests; //finding the average of each student

    //cout << "Average Score of student #" << i + 1 << " " << structArray[i].studentName <<" is: "<< structArray[i].average << endl;
    }

    //unsorted list of students and their averages
    cout << "\nAverage for each student;" << endl;
    for (int i = 0; i < totalStudents; i++)
    {
        cout << "For " << structArray[i].studentName << " their average is: " << structArray[i].average << endl;
    }

    //Bubble sort from student with the lowest average to student with the highst average
    for(int i = 0; i < totalStudents; i++)
    {
        for(int j = i+1; j < totalStudents ; j++)
        {
            if(structArray[j].average < structArray[i].average)
            {
                temp = structArray[i].average;
                structArray[i].average = structArray[j].average;
                structArray[j].average = temp;

                tempName = structArray[i].studentName;
                structArray[i].studentName = structArray[j].studentName;
                structArray[j].studentName = tempName;
            }
        }
    }
    cout << "\nAverage for each student when sorted;" << endl;
    for (int i = 0; i < totalStudents; i++)
    {
        cout << "For " << structArray[i].studentName << " their average is: " << structArray[i].average << endl;
    }
    //BInary search by name of student
    const char CAPACITY = 10;
    const int NOT_FOUND_FLAG = -1;

    string searchValue;
    int searchValueIndex = NOT_FOUND_FLAG;

    cout << "Please enter the name of the student that you wish to find: ";
    cin >> searchValue;

        for (int currentIndex = 0 ; currentIndex < CAPACITY; currentIndex++)
   {
       if (structArray[currentIndex].studentName == searchValue)
       {
           searchValueIndex = currentIndex;
       }
   }

   if(searchValueIndex == NOT_FOUND_FLAG)
   {
       cout << "we did not find the student you are looking for." << endl;
   }
   else
   {

       cout << " The name of the student is " << structArray[searchValueIndex].studentName << " with average of " << structArray[searchValueIndex].average << endl;
   }


    return 0;

}








/*#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct structStd{
        string stdName ;  //student Name
        int score[5] ; //stores 5 test scores
        };

    struct structStd structArr[10]; //array of Struct structStd
    int totalStd , totalTests, sum;
    float average, totalAverage, classAverage;
    char grade;     totalStd = 10; //total students in the class are 10
    totalTests = 5; // total test for each student

    cout << "*****C++ program of the grading system of a Class*****\n";
    cout<<"\nThere are total of 10 student in the class\nand each student has taken 5 tests, where each test is worth 100 points\n";

    //using for-loop for gettign each student's details
    for (int i = 0; i < totalStd; i++)
    {
    cout << "\nFor student #" << i + 1;
    cout<<"\nInput student #" << i + 1 <<" name: ";
    cin >> structArr[i].stdName;

    cout<<"\nNow, enter each of the 5 marks:\n";
    sum = 0 ;

    //using inner for-loop to get 5 test scores for each student
    for (int j = 0; j < totalTests; j++)
        {
            cout << "Input test #" << j + 1 << " score: ";
            cin >> structArr[i].score[j];
            sum = sum + structArr[i].score[j];
        }
    average = (float) sum / totalTests; //finding the average of each student

    // using if-statements to determine the grades
    if (average >= 90)
        grade = 'A';
    if ((average >= 80) && (average < 90))
        grade = 'B';
    if ((average >= 70) && (average < 80))
        grade = 'C';
    if ((average >= 60) && (average < 70))
        grade = 'D';
    if (average < 60)
        grade = 'E';

    totalAverage += average;
    //updating the totalAverage by adding current student's average score  // printing the average score of each student
    cout << "Average Score of student #" << i + 1 << " " << structArr[i].stdName <<" is: "<< average;
    cout << "\nand Grade is: " << grade << endl;
    }

    // calculating and printing the final class Average classAverage
    classAverage = (float) totalAverage / 10;
    cout << "\n\nClass Average is: " << classAverage;

    return 0;

}*/

