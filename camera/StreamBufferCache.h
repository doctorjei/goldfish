/*
 * Copyright (C) 2023 The Android Open Source Project
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

#pragma once

#include <stdint.h>
#include <map>

#include <aidl/android/hardware/camera/device/StreamBuffer.h>

#include "CachedStreamBuffer.h"
#include "StreamInfoCache.h"

namespace android {
namespace hardware {
namespace camera {
namespace provider {
namespace implementation {

using aidl::android::hardware::camera::device::StreamBuffer;

struct StreamBufferCache {
    StreamBufferCache() = default;
    CachedStreamBuffer* update(const StreamBuffer& sb, const StreamInfoCache& sic);
    void remove(int64_t bufferId);

private:
    // std::map is to keep iterators valid after `insert`
    std::map<int64_t, CachedStreamBuffer> mCache;

    StreamBufferCache(const StreamBufferCache&) = delete;
    StreamBufferCache& operator=(const StreamBufferCache&) = delete;
    StreamBufferCache(StreamBufferCache&&) = delete;
    StreamBufferCache& operator=(StreamBufferCache&&) = delete;
};

}  // namespace implementation
}  // namespace provider
}  // namespace camera
}  // namespace hardware
}  // namespace android
