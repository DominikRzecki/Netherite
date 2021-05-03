//
// Created by dominik on 2/24/21.
//

#include "Module.h"

Netherite::Module::Module() = default;

Netherite::Module::Module(Module &parent)

:Netherite::ParentChildHierarchy<Module>(parent)
{
}

Netherite::Module Netherite::Module::Invalid;
