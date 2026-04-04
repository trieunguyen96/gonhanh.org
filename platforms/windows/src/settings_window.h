#pragma once
#include <windows.h>
#include <commctrl.h>
#include <vector>

namespace gonhanh {

class SettingsWindow {
public:
    static SettingsWindow& Instance();
    void Show();
    void Hide();
    bool IsVisible() const { return visible_; }

private:
    SettingsWindow() = default;
    ~SettingsWindow();
    SettingsWindow(const SettingsWindow&) = delete;
    SettingsWindow& operator=(const SettingsWindow&) = delete;

    void Create();
    void CreateControls();
    void LoadSettings();
    void SaveSettings();

    // Painting
    void PaintSidebar(HDC hdc);
    void PaintContent(HDC hdc);

    static INT_PTR CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    HWND hwnd_ = nullptr;
    bool visible_ = false;

    // Custom painted section 2 position and click area
    RECT shortcutsRowRect_ = {};

    // Scrolling (content area only)
    int scrollPos_ = 0;
    int contentHeight_ = 0;
    std::vector<HWND> contentControls_;  // Controls to scroll
    void UpdateScrollInfo();
    void ScrollContent(int newPos);

};

} // namespace gonhanh
