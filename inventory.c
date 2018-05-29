/* inventory.c - inventory commands for the text_adventure.c game */

#include <stdio.h>
#include "object.h"
#include "misc.h"


/* moveObject function - moves the location of an object when its given valid
 * paramiters, if not gives an error message */
static void moveObject(const char *noun, OBJECT *from, OBJECT *to)
{
  OBJECT *obj = parseObject(noun);
  /* if there is no object matching the input text */
  if (obj == NULL) { 
    printf("I don't understand what item you mean.\n");
  }
  /* if the object exists but isn't in your current location */
  else if (from != obj->location) {
    printf("You can't.\n");
  }
  /* if the reciptient of the object doesn't exist */
  else if (to == NULL) {
    printf("There is nobody here to give that to.\n");
  }
  /* all other cases put the object where asked */
  else {
    obj->location = to;
    printf("OK.\n");
  }
}

/* executeGet function - calls the moveObject function passing the players
 * location and the player as paramiters */
void executeGet(const char *noun)
{
  moveObject(noun, player->location, player);
}

/* executeDrop function - calls the moveObject function passing the player and
 * the players location as paramiters */
void executeDrop(const char *noun)
{
  moveObject(noun, player, player->location);
}

void executeGive(const char *noun)
{
  moveObject(noun, player, personHere());
}

void executeAsk(const char *noun)
{
  moveObject(noun, personHere(), player);
}

void executeInventory(void)
{
  if (listObjectsAtLocation(player) == 0) {
    printf("Your pack is empty.\n");
  }
}
