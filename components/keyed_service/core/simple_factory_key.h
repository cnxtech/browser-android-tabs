// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_KEYED_SERVICE_CORE_SIMPLE_FACTORY_KEY_H_
#define COMPONENTS_KEYED_SERVICE_CORE_SIMPLE_FACTORY_KEY_H_

#include "base/files/file_path.h"
#include "base/macros.h"
#include "components/keyed_service/core/keyed_service_export.h"

// A key used by SimpleKeyedServiceFactory is used to associated the
// KeyedService instances. It is a way to have KeyedService without depending on
// a more complex context. It can be mixed with more heavy-weight
// KeyedServiceFactories if there is a unique mapping between the
// SimpleFactoryKey and the more complex context. This mapping is the
// responsibility of the embedder.
class KEYED_SERVICE_EXPORT SimpleFactoryKey {
 public:
  explicit SimpleFactoryKey(const base::FilePath& path);
  virtual ~SimpleFactoryKey();

  const base::FilePath& GetPath() const { return path_; }

  virtual bool IsOffTheRecord() const = 0;

 private:
  base::FilePath path_;

  DISALLOW_COPY_AND_ASSIGN(SimpleFactoryKey);
};

#endif  // COMPONENTS_KEYED_SERVICE_CORE_SIMPLE_FACTORY_KEY_H_
