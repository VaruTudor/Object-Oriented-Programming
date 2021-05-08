#include "Asignment10.h"
#include <QtWidgets/QApplication>
#include "Asignment10.h"

#include <fstream>
#include <sstream>

using namespace std;

void tokenize(const std::string& string_to_split, const char delimiter, std::vector<std::string>& output)
{
	/*
		splits a given string into smaller strings which are added to a vector of strings
	*/

	std::stringstream string_to_split_stream(string_to_split);

	std::string temp;

	while (getline(string_to_split_stream, temp, delimiter))
	{
		output.push_back(temp);
	}

}

int main(int argc, char *argv[])
{
	
	
	// true if file repository is used
	// false if memory repository is used
	bool use_file_repository_admin, use_file_repository_assistant, use_csv;

	std::string file_path, mylist_path, line_from_config;

	std::ifstream config_file;
	config_file.open("config.txt", std::ios_base::app);

	std::vector<std::string> words_from_config;

	// here we read the configuration file
	while (std::getline(config_file, line_from_config))
	{
		//remove_unnecessary_spaces(line_from_config);
		std::string::iterator end_position = std::remove(line_from_config.begin(), line_from_config.end(), ' ');
		line_from_config.erase(end_position, line_from_config.end());

		//adding all words in a vector for further processing
		tokenize(line_from_config, '=', words_from_config);
	}

	// here we put the information into variables
	for (int i = 0; i < words_from_config.size(); i++)
	{
		if (words_from_config.at(i) == "file_path")
		{
			file_path = words_from_config.at(i + 1);
		}
		else if (words_from_config.at(i) == "mylist_path")
		{
			mylist_path = words_from_config.at(i + 1);
		}
		else if (words_from_config.at(i) == "use_file_repository_for_admin")
		{
			use_file_repository_admin = atoi(words_from_config.at(i + 1).c_str());
		}
		else if (words_from_config.at(i) == "use_file_repository_for_assistant")
		{
			use_file_repository_assistant = atoi(words_from_config.at(i + 1).c_str());
		}
		else if (words_from_config.at(i) == "use_csv")
		{
			use_csv = atoi(words_from_config.at(i + 1).c_str());
		}
	}

	if (use_file_repository_admin == 0)
	{
		if (use_file_repository_assistant == 0)
		{
			QApplication app(argc, argv);

			Repository* repository = new MemoryRepository{};
			Repository* assistant_repository = new MemoryRepository{};
			Service service{ repository,assistant_repository };

			Asignment10 gui{ service };

			gui.show();

			return app.exec();
		}
		else if (use_file_repository_assistant == 1 && use_csv == 1)
		{
			QApplication app(argc, argv);

			Repository* repository = new MemoryRepository{};
			Repository* assistant_repository{};
			Service service{ repository,assistant_repository };

			service.set_mylist_csv_file_path(mylist_path);
			
			Asignment10 gui{ service };

			gui.show();

			return app.exec();
		}
		else
		{
			QApplication app(argc, argv);

			Repository* repository = new MemoryRepository{};
			Repository* assistant_repository{};
			Service service{ repository,assistant_repository };

			service.set_mylist_html_file_path(mylist_path);

			Asignment10 gui{ service };

			gui.show();

			return app.exec();
		}
	}
	else
	{
		if (use_file_repository_assistant == 0)
		{
			QApplication app(argc, argv);

			Repository* repository = new FileRepository{ file_path };
			Repository* assistant_repository = new MemoryRepository{};
			Service service{ repository,assistant_repository };

			Asignment10 gui{ service };

			gui.show();

			return app.exec();
		}
		else if (use_file_repository_assistant == 1 && use_csv == 1)
		{
			QApplication app(argc, argv);

			Repository* repository = new FileRepository{ file_path };
			Repository* assistant_repository;;
			Service service{ repository,assistant_repository };


			service.set_mylist_csv_file_path(mylist_path);

			Asignment10 gui{ service };

			gui.show();

			return app.exec();
		}
		else
		{
			QApplication app(argc, argv);

			Repository* repository = new FileRepository{ file_path };
			Repository* assistant_repository{};
			Service service{ repository,assistant_repository };

			service.set_mylist_html_file_path(mylist_path);

			Asignment10 gui{ service };

			gui.show();

			return app.exec();
		}
	}
	
}
