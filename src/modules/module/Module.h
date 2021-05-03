//
// Created by dominik on 2/24/21.
//

#ifndef NETHERITE_MODULE_H
#define NETHERITE_MODULE_H

#include <vector>
#include <exception>
#include <memory>
#include <cassert>

#include "Netherite/ParentChildHierarchy.h"

namespace Netherite {
class Module :public Netherite::ParentChildHierarchy<Module> {
    public:

        Module();
        Module(Module &parent);

        static Module Invalid;

    private:
    };
}

using NModule = Netherite::Module;

#endif //NETHERITE_MODULE_H
