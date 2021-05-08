#include "ui.h"
#include <crtdbg.h>

int main()
{
	// Tests will pass only after everything has been implemented according to specifications.
	tests_dynamic_container();


	Repository* repository = create_repository();
	Repository_of_dynamic_containers* operations_stack = create_stack();
	Service* controller = create_service(repository, operations_stack);


	add_file_service(controller, 11, "Wolf 1061 c", "terrestrial", 13);
	add_file_service(controller, 12, "HAT-P-26b", "Neptune-like", 450);
	add_file_service(controller, 13, "Proxima Centauri b", "terrestrial", 4);
	add_file_service(controller, 14, "K2-1b", "super-Earth", 1116);
	//add_file_service(controller, 15, "K28b", "sper-Earth", 1115);
	//add_file_service(controller, 16, "K18b", "suer-Earth", 1113);
	//add_file_service(controller, 17, "-18b", "supr-Earth", 11);
	//add_file_service(controller, 18, "K-18b", "supe-Earth", 1);

	UI* ui = create_ui(controller);
	
	start_ui(ui);

	destroy_ui(ui);

	return 0;
}