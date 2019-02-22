#include <iostream>
#include <string>
using namespace std;


class dayType
{
public:
    dayType();
    //Default constructor. Time will be set to first doW
    dayType(string d);
    //Constructor with parameters.
    void setDay(string d);
    //Function to set day
    void printDay() const;
    //Function to print day
    void nextDay();
    //Function to show next day
    void prevDay();
    //Function to show previous day
    void addDay(int nDays);
    //Function to add custom amount of days
    //string day_Type::weekDays[7] = {"monday", "tuesday", "wednesday",
    //    "thursday", "friday", "saturday", "sunday"};
    
    dayType& operator++ ()     // prefix ++
    {
        weekDay++;
        if (weekDay > 6) {
            weekDay = 0;
        }
        // Do work on this.   (increment your object here)
        return *this;
    }
    
    // You want to make the ++ operator work like the standard operators
    // The simple way to do this is to implement postfix in terms of prefix.
    //
    dayType  operator++ (int)  // postfix ++
    {
        dayType result(*this);   // make a copy for result
        ++(*this);              // Now use the prefix version to do the work
        return result;          // return the copy (the old) value.
    }
    
private:
    int weekDay = 0; //Stores the number of the day (0-6)
    int n;
    string weekDays[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
};


void dayType::setDay(string d)
{
    if (d == "Monday"){ weekDay = 0;}
    else if (d == "Tuesday"){ weekDay = 1;}
    else if (d == "Wednesday"){ weekDay = 2;}
    else if (d == "Thursday"){ weekDay = 3;}
    else if (d == "Friday"){ weekDay = 4;}
    else if (d == "Saturday"){ weekDay = 5;}
    else if (d == "Sunday"){ weekDay = 6;}
    else {cout << "Wrong day input! Try Monday.";}
};

void dayType::printDay() const
{
    cout << "Today is " << weekDays[weekDay] << endl;
};

void dayType::nextDay()
{
    if (weekDay+1>7) {n = weekDay+1 % 7;}
    else {n = weekDay+1;};
    cout << "Next day will be " << weekDays[n] << endl;
};

void dayType::prevDay()
{
    if (weekDay-1<0) {n = 6;}
    else {n = weekDay-1;};
    cout << "Prev day was " << weekDays[n] << endl;
};

void dayType::addDay(int nDays) {
    if (weekDay+nDays>7) {weekDay = (weekDay+(nDays % 7)-1);
    } else {weekDay += nDays;};
};

dayType::dayType()
{
    weekDay = 0;
}

dayType::dayType(string d)
{
    setDay(d);
}

int main () {
    dayType myDay;
    myDay.setDay("Friday");
    myDay.printDay();
    myDay.prevDay();
    myDay.nextDay();
    myDay.addDay(2);
    myDay.printDay();
    myDay.addDay(281);
    myDay.printDay();
    myDay++;
    myDay.printDay();
    return 0;
}
