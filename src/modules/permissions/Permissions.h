//
// Created by dominik on 5/10/21.
//

#ifndef NETHERITE_PERMISSIONS_H
#define NETHERITE_PERMISSIONS_H

#include "Permission.h"
#include "PermissionList.h"

namespace Netherite {
    class Permissions {
        Permissions() :_list{ Permission("root") } {}

        void register_permission(Permission &perm) {

        }

        inline PermissionList& operator()() {
            return _list;
        }
    private:
        PermissionList _list;
    };
}

using NPerms =  Netherite::Permissions;

#endif //NETHERITE_PERMISSIONS_H
