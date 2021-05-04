//
// Created by dominik on 5/3/21.
//

#include "Permission.h"

Netherite::Permission::Permission(std::string id, Permission& parent)
:Netherite::ParentChildHierarchy<Permission>(parent) {

}

Netherite::Permission::Permission(const char *id, Permission& parent)
:Netherite::ParentChildHierarchy<Permission>(parent) {

}
