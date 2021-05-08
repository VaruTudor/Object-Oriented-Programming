#include "DynamicVector.h"
#include "Repository.h"
#include "Service.h"
#include "UI.h"

#include <crtdbg.h>

int main()
{
	test_DynamicVector();
	test_repository();
	test_service();
	{

		Repository repository{};
		Repository assistant_repository{};
		Service service{ repository,assistant_repository };
		UI ui{ service };

		ui.run();
	}

	_CrtDumpMemoryLeaks();
	return 0;
}