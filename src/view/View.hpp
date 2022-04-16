#ifndef VIEW_HPP
#define VIEW_HPP

#include <functional>

namespace view {

class View
{
public:
    View(const std::function<void(const std::string)>& _onAddTaskFunc,
         const std::function<void(const int)>& _onDeleteTaskFunc,
         const std::function<void()>& _onSaveFileFunc,
         const std::string _dateString,
         const std::vector<std::string>& _taskVector);
};

}

#endif
