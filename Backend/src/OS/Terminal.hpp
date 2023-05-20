#pragma once

auto ensure_utf8_encoding_in_terminal() -> void;
auto ensure_colors_enabled_in_terminal() -> void;

// Empty implementation for non-Windows platforms.
#if !defined(WIN32) or !WIN32
inline auto ensure_utf8_encoding_in_terminal() -> void { }
inline auto ensure_colors_enabled_in_terminal() -> void { }
#endif
