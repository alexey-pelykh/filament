/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "FFilamentInstance.h"

#include <gltfio/Animator.h>

#include "FFilamentAsset.h"

using namespace filament;
using namespace utils;

namespace gltfio {

const char* FFilamentInstance::getName(utils::Entity entity) const noexcept {
    return owner->getName(entity);
}

std::string FFilamentInstance::getExtras(utils::Entity entity) const noexcept {
    const auto itNode = reverseNodeMap.find(entity);
    if (itNode == reverseNodeMap.cend()) {
        return std::string();
    }
    const auto itExtras = owner->mExtras.find(reinterpret_cast<const void*>(itNode->second));
    if (itExtras == owner->mExtras.cend()) {
        return std::string();
    }
    return itExtras->second;
}

FilamentAsset* FilamentInstance::getOwner() const noexcept {
    return upcast(this)->owner;
}

size_t FilamentInstance::getEntityCount() const noexcept {
    return upcast(this)->entities.size();
}

const Entity* FilamentInstance::getEntities() const noexcept {
    const auto& entities = upcast(this)->entities;
    return entities.empty() ? nullptr : entities.data();
}

Entity FilamentInstance::getRoot() const noexcept {
    return upcast(this)->root;
}

const char* FilamentInstance::getName(utils::Entity entity) const noexcept {
    return upcast(this)->getName(entity);
}

std::string FilamentInstance::getExtras(utils::Entity entity) const noexcept {
    return upcast(this)->getExtras(entity);
}

Animator* FilamentInstance::getAnimator() noexcept {
    return upcast(this)->getAnimator();
}

} // namespace gltfio
