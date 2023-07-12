#ifndef SRC_DATABASE_H_
#define SRC_DATABASE_H_

#define ENTITY int


//////////////////////////////////////////////////////
ENTITY *select(FILE *db, int id);
int delete(FILE *db, int id);
int insert(FILE *db, ENTITY *entity);
int update(FILE *db, int id, ENTITY *entity);
//////////////////////////////////////////////////////

#endif  // SRC_DATABASE_H_
