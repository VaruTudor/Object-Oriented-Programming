#pragma once
#include "service.h"

typedef struct
{
	Service* service;
} UI;

UI* create_ui(Service* service);

void destroy_ui(UI* ui);

void start_ui(UI* ui);