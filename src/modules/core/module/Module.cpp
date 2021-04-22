//
// Created by dominik on 2/24/21.
//

#include "Module.h"

Netherite::Module::Module() = default;

Netherite::Module::Module(Module &parent) {
    this->attach(parent);
}

Netherite::Module::~Module() {
    for (auto &i : _children) {
        delete i;
    }
    if (_parent) {
        _parent->_children.erase(_parent->_children.begin() + _parent->index_of(*this) );
    }
}

Netherite::Module &Netherite::Module::child_at(size_t index) {
    if ( index < _children.size() ) {
        return *_children.at(index);
    } else {
        return Module::Invalid;
    }
}

size_t Netherite::Module::index_of(Module &child) {
    for (size_t i = _children.size() - 1; i >= 0; i--) {
        if (&child == _children[i]) {
            return i;
        }
    }
    assert(("Module is not child of Module", 0));
}

Netherite::Module Netherite::Module::Invalid;
