// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_UI_DEVTOOLS_VIEWS_OVERLAY_AGENT_AURA_H_
#define COMPONENTS_UI_DEVTOOLS_VIEWS_OVERLAY_AGENT_AURA_H_

#include "components/ui_devtools/views/overlay_agent_views.h"

#include "components/ui_devtools/dom_agent.h"

namespace aura {
class Env;
}

namespace ui_devtools {

class OverlayAgentAura : public OverlayAgentViews {
 public:
  OverlayAgentAura(DOMAgent* dom_agent);
  ~OverlayAgentAura() override;
  void RegisterEnv(aura::Env* env);

  int FindElementIdTargetedByPoint(ui::LocatedEvent* event) const override;
  static OverlayAgentAura* GetInstance() { return overlay_agent_aura_; }

 private:
  void InstallPreTargetHandler() override;
  void RemovePreTargetHandler() override;

  FRIEND_TEST_ALL_PREFIXES(OverlayAgentTest, HighlightWindow);
  FRIEND_TEST_ALL_PREFIXES(OverlayAgentTest, HighlightEmptyOrInvisibleWindow);
  std::vector<aura::Env*> envs_;

  static OverlayAgentAura* overlay_agent_aura_;

  DISALLOW_COPY_AND_ASSIGN(OverlayAgentAura);
};

}  // namespace ui_devtools

#endif  // COMPONENTS_UI_DEVTOOLS_VIEWS_OVERLAY_AGENT_AURA_H_
