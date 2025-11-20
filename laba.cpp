/***************************
* Автор: Дорошкевич Матвей *
* ПИ-251                   *
***************************/
#include <iostream>
#include <iomanip>

using namespace std;

// Проверка високосного года
bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Получить количество дней в месяце
int getDaysInMonth(int month, int year) {
  if (month == 2) {
    return isLeapYear(year) ? 29 : 28;
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    return 30;
  }
  return 31;
}

// Получить день недели для 1 числа месяца
int getFirstDayOfMonth(int month, int year) {
  if (month < 3) {
    month += 12;
    year--;
  }
  int lastTwoDigits = year % 100;
  int century = year / 100;
  int dayOfWeek = (1 + 13 * (month + 1) / 5 + lastTwoDigits + lastTwoDigits / 4 + century / 4 + 5 * century) % 7;
  return (dayOfWeek + 5) % 7;
}

// Названия месяцев
string getMonthName(int month) {
  string monthNames[] = {
    "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь",
    "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"
  };
  return monthNames[month - 1];
}

// Вывод календаря на месяц
void printMonthCalendar(int month, int year) {
  cout << endl;
  cout << setw(20) << getMonthName(month) << " " << year << endl;
  cout << " Пн  Вт  Ср  Чт  Пт  Сб  Вс" << endl;
  
  int firstDay = getFirstDayOfMonth(month, year);
  int daysInMonth = getDaysInMonth(month, year);
  
  // Пробелы перед первым днем
  for (int spaceCounter = 0; spaceCounter < firstDay; spaceCounter++) {
    cout << "    ";
  }
  
  // Вывод дней месяца
  for (int currentDay = 1; currentDay <= daysInMonth; currentDay++) {
    cout << setw(3) << currentDay << " ";
    // Переход на новую строку в воскресенье
    if ((firstDay + currentDay) % 7 == 0) {
      cout << endl;
    }
  }
  cout << endl;
}

int main() {
  int selectedYear;
  
  cout << "Введите год: ";
  cin >> selectedYear;
  
  cout << endl;
  cout << "КАЛЕНДАРЬ НА " << selectedYear << " ГОД" << endl;
  cout << "====================" << endl;
  
  // Вывод всех месяцев года
  for (int currentMonth = 1; currentMonth <= 12; currentMonth++) {
    printMonthCalendar(currentMonth, selectedYear);
  }
  
  return 0;
}
