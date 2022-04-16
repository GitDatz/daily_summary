#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <vector>

namespace model {

class Data
{
public:
    Data();
    void AddTask(const std::string);
    void DeleteTask(const int);
    const std::string GetDateString();
    std::vector<std::string>& GetTaskVector();
    void SaveToFile();
private:
    void FetchCurrentDate();
    void ReadFromFile();
    const std::string FILE_PATH = "../tasks.txt";
    std::string mDateString;
    std::vector<std::string> mTaskVector;
};

}

#endif
