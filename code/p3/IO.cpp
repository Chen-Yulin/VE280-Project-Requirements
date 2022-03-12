#include "IO.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>

static direction_t find_direct_enum(const string str){
    direction_t direction;
    if (str == "east") {
        direction = EAST;
    }else if (str == "north") {
        direction = NORTH;
    }else if (str == "west") {
        direction = WEST;
    }else {
        direction = SOUTH;
    }
    return direction;
}

static int find_array_elt(const string op_name){
    for (int i = 0; i < 9; ++i) {
        if (op_name == opName[i]) {
            return i;
        }
    }
    cout<<"Error: op_name not found"<<endl;
    return -1;
}

static bool check_instruct_line_valid(const string line){
    if (line.length()==0){
        return false;
    }else{
        return true;
    }
}

static instruction_t read_inst_line(const string line){
    instruction_t instruction;
    string op_name;
    string step;
    int numOfSpace = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i]==' ') {
            numOfSpace++;
        }
        if (numOfSpace == 2){
            break;
        }else if (numOfSpace == 0) {
            op_name += line[i];
        }else if (numOfSpace == 1) {
            step += line[i];
        }
    }
    instruction.op = (opcode_t)find_array_elt(op_name);
    instruction.address = atoi(step.c_str());
    return instruction;
}

static void read_array(instruction_t program[MAXPROGRAM], instruction_t *program_p){
    for (int i = 0; i < MAXPROGRAM; i++) {
        program[i] = program_p[i];
    }
}

bool species_IsIn(species_t species[MAXSPECIES], species_t *new_species){
    for (int i = 0; i < MAXSPECIES; i++) {
        if (new_species->name == species[i].name){
            return true;
        }
    }
    return false;
}

instruction_t* read_instruction(const string creatureDir){
    instruction_t* instruction = new instruction_t[MAXPROGRAM];
    ifstream instruction_cfg(creatureDir);
    if (!instruction_cfg) {
        cout<<"Error: world_cfg directory wrong"<<endl;
        return instruction;
    }
    int line_num = 0;
    while(instruction_cfg){
        if (line_num>39) {
            cout<<"program number out of range"<<endl;
            break;
        }
        string line;
        getline(instruction_cfg, line);
        if (!check_instruct_line_valid(line)){
            break;
        }
        instruction[line_num] = read_inst_line(line);
        line_num++;
    }
    return instruction;
}

void print(world_t &world){
    grid_t grid_p = world.grid;
    for (int i = 0; i < grid_p.height; i++) {
        for (int j = 0; j < grid_p.width; j++) {
            if (grid_p.squares[i][j]==NULL) {
                cout<<"---- ";
            }else{
                cout<<grid_p.squares[i][j]->species->name[0]<<grid_p.squares[i][j]->species->name[1]<<'_';
                switch (grid_p.squares[i][j]->direction) {
                    case NORTH: cout<<"^ "; break;
                    case SOUTH: cout<<"v "; break;
                    case WEST: cout<<"< "; break;
                    case EAST: cout<<"> "; break;
                    default: cout<<"- "; break;
                }

            }
        }
        cout<<endl;
    }
}

world_t read_world(const string worldDir, const string creatureDir){
    world_t world;
    ifstream world_cfg(worldDir);
    if (!world_cfg) {
        cout<<"Error: world_cfg directory wrong"<<endl;
        return world;
    }
    world_cfg>>world.grid.height>>world.grid.width;//read index into grid
    
    //initialize grid.square as NULL
    for (int i = 0; i < world.grid.height; i++) {
        for (int j = 0; j < world.grid.width; j++) {
            world.grid.squares[i][j] = nullptr;
        }
    }
    //initialize num
    world.numCreatures = 0;
    world.numSpecies = 0;
    species_t myspecies[MAXCREATURES];
    creature_t single_creature[MAXCREATURES];
    while(world_cfg){
        
        string speciesName, direction;
        int location_h,location_w;
        world_cfg>>speciesName>>direction>>location_h>>location_w;//read creature info
        if (speciesName==""){
            break;
        }
        world.numCreatures++;
        single_creature[world.numCreatures-1].location.r = location_h;//give location
        single_creature[world.numCreatures-1].location.c = location_w;//give location
        single_creature[world.numCreatures-1].direction = find_direct_enum(direction);
        single_creature[world.numCreatures-1].programID = 1;
        myspecies[world.numCreatures-1].name = speciesName;//give species name 
        read_array(myspecies[world.numCreatures-1].program, read_instruction(creatureDir+speciesName));//copy the program to the creature
        single_creature[world.numCreatures-1].species = &(myspecies[world.numCreatures-1]);
        world.creatures[world.numCreatures-1] = single_creature[world.numCreatures-1];//add the new creature to the collection of creatures in the world
        
        //add creature to grid
        world.grid.squares[location_h][location_w] = &world.creatures[world.numCreatures-1];

        //add species to the collection of species in the world
        if (!species_IsIn(world.species, single_creature[world.numCreatures-1].species)){
            world.numSpecies++;
            world.species[world.numSpecies-1] = *single_creature[world.numCreatures-1].species;
        }
    }
    return world;
}






