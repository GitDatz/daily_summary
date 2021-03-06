#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "../model/Data.hpp"

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace controller {

class Controller
{
public:
    Controller(std::unique_ptr<model::Data>);
    void AddTask(const std::string);
    void DeleteTask(const int);
    const std::string GetDateString();
    std::vector<std::string>& GetTaskVector();
    void SaveToFile();
private:
    std::unique_ptr<model::Data> mData;
};

}

#endif
