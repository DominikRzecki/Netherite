//
// Created by dominik on 2/24/21.
//

#ifndef NETHERITE_MODULE_H
#define NETHERITE_MODULE_H

#include <vector>
#include <exception>
#include <memory>
#include <cassert>

namespace Netherite {
    class Module {
    public:

        Module();
        Module(Module &parent);

        ~Module();

        inline Module &parent() {
            return *_parent;
        }

        inline void attach(Module &parent) {
            _parent = &parent;
            _parent->_children.push_back(this);
        }

        inline void detach() {
            _parent->_children.erase(_parent->_children.begin() + _parent->index_of(*this) );
            _parent = nullptr;
        }

        Module &child_at(size_t index = 0);
        size_t index_of(Module &child);

        static Module Invalid;

    private:
        Module *_parent{};

        std::vector<Module *> _children;

    };
}

using NModule = Netherite::Module;

#endif //NETHERITE_MODULE_H
