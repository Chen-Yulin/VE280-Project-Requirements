#include "program.h"
#include "world_type.h"

static point_t get_ahead_block_point(const creature_t *creature,const grid_t *grid){
    int loca_r = creature->location.r;
    int loca_c = creature->location.c;
    switch (creature->direction) {
    case NORTH: loca_r--; break;
    case SOUTH: loca_r++; break;
    case EAST: loca_c++; break;
    case WEST: loca_c--; break;
    default: cout<<"ERROR: direction wrong"<<endl; break;
    }
    point_t point;
    point.c = loca_c;
    point.r = loca_r;
    return point;
}

static creature_t* get_ahead_block(const creature_t *creature,const grid_t *grid){
    int loca_r = creature->location.r;
    int loca_c = creature->location.c;
    switch (creature->direction) {
    case NORTH: loca_r--; break;
    case SOUTH: loca_r++; break;
    case EAST: loca_c++; break;
    case WEST: loca_c--; break;
    default: cout<<"ERROR: direction wrong"<<endl; break;
    }
    return grid->squares[loca_r][loca_c];
}

bool ifempty(const creature_t *creature1, const grid_t *grid){
    creature_t *creature2 = get_ahead_block(creature1, grid);
    if (creature2==NULL) {
        return true;
    }else{
        return false;
    }
}

bool ifwall(const creature_t *creature1, const grid_t* grid){
    point_t next_point = get_ahead_block_point(creature1, grid);
    if(next_point.c >= 0 && next_point.c < grid->width && next_point.r >= 0 && next_point.r < grid->height){
        return false;
    }else {
        return true;
    }
}

bool ifenemy(const creature_t *creature1, const grid_t *grid){
    if (ifempty(creature1, grid)||ifwall(creature1, grid)){
        return false;
    }
    creature_t *creature2 = get_ahead_block(creature1, grid);
    if (creature1->species->name == creature2->species->name) {
        return false;
    }else{
        return true;
    }
}

bool ifsame(const creature_t *creature1, const grid_t *grid){
    if (ifempty(creature1, grid)){
        return false;
    }
    creature_t *creature2 = get_ahead_block(creature1, grid);
    if (creature1->species->name == creature2->species->name) {
        return true;
    }else{
        return false;
    }
}

void hop(creature_t *creature, grid_t *grid){
    if (ifempty(creature, grid) && !ifwall(creature, grid)){
        int pre_r = creature->location.r;
        int pre_c = creature->location.c;
        point_t point;
        point = get_ahead_block_point(creature, grid);
        creature->location = point;
        grid->squares[point.r][point.c] = creature;
        grid->squares[pre_r][pre_c] = nullptr;
    }
    return;
}

void left(creature_t *creature){
    switch (creature->direction) {
    case NORTH: creature->direction = WEST; break;
    case WEST: creature->direction = SOUTH; break;
    case SOUTH: creature->direction = EAST; break;
    case EAST: creature->direction = NORTH; break;
    }
    return;
}

void right(creature_t *creature){
    switch (creature->direction) {
    case NORTH: creature->direction = EAST; break;
    case WEST: creature->direction = NORTH; break;
    case SOUTH: creature->direction = WEST; break;
    case EAST: creature->direction = SOUTH; break;
    }
    return;
}

void infect(const creature_t *creature1, grid_t *grid){
    if (ifempty(creature1, grid) || ifwall(creature1, grid) || ifsame(creature1, grid)){
        return;
    }
    creature_t *creature2 = get_ahead_block(creature1, grid);
    creature2->species = creature1->species;
    creature2->programID = 1;
}

void go(creature_t *creature){
    creature->programID = creature->species->program[creature->programID-1].address;
    return;
}


