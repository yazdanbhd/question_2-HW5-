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











