#include "sistema.h"

int main(){
    Sistema sistema;
    while (!sistema.game_over()){
        sistema.process_events();
        sistema.update();
        sistema.render();
    }

    return 0;
}
