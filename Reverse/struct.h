00000000 struct Hud // sizeof=0x1
00000000 {
00000000 };

00000000 struct Player // sizeof=0x2C0
00000000 {
00000000     char pad_000[52];
00000034     float Speed;
00000038     char pad_038[536];
00000250     float StartPositionX;
00000254     float StartPositionY;
00000258     char pad_258[96];
000002B8     float Player_Pos_X;
000002BC     float Player_Pos_Y;
000002C0 };

00000000 struct Render // sizeof=0x4B8
00000000 {
00000000     char pad0[68];
00000044     _BYTE bIsFOVLocked;
00000045     char pad1[59];
00000080     struct RendererBackend *pRenderer;
00000088     char pad2[16];
00000098     struct Camera *pCamera;
000000A0     char pad3[1024];
000004A0     int ViewportX;
000004A4     int ViewportWidth;
000004A8     float process_FOV;
000004AC     char pad4[4];
000004B0     float FOV;
000004B4     char pad_end[4];
000004B8 };

00000000 struct Camera // sizeof=0x1
00000000 {
00000000 };

00000000 struct RendererBackend // sizeof=0x1
00000000 {
00000000 };

FFFFFFFF struct UISettingWidget;

00000000 struct OptionsUIController // sizeof=0x248
00000000 {
00000000     void *pBasePanelContext;
00000008     char pad_base[96];
00000068     UISettingWidget *pOptionsContext;
00000070     char pad_070[56];
000000A8     UISettingWidget *pShowCornerMap_Widget;
000000B0     UISettingWidget *pAutoRecenterMap_Widget;
000000B8     UISettingWidget *pAlwaysShowSockets;
000000C0     UISettingWidget *pAlwaysAttackInPlace;
000000C8     UISettingWidget *pAttackInPlaceStopsMove;
000000D0     UISettingWidget *pShowFullGroundDescs;
000000D8     UISettingWidget *pShowLifeLevels;
000000E0     UISettingWidget *pHideReservationLevels;
000000E8     UISettingWidget *pShowFlaskBuffs;
000000F0     UISettingWidget *pShowAuraIcons;
000000F8     UISettingWidget *pShowGlobalChat;
00000100     UISettingWidget *pShowTradeChat;
00000108     UISettingWidget *pShowGuildChat;
00000110     UISettingWidget *pShowChatTimestamps;
00000118     UISettingWidget *pScreenShakeV2;
00000120     UISettingWidget *pUnknownVtable848;
00000128     char pad_128[8];
00000130     UISettingWidget *pCameraZRotation;
00000138     UISettingWidget *pMinimapGeometryAlpha;
00000140     UISettingWidget *pMinimapWalkAlpha;
00000148     UISettingWidget *pMinimapZoom;
00000150     UISettingWidget *pShowAllyMiniLifeBars;
00000158     UISettingWidget *pShowEnemyMiniLifeBars;
00000160     UISettingWidget *pShowPlayerMiniLifeBar;
00000168     UISettingWidget *pShowAllyNamesOnMap;
00000170     UISettingWidget *pMapOverlayModsHidden;
00000178     char pad_178[16];
00000188     UISettingWidget *pShowClock;
00000190     UISettingWidget *pHideRemoveOnlyTabs;
00000198     UISettingWidget *pOutputDialogueToChat;
000001A0     UISettingWidget *pQuestTracking;
000001A8     UISettingWidget *pAddSupportGemPopup1;
000001B0     UISettingWidget *pAddSupportGemPopup2;
000001B8     UISettingWidget *pChatBoxFontSize;
000001C0     UISettingWidget *pAlwaysHighlight;
000001C8     UISettingWidget *pAlwaysHighlightGamepad;
000001D0     UISettingWidget *pLanguageDropdown;
000001D8     UISettingWidget *pChatLangDropdown;
000001E0     UISettingWidget *pEnableProfanityFilter;
000001E8     UISettingWidget *pReduceUIAnimations;
000001F0     void *pCursorManager;
000001F8     UISettingWidget *pCursorHoverImage;
00000200     UISettingWidget *pCursorPressedImage;
00000208     char pad_208[8];
00000210     UISettingWidget *pConfineMouseToWindow;
00000218     UISettingWidget *pAlwaysHighlight2;
00000220     UISettingWidget *pMouseWheelZoom;
00000228     UISettingWidget *pHideEmail;
00000230     UISettingWidget *pUnknownSetting1;
00000238     char pad_238[8];
00000240     UISettingWidget *pShowResistanceIcons;
00000248 };
