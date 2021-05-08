#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "test_file.h"
#include "test_repositorry.h"
#include "test_controller.h"

void general_test()
{
	test_file_complete();
	test_repository_complete();
	test_controller_complete();
}

int main()
{
	ui();
	//general_test();
	return 0;
}