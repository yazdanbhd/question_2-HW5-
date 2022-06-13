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









