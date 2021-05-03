//
// Created by dominik on 2/25/21.
//

#include "Control.h"
#include <iostream>

Netherite::Control::Control()
    : Module{}, _thread{ &Control::Exec, this}
{
    _thread.disable();
}

Netherite::Control::Control(Netherite::Module &parent)
    : Module{ parent }, _thread{ &Control::Exec, this }
{
    _thread.disable();
}

void Netherite::Control::Exec() {
    for ( int i = 0; i < 10; i++ ){
        std::cout<<i<<std::endl;
        //if (i == 7) {
        //}
    }
}

void Netherite::Control::Init() {

}