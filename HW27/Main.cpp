#include <iostream>
#include <string>

struct Movie {
	std::string title = "Empty";
	int year = 2000;
	std::string genre = "Empty";
	unsigned int duration = 60;
	unsigned int price = 0;
};

Movie expensive(Movie arr[], const int length);
void update_info(Movie& M);
void movie_name(Movie arr[], const int length);




void print_movie(const Movie& M);

int main() {
	setlocale(0, "");
	int n;

	//Задание 1.
	std::cout << "Задание 1.\n\n";
	Movie M1;
	print_movie(M1);

	//Задание 2.
	std::cout << "Задание 2.\n\n";

	Movie M2{
		"Jhon whik",
		2010,
		"Action",
		120,
		500
	};

	Movie M3{
		"Back to the future",
		1995,
		"Fantastic",
		110,
		1100
	};

	Movie M4{
		"Elisium",
		2012,
		"Action",
		90,
		800
	};

	Movie M5{
		"Avatar",
		2011,
		"Fantastik",
		150,
		1800
	};

	const int size1 = 4;
	Movie Base[size1]{ M2, M3, M4, M5 };
	print_movie(expensive(Base, size1));

	//Задание 3.
	std::cout << "Задание 3.\n\n";
	movie_name(Base, size1);
	std::cout << "Выбирете фильм -> ";
	int num;
	std::cin >> num;
	std::cin.ignore();
	switch (num) {
	case 1:print_movie(M2);
		   update_info(M2); break;
	case 2:print_movie(M3);
		   update_info(M3); break;
	case 3:print_movie(M4);
		   update_info(M4); break;
	case 4:print_movie(M5);
		   update_info(M5); break;
	};

	

	





	return 0;
}

void print_movie(const Movie& M) {
	std::cout << "1. Название фильма: " << M.title << '\n';
	std::cout << "2. Год выхода фильма: " << M.year << '\n';
	std::cout << "3. Жанр фильма: " << M.genre << '\n';
	std::cout << "4. Продолжительность фильма: " << M.duration << "мин\n";
	std::cout << "5. Цена за диск: " << M.price << " rub\n\n";
}

Movie expensive(Movie arr[], const int length) {
	int numb = 0;
	int max = arr[0].price;
	for (int i = 0; i < length; i++)
		if (arr[i].price > max) {
			max = arr[i].price;
			numb = i;
		}
	return arr[numb];
}

void update_info(Movie& M) {
	int select = 0;
	std::cout << "Что вы хотите изменить? -> ";
	std::cin >> select;
	std::cin.ignore();
	switch (select) {
	case 1: std::cout << "Новое название -> ";
		std::getline(std::cin, M.title); break;
	case 2: std::cout << "Новая дата выхода -> ";
		std::cin >> M.year; break;
	case 3: std::cout << "Новый жанр -> ";
		std::getline(std::cin, M.genre); break;
	case 4: std::cout << "Новое время -> ";
		std::cin >> M.duration; break;
	case 5: std::cout << "Новая цена -> ";
		std::cin >> M.price; break;
	}
	std::cout << "Изменения внесены!\n";
	
}

void movie_name(Movie arr[], const int length) {
	std::cout << "Ваши фильмы:\n";
	for (int i = 0; i < length; i++)
		std::cout << i + 1 << '.' << arr[i].title << std::endl;
}