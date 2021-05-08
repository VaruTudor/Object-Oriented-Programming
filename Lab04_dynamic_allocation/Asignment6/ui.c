#include "UI.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define max_tokens 8

UI* create_ui(Service* service)
{
	if (service == NULL)
		return NULL;

	UI* ui = (UI*)malloc(sizeof(UI));
	ui->service = service;

	return ui;
}


void UI_customGetLine(char* userInput) {
	char currentCharacter;
	int currentIndex = 0;
	while (1) {
		scanf("%c", &currentCharacter);
		if (currentCharacter == '\n') {
			break;
		}
		userInput[currentIndex++] = currentCharacter;
	}
	userInput[currentIndex] = 0;
}

void destroy_ui(UI* ui)
{
	// first destroy the Service
	destroy_service(ui->service);

	// free the UI memory
	free(ui);
}

void start_ui(UI* ui)
{
	char input_line[50];
	char* input_line_tokens[max_tokens];
	int index;

	while (1)
	{
		UI_customGetLine(input_line);

		if (strcmp(input_line, "exit") == 0)
		{
			//destroyService(ui->serv);
			break;
		}

		int current_token_index = 0;
		char* current_token = strtok(input_line, ", ");

		while (current_token != NULL)
		{
			input_line_tokens[current_token_index++] = current_token;
			current_token = strtok(NULL, " ,");
		}

		if (strcmp(input_line_tokens[0], "add") == 0)
		{
			add_file_service(ui->service, atoi(input_line_tokens[1]), input_line_tokens[2], input_line_tokens[3], atoi(input_line_tokens[4]));
		}
		else if (strcmp(input_line_tokens[0], "undo") == 0)
		{
			undo(ui->service);
		}
		else if (strcmp(input_line_tokens[0], "redo") == 0)
		{
			redo(ui->service);
		}
		else if (strcmp(input_line_tokens[0], "list") == 0)
		{
			if (current_token_index == 1)
				for (index = 0; index < get_repository_lenght(ui->service->repository); index++)
					printf("%d, %s, %s, %d\n", get_archive_catalogue_number(get_repository_file_at_position(ui->service->repository, index)), get_state_of_deterioration(get_repository_file_at_position(ui->service->repository, index)),
						get_file_type(get_repository_file_at_position(ui->service->repository, index)), get_year_of_creation(get_repository_file_at_position(ui->service->repository, index)));
			else
			{
				Repository* list_of_files = filter_by_year_of_creation(ui->service, atoi(input_line_tokens[1]));
				for (index = 0; index < list_of_files->Files->length; index++)
				{
					printf("%d, %s, %s, %d\n", get_archive_catalogue_number(list_of_files->Files->elements[index]), get_state_of_deterioration(list_of_files->Files->elements[index]),
						get_file_type(list_of_files->Files->elements[index]), get_year_of_creation(list_of_files->Files->elements[index]));
				}
			}
		}
		else if (strcmp(input_line_tokens[0], "delete") == 0)
		{
			delete_file_service(ui->service, atoi(input_line_tokens[1]));
		}
		else if (strcmp(input_line_tokens[0], "update") == 0)
		{
			update_file_service(ui->service, atoi(input_line_tokens[1]), input_line_tokens[2], input_line_tokens[3], atoi(input_line_tokens[4]));
		}
		else
			printf("Unknown command!!!\n");
	}
}