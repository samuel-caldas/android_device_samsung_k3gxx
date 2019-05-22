/*
 * Copyright (C) 2007 The Android Open Source Project
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

#ifndef ANDROID_CUTILS_ATOMIC_H
#define ANDROID_CUTILS_ATOMIC_H

#include <stdint.h>
#include <sys/types.h>
#include <stdatomic.h>

#ifndef ANDROID_ATOMIC_INLINE
#define ANDROID_ATOMIC_INLINE static inline
#endif

ANDROID_ATOMIC_INLINE
int android_atomic_release_cas(int32_t oldvalue, int32_t newvalue,
                               volatile int32_t* addr)
{
    volatile atomic_int_least32_t* a = (volatile atomic_int_least32_t*)addr;
    return (int)(!atomic_compare_exchange_strong_explicit(
                                          a, &oldvalue, newvalue,
                                          memory_order_release,
                                          memory_order_relaxed));
}

#endif // ANDROID_CUTILS_ATOMIC_H
