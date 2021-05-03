//
// Created by dominik on 2/24/21.
//

#ifndef NETHERITE_CORE_H
#define NETHERITE_CORE_H

#include "../module/Module.h"
#include "../thread/Thread.h"
#include "../control/Control.h"

namespace Netherite {
class Core : public Netherite::Module {
    public:

    Core();

    ~Core();

    void Init();

    void Exec();

    private:

        Netherite::Control _module_ctl;

    };
}

using NCore = Netherite::Core;

#endif //NETHERITE_CORE_H