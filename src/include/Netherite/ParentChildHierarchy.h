//
// Created by dominik on 4/23/21.
//

#ifndef NETHERITE_PARENTCHILDHIERARCHY_H
#define NETHERITE_PARENTCHILDHIERARCHY_H

#include <vector>
#include <exception>
#include <cassert>



namespace Netherite {
    template<class T>
    class ParentChildHierarchy {
    public:
        ParentChildHierarchy() = default;

        explicit ParentChildHierarchy(T &parent) {
            this->attach(parent);
        }

        inline T &parent() const {
            return *_parent;
        }

        inline void attach(T &parent) {
            _parent = &parent;
            _parent->_children.push_back(static_cast<T*>(this));
        }

        inline void detach() {
            _parent->_children.erase(_parent->_children.begin() + _parent->index_of(*this));
            _parent = nullptr;
        }

        T &child_at( const size_t index = 0 ) const {
            if ( index < _children.size() ) {
                return *_children.at(index);
            } else {
                assert(( __FUNCTION__ + "index out of Range", 0));
            }
        }

        ssize_t index_of(T &child) const {
            for (ssize_t i = _children.size() - 1; i >= 0; i--) {
                if (&child == _children[i]) return i ;
            }
            return -1;
        }

        const std::vector<T *>& children{_children};

    protected:

        ~ParentChildHierarchy() {
            for (auto &i : _children) {
                delete i;
            }
            if (_parent) {
                _parent->_children.erase(_parent->_children.begin() + _parent->index_of(static_cast<T&>(*this)) );
            }
        }

    private:
        T *_parent{};
        std::vector<T *> _children;
    };
}

template<class T>
using NParentChildHierarchy = Netherite::ParentChildHierarchy<T>;

#endif //NETHERITE_PARENTCHILDHIERARCHY_H
