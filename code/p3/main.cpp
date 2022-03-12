#include "IO.h"
#include "program.h"
#include "world_type.h"
#include <fstream>

int main(int argc, char *argv[])
{
    //string worldDir = argv[1];
    //string creatureDir = argv[2];
    world_t world = read_world("./tests/world-tests/outside-world", "./tests/creatures/");
    print(world);
    for(int loop_num = 1; loop_num < 20; loop_num++){
        cout<<"the "<<loop_num<<" simulation"<<endl;
        for (int creature_index = 0; creature_index < world.numCreatures; creature_index++) {
            int turn_over = 0;
            while (!turn_over){
                switch (world.creatures[creature_index].species->program[world.creatures[creature_index].programID-1].op) {
                    case IFEMPTY:
                        if (ifempty(&world.creatures[creature_index], &world.grid)) {
                            go(&world.creatures[creature_index]);
                        }else{
                            world.creatures[creature_index].programID++;
                        }
                        break;
                    case IFSAME:
                        if (ifsame(&world.creatures[creature_index], &world.grid)) {
                            go(&world.creatures[creature_index]);
                        }else{
                            world.creatures[creature_index].programID++;
                        }
                        break;
                    case IFWALL:
                        if (ifwall(&world.creatures[creature_index], &world.grid)) {
                            go(&world.creatures[creature_index]);
                        }else{
                            world.creatures[creature_index].programID++;
                        }
                        break;
                    case IFENEMY:
                        if (ifenemy(&world.creatures[creature_index], &world.grid)) {
                            go(&world.creatures[creature_index]);
                        }else{
                            world.creatures[creature_index].programID++;
                        }
                        break;
                    case GO:
                        go(&world.creatures[creature_index]);
                        break;
                    case HOP:
                        hop(&world.creatures[creature_index], &world.grid);
                        world.creatures[creature_index].programID++;
                        turn_over = 1;
                        break;
                    case INFECT:
                        infect(&world.creatures[creature_index], &world.grid);
                        world.creatures[creature_index].programID++;
                        turn_over = 1;
                        break;
                    case LEFT:
                        left(&world.creatures[creature_index]);
                        world.creatures[creature_index].programID++;
                        turn_over = 1;
                        break;
                    case RIGHT:
                        right(&world.creatures[creature_index]);
                        world.creatures[creature_index].programID++;
                        turn_over = 1;
                        break;
                }
            }
            if(world.creatures[creature_index].location.r >= world.grid.height ||
               world.creatures[creature_index].location.r < 0 ||
               world.creatures[creature_index].location.c >= world.grid.width ||
               world.creatures[creature_index].location.r < 0){
                cout<<"someone is out of bound"<<endl;
                return 1;
            }
        }
        print(world);
    }
    return 0;
}
