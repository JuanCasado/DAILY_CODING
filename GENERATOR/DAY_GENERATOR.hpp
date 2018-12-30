#ifndef DAY_GENERATOR_HPP
#define DAY_GENERATOR_HPP

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <sstream>
#include <stdio.h>

class DayGenerator {
public:
 DayGenerator(const std::string &name, const std::string &description): _name{name}, _description{description} {
   setNum();
 };
 void newDay(void);
 int getDayNum(void) { return _day_num; }
private:
 void setNum (void);
 std::string _name;
 std::string _description;
 int _day_num = 0;
};

#endif