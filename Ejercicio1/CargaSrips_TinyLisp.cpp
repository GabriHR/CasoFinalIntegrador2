#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct ColorConsole
{
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox
{
    void new_text() {/*...*/}
    static void set_text(const string &text) { cout << text << endl; }
};
ConsoleBox *consolebox = new ConsoleBox;

void load_script(const char* filename, bool show_script = false)
{
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error opening " << filename << endl;
        return;
    }

    string script;
    string line;
    while (getline(file, line))
    {
        script += line + "\n";
    }

    if (show_script)
    {
        cout << ColorConsole::fg_blue << ColorConsole::bg_white;
        cout << script << endl;
    }
    consolebox->new_text();
    ConsoleBox::set_text(script);
}