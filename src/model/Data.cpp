#include "Data.hpp"

#include <fstream>
#include <iostream>

namespace model {

Data::Data(const std::string _dateString)
: mDateString(_dateString)
{
    ReadFromFile();
}

void Data::AddTask(const std::string _task)
{
    mTaskVector.push_back(_task);
}

void Data::DeleteTask(const int _index)
{
    mTaskVector.erase(mTaskVector.begin() + _index);
}

const std::string Data::GetDateString()
{
    return mDateString;
}

std::vector<std::string>& Data::GetTaskVector()
{
    return mTaskVector;
}

void Data::ReadFromFile()
{
    std::ifstream file(FILE_PATH);
    if (file) {
        for ( std::string line; std::getline(file, line); ) {
            mTaskVector.push_back(line);
        }
    }
}

void Data::SaveToFile()
{
    std::ofstream file;
    file.open(FILE_PATH);
    for ( auto task : mTaskVector ) {
        file << task << std::endl;
    }
    file.close();
}

}
