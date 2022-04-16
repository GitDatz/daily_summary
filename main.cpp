#include "controller/Controller.hpp"

#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

#include <string>

int main() {
    auto data = new model::Data();
    auto controller = new controller::Controller(*data);

    std::string task_str;
    int selected_task = 0;

    auto screen = ftxui::ScreenInteractive::TerminalOutput();
 
    ftxui::InputOption input_option;
    input_option.on_enter = [&] { controller->AddTask(task_str); task_str = ""; };
    ftxui::Component task_input = ftxui::Input(&task_str, "Task", &input_option);

    auto header_component = ftxui::Renderer([&] {
        return ftxui::vbox({
                ftxui::text(" Daily Summary") | ftxui::bold,
                ftxui::text(controller->GetDateString()),
                ftxui::separatorLight(),
            });
    });

    auto input_component = ftxui::Renderer(task_input, [&] {
        return ftxui::hbox(ftxui::text(" Task : "), task_input->Render()) | ftxui::border;
    });

    auto buttons_container = ftxui::Container::Horizontal({
        ftxui::Button(" Save to File ", [&] { controller->SaveToFile(); }, ftxui::ButtonOption::Simple()),
        ftxui::Button(" Quit ", screen.ExitLoopClosure(), ftxui::ButtonOption::Simple()),
    });

    ftxui::MenuOption menu_option;
    menu_option.on_enter = [&] { controller->DeleteTask(selected_task); };
    auto menu = ftxui::Menu(&controller->GetTaskVector(), &selected_task, &menu_option) | ftxui::border;

    screen.Loop(ftxui::Container::Vertical({
        header_component,
        menu,
        input_component,
        buttons_container
    }) | ftxui::borderDouble );
    
    return 0;
}
