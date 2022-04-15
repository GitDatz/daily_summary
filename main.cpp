#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>

const std::string FILE_PATH = "../tasks.txt";

const std::string get_current_date_string() {
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, " %A %e of %B %Y");
    return oss.str();
}

const std::vector<std::string> get_task_vector() {
    std::vector<std::string> string_vector;
    std::ifstream file(FILE_PATH);
    if (file) {
        for ( std::string line; std::getline(file, line); ) {
            string_vector.push_back(line);
        }
    }
    return string_vector;
}

int main() {
    using namespace ftxui;

    std::string task_str;
    auto task_vector = get_task_vector();
    int selected_task = 0;

    auto screen = ScreenInteractive::TerminalOutput();
 
    Component task_input = Input(&task_str, "Task");

    auto header_component = Renderer([&] {
        return vbox({
                text(" Daily Summary") | bold,
                text(get_current_date_string()),
                separatorLight(),
            });
    });

    auto input_component = Renderer(task_input, [&] {
        return hbox(text(" Task : "), task_input->Render()) | border;
    });

    auto buttons_container = Container::Horizontal({
        Button(" Add Task ", [&] { task_vector.push_back(task_str); task_str = ""; }, ButtonOption::Simple()),
        Button(" Quit ", screen.ExitLoopClosure(), ButtonOption::Simple()),
    });

    MenuOption option;
    option.on_enter = [&] { task_vector.erase(task_vector.begin() + selected_task); };
    auto menu = Menu(&task_vector, &selected_task, &option) | border;

    screen.Loop(Container::Vertical({
        header_component,
        menu,
        input_component,
        buttons_container
    }) | borderDouble );
    
    return 0;
}
