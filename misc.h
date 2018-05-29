/* misc.h - header file for misc.c, part of text_adventure.c game */

extern OBJECT *getPassageTo(OBJECT *targetLocation);
extern OBJECT *parseObject(const char *noun);
extern OBJECT *personHere(void);
extern int listObjectsAtLocation(OBJECT *location);

