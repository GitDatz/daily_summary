#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <vector>

namespace model {

class Data
{
public:
    Data(const std::string _dateString);
    void AddTask(const std::string _task);
    void DeleteTask(const int _index);
    const std::string GetDateString();
    std::vector<std::string>& GetTaskVector();
    void SaveToFile();
private:
    void ReadFromFile();
    const std::string FILE_PATH = "../tasks.txt";
    std::string mDateString;
    std::vector<std::string> mTaskVector;
};

}

#endif
