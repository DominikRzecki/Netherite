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

        explicit Permission(std::string id);
        explicit Permission(const char id[]);
        explicit Permission(std::string id, Netherite::Permission &parent);
        explicit Permission(const char id[], Netherite::Permission &parent);

        inline bool operator==(Netherite::Permission& other) {
            return (this == &other);
        }

        inline bool operator>=(Netherite::Permission& other) {
            return (is_greater_than(other) || *this == other);
        }

        inline bool operator<=(Netherite::Permission& other) {
            return (is_lower_than(other) || *this == other);
        }

        inline bool operator==(const char other[]) {
            return (this->_id == other);
        }

        inline bool is_greater_than (Permission &other) {
            return other.is_lower_than(*this);
        }

        bool is_lower_than (Permission &other) {
            Permission* currentParent = this;
            while( *currentParent != other ) {
                if(currentParent != Permission::invalid){
                    currentParent = &currentParent->parent();
                } else {
                    return false;
                }
            }
            return true;
        }

        Permission& operator()(const char child_id[]) {
            for (auto &i : children) {
                if(*i == child_id) {
                    return *i;
                }
            }
            return *this;
        }

        const std::string &id = _id;

    private:

        std::string _id;
    };
}

using NPerm = Netherite::Permission;

#endif //NETHERITE_PERMISSION_H
