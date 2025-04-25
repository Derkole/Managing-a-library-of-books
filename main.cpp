#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Book 
{
    std::string title;      // Название
    std::string author;     // Автор
    int year;               // Год 
};

std::vector<Book> books;  // Глобальный вектор книг

void menu()
{
    std::cout << "Меню:\n";
    std::cout << "1. Добавить книгу\n";
    std::cout << "2. Найти книгу по автору\n";
    std::cout << "3. Найти книгу по году издания\n";
    std::cout << "4. Показать все книги\n";
    std::cout << "5. Средний год издания\n";
    std::cout << "6. Выход\n";
}

void add_a_book() // 1
{
    Book new_book;                               // Новая книга

    std::cout << "Введите название книги: ";     // Вывод cout 
    std::cin.ignore();                           // Очистка буфера перед getline()
    std::getline(std::cin, new_book.title);      // Ввод getline названия книги

    std::cout << "Введите автора книги: ";       // Вывод cout 
    std::cin.ignore();                           // Очистка буфера перед getline()
    std::getline(std::cin, new_book.author);     // Ввод getline автора книги

    std::cout << "Введите год издания: ";        // Вывод cout
    std::cin >> new_book.year;                   // Сохраняем в поле year

    books.push_back(new_book);                   // Добавляем книгу в vector books
    std::cout << "Книга успешно добавлена!\n";
}

void find_by_author() // 2
{
    if (books.empty()) {std::cout << "Список книг пуст!\n"; return;}

    std::cout << "Введите имя автора для поиска: ";
    std::cin.ignore();
    std::string search_author;
    std::getline(std::cin, search_author);

    bool found{false};
    std::cout << "Найденные книги автора " << search_author << ":\n";

    for (const Book& book : books) 
    {
        if (book.author == search_author) 
        {std::cout << "- " << book.title << " (" << book.year << ")\n"; found = true;}
    }

    if (!found) {std::cout << "Книги данного автора не найдены.\n";}
    std::cout << "\n";
}

void search_by_year() // 3
{
    if (books.empty()) {std::cout << "Список книг пуст!\n"; return;}

    std::cout << "Введите год издания для поиска: ";
    int search_year;
    std::cin >> search_year;
    std::cin.ignore();

    bool found{false};
    std::cout << "Найденные книги " << search_year << " года:\n";

    for (const Book& book : books) 
    {
        if (book.year == search_year) 
        {std::cout << "- " << book.title << " (" << book.year << ")\n"; found = true;}
    }

    if (!found) {std::cout << "Книги данного автора не найдены.\n";}
    std::cout << "\n";
}

void all_books() // 4
{
    if (books.empty()) {std::cout << "Список книг пуст!\n"; return;}

    std::cout << "Список всех книг:\n";

    for (const Book& book : books) 
    {
        std::cout << "- " << book.title << " (Автор: " << book.author << ", Год: " << book.year << ")\n";
    }
    
    std::cout << "\n";
}

void average_year_books() // 5
{
    if (books.empty()) {std::cout << "Список книг пуст!\n\n"; return;}

    int sum_years = 0;
    
    // Суммируем все года
    for (const Book& book : books) {sum_years += book.year;}

    // Вычисляем среднее
    double average = static_cast<double>(sum_years) / books.size();

    // Выводим результат
    std::cout << "Средний год издания: " << std::fixed << std::setprecision(0) << average << "\n\n";
}

void exiting_the_program() // 6
{
    std::cout << "Выход из программы...\n";
}

int main()
{
    int choice{0};

    while (choice != 6)
    {
        menu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            add_a_book();
            break;
        case 2:
            find_by_author();
            break;
        case 3:
            search_by_year();
            break;
        case 4:
            all_books();
            break;
        case 5:
        average_year_books();
            break;
        case 6:
            exiting_the_program();
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}
