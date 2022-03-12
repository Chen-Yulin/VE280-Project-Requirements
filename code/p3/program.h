#ifndef ADD_P
#define ADD_P
#include "world_type.h"
#include <iostream>
using namespace std;

bool ifenemy(const creature_t*, const grid_t*);//the former creature is the source one
bool ifsame(const creature_t*, const grid_t*);
bool ifempty(const creature_t*, const grid_t*);
bool ifwall(const creature_t*, const grid_t *);

void go(creature_t*);
void left(creature_t*);
void right(creature_t*);
void hop(creature_t*, grid_t*);
void infect(const creature_t*, grid_t*);
bool speciess_IsIn(species_t species[MAXSPECIES], species_t *new_species);

#endif
