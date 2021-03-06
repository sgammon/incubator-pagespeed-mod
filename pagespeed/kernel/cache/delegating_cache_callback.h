/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

//         morlovich@google.com (Maksim Orlovich)

#ifndef PAGESPEED_KERNEL_CACHE_DELEGATING_CACHE_CALLBACK_H_
#define PAGESPEED_KERNEL_CACHE_DELEGATING_CACHE_CALLBACK_H_

#include "pagespeed/kernel/base/basictypes.h"
#include "pagespeed/kernel/base/string.h"
#include "pagespeed/kernel/cache/cache_interface.h"

namespace net_instaweb {

// Helper class for implementing Caches that wrap other caches, adding
// functionality in callbacks.
class DelegatingCacheCallback : public CacheInterface::Callback {
 public:
  explicit DelegatingCacheCallback(CacheInterface::Callback* callback);
  ~DelegatingCacheCallback() override;

  // Note that we have to forward validity faithfully here, as if we're
  // wrapping a 2-level cache it will need to know accurately if the value
  // is valid or not.
  bool ValidateCandidate(const GoogleString& key,
                         CacheInterface::KeyState state) override;

  void Done(CacheInterface::KeyState state) override;

 private:
  CacheInterface::Callback* callback_;
  bool validate_candidate_called_;

  DISALLOW_COPY_AND_ASSIGN(DelegatingCacheCallback);
};

}  // namespace net_instaweb

#endif  // PAGESPEED_KERNEL_CACHE_DELEGATING_CACHE_CALLBACK_H_
