#include <isl/set.h>

#undef EL
#define EL isl_basic_set

#include <isl_list_templ.h>

#undef EL
#define EL isl_set

#include <isl_list_templ.h>

#undef BASE
#define BASE basic_set

#include <isl_list_templ.c>

#undef BASE
#define BASE set

#include <isl_list_templ.c>
