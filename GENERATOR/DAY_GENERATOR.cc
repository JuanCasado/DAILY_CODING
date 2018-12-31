#include <fstream>

#include "DAY_GENERATOR.hpp"

void DayGenerator::newDay(void) {
    if (_day_num!=0){
        std::string folder_name = "/Users/mr.blissfulgrin/Documents/ME/DAILY_CODING/DAY" + std::to_string(_day_num);
        std::string content ;

        std::cout << folder_name << std::endl;
        mkdir(folder_name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

        std::ofstream main_readme;
        main_readme.open("/Users/mr.blissfulgrin/Documents/ME/DAILY_CODING/README.md", std::ios::in | std::ios::out | std::ios::app);
        if (main_readme.is_open()) {
            main_readme << "\n* **DAY" + std::to_string(_day_num) + "**: ";
            main_readme << _description << std::endl;
        } else {
            std::cout << "ERROR OPENING README.md (main) FILE" << std::endl;
        }
        main_readme.close();

        std::ofstream new_readme;
        new_readme.open(folder_name + "/README.md", std::ios::in | std::ios::out | std::ios::app);
        if (new_readme.is_open()) {
            new_readme << _description << std::endl;
        } else {
            std::cout << "ERROR OPENING README.md (new) FILE" << std::endl;
        }
        new_readme.close();

        std::ofstream new_main;
        new_main.open(folder_name + "/main.cc",
                      std::ios::in | std::ios::out | std::ios::app);
        if (new_main.is_open()) {
          new_main << "#include \"" + _name + ".hpp\"\n\n"
                        "int main(int argc, char const *argv[]) "
                        "{\n\treturn 0;\n}"
                   << std::endl;
        } else {
          std::cout << "ERROR OPENING main.cc FILE" << std::endl;
        }
        new_main.close();

        std::ofstream new_make;
        new_make.open(folder_name + "/Makefile",
                      std::ios::in | std::ios::out | std::ios::app);
        if (new_make.is_open()) {
          new_make << "CC=g++\nCFLAGS = -std=c++2a -g -Wall\nTARGET = "+_name+"\n\n"+
                        "all : $(TARGET)\n\n"
                        "$(TARGET):.$(TARGET).o .main.o\n"
                        "\t$(CC) $(CFLAGS) $^ -o $@\n"
                        ".$(TARGET).o : $(TARGET).cc $(TARGET).hpp\n"
                        "\t$(CC) $(CFLAGS) -c $< -o $@\n"
                        ".main.o : main.cc $(TARGET).hpp\n"
                        "\t$(CC) $(CFLAGS) -c $< -o $@\n\n"
                        ".PHONY : clean\nclean:\n"
                        "\trm -f $(TARGET) *.o *.gch .*.o .*.gch\n"
                        << std::endl;
        } else {
          std::cout << "ERROR OPENING main.cc FILE" << std::endl;
        }
        new_make.close();

        std::ofstream newcc;
        newcc.open(folder_name + "/"+_name+".cc",
                   std::ios::in | std::ios::out | std::ios::app);
        if (newcc.is_open()) {
          newcc << "#include \"" + _name << ".hpp\"" << std::endl;
        } else {
          std::cout << "ERROR OPENING main.cc FILE" << std::endl;
        }
        newcc.close();

        std::ofstream newhpp;
        newcc.open(folder_name + "/" + _name + ".hpp",
                   std::ios::in | std::ios::out | std::ios::app);
        if (newcc.is_open()) {
          newcc << "#ifndef " + _name +"_HPP\n"
                    "#define " + _name + "_HPP\n\n\n"
                    "#endif"
                << std::endl;
        } else {
          std::cout << "ERROR OPENING main.cc FILE" << std::endl;
        }
        newcc.close();

        std::string cd = "cd "+folder_name + ";";
        std::string make = cd + "make ";
        std::string add = cd + "git add " + "*";
        std::string commit = cd + "git commit -m \"DAY" + std::to_string(+_day_num) + "::" + _name + " : " + _description + "\"";
        std::string push = cd + "git push";
        std::string sublime = "sublime "+folder_name;

        system(add.c_str());
        system(commit.c_str());
        system(push);
        system(sublime.c_str());
        system(make.c_str());
    }
}

void DayGenerator::setNum(void) {
  std::fstream last_day;
  last_day.open("/Users/mr.blissfulgrin/Documents/ME/DAILY_CODING/GENERATOR/.last_day", std::ios::in | std::ios::out);
  if (last_day.is_open()) {
    last_day.seekg(std::ios::beg);
    last_day.seekp(std::ios::beg);
    std::string content;
    last_day >> content;
    _day_num = std::atoi(content.c_str());
    last_day.seekp(std::ios::beg);
    last_day << _day_num + 1;
    }else{
        std::cout << "ERROR OPENING .last_day FILE" << std::endl;
    }
    last_day.close();
}
