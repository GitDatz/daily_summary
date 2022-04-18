#include "controller/Controller.hpp"
#include "view/View.hpp"

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include <ctime>
#include <functional>
#include <iomanip>
#include <string>
#include <sstream>

const std::string get_current_date_string()
{
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, " %A %e of %B %Y");
    return oss.str();
}

int main() {
    auto data = std::make_unique<model::Data>(get_current_date_string());
    auto controller = new controller::Controller(std::move(data));
    
    std::function<void(const std::string)> add_task_func =
        [&] (const std::string task_to_add) { controller->AddTask(task_to_add); };

    std::function<void(const int)> delete_task_func =
        [&] (const int index) { controller->DeleteTask(index); };

    std::function<void()> save_to_file_func =
        [&] () { controller->SaveToFile(); };

    auto view = new view::View(add_task_func,
                               delete_task_func,
                               save_to_file_func,
                               controller->GetDateString(),
                               controller->GetTaskVector());

    return 0;
}
