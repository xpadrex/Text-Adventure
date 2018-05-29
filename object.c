/* object.c - struct with the object struct for player, location and items,
 * part of the text_adventure.c game */

#include <stdio.h>
#include "object.h"

OBJECT objs[] = {
  {"an open field", "field", NULL, NULL},
  {"a little cave", "cave", NULL, NULL},
  {"a silver coin", "silver", field, NULL},
  {"a gold coin", "gold", cave, NULL},
  {"a burly guard", "guard", field, NULL},
  {"yourself", "yourself", field, NULL},
  {"a cave entrance", "entrance", field, cave},
  {"a way out", "out", cave, field}
};
