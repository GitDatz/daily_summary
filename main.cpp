#include <iostream>
#include <string>
#include <vector>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

int main() {
    std::string task_str;
    auto screen = ScreenInteractive::TerminalOutput();
 
    Component task_input = Input(&task_str, "Task");

    auto header_component = Renderer([&] {
        return vbox({
                text(" Daily Summary"),
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
