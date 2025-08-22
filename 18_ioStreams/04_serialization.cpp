#include <fstream>
#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    string branch;

    Student()
    {
        
    };

    Student(string name, int roll, string branch)
    {
        this->name = name;
        this->roll = roll;
        this->branch = branch;
    };

    friend ofstream & operator<<(ofstream &ofs, Student &s);
    friend ifstream & operator>>(ifstream &ifs, Student &s);

    void display()
    {
        cout<<name<<" "<<roll<<" "<<branch<<endl;
    };
};

ofstream & operator<<(ofstream &ofs, Student &s)
{
    ofs<<s.name<<endl;
    ofs<<s.roll<<endl;
    ofs<<s.branch<<endl;

    return ofs;
};

ifstream & operator>>(ifstream &ifs, Student &s)
{
    ifs>>s.name;
    ifs>>s.roll;
    ifs>>s.branch;

    return ifs;
};

int main()
{
    Student s1("dtblocker",69,"Electrical");

    ofstream ofs("student.txt", ios::trunc);

    // ofs<<s1<<endl; // invalid as s1 is not valid object to be rpinted in file

    // so use
    ofs<<s1;
    ofs.close();

    Student s2;
    ifstream ifs("student.txt");
    ifs>>s2;
    s2.display();

    return 0;
};