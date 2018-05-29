/* inventory.h - declarations for inventory funtions in inventory.c, part of
 * the text_adventure.c game */

extern void executeGet(const char *noun);
extern void executeDrop(const char *noun);
extern void executeGive(const char *noun);
extern void executeAsk(const char *noun);
extern void executeInventory(void);

