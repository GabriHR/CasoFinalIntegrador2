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
    void set_text(const string &text) { cout << text << endl; }
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
    consolebox->set_text(script);
}

void load_script()
{
    string filename;
    cout << "Archivo: ";
    cin >> filename;
    load_script(filename.c_str(), true);
}

int main() {
    try {
        load_script();
    } catch (const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
    return 0;
}