// Copyright 2019 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_ANDROID_VR_UI_MODULE_DUMMY_FACTORY_H_
#define CHROME_BROWSER_ANDROID_VR_UI_MODULE_DUMMY_FACTORY_H_

#include <memory>

#include "chrome/browser/android/vr/ui_factory.h"

namespace vr {

// Like the default UI factory. But it also tries to load a dummy lib. Used to
// exercise the library loading mechanism.
class UiModuleFactory : public UiFactory {
 public:
  ~UiModuleFactory() override;

  std::unique_ptr<UiInterface> Create(
      UiBrowserInterface* browser,
      PlatformInputHandler* content_input_forwarder,
      std::unique_ptr<KeyboardDelegate> keyboard_delegate,
      std::unique_ptr<TextInputDelegate> text_input_delegate,
      std::unique_ptr<AudioDelegate> audio_delegate,
      const UiInitialState& ui_initial_state) override;

 private:
  void* ui_library_handle_ = nullptr;
};

}  // namespace vr

#endif  // CHROME_BROWSER_ANDROID_VR_UI_MODULE_DUMMY_FACTORY_H_
