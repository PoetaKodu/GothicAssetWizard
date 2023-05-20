#include "Terminal.hpp"

#include <Windows.h>

auto ensure_utf8_encoding_in_terminal() -> void
{
  SetConsoleCP(CP_UTF8);
  SetConsoleOutputCP(CP_UTF8);
}

auto ensure_colors_enabled_in_terminal() -> void
{
  auto const output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  if (output_handle == INVALID_HANDLE_VALUE) {
    return;
  }

  DWORD mode;
  if (!GetConsoleMode(output_handle, &mode)) {
    return;
  }

  mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(output_handle, mode);
}