#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_tokens 8

int ui()
{
	Repository repository = create_repository();
	Controller controller = create_controller(repository);

	char input_line[50];
	char* input_line_tokens[max_tokens];
	int index;
	//File files_data[30] = get_files_data(&controller);


	while (1)
	{
		gets(input_line);

		if (strcmp(input_line, "exit") == 0) break;

		int current_token_index = 0;
		char* current_token = strtok(input_line, ", ");

		while (current_token != NULL)
		{
			input_line_tokens[current_token_index++] = current_token;
			current_token = strtok(NULL, " ,");
		}

		if (strcmp(input_line_tokens[0], "add") == 0)
		{
			add_file_controller(&controller, atoi(input_line_tokens[1]), input_line_tokens[2], input_line_tokens[3], atoi(input_line_tokens[4]));
		}
		else if (strcmp(input_line_tokens[0], "delete") == 0)
		{
			delete_file_controller(&controller, atoi(input_line_tokens[1]));
		}
		else if (strcmp(input_line_tokens[0], "update") == 0)
		{
			update_file_controller(&controller, atoi(input_line_tokens[1]), input_line_tokens[2], input_line_tokens[3], atoi(input_line_tokens[4]));
		}
		else if (strcmp(input_line_tokens[0], "list") == 0)
		{
			if (current_token_index == 1)
				for (index = 0; index < get_files_lenght(&controller); index++)//&controller.repository.Files[index]
					printf("%d, %s, %s, %d\n", get_archive_catalogue_number(get_file_from_data(&controller, index)), get_state_of_deterioration(&controller.repository.Files[index]),
						get_file_type(&controller.repository.Files[index]), get_year_of_creation(&controller.repository.Files[index]));
			else
				for (index = 0; index < get_files_lenght(&controller); index++)
				{
					if (strcmp(get_file_type(&controller.repository.Files[index]), input_line_tokens[1]) == 0)
						printf("%d, %s, %s, %d\n", get_archive_catalogue_number(&controller.repository.Files[index]), get_state_of_deterioration(&controller.repository.Files[index]),
							get_file_type(&controller.repository.Files[index]), get_year_of_creation(&controller.repository.Files[index]));

				}
		}
	}

	return 0;
}
	

