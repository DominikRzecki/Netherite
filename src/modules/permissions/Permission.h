//
// Created by dominik on 5/3/21.
//

#ifndef NETHERITE_PERMISSION_H
#define NETHERITE_PERMISSION_H

#include <string>
#include "Netherite/ParentChildHierarchy.h"

namespace Netherite {
    class Permission : public Netherite::ParentChildHierarchy<Permission> {
    public:
        explicit Permission(std::string id, Netherite::Permission &parent = _root);
        explicit Permission(const char id[], Netherite::Permission &parent  = _root);

        inline bool operator==(Netherite::Permission& other) {
            return (this == &other);
        }

        inline bool operator==(const char other[]) {
            return (this->_id == other);
        }

        constexpr Permission& operator()(const char child_id[]) {
            for (auto &i : children) {
                if(*i == child_id) {
                    return *i;
                }
            }
            return _root;
        }

        const std::string &id = _id;

    private:

        static Netherite::Permission _root;

        std::string _id;
    };
}

using NPerm = Netherite::Permission;

#endif //NETHERITE_PERMISSION_H
