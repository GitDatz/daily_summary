#include "Controller.hpp"

#include <fstream>
#include <iostream>

namespace controller {

Controller::Controller(std::unique_ptr<model::Data> _data)
: mData(std::move(_data))
{
}

void Controller::AddTask(const std::string _task)
{
    mData->AddTask(_task);
}

void Controller::DeleteTask(const int _index)
{
    mData->DeleteTask(_index);
}

const std::string Controller::GetDateString()
{
    return mData->GetDateString();
}

std::vector<std::string>& Controller::GetTaskVector()
{
    return mData->GetTaskVector();
}

void Controller::SaveToFile()
{
    mData->SaveToFile();
}

}
