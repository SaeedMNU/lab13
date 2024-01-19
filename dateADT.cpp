#include <iostream>

class Date {
  
private:
  int day;
  int month;
  int year;

public:
  Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
  }

  int getDay() const {
    return day;
  }

  int getMonth() const {
    return month;
  }

  int getYear() const {
    return year;
  }
};

// comparing dates
bool operator<(const Date& lhs, const Date& rhs) {
  if (lhs.getYear() < rhs.getYear()) {
    return true;
  } else if (lhs.getYear() == rhs.getYear() &&
	     lhs.getMonth() < rhs.getMonth()) {
    return true;
  } else if (lhs.getYear() == rhs.getYear() &&
	     lhs.getMonth() == rhs.getMonth() &&
	     lhs.getDay() < rhs.getDay()) {
    return true;
  }

  return false;
}

// printing dates
std::ostream& operator<<(std::ostream& out, const Date& date) {
  out << date.getDay() << '/' << date.getMonth() << '/'
      << date.getYear();
  return out;
}

int main() {
  Date date1(10, 1, 2023);
  Date date2(10, 12, 2023);

  std::cout << "Date 1: " << date1 << std::endl;
  std::cout << "Date 2: " << date2 << std::endl;

  if (date1 < date2) {
    std::cout << "Date 1 is earlier than Date 2" << std::endl;
  } else {
    std::cout << "Date 2 is earlier than Date 1" << std::endl;
  }

  return 0;
}
