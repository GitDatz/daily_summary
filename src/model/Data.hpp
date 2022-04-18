#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <vector>

namespace model {

class Data
{
public:
    Data();
    Data(const std::string _dateString);
    virtual ~Data();
    virtual void AddTask(const std::string _task);
    virtual void DeleteTask(const int _index);
    virtual const std::string GetDateString();
    virtual std::vector<std::string>& GetTaskVector();
    virtual void SaveToFile();
private:
    void ReadFromFile();
    const std::string FILE_PATH = "../tasks.txt";
    std::string mDateString;
    std::vector<std::string> mTaskVector;
};

}

#endif
