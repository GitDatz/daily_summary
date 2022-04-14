#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

const std::string get_current_date_string() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, " %A %e of %B %Y");
    return oss.str();
}

int main() {
    using namespace ftxui;

    std::string task_str;
    auto screen = ScreenInteractive::TerminalOutput();
 
    Component task_input = Input(&task_str, "Task");

    auto header_component = Renderer([&] {
        return vbox({
                text(" Daily Summary") | bold,
                text(get_current_date_string()),
                separator(),
            });
    });

    auto input_component = Renderer(task_input, [&] {
        return hbox(text(" Task : "), task_input->Render());
    });

    auto buttons_container = Container::Horizontal({
        Button("Add Task", [&] {}),
        Button("Quit", screen.ExitLoopClosure()),
    });

    screen.Loop(Container::Vertical({
        header_component,
        input_component,
        buttons_container
    }) | border);
    
    return 0;
}
