#include "Repository.h"
#include "Service.h"
#include "UI.h"
#include <crtdbg.h>

int main()
{
	test_dynamic_vector();
	test_repository();
	test_service();
	{

		Repository repository{};
		Service service{ repository };
		UI ui{ service };

		ui.run();	
	}

	_CrtDumpMemoryLeaks();
	return 0;
}