//
// Created by dominik on 5/4/21.
//

#ifndef NETHERITE_PERMISSIONLIST_H
#define NETHERITE_PERMISSIONLIST_H

#include <vector>

#include "Permission.h"

namespace Netherite {
    class PermissionList {
    public:
        PermissionList(const PermissionList&& other) :_vec{other._vec} {}
        PermissionList(const std::vector<Permission*>&& other) :_vec{other} {}
        PermissionList(Permission(&& arr)[], size_t size) :_vec{arr, arr + size} {}
        PermissionList(Permission&& root) :_vec{&root} {}

        Permission& root(){
            return *_vec[0];
        }

    private:
        std::vector<Permission*> _vec;
    };
}
using NPermList = Netherite::PermissionList;

#endif //NETHERITE_PERMISSIONLIST_H