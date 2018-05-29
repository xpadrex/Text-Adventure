/* misc.c - helper functions for text_adventure.c */

#include <stdio.h>
#include <string.h>
#include "object.h"
#include "misc.h"

/* getPassageTo function - scans through all objects untill we encounter a
 * passage from player->location to targetLocation */
OBJECT *getPassageTo(OBJECT *targetLocation)
{
  OBJECT *obj;
  /* scan through all objects until we find a passage running from
   * player->location to targetLocation */
  for (obj = objs; obj < endOfObjs; obj++) {
    if (obj->location == player->location && obj->destination ==
        targetLocation) {
      return obj;         // return a pointer to the passage object
    }
  }
  return NULL;            // return NULL if no passage exists
}

OBJECT *parseObject(const char *noun)
{
  OBJECT *obj, *found = NULL;
  for (obj = objs; obj < endOfObjs; obj++) {
    if (noun != NULL && strcmp(noun, obj->tag) == 0) {
      found = obj;
    }
  }
  return found;
}

/* personHere function returns a pointer to the person at the same location as
 * the player, or NULL if the player is alone */
OBJECT *personHere(void)
{
  OBJECT *obj;
  for (obj = objs; obj < endOfObjs; obj++)
  {
    if (obj->location == player->location && obj == guard) {
      return obj;
    }
  }
  return NULL;
}

int listObjectsAtLocation(OBJECT *location)
{
  int count = 0;
  OBJECT *obj;
  for (obj = objs; obj < endOfObjs; obj++) {
    if (obj != player && obj->location == location) {
      if (count++ == 0) {
        printf("You see:\n");
      }

      printf("%s\n", obj->description);
    }
  }

  return count;
}
