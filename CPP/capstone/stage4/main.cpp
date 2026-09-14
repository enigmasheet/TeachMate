// Capstone - Stage 4: A generic, modern gradebook
// ===============================================
// The final layer ties the whole course together:
//   - templates        : Repository<T> works for any type
//   - classes          : Student and Gradebook
//   - algorithms/lambda: top() finds the best student
//   - optional         : find() may return "no student"
//   - exceptions       : save()/load() report problems safely
//   - <iomanip>        : tidy output
//
// Menu:
//   1) Add  2) List  3) Average  4) Top  5) Find  6) Save  7) Load  8) Quit

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

// A container that can store a list of any type T.
template <typename T>
class Repository
{
private:
    std::vector<T> items;

public:
    void add(const T &item)
    {
        items.push_back(item);
    }

    int size() const
    {
        return static_cast<int>(items.size());
    }

    bool empty() const
    {
        return items.empty();
    }

    const std::vector<T> &all() const
    {
        return items;
    }

    void clear()
    {
        items.clear();
    }
};

class Student
{
private:
    std::string name;
    int mark;

public:
    Student(std::string n, int m)
    {
        name = n;
        mark = m;
        if (mark < 0)
            mark = 0;
        if (mark > 100)
            mark = 100;
    }

    std::string getName() const
    {
        return name;
    }

    int getMark() const
    {
        return mark;
    }
};

class Gradebook
{
private:
    Repository<Student> students;

public:
    void add(const Student &s)
    {
        students.add(s);
    }

    int count() const
    {
        return students.size();
    }

    void list() const
    {
        if (students.empty())
        {
            std::cout << "No students yet.\n";
            return;
        }

        for (const Student &s : students.all())
        {
            std::cout << std::left << std::setw(10) << s.getName()
                      << std::right << s.getMark() << "\n";
        }
    }

    double average() const
    {
        if (students.empty())
            return 0.0;

        int total = 0;
        for (const Student &s : students.all())
            total = total + s.getMark();

        double size = students.size();
        return total / size;
    }

    // Uses an algorithm plus a lambda to find the best student.
    std::optional<Student> top() const
    {
        if (students.empty())
            return std::nullopt;

        const std::vector<Student> &all = students.all();
        auto best = std::max_element(all.begin(), all.end(),
                                     [](const Student &a, const Student &b)
                                     { return a.getMark() < b.getMark(); });

        return *best;
    }

    std::optional<Student> find(const std::string &name) const
    {
        for (const Student &s : students.all())
            if (s.getName() == name)
                return s;

        return std::nullopt;
    }

    void save() const
    {
        std::ofstream out("students.txt");
        if (!out)
            throw std::runtime_error("Could not open students.txt for writing");

        for (const Student &s : students.all())
            out << s.getName() << " " << s.getMark() << "\n";

        std::cout << "Saved " << students.size() << " student(s).\n";
    }

    void load()
    {
        std::ifstream in("students.txt");
        if (!in)
            throw std::runtime_error("No saved file found (students.txt)");

        students.clear();
        std::string name;
        int mark = 0;
        while (in >> name >> mark)
            students.add(Student(name, mark));

        std::cout << "Loaded " << students.size() << " student(s).\n";
    }
};

int main()
{
    Gradebook book;
    bool running = true;

    while (running)
    {
        std::cout << "\n1) Add  2) List  3) Average  4) Top"
                     "  5) Find  6) Save  7) Load  8) Quit\n";
        std::cout << "Choice: ";

        int choice = 0;
        std::cin >> choice;

        try
        {
            if (choice == 1)
            {
                std::string name;
                int mark = 0;
                std::cout << "Name: ";
                std::cin >> name;
                std::cout << "Mark: ";
                std::cin >> mark;
                book.add(Student(name, mark));
            }
            else if (choice == 2)
                book.list();
            else if (choice == 3)
                std::cout << std::fixed << std::setprecision(2)
                          << "Average: " << book.average() << "\n";
            else if (choice == 4)
            {
                std::optional<Student> best = book.top();
                if (best.has_value())
                    std::cout << "Top: " << best->getName()
                              << " (" << best->getMark() << ")\n";
                else
                    std::cout << "No students yet.\n";
            }
            else if (choice == 5)
            {
                std::string name;
                std::cout << "Name to find: ";
                std::cin >> name;

                std::optional<Student> found = book.find(name);
                if (found.has_value())
                    std::cout << found->getName() << " scored "
                              << found->getMark() << "\n";
                else
                    std::cout << "Not found.\n";
            }
            else if (choice == 6)
                book.save();
            else if (choice == 7)
                book.load();
            else if (choice == 8)
                running = false;
            else
                std::cout << "Please choose 1-8.\n";
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "Goodbye!\n";

    // Repository is generic, so it also works for other types:
    //   Repository<std::string> tags;
    //   tags.add("senior");
    return 0;
}

// Try it:
//   1. Add a menu option that lists only passes (mark >= 60).
//   2. Try loading before saving to see the exception message.
//   3. Add a Repository<std::string> for tags and print each tag.
