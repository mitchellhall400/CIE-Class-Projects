/**********************************************************************************************************************
 *      Programmer: Mitchell Hall
 *            Date: 4/8/19
 *    Project Name: hw1
 *     Description: A compilation of functions from the Date object defined in the ECMAScript 2015 Standard.
 *      References: www.ecma-international.org/ - Object functions reference.
 *                  www.epochconverter.com/ - Used to test and compare my functions.
 *                  https://kalender-365.de/leap-years.php - List of leap years.
 *                  https://currentmillis.com/ - Used to test and compare my functions.
 **********************************************************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>

//Global Variables
const long long int msPerDay = 86400000;

//Function Prototypes
int Day(long long int t);               //see Section 20.3.1.2
int TimeWithinDay(long long int t);     //see Section 20.3.1.2
int DaysInYear(int y);                  //see Section 20.3.1.3
int DaysFromYear(int y);                //see Section 20.3.1.35
long long int TimeFromYear(int y);      //see Section 20.3.1.3
int YearFromTime(long long int t);      //see Section 20.3.1.3
bool InLeapYear(long long int t);       //see Section 20.3.1.3
int DayWithinYear(long long int t);     //see Section 20.3.1.4
int MonthFromTime(long long int t);     //see Section 20.3.1.4
int DateFromTime(long long int t);      //see Section 20.3.1.5
void PrintDate(long long int t);

//Main Function
int main() {

    //Day()
    std::cout << "\n*** Checking Day(t) Function ***" << std::endl;
    std::cout << "\tWhat day is -1555200001234ms? " << Day(-1555200001234) << ", correct answer = -18001" << std::endl;
    std::cout << "\tWhat day is -1ms? " << Day(-1) << ", correct answer = -1" << std::endl;
    std::cout << "\tWhat day is 86399999ms? " << Day(msPerDay-1) << ", correct answer = 0" << std::endl;
    std::cout << "\tWhat day is 86400000ms? " << Day(msPerDay) << ", correct answer = 1" << std::endl;
    std::cout << "\tWhat day is 1555200001234ms? " << Day(1555200000123) << ", correct answer = 18000" << std::endl;

    //TimeWithinDay()
    std::cout << "\n*** Checking TimeWithinDay(t) Function ***" << std::endl;
    std::cout << "\tHow much time is -86399999ms into the day? " << TimeWithinDay((-1 * (msPerDay - 1)))
              << ", correct answer = 1" << std::endl;
    std::cout << "\tHow much time is -1 into the day? " << TimeWithinDay(-1)
              << ", correct answer = 86399999ms" << std::endl;
    std::cout << "\tHow much time is 86399999ms into the day? " << TimeWithinDay(msPerDay-1)
              << ", correct answer = 86399999" << std::endl;
    std::cout << "\tHow much time is 86400000ms into the day? " << TimeWithinDay(msPerDay)
              << ", correct answer = 0" << std::endl;
    std::cout << "\tHow much time is 1555200001234ms into the day? " << TimeWithinDay(1555200001234)
              << ", correct answer = 1234" << std::endl;

    //DaysInYear()
    std::cout << "\n*** Checking DaysInYear(y) Function ***" << std::endl;
    std::cout << "\tHow many days are in year 2016? " << DaysInYear(2016) << ", correct answer = 366" << std::endl;
    std::cout << "\tHow many days are in year 2017? " << DaysInYear(2017) << ", correct answer = 365" << std::endl;
    std::cout << "\tHow many days are in year 2018? " << DaysInYear(2018) << ", correct answer = 365" << std::endl;
    std::cout << "\tHow many days are in year 2019? " << DaysInYear(2019) << ", correct answer = 365" << std::endl;
    std::cout << "\tHow many days are in year 2020? " << DaysInYear(2020) << ", correct answer = 366" << std::endl;
    std::cout << "\tHow many days are in year 1804? " << DaysInYear(1804) << ", correct answer = 366" << std::endl;
    std::cout << "\tHow many days are in year 1805? " << DaysInYear(1805) << ", correct answer = 365" << std::endl;

    //DaysFromYear()
    std::cout << "\n*** Checking DaysFromYear(y) Function ***" << std::endl;
    std::cout << "\tHow many days from 1970 to 1968? " << DaysFromYear(1968)
              << ", correct answer = -731" << std::endl;
    std::cout << "\tHow many days from 1970 to 1969? " << DaysFromYear(1969)
              << ", correct answer = -365" << std::endl;
    std::cout << "\tHow many days from 1970 to 1970? " << DaysFromYear(1970) << ", correct answer = 0" << std::endl;
    std::cout << "\tHow many days from 1970 to 1971? " << DaysFromYear(1971)
              << ", correct answer = 365" << std::endl;
    std::cout << "\tHow many days from 1970 to 1973? " << DaysFromYear(1973)
              << ", correct answer = 1096" << std::endl;
    std::cout << "\tHow many days from 1970 to 2019? " << DaysFromYear(2019)
              << ", correct answer = 17897" << std::endl;

    //TimeFromYear()
    std::cout << "\n*** Checking TimeFromYear(y) Function ***" << std::endl;
    std::cout << "\tHow much time from 1970 to 1968? " << TimeFromYear(1968)
              << ", correct answer = -63158400000" << std::endl;
    std::cout << "\tHow much time from 1970 to 1969? " << TimeFromYear(1969)
              << ", correct answer = -31536000000" << std::endl;
    std::cout << "\tHow much time from 1970 to 1970? " << TimeFromYear(1970)
              << ", correct answer = 0" << std::endl;
    std::cout << "\tHow much time from 1970 to 1971?  " << TimeFromYear(1971)
              << ", correct answer = 31536000000" << std::endl;
    std::cout << "\tHow much time from 1970 to 1973? " << TimeFromYear(1973)
              << ", correct answer = 94694400000" << std::endl;
    std::cout << "\tHow much time from 1970 to 2019? " << TimeFromYear(2019)
              << ", correct answer = 1546300800000" << std::endl;

    //YearFromTime()
    std::cout << "\n*** Checking YearFromTime(t) Function ***" << std::endl;
    std::cout << "\tWhat year is -63158400001ms? " << YearFromTime(-63158400001)
              << ", correct answer = 1967" << std::endl;
    std::cout << "\tWhat year is -63158400000ms? " << YearFromTime(-63158400000)        //Leap year
              << ", correct answer = 1968" << std::endl;
    std::cout << "\tWhat year is -1ms? " << YearFromTime(-1) << ", correct answer = 1969" << std::endl;
    std::cout << "\tWhat year is 0ms? " << YearFromTime(0) << ", correct answer = 1970" << std::endl;
    std::cout << "\tWhat year is 31536000000ms? " << YearFromTime(31536000000)
              << ", correct answer = 1971" << std::endl;
    std::cout << "\tWhat year is 1555200000000ms? " << YearFromTime(1555200000000)
              << ", correct answer = 2019" << std::endl;

    //InLeapYear()
    std::cout << "\n*** Checking InLeapYear(t) Function ***" << std::endl;
    std::cout << "\tIs -31536000001ms in a leap year? " << InLeapYear(-31536000001)
              << ", correct answer = true" << std::endl;
    std::cout << "\tIs -1ms in a leap year? " << InLeapYear(-1) << ", correct answer = false" << std::endl;
    std::cout << "\tIs 63072000000ms in a leap year? " << InLeapYear(63072000000)
              << ", correct answer = true" << std::endl;
    std::cout << "\tIs 94694400000ms in a leap year? " << InLeapYear(94694400000)
              << ", correct answer = false" << std::endl;
    std::cout << "\tIs 126230400000ms in a leap year? " << InLeapYear(126230400000)
              << ", correct answer = false" << std::endl;
    std::cout << "\tIs 157766400000ms in a leap year? " << InLeapYear(157766400000)
              << ", correct answer = false" << std::endl;
    std::cout << "\tIs 189302400000ms in a leap year? " << InLeapYear(189302400000)
              << ", correct answer = true" << std::endl;

    //DayWithinYear()
    std::cout << "\n*** Checking DayWithinYear(t) Function ***" << std::endl;
    std::cout << "\tWhat day within the year is -31536000001ms? " << DayWithinYear(-31536000001)
              << ", correct answer = 364" << std::endl;
    std::cout << "\tWhat day within the year is -1ms? " << DayWithinYear(-1)
              << ", correct answer = 364" << std::endl;
    std::cout << "\tWhat day within the year is 0ms? " << DayWithinYear(0) << ", correct answer = 0" << std::endl;
    std::cout << "\tWhat day within the year is 31535999999ms? " << DayWithinYear(31535999999)
              << ", correct answer = 364" << std::endl;
    std::cout << "\tWhat day within the year is 31536000000ms? " << DayWithinYear(31536000000)
              << ", correct answer = 0" << std::endl;

    //MonthFromTime()
    std::cout << "\n*** Checking MonthFromTime(t) Function ***" << std::endl;
    std::cout << "\tWhat month is -31536000001ms? " << MonthFromTime(-31536000001)
              << ", correct answer = 11" << std::endl;
    std::cout << "\tWhat month is -1ms? " << MonthFromTime(-1) << ", correct answer = 11" << std::endl;
    std::cout << "\tWhat month is 0ms? " << MonthFromTime(0) << ", correct answer = 0" << std::endl;
    std::cout << "\tWhat month is 31535999999ms? " << MonthFromTime(31535999999)
              << ", correct answer = 11" << std::endl;
    std::cout << "\tWhat month 31536000000ms? " << MonthFromTime(31536000000)
              << ", correct answer = 0" << std::endl;

    //DateFromTime()
    std::cout << "\n*** Checking DateFromTime(t) Function ***" << std::endl;
    std::cout << "\tWhat date is -31536000001ms? " << DateFromTime(-31536000001)
              << ", correct answer = 31" << std::endl;
    std::cout << "\tWhat date is -1ms? " << DateFromTime(-1) << ", correct answer = 31" << std::endl;
    std::cout << "\tWhat date is 0ms? " << DateFromTime(0) << ", correct answer = 1" << std::endl;
    std::cout << "\tWhat date is 31535999999ms? " << DateFromTime(31535999999)
              << ", correct answer = 31" << std::endl;
    std::cout << "\tWhat date 31536000000ms? " << DateFromTime(31536000000)
              << ", correct answer = 1" << std::endl;

    //PrintDate()
    std::cout << "\n*** Checking PrintDate(t) Function ***" << std::endl;
    std::cout << "\tPrinting -31538000001ms, should be 1968-12-31T23:26:39" << std::endl;
    PrintDate(-31538000123);
    std::cout << "\tPrinting 0ms, should be 1970-01-01T00:00:00" << std::endl;
    PrintDate(0);
    std::cout << "\tPrinting 31535999999ms, should be 1970-12-31T23:59:59" << std::endl;
    PrintDate(31535999999);
    std::cout << "\tPrinting 1567486491616ms, should be 2019-09-03T04:54:51" << std::endl;
    PrintDate(1567486491616);

    return 0;
}

/**********************************************************************************************************************
 * Description: Returns what day time t is away from 1/1/1970
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: int - days from 1/1/1970
 **********************************************************************************************************************/
int Day(long long int t) {
    return floor(static_cast<double>(t) / msPerDay);
}

/**********************************************************************************************************************
 * Description: Returns how many milliseconds time t since 1/1/1970 is into the day
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: int - How many milliseconds it is into the day
 **********************************************************************************************************************/
int TimeWithinDay(long long int t) {
    long long int timeInDay = t % msPerDay;
    if(timeInDay < 0) {
        return static_cast<int>(msPerDay + timeInDay);    //Inverting for negative time
    }
    return static_cast<int>(timeInDay);
}

/**********************************************************************************************************************
 * Description: Returns number of days within year y
 *      Inputs: int y - year number
 *     Outputs: int - number of days in year
 **********************************************************************************************************************/
int DaysInYear(int y) {
    if(y % 4 != 0) {
        return 365;
    }
    else if((y % 4 == 0) && (y % 100 != 0)) {
        return 366;
    }
    else if((y % 100) && (y % 400)) {
        return 365;
    }
    else if(y % 400) {
        return 366;
    }
    return -1;      //Error return code
}

/**********************************************************************************************************************
 * Description: Returns number of days from 1/1/1970 to year y
 *      Inputs: int y - year number
 *     Outputs: int - number of days since 1/1/1970
 **********************************************************************************************************************/
int DaysFromYear(int y) {           //Problem here with negative time
    auto doubleY = static_cast<double>(y);       //Auto assign when casting in initialization
    return static_cast<int>(365 * (doubleY - 1970) + floor((doubleY - 1969) / 4)
           - floor((doubleY - 1901) / 100) + floor((doubleY - 1601) / 400));
}

/**********************************************************************************************************************
 * Description: Returns number of milliseconds from 1/1/1970 to year y
 *      Inputs: int y - year number
 *     Outputs: long long int - number of milliseconds since 1/1/1970
 **********************************************************************************************************************/
long long int TimeFromYear(int y) {
    return msPerDay * DaysFromYear(y);
}

/**********************************************************************************************************************
 * Description: Returns the year that time t from 1/1/1970 falls in
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: int - year number
 **********************************************************************************************************************/
int YearFromTime(long long int t) {
    int y = 0;
    while(TimeFromYear(y + 1) <= t) {
        y++;
    }
    return y;
}

/**********************************************************************************************************************
 * Description: Returns whether or not the time inputted is within a leap year
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: bool - if the time given is within a leap year
 **********************************************************************************************************************/
bool InLeapYear(long long int t) {
    return DaysInYear(YearFromTime(t)) == 366;
}

/**********************************************************************************************************************
 * Description: Returns what day number time t since 1/1/1970 is within the year
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: int - day number in year
 **********************************************************************************************************************/
int DayWithinYear(long long int t) {
    return Day(t) - DaysFromYear(YearFromTime(t));
}

/**********************************************************************************************************************
 * Description: Returns what month number time t since 1/1/1970 is within the year
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: int - month number in year
 **********************************************************************************************************************/
int MonthFromTime(long long int t) {
    int day = DayWithinYear(t);
    bool leap = InLeapYear(t);

    //January
    if(0 <= day && day < 31) {
        return 0;
    }
    //February
    else if(31 <= day && day < 59) {
        return 1;
    }
    //March
    else if(59 + leap <= day && day < 90 + leap) {
        return 2;
    }
    //April
    else if(90 + leap <= day && day < 120 + leap) {
        return 3;
    }
    //May
    else if(120 + leap <= day && day < 151 + leap) {
        return 4;
    }
    //June
    else if(151 + leap <= day && day < 181 + leap) {
        return 5;
    }
    //July
    else if(181 + leap <= day && day < 212 + leap) {
        return 6;
    }
    //August
    else if(212 + leap <= day && day < 243 + leap) {
        return 7;
    }
    else if(243 + leap <= day && day < 273 + leap) {
        return 8;
    }
    else if(273 + leap <= day && day < 304 + leap) {
        return 9;
    }
    else if(304 + leap <= day && day < 334 + leap) {
        return 10;
    }
    else if(334 + leap <= day && day < 365 + leap) {
        return 11;
    }
    return -1;      //Error return code
}

/**********************************************************************************************************************
 * Description: Returns date within the month given time t since 1/1/1970
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: int - date number in month
 **********************************************************************************************************************/
int DateFromTime(long long int t) {
    int day = DayWithinYear(t);
    int month = MonthFromTime(t);
    bool leap = InLeapYear(t);

    //January
    if(month == 0) {
        return day + 1;
    }
    //February
    else if(month == 1) {
        return day - 30;
    }
    //March
    else if(month == 2) {
        return day - 58 - leap;
    }
    //April
    else if(month == 3) {
        return day - 89 - leap;
    }
    //May
    else if(month == 4) {
        return day - 119 - leap;
    }
    //June
    else if(month == 5) {
        return day - 150 - leap;
    }
    //July
    else if(month == 6) {
        return day - 180 - leap;
    }
    //August
    else if(month == 7) {
        return day - 211 - leap;
    }
    //September
    else if(month == 8) {
        return day - 242 - leap;
    }
    //October
    else if(month == 9) {
        return day - 272 - leap;
    }
    //November
    else if(month == 10) {
        return day - 303 - leap;
    }
    //December
    else if(month == 11) {
        return day - 333 - leap;
    }
    return -1;      //Return error code
}

/**********************************************************************************************************************
 * Description: Prints the date in the YYYY-MM-DDTHH:mm:ss format.
 *      Inputs: long long int t - ms since 1/1/1970
 *     Outputs: void
 **********************************************************************************************************************/
void PrintDate(long long int t) {
    long long int time = TimeWithinDay(t);
    std::cout << YearFromTime(t) << "-"                                                                //Print year
              << std::setw(2) << std::setfill('0') << MonthFromTime(t) + 1 << "-"               //Print month
              << std::setw(2) << std::setfill('0') << DateFromTime(t) << "T"                    //Print date
              << std::setw(2) << std::setfill('0') << time / 3600000 << ":"                     //Print hour
              << std::setw(2) << std::setfill('0') << (time % 3600000) / 60000 << ":"           //Print minutes
              << std::setw(2) << std::setfill('0') << ((time % 3600000) % 60000) / 1000         //Print seconds
              << std::endl;
}