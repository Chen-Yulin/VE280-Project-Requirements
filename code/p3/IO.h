#ifndef ADD_IO
#define ADD_IO
#include "world_type.h"
#include <iostream>
#include <string>
using namespace std;
void print(world_t &world);
world_t read_world(const string worldDir, const string creatureDir);
instruction_t* read_instruction(const string creatureDir);
bool speciess_IsIn(species_t species[MAXSPECIES], species_t *new_species);
#endif


