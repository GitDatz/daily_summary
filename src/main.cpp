#include "controller/Controller.hpp"
#include "view/View.hpp"

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include <functional>
#include <string>

int main() {
    auto data = new model::Data();
    auto controller = new controller::Controller(*data);
    
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
