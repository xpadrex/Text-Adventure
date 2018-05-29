/* object.c - struct with the object struct for player, location and items,
 * part of the text_adventure.c game */

#include <stdio.h>
#include "object.h"

OBJECT objs[] = {
  {"an open field", "field", NULL},
  {"a little cave", "cave", NULL},
  {"a silver coin", "silver", field},
  {"a gold coin", "gold", cave},
  {"a burly guard", "guard", field},
  {"yourself", "yourself", field}
};
