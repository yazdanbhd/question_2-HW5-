#include <iostream>
#include "Course.cpp"

int main()
{
    Course course_1("Farsi", 3, vector<double> {12, 12, 12});
    Course course_2("Rizai", 3, vector<double> {20, 20, 20});
    Course course_3("Olom", 3, vector<double> {12, 10, 5});
    Course course_4("Dyni", 3, vector<double> {10, 14, 20});
    Course course_5("Zist", 3, vector<double> {14, 14, 14});
    Course course_6("Phyisc", 3, vector<double> {14, 14, 14});
    Course course_7("C++", 3, vector<double> {14, 14, 14});

    vector<Course> student_1_COURSES = { course_1 ,course_2 ,course_3 ,course_4 };
    vector<Course> student_2_COURSES = { course_5 ,course_4,course_3 ,course_2 };
    vector<Course> student_3_COURSES = { course_1 ,course_2,course_3 ,course_4 };
    vector<Course> student_4_COURSES = { course_7 ,course_5,course_4 ,course_1 };
    vector<Course> student_5_COURSES = { course_3 ,course_2,course_2 ,course_4 };
    vector<Course> student_6_COURSES = { course_2 ,course_3,course_5 ,course_7 };
    vector<Course> student_7_COURSES = { course_6 ,course_6,course_7 ,course_7 };

    Studnet student_1(student_1_COURSES, "PC", "reza", "mohammadi", "45bbb3333",98, 2);
    Studnet student_2(student_2_COURSES, "POWER", "ali", "kamali", "82cbc3333",96, 3);
    Studnet student_3(student_3_COURSES, "FARSI", "mamad", "zahedi", "52csc3333",95, 1);
    Studnet student_4(student_4_COURSES, "RAVAN SHENASI", "mamad", "zahedi", "52csc3333",95, 1);
    Studnet student_5(student_5_COURSES, "NOJOM", "mamad", "zahedi", "52csc3333",96, 2);
    Studnet student_6(student_6_COURSES, "POWER", "mamad", "zahedi", "52csc3333",94, 8);
    Studnet student_7(student_7_COURSES, "POWER", "mamad", "zahedi", "52csc3333",98, 7);

    student_1.validate();
    student_2.validate();
    student_3.validate();
    student_4.validate();
    student_5.validate();
    student_6.validate();
    student_7.validate();

    cout << student_1.gpa() << endl;
    cout << student_2.gpa() << endl;
    cout << student_3.gpa() << endl;
    cout << student_4.gpa() << endl;
    cout << student_5.gpa() << endl;
    cout << student_6.gpa() << endl;
    cout << student_7.gpa() << endl;

    cout << student_1.calculateSalary() <<endl;
    cout <<student_2.calculateSalary() << endl;
    cout << student_3.calculateSalary() << endl;
    cout << student_4.calculateSalary() << endl;
    cout << student_5.calculateSalary() << endl;
    cout << student_6.calculateSalary() << endl;
    cout << student_7.calculateSalary() << endl;

    Professor professor_1("Instructor", "Mahdi", "zahed", "82cTc3333",10, 1);
    Professor professor_2("Professor", "Ali", "Kazemi", "82ccc3333",10, 1);
    Professor professor_3("Associate Professor", "Reza", "zahed", "82ccc3333",10, 1);
    cout << professor_1.validate() << endl;
    cout << professor_2.validate() << endl;
    cout << professor_3.validate() << endl;

    cout << professor_1.calculateSalary() << endl;
    cout << professor_2.calculateSalary() << endl;
    cout << professor_3.calculateSalary() << endl;

    vector<Studnet> students = { student_1,student_2 , student_3 };
    vector<Professor> professors = { professor_1, professor_2 ,professor_3 };
    Universe universe(7000000, professors, students);
    cout << "Universe Average GPA For All => " << universe.averageGpa() << endl;
    double averageGpaOfField = universe.averageGpaOfField("PC");
    double averageMarkOfCourse = universe.averageMarkOfCourse("Farsi");
    bool isEnoughBudget = universe.isEnoughBudget();
    universe.saveToFile(vector<string>{"PC" , "POWER" , "FARSI"}  );

}
