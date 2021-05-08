#include "test_controller.h"
#include "controller.h"
#include "domain.h"
#include "repository.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_controller_add()
{
	Repository repository = create_repository();
	Controller controller = create_controller(repository);
	assert(controller.repository.lenght_of_repository == 0);

	add_file_controller(&controller, 124, "acd", "dfg", 477);
	add_file_controller(&controller, 126, "acf", "gfg", 478);
	assert(controller.repository.lenght_of_repository == 2);

	add_file_controller(&controller, 126, "acf", "gfg", 478);
	assert(controller.repository.lenght_of_repository == 2);

}

void test_controller_delete()
{
	Repository repository = create_repository();
	Controller controller = create_controller(repository);
	assert(controller.repository.lenght_of_repository == 0);

	add_file_controller(&controller, 124, "acd", "dfg", 477);
	add_file_controller(&controller, 126, "acf", "gfg", 478);
	add_file_controller(&controller, 127, "af", "fg", 479);
	assert(controller.repository.lenght_of_repository == 3);

	delete_file_controller(&controller, 126);
	assert(controller.repository.lenght_of_repository == 2);
}

void test_controller_update()
{
	Repository repository = create_repository();
	Controller controller = create_controller(repository);
	assert(controller.repository.lenght_of_repository == 0);

	add_file_controller(&controller, 24, "acd", "dfg", 477);
	update_file_controller(&controller, 24, "aa", "bb", 47);
	assert(controller.repository.Files[24].year_of_creation == 47);
	assert(strcmp(controller.repository.Files[24].state_of_deterioration, "aa") == 0);
	assert(strcmp(controller.repository.Files[24].file_type, "bb") == 0);
}

void test_controller_complete()
{
	test_controller_add();
	test_controller_delete();
	test_controller_update();
}

