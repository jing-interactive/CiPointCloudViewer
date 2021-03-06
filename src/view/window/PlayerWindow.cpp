//
// Created by Masayuki IZUMI on 9/29/16.
//

#include "view/window/PlayerWindow.h"

namespace view {
namespace window {

PlayerWindow::PlayerWindow(
  const std::string name,
  const int width,
  const int spacing,
  const ImGuiWindowFlags flags,
  const std::shared_ptr<io::CapturedLogManager> &captured_log_manager
)
  : Window(name, width, spacing, flags)
  , captured_log_manager_(captured_log_manager)
{}

void PlayerWindow::drawImpl() {
  ui::Separator();
  ui::Columns(3, "Player", true);
  ui::Text("serial");
  ui::NextColumn();
  ui::Text("loaded");
  ui::NextColumn();
  ui::Text("size");
  ui::NextColumn();
  ui::Separator();
  for (auto &pair : captured_log_manager_->loaders()) {
    ui::Selectable(pair.first.c_str(), false, ImGuiSelectableFlags_SpanAllColumns);
    ui::NextColumn();
    ui::Text("%s", pair.second->hasLoaded() ? "Loaded." : "Now loading...");
    ui::NextColumn();
    ui::Text("%zu / %zu", pair.second->loaded_file_count(), pair.second->total_file_count());
    ui::NextColumn();
  }
  if (captured_log_manager_->loaders().empty()) {
    ui::Text("...");
    ui::NextColumn();
    ui::Text("NO LOGS");
    ui::NextColumn();
    ui::Text("%d / %d", 0, 0);
    ui::NextColumn();
  }
  ui::Separator();
  drawSpacer();
  {
    auto state = captured_log_manager_->state();

    if (state == io::CapturedLogManager::State::LOADED) {
      if (ui::Button("Start")) {
        captured_log_manager_->start();
      }
    }

    if (state == io::CapturedLogManager::State::PLAYING) {
      if (ui::Button("Stop")) {
        captured_log_manager_->stop();
      }
    }
  }
}

}
}
