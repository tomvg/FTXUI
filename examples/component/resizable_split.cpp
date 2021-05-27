#include "ftxui/component/component.hpp"           // for Slider
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

using namespace ftxui;

int main(int argc, const char* argv[]) {
  auto screen = ScreenInteractive::Fullscreen();

  auto middle = Renderer([] { return text(L"middle") | center; });
  auto left = Renderer([] { return text(L"Left") | center; });
  auto right = Renderer([] { return text(L"right") | center; });
  auto top = Renderer([] { return text(L"top") | center; });
  auto bottom = Renderer([] { return text(L"bottom") | center; });

  int left_size = 20;
  int right_size = 20;
  int top_size = 10;
  int bottom_size = 10;

  auto container = middle;
  container = ResizableSplit::Left(left, container, &left_size);
  container = ResizableSplit::Right(right, container, &right_size);
  container = ResizableSplit::Top(top, container, &top_size);
  container = ResizableSplit::Bottom(bottom, container, &bottom_size);

  auto renderer =
      Renderer(container, [&] { return container->Render() | border; });

  screen.Loop(renderer);
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.