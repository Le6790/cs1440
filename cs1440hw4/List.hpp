#pragma once

#include <string>

#include "Employment.hpp"

/* implement these functions */
Employment* build_empl_list(std::string filename);

void print_every_empl(Employment *emp);

int list_length(Employment *emp);

Employment* append_lists(Employment* head, Employment* tail);
