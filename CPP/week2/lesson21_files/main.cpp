// Lesson 21 - Saving to and reading from a file
// Goal: keep data after the program ends.

#include <fstream>
#include <iostream>
#include <string>

int main()
{
    // 1) Write two lines to a file.
    std::ofstream out("marks.txt");
    out << "Sam 88\n";
    out << "Mia 95\n";
    out.close();

    // 2) Read them back and print them.
    std::ifstream in("marks.txt");
    std::string name;
    int mark;

    while (in >> name >> mark)
    {
        std::cout << name << " scored " << mark << "\n";
    }

    std::cout << "Data was saved in marks.txt\n";
    return 0;
}

// Try it:
//   1. Add a third student to the file.
//   2. Open marks.txt in a text editor to see what was written.
//   3. Run the program twice: the file is rewritten each time.
