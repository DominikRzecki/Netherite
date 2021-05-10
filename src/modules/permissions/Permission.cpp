//
// Created by dominik on 5/3/21.
//

#include "Permission.h"

#include <utility>

Netherite::Permission::Permission(std::string id) {
    _id = std::move(id);
    if (!invalid)
        invalid = new Permission("invalid");
}

Netherite::Permission::Permission(const char *id) {
    _id = id;
    if (!invalid)
        invalid = new Permission("invalid");
}

Netherite::Permission::Permission(std::string id, Permission& parent)
:Netherite::ParentChildHierarchy<Permission>(parent) {
    _id = std::move(id);
    if (!invalid)
        invalid = new Permission("invalid");
}

Netherite::Permission::Permission(const char *id, Permission& parent)
:Netherite::ParentChildHierarchy<Permission>(parent) {
    _id = id;
    if (!invalid)
        invalid = new Permission("invalid");
}
