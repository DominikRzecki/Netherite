//
// Created by dominik on 2/25/21.
//

#ifndef NETHERITE_CONTROL_H
#define NETHERITE_CONTROL_H

#include "../thread/Thread.h"
#include "../module/Module.h"

namespace Netherite {
    class Control : public Netherite::Module {
    public:
        Control();

        explicit Control(Netherite::Module &parent);

        void Init();

        void Exec();

    private:

        Netherite::Thread _thread;
    };
}
#endif //NETHERITE_CONTROL_H