#include <cstddef>
struct Hud // sizeof=0x1
{

};
struct Player // sizeof=0x2C0
{
    char pad_000[52];
    float Speed;
    char pad_038[536];
    float StartPositionX;
    float StartPositionY;
    char pad_258[96];
    float Player_Pos_X;
    float Player_Pos_Y;
};

struct Render // sizeof=0x4B8
{
    char pad0[68];
    std::byte bIsFOVLocked;
    char pad1[59];
    struct RendererBackend *pRenderer;
    char pad2[16];
    struct Camera *pCamera;
    char pad3[1024];
    int ViewportX;
    int ViewportWidth;
    float process_FOV;
    char pad4[4];
    float FOV;
    char pad_end[4];
};

struct Camera // sizeof=0x1
{
};
struct RendererBackend // sizeof=0x1
{
};
struct UISettingWidget;
struct OptionsUIController // sizeof=0x248
{
    void *pBasePanelContext;
    char pad_base[96];
    UISettingWidget *pOptionsContext;
    char pad_070[56];
    UISettingWidget *pShowCornerMap_Widget;
    UISettingWidget *pAutoRecenterMap_Widget;
    UISettingWidget *pAlwaysShowSockets;
    UISettingWidget *pAlwaysAttackInPlace;
    UISettingWidget *pAttackInPlaceStopsMove;
    UISettingWidget *pShowFullGroundDescs;
    UISettingWidget *pShowLifeLevels;
    UISettingWidget *pHideReservationLevels;
    UISettingWidget *pShowFlaskBuffs;
    UISettingWidget *pShowAuraIcons;
    UISettingWidget *pShowGlobalChat;
    UISettingWidget *pShowTradeChat;
    UISettingWidget *pShowGuildChat;
    UISettingWidget *pShowChatTimestamps;
    UISettingWidget *pScreenShakeV2;
    UISettingWidget *pUnknownVtable848;
     char pad_128[8];
     UISettingWidget *pCameraZRotation;
     UISettingWidget *pMinimapGeometryAlpha;
     UISettingWidget *pMinimapWalkAlpha;
     UISettingWidget *pMinimapZoom;
     UISettingWidget *pShowAllyMiniLifeBars;
     UISettingWidget *pShowEnemyMiniLifeBars;
     UISettingWidget *pShowPlayerMiniLifeBar;
     UISettingWidget *pShowAllyNamesOnMap;
     UISettingWidget *pMapOverlayModsHidden;
     char pad_178[16];
     UISettingWidget *pShowClock;
     UISettingWidget *pHideRemoveOnlyTabs;
     UISettingWidget *pOutputDialogueToChat;
     UISettingWidget *pQuestTracking;
     UISettingWidget *pAddSupportGemPopup1;
     UISettingWidget *pAddSupportGemPopup2;
     UISettingWidget *pChatBoxFontSize;
     UISettingWidget *pAlwaysHighlight;
     UISettingWidget *pAlwaysHighlightGamepad;
     UISettingWidget *pLanguageDropdown;
     UISettingWidget *pChatLangDropdown;
     UISettingWidget *pEnableProfanityFilter;
     UISettingWidget *pReduceUIAnimations;
     void *pCursorManager;
     UISettingWidget *pCursorHoverImage;
     UISettingWidget *pCursorPressedImage;
     char pad_208[8];
     UISettingWidget *pConfineMouseToWindow;
     UISettingWidget *pAlwaysHighlight2;
    UISettingWidget *pMouseWheelZoom;
    UISettingWidget *pHideEmail;
     UISettingWidget *pUnknownSetting1;
    char pad_238[8];
     UISettingWidget *pShowResistanceIcons;
};
