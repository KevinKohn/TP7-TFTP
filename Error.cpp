#include "Error.h"
#include <cstdio>

Error :: Error(unsigned int code) : errorCode(code) { type = EV_ERROR; }


