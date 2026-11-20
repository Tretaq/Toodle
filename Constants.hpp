#pragma once

namespace cfg {
    inline constexpr float kWindowWidth = 480.f;
    inline constexpr float kWindowHeight = 800.f;
    inline constexpr float kGravity = 2000.f;
    inline constexpr float kJumpSpeed = 1000.f;
    constexpr float kJumpHight = kJumpSpeed * kJumpSpeed / (2.f * kGravity);
    constexpr float kMoveSpeed = 1000.f;
}