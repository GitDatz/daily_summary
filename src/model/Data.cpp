#include "Data.hpp"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace model {

Data::Data()
{
    FetchCurrentDate();
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

void Data::FetchCurrentDate()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, " %A %e of %B %Y");
    mDateString = oss.str();
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
