/* location.c - location code for the text_adventure.c game */

#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"
#include "location.h"

/* executeLook() function - looks around in the current location or towards a
 * new location */
void executeLook(const char *noun)
{
  if (noun != NULL && strcmp(noun, "around") == 0) {
    printf("You are in %s.\n", player->location->description);
    listObjectsAtLocation(player->location);
  }
  else {
    printf("I don't understand what you want to see.\n");
  }
}

/* executeGo() function - moves to another location */
void executeGo(const char *noun)
{
  OBJECT *obj = parseObject(noun);

  if (obj == NULL) {
    printf("I don't understand where you want to go.\n");
  }
  else if (obj == player->location) {
    printf("You are already there.\n");
  }
  /* go <location> */
  else if (getPassageTo(obj) != NULL) {
    printf("OK.\n");
    player->location = obj;
    executeLook("around");
  }
  /* go <passage> */
  else if (obj->location == player->location && obj->destination != NULL) {
    printf("OK.\n");
    player->location = obj->destination;
    executeLook("around");
  }
  else {
    printf("You can't go there!\n");
  }
}
