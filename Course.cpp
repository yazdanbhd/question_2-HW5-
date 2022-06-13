#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

template <class T,size_t n>
size_t getArraySize(T(&)[n])
{
    retrun n;
}

bool is_number(const string& s)
{
    string::const_iterator it = s.begin();
    while(it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

class Course {

    private:
        string name;
        int unit;
        vector <doubele> mark;


    public:

        Course(const Course& courseOld) {
            this-> name = courseOld.name;
            this-> unit = courseOld.unit;
            this-> mark = courseOld.mark;
        }

        course(
            string name,
            int unit,
            vector <double> mark
        ) {
            this->name = name;
            this->unit = unit;
            this-.mark = mark;
        }
        void setName(string name)
        {
            this->name = name;
        }
        void setUnit(int unit)
        {
            this->unit = unit;
        }
        void setMark(vector <double> mark)
        {
            this->mark = mark;
        }
        string getName()
        {
            return name;
        }

         int getUnit()
         {
             return unit;
         }

        vector<double> getMark ()
        {
            return mark;
        }

        double getAvg()
        {
            double avg=0;
            for (int i=0; i<mark.size(); i++)
            {
                avg += mark[i];
            }
            avg /= mark.size();
            return avg;
        }

        friend ostream& operator<<(ostream& output, const Course& course)
        {
            output << "salam";
            return output;
        }

        friend istream& operator>>(istream& input, Course& course)
        {
            input >> course.name >> course.unit;
            return input;
        }

    };

class Person {

private:
    string firstName;
    string lastName;
    string id;
    double  workHour;
    int year;


public:

    ~Person() {
    }


    Person(
            string firstName,
            string lastName,
            string id,
            double workHour ,
            int year
    ) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = id;
        this->workHour = workHour;
        this->year = year;

        if (validate() == false) {
            exit(0);
        }

    }

    // Copy Constructer
    Person(const Person& constOld)
    {
        this->firstName = constOld.firstName;
        this->lastName = constOld.lastName;
        this->id = constOld.id;
        this->workHour = constOld.workHour;
        this->year = constOld.year;
    }

    void setFirstName(string name)
    {
        this->firstName = name;
    }

    void setLastName(string last)
    {
        this->lastName = lastName;
    }

    void setID(string id) {
        this->id = id;
    }


    void setWorkHour(double workHour)
    {
        this->workHour = workHour;
    }

    void setYear(int year)
    {
        this->year = year;
    }


    string getFirstName()
    {
        return this->firstName;
    }

    string getLastName()
    {
        return this->lastName;
    }

    string getId()
    {
        return this->id;
    }

    double getWorkHour()
    {
        return this->workHour;
    }

    int getYear()
    {
        return year;
    }

    bool validate()
    {

        if (id.length() > 8 && id.length() < 11)
        {
            int testOne = stoi(id.substr(0, 2));
            if (testOne <= 84 && testOne >= 0)
            {
                bool testTwo = is_number(id.substr(3, 5));
                if (testTwo == false)
                {
                    int testThree;

                    for (int i = 5; i < id.length(); i++)
                    {
                        int temp = stoi(id.substr(i, i + 1));
                        if (temp < 4 || temp > 6) {}
                        else
                        {
                            cout << "Invalid ID";
                            return false;
                            break;
                        }
                    }

                }
                else { cout << "Invalid ID" << endl;  return false; };
            }
            else
            {
                cout << "Invalid ID" << endl; return false;
            }
        }
        else
        {
            cout << "Invalid ID" << endl;

            return false;
        }

        return true;

    }

    double calculateSalary()
    {
        int a = static_cast<int>(workHour);
        return a * 100000;
    }


    friend ostream& operator<<(ostream& output, const Person& person)
    {
        output << "Salam";
        return output;
    }

    friend istream& operator>>(istream& input, Person& person)
    {
        input >> person.firstName >> person.lastName >> person.id;
        return input;
    }


};

class Studnet : public Person
{


private:
    vector<Course> courses ;
    int courseCount;
    string filedOFStudy;
    int numOFCourses;



public:


    Studnet(
            vector<Course> courses,
            string filedOFStudy,
            string firstName,
            string lastName,
            string id,
            int year ,
            double workHour
    ) : Person (firstName,lastName,id,workHour,year)
    {
        this->courses = courses;
        this->filedOFStudy = filedOFStudy;
        this->numOFCourses = numOFCourses;
    }

    double gpa()
    {

        double avg = 0;
        for (int i = 0; i < courses.size(); i++)
        {
            avg += courses[i].getAvg();
        }
        avg /= courses.size();
        return avg;
    }


    double calculateSalary()
    {
        int salary = 0;
        if (gpa() > 17.0)
        {
            double mainIcnom  = static_cast<int>(getWorkHour()) * 20000;
            int percent = mainIcnom * 0.1;
            salary = mainIcnom + percent;
        }
        else
        {
            salary = static_cast<int>(getWorkHour()) * 20000;
        }
        return salary;

        Person::calculateSalary();
    }


    string getFiledOFStudy()
    {
        return filedOFStudy;
    }

    int getCoursesCount()
    {
        return courses.size();
    }

    double getAvg()
    {
        double avg = 0;
        for (Course course : courses)
        {
            avg += course.getAvg();
        }
        avg /= courses.size();
        if (avg < 0) { return 0; }
        else { return avg; }
    }


    double getCourseAverage(string couresName)
    {

        int avg = 0;
        int count = 0 ;
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].getName() == couresName)
            {
                avg += courses[i].getAvg();
                count = count + 1;
            }
        }



        if (count == 0)
        {
            return 0;
        }
        else
        {
            return avg /= count;
        }

    }

    bool hasCourse(string couresName)
    {
        for (Course course : courses)
        {
            if (course.getName() == couresName)
            {
                return true;
            }

        }
        return false;
    }


    friend ostream& operator<<(ostream& output, const Studnet& studnet)
    {
        output << "Salam";
        return output;
    }

    friend istream& operator>>(istream& input, Studnet& studnet)
    {

        return input;
    }

};


class Professor : public Person {

private :

    string title;

public:
    Professor(
            string title ,
            string firstName,
            string lastName,
            string id,
            int year ,
            double workHour) : Person(firstName, lastName, id,year , workHour)
    {
        this->title = title;
    }


    bool validate()
    {
        string id = getId();
        if (id.length() == 8 )
        {
            int testOne = stoi(id.substr(0, 2));
            if (testOne <= 84 && testOne >= 0)
            {
                bool testTwo = is_number(id.substr(3, 5));
                if (testTwo == false && id.substr(3,4) == "#")
                {
                    int testThree;

                    for (int i = 5; i < id.length(); i++)
                    {
                        int temp = stoi(id.substr(i, i + 1));
                        if (temp < 4 || temp > 6) {}
                        else
                        {
                            cout << "Invalid ID";
                            return false;
                            break;
                        }
                    }

                }
                else { cout << "Invalid ID" << endl;  return false; };
            }
            else
            {
                cout << "Invalid ID" << endl; return false;
            }
        }
        else
        {
            cout << "Invalid ID" << endl;

            return false;
        }

        Person::validate();

    }



    double calculateSalary()
    {

        int hourPerTier{};

        if (title == "Instructor")
        {
            hourPerTier = 10000;
        }


        if (title == "Assistant Professor")
        {
            hourPerTier = 20000;
        }


        if (title == "Associate Professor")
        {
            hourPerTier = 30000;
        }

        if (title == "Professor")
        {
            hourPerTier = 40000;
        }

        double salary = static_cast<int>(getWorkHour()) * (50000+hourPerTier);



        return salary;

        Person::calculateSalary();
    }



    friend ostream& operator<<(ostream& output, const Professor& professor) {
        output << "Salam";
        return output;
    }

    friend istream& operator>>(istream& input, Professor& professor) {

        return input;
    }


};

class Universe {

private:

    int budget;
    vector<Professor> professors;
    vector <Studnet> students;




public :
    Universe(
            int budget,
            vector<Professor> professors,
            vector <Studnet> students
    ) {
        this->budget = budget;
        this->professors = professors;
        this->students = students;
    }

    // Copy Constructer
    Universe(const Universe& universe) {
        this->budget = universe.budget;
        this->professors = universe.professors;
        this->students = universe.students;
    }

    double averageMarkOfCourse(string courseName) {

        double avg = 0;
        int count = 0;
        for (int i = 0; i < students.size(); i++) {
            if (students[i].hasCourse(courseName)) {
                avg += students[i].getCourseAverage(courseName);
                count = count + 1;
            }
        }

        avg /= count;
        cout << "Universe Average For Course => " << courseName << " => " << avg << endl;


        return avg;

    }

    double averageGpaOfField(string filedOFStudy) {

        int avg = 0;
        int count = 0;
        for (int i = 0; i < students.size(); i++) {
            string temp = students[i].getFiledOFStudy();
            if (temp == filedOFStudy) {
                avg += students[i].getAvg();
                count = count + 1;
            }
        }




        if (count == 0) {
            cout << "Enter Course Name Correctly => " << endl;
            return 0;
        }
        else {
            cout << "Universe Average GPA For filed OF Study => " << filedOFStudy << " ==> " << (avg /= count) << endl;
            return avg /= count;
        }


    }

    double averageGpa() {

        int avg = 0;
        int count = 0;
        for (int i = 0; i < students.size(); i++) {
            avg += students[i].getAvg();
            count = count + 1;
        }




        if (count == 0) {
            return 0;
        }
        else {
            return avg /= count;
        }


    }

    double getStudentBudget() {

        double budget = 0;

        for (Studnet studnet : students) {
            budget += studnet.calculateSalary();
        }

        return budget;
    }

    double getProfessorBudget() {

        double budget = 0;

        for (Professor professor: professors) {
            budget += professor.calculateSalary();
        }

        return budget;
    }

    bool isEnoughBudget() {
        int finalBudget = getStudentBudget() + getProfessorBudget();

        cout << "Universe Budge Is Enough ? =>" << (finalBudget < budget) << endl;
        return finalBudget < budget;
    }


    vector<Studnet> saveToFile(vector<string> fillOfStudys) {


        vector<Studnet> bestStudnets;

        for (string fillOfStudy : fillOfStudys) {
            double  max = 0 ;
            vector<Studnet> pointed;
            for (Studnet studnet : students) {
                if (studnet.getFiledOFStudy() == fillOfStudy) {

                    if (studnet.getAvg() > max) {
                        max = studnet.getAvg();
                        pointed.clear();
                        pointed.push_back(studnet);
                    }
                }
            }
            bestStudnets.push_back(pointed[0]);
        }


        string filename("best Studnets.txt");
        fstream file_out;
        file_out.open(filename, std::ios_base::out);





        for (Studnet studnet  :bestStudnets) {

            if (file_out.is_open()) {
                cout << "Writing The File ...." << filename << '\n';
                file_out <<
                         studnet.getId() << " " <<
                         studnet.getFirstName() << " " <<
                         studnet.getLastName() << " " <<
                         studnet.getFiledOFStudy() << " " <<
                         studnet.getAvg() << " " << endl;
            }
        }

        file_out.close();


        return bestStudnets;
    }


    friend ostream& operator<<(ostream& output, const Universe& universe) {

        vector<Studnet> studnets = universe.students;
        vector<Professor> professors = universe.professors;


        for (Studnet std : studnets) {
            cout << "Studnet Name => " << std.getFirstName() << endl;
        }

        for (Professor pf: professors) {
            cout << "Professor Name => " << pf.getFirstName() << endl;
        }


        return output;
    }

    friend istream& operator>>(istream& input, Universe& universe) {
        return input;
    }

};







