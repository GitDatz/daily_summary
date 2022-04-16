#include "View.hpp"

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

namespace view {

View::View(
    const std::function<void(const std::string)>& _onAddTaskFunc,
    const std::function<void(const int)>& _onDeleteTaskFunc,
    const std::function<void()>& _onSaveFileFunc,
    const std::string _dateString,
    const std::vector<std::string>& _taskVector)
{
    auto screen = ftxui::ScreenInteractive::TerminalOutput();
    std::string task_str;
    int selected_task = 0;
 
    ftxui::InputOption input_option;
    input_option.on_enter = [&] { _onAddTaskFunc(task_str); task_str = ""; };
    ftxui::Component task_input = ftxui::Input(&task_str, "Task", &input_option);

    auto header_component = ftxui::Renderer([&] {
        return ftxui::vbox({
                ftxui::text(" Daily Summary") | ftxui::bold,
                ftxui::text(_dateString),
                ftxui::separatorLight(),
            });
    });

    auto input_component = ftxui::Renderer(task_input, [&] {
        return ftxui::hbox(ftxui::text(" Task : "), task_input->Render()) | ftxui::border;
    });

    auto buttons_container = ftxui::Container::Horizontal({
        ftxui::Button(" Save to File ", [&] { _onSaveFileFunc(); }, ftxui::ButtonOption::Simple()),
        ftxui::Button(" Quit ", screen.ExitLoopClosure(), ftxui::ButtonOption::Simple()),
    });

    ftxui::MenuOption menu_option;
    menu_option.on_enter = [&] { _onDeleteTaskFunc(selected_task); };
    auto menu = ftxui::Menu(&_taskVector, &selected_task, &menu_option) | ftxui::border;

    screen.Loop(ftxui::Container::Vertical({
        header_component,
        menu,
        input_component,
        buttons_container
    }) | ftxui::borderDouble );
}

}
