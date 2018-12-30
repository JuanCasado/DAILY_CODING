#include "DAY_GENERATOR.hpp"

int main(int argc, char const *argv[]) {
    if (argc > 2){
        std::string name = argv[1];
        std::stringstream ss;
        for (int i = 2; i < argc; ++i){
            ss << argv[i] << " ";
        }
        DayGenerator new_day{name, ss.str()};
        new_day.newDay();
        std::cout << "New day " << new_day.getDayNum() << " generated" << std::endl;
        return 0;
    }else{
        std::cerr << "NO CONTENT PROVIDED" << std::endl;
        return 1;
    }
}
