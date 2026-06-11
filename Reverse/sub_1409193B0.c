// Hidden C++ exception states: #wind=27
__int64 __fastcall sub_1409193B0(OptionsUIController *OptionsUIController, __m128i *a2)
{
  __m128i *v2; // r12
  int v4; // r13d
  __int64 v5; // rsi
  UISettingWidget **p_pOptionsContext; // r15
  UISettingWidget *pShowCornerMap_Widget; // rdi
  void (__fastcall *setter)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 true_or_false; // al
  UISettingWidget *pAutoRecenterMap_Widget; // rdi
  void (__fastcall *v11)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v12; // al
  UISettingWidget *pMinimapGeometryAlpha; // rbx
  __m128 *v14; // rcx
  char v15; // dl
  __int64 v16; // rcx
  __int64 v17; // rcx
  int *v18; // rdx
  int v19; // ecx
  UISettingWidget *pMinimapWalkAlpha; // rbx
  __m128 *v21; // rcx
  char v22; // dl
  __int64 v23; // rcx
  __int64 v24; // rcx
  int *v25; // rdx
  int v26; // ecx
  UISettingWidget *pMinimapZoom; // rbx
  __m128 *v28; // rcx
  char v29; // dl
  __int64 v30; // rcx
  __int64 v31; // rcx
  int *v32; // rdx
  int v33; // ecx
  _QWORD *v34; // r15
  UISettingWidget *pAlwaysShowSockets; // rdi
  void (__fastcall *v36)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v37; // al
  __int64 v38; // rdx
  __int64 v39; // r8
  UISettingWidget **v40; // r9
  UISettingWidget *pAlwaysAttackInPlace; // rdi
  void (__fastcall *v42)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v43; // al
  void *v44; // r9
  UISettingWidget *pAttackInPlaceStopsMove; // rdi
  void (__fastcall *v46)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v47; // al
  __int64 v48; // rdx
  __int64 v49; // r8
  UISettingWidget **v50; // r9
  UISettingWidget *pShowAllyMiniLifeBars; // rdi
  void (__fastcall *v52)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v53; // al
  void *v54; // r9
  UISettingWidget *pShowEnemyMiniLifeBars; // rdi
  void (__fastcall *v56)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v57; // al
  __int64 v58; // rdx
  __int64 v59; // r8
  UISettingWidget **v60; // r9
  UISettingWidget *pShowPlayerMiniLifeBar; // rdi
  void (__fastcall *v62)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v63; // al
  void *v64; // r9
  UISettingWidget *pShowResistanceIcons; // rdi
  void (__fastcall *v66)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v67; // al
  __int64 v68; // rdx
  __int64 v69; // r8
  UISettingWidget **v70; // r9
  UISettingWidget *pShowAllyNamesOnMap; // rdi
  void (__fastcall *v72)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v73; // al
  void *v74; // r9
  UISettingWidget *pMapOverlayModsHidden; // rdi
  void (__fastcall *v76)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v77; // al
  _QWORD *v78; // rsi
  UISettingWidget *pShowClock; // rdi
  void (__fastcall *v80)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v81; // al
  _QWORD *v82; // r9
  __int64 v83; // rdi
  void (__fastcall *v84)(__int64, _QWORD, _QWORD); // rbx
  unsigned __int8 v85; // al
  __int64 v86; // r15
  __int64 v87; // rdx
  __int64 v88; // r8
  UISettingWidget **v89; // r9
  UISettingWidget *pHideRemoveOnlyTabs; // rdi
  void (__fastcall *v91)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v92; // al
  void *v93; // r9
  UISettingWidget *pOutputDialogueToChat; // rdi
  void (__fastcall *v95)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v96; // al
  __int64 v97; // rdx
  __int64 v98; // r8
  UISettingWidget **v99; // r9
  UISettingWidget *pQuestTracking; // rdi
  void (__fastcall *v101)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v102; // al
  void *v103; // r9
  UISettingWidget *pShowFullGroundDescs; // rdi
  void (__fastcall *v105)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v106; // al
  __int64 v107; // rdx
  __int64 v108; // r8
  UISettingWidget **v109; // r9
  UISettingWidget *pShowLifeLevels; // rdi
  void (__fastcall *v111)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v112; // al
  void *v113; // r9
  UISettingWidget *pHideReservationLevels; // rdi
  void (__fastcall *v115)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v116; // al
  __int64 v117; // rdx
  __int64 v118; // r8
  UISettingWidget **v119; // r9
  UISettingWidget *pShowFlaskBuffs; // rdi
  void (__fastcall *v121)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v122; // al
  void *v123; // r9
  UISettingWidget *pShowAuraIcons; // rdi
  void (__fastcall *v125)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v126; // al
  UISettingWidget *pUnknownVtable848; // rdi
  void (__fastcall *v128)(UISettingWidget *, _QWORD); // rbx
  int v129; // eax
  UISettingWidget *pCursorHoverImage; // rbx
  float v131; // xmm0_4
  UISettingWidget *pCursorPressedImage; // rdi
  void (__fastcall *v133)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v134; // al
  __int64 v135; // rdi
  void (__fastcall *v136)(__int64, _QWORD, _QWORD); // rbx
  unsigned __int8 v137; // al
  __int64 v138; // rax
  _QWORD *v139; // rbx
  __int64 v140; // rdi
  char *v141; // rdx
  void *pCursorManager; // rsi
  __int64 v143; // rcx
  __int64 v144; // rdx
  __int64 v145; // r8
  __int64 v146; // r9
  __int64 v147; // rdx
  __int64 v148; // rcx
  _QWORD *v149; // rax
  __int64 v150; // rax
  void *v151; // rsi
  char *v152; // rdx
  __int64 v153; // rcx
  unsigned __int64 v154; // rdx
  char *v155; // r8
  unsigned __int64 v156; // r8
  __int128 *v157; // rax
  __int64 v158; // rax
  unsigned __int64 v159; // rdx
  __int64 v160; // rcx
  char v161; // bl
  __int64 v162; // rdx
  bool v163; // si
  __int64 v164; // rbx
  __int64 v165; // rcx
  __int64 v166; // rax
  volatile signed __int32 *v167; // rbx
  __int64 v168; // rax
  __int64 v169; // rbx
  _QWORD *v170; // rcx
  __int64 v171; // rax
  __int64 v172; // rdx
  bool v173; // zf
  float *v174; // rbx
  _QWORD *v175; // rax
  __int64 v176; // rax
  __int64 v177; // rax
  __int64 v178; // rax
  int v179; // edx
  float v180; // xmm0_4
  char v181; // si
  __int64 v182; // rdx
  int v183; // r13d
  _WORD *v184; // rdx
  __int64 v185; // r8
  char v186; // si
  __int64 v187; // rdx
  _WORD *v188; // rdx
  __int64 v189; // rax
  __int64 v190; // rsi
  __int128 *v191; // rax
  __int64 v192; // rdi
  __int64 v193; // rcx
  const wchar_t *v194; // rdx
  _WORD *v195; // r8
  unsigned __int64 v196; // rcx
  unsigned __int64 v197; // rdx
  __int64 v198; // rax
  unsigned __int64 v199; // rdx
  unsigned __int64 v200; // rax
  __int64 v201; // rcx
  UISettingWidget *pScreenShakeV2; // rdi
  void (__fastcall *v203)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD); // rbx
  __int64 v204; // rax
  __int64 v205; // r9
  UISettingWidget *v206; // rdi
  void (__fastcall *v207)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD); // rbx
  __int64 v208; // rax
  __int64 v209; // r9
  UISettingWidget *v210; // rdi
  void (__fastcall *v211)(UISettingWidget *, __int64); // rbx
  __int64 v212; // rax
  unsigned __int8 v213; // al
  const wchar_t *v214; // rdx
  _WORD *v215; // r8
  __int64 v216; // rcx
  UISettingWidget *pCameraZRotation; // rdi
  void (__fastcall *v218)(UISettingWidget *, _QWORD, _QWORD); // rbx
  UISettingWidget **v219; // rsi
  unsigned __int8 v220; // al
  _WORD *v221; // rdx
  __int64 v222; // rcx
  const wchar_t *v223; // r8
  UISettingWidget *pShowGlobalChat; // rdi
  void (__fastcall *v225)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v226; // al
  _WORD *v227; // rdx
  __int64 v228; // rcx
  const wchar_t *v229; // r8
  UISettingWidget *pShowTradeChat; // rdi
  void (__fastcall *v231)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v232; // al
  _WORD *v233; // rdx
  __int64 v234; // rcx
  const wchar_t *v235; // r8
  UISettingWidget *pShowGuildChat; // rdi
  void (__fastcall *v237)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v238; // al
  _WORD *v239; // rdx
  __int64 v240; // rcx
  const wchar_t *v241; // r8
  UISettingWidget *pShowChatTimestamps; // rdi
  void (__fastcall *v243)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v244; // al
  _WORD *v245; // r8
  __int64 v246; // rcx
  const wchar_t *v247; // rdx
  UISettingWidget *pAddSupportGemPopup1; // rdi
  void (__fastcall *v249)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v250; // al
  _WORD *v251; // rdx
  __int64 v252; // rcx
  const wchar_t *v253; // r8
  UISettingWidget *pAddSupportGemPopup2; // rdi
  void (__fastcall *v255)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v256; // al
  const wchar_t *v257; // rdx
  _WORD *v258; // r8
  __int64 v259; // rcx
  unsigned __int64 j; // rsi
  UISettingWidget *pChatBoxFontSize; // rdi
  void (__fastcall *v262)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD); // rbx
  __int64 v263; // rax
  __int64 v264; // r9
  UISettingWidget *v265; // rdi
  void (__fastcall *v266)(UISettingWidget *, _QWORD); // rbx
  UISettingWidget **v267; // rsi
  int v268; // eax
  UISettingWidget *pAlwaysHighlight; // rbx
  __m128 *v270; // rcx
  char v271; // dl
  __int64 v272; // rcx
  __int64 v273; // rcx
  int *v274; // rdx
  int v275; // ecx
  UISettingWidget *pAlwaysHighlightGamepad; // rbx
  const wchar_t *v277; // r8
  __m128 *v278; // rcx
  char v279; // dl
  __int64 v280; // rcx
  __int64 v281; // rcx
  int *v282; // rdx
  int v283; // ecx
  _WORD *v284; // rdx
  __int64 v285; // rcx
  UISettingWidget *pAlwaysHighlight2; // rdi
  void (__fastcall *v287)(UISettingWidget *, _QWORD, _QWORD); // rbx
  UISettingWidget **v288; // rsi
  unsigned __int8 v289; // al
  _WORD *v290; // rdx
  __int64 v291; // rcx
  const wchar_t *v292; // r8
  UISettingWidget *pConfineMouseToWindow; // rdi
  void (__fastcall *v294)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v295; // al
  _WORD *v296; // rdx
  __int64 v297; // rcx
  const wchar_t *v298; // r8
  UISettingWidget *pMouseWheelZoom; // rdi
  void (__fastcall *v300)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v301; // al
  _WORD *v302; // rdx
  __int64 v303; // rcx
  const wchar_t *v304; // r8
  UISettingWidget *pHideEmail; // rdi
  void (__fastcall *v306)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v307; // al
  const wchar_t *v308; // rdx
  __int64 v309; // rcx
  const wchar_t *v310; // r8
  UISettingWidget *pEnableProfanityFilter; // rdi
  void (__fastcall *v312)(UISettingWidget *, _QWORD, _QWORD); // rbx
  unsigned __int8 v313; // al
  _WORD *v314; // r8
  UISettingWidget *pReduceUIAnimations; // rcx
  __int64 result; // rax
  const wchar_t *v317; // rdx
  __int64 v318; // rcx
  unsigned __int16 *v319; // r8
  __m128i v320; // xmm6
  __int64 v321; // rax
  __int64 v322; // rbx
  __int64 v323; // rdx
  _BOOL8 v324; // rcx
  __int64 v325; // r8
  unsigned int v326; // r12d
  char *v327; // rdi
  _WORD *v328; // rdx
  __int64 v329; // rcx
  __int64 v330; // rcx
  __int64 v331; // rdx
  __int64 v332; // rdx
  __int64 v333; // rcx
  __int64 v334; // r8
  unsigned int *v335; // r15
  bool v336; // r13
  char v337; // al
  UISettingWidget *pLanguageDropdown; // rsi
  void (__fastcall *v339)(UISettingWidget *, __int64, _OWORD *, bool, _DWORD); // rdi
  __int64 v340; // rax
  __int64 v341; // rdx
  char v342; // di
  __int64 v343; // rdx
  const wchar_t *v344; // rdx
  __int64 v345; // rcx
  unsigned __int16 *v346; // r8
  __m128i v347; // xmm6
  __int64 v348; // rax
  __int64 v349; // rbx
  UISettingWidget *pChatLangDropdown; // rsi
  void (__fastcall *v351)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD); // rdi
  __int64 v352; // rax
  __int64 v353; // r9
  __int64 v354; // rdx
  _BOOL8 v355; // rcx
  __int64 v356; // r8
  unsigned int v357; // r12d
  __m128i *v358; // rdi
  __int64 v359; // rcx
  __int64 v360; // rdx
  __int64 v361; // rdx
  __int64 v362; // rcx
  __int64 v363; // r8
  unsigned int *v364; // r15
  bool v365; // r13
  char v366; // al
  UISettingWidget *v367; // rsi
  void (__fastcall *v368)(UISettingWidget *, __int64, _OWORD *, bool, _DWORD); // rdi
  __int64 v369; // rax
  __int64 v370; // rdx
  __int64 v371; // rdx
  __int64 v372; // rcx
  __int64 v373; // r8
  int v374; // r15d
  __int64 v375; // rdx
  __int64 v376; // rcx
  __int64 v377; // r8
  _DWORD *v378; // rdi
  __int64 v379; // rdx
  __int64 v380; // rcx
  __int64 v381; // r8
  _DWORD *m; // rsi
  char v383; // r13
  __int64 *v384; // rax
  __int64 v385; // rdi
  char v386; // r13
  char v387; // si
  __int64 v388; // rdx
  __m128i v389; // [rsp+48h] [rbp-C0h] BYREF
  int v390; // [rsp+58h] [rbp-B0h]
  __m128i v391; // [rsp+68h] [rbp-A0h] BYREF
  __m128i v392; // [rsp+78h] [rbp-90h] BYREF
  __m128 v393; // [rsp+88h] [rbp-80h] BYREF
  unsigned __int64 v394; // [rsp+98h] [rbp-70h]
  __int32 v395; // [rsp+A0h] [rbp-68h]
  __m128i v396; // [rsp+A8h] [rbp-60h] BYREF
  _OWORD v397[4]; // [rsp+B8h] [rbp-50h] BYREF
  int v398; // [rsp+F8h] [rbp-10h] BYREF
  int v399; // [rsp+100h] [rbp-8h] BYREF
  int v400; // [rsp+108h] [rbp+0h] BYREF
  int v401; // [rsp+110h] [rbp+8h] BYREF
  int v402; // [rsp+118h] [rbp+10h] BYREF
  __m128 v403; // [rsp+120h] [rbp+18h] BYREF
  unsigned __int64 v404; // [rsp+130h] [rbp+28h]
  __int32 v405; // [rsp+138h] [rbp+30h]
  __int128 v406; // [rsp+140h] [rbp+38h] BYREF
  __int128 v407; // [rsp+150h] [rbp+48h]
  __int128 v408; // [rsp+160h] [rbp+58h] BYREF
  __int128 v409; // [rsp+170h] [rbp+68h]
  __int128 v410; // [rsp+180h] [rbp+78h]
  __int64 (__fastcall **v411)(); // [rsp+190h] [rbp+88h]
  char *v412; // [rsp+198h] [rbp+90h]
  __int64 v413; // [rsp+1A0h] [rbp+98h] BYREF
  __int64 v414; // [rsp+1A8h] [rbp+A0h] BYREF
  char *i; // [rsp+1B0h] [rbp+A8h]
  _BYTE v416[32]; // [rsp+1B8h] [rbp+B0h] BYREF
  _QWORD v417[2]; // [rsp+1D8h] [rbp+D0h] BYREF
  __int128 v418; // [rsp+1E8h] [rbp+E0h] BYREF
  __int128 v419; // [rsp+1F8h] [rbp+F0h]
  __m128i v420; // [rsp+208h] [rbp+100h]
  _QWORD v421[7]; // [rsp+218h] [rbp+110h] BYREF
  _QWORD *v422; // [rsp+250h] [rbp+148h]
  _QWORD v423[7]; // [rsp+258h] [rbp+150h] BYREF
  _QWORD *v424; // [rsp+290h] [rbp+188h]
  _QWORD v425[7]; // [rsp+298h] [rbp+190h] BYREF
  _QWORD *v426; // [rsp+2D0h] [rbp+1C8h]
  __m128i *k; // [rsp+350h] [rbp+248h] BYREF
  void *Src; // [rsp+358h] [rbp+250h] BYREF
  unsigned __int64 v429; // [rsp+360h] [rbp+258h] BYREF

  k = a2;
  v2 = a2;
  v4 = 0;
  v390 = 0;
  v5 = a2->m128i_i64[1];
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_corner_map"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowCornerMap_Widget = OptionsUIController->pShowCornerMap_Widget;
    setter = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowCornerMap_Widget + 0x340LL);// ?? Включить или выключить
                                                //
    true_or_false = bool_enable_disable_parser();
    setter(pShowCornerMap_Widget, true_or_false, 0);
    p_pOptionsContext = &OptionsUIController->pOptionsContext;
    v5 = v2->m128i_i64[1];
    if ( !v5 )
      goto LABEL_6;
  }
  else
  {
    p_pOptionsContext = &OptionsUIController->pOptionsContext;
  }
  v389 = *(__m128i *)string_constructor(&v392, (__int64)L"auto_recenter_map");
  v391 = *v2;
  if ( !string_compare((__int64)&v391, (__int64)&v389) )
    goto LABEL_7;
LABEL_6:
  pAutoRecenterMap_Widget = OptionsUIController->pAutoRecenterMap_Widget;
  v11 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pAutoRecenterMap_Widget + 832LL);
  v12 = sub_1417E50D0(*p_pOptionsContext);
  v11(pAutoRecenterMap_Widget, v12, 0);
  if ( v5 )
  {
LABEL_7:
    v389 = *(__m128i *)string_constructor(&v392, (__int64)L"minimap_geometry_alpha");
    v391 = *v2;
    if ( !string_compare((__int64)&v391, (__int64)&v389) )
      goto LABEL_30;
  }
  pMinimapGeometryAlpha = OptionsUIController->pMinimapGeometryAlpha;
  v398 = (int)(float)(sub_1417E51F0(*p_pOptionsContext) * 100.0);
  if ( byte_1443499CC != 2 )
    goto LABEL_23;
  v14 = *((__m128 **)pMinimapGeometryAlpha + 40);
  if ( !v14 )
  {
    v393.m128_i16[0] = 0;
    v393.m128_i8[2] = 0;
    goto LABEL_23;
  }
  v393 = v14[35];
  v394 = v14[36].m128_u64[0];
  v395 = v14[36].m128_i32[2];
  v403 = v393;
  v404 = v394;
  v405 = v395;
  if ( pMinimapGeometryAlpha != (UISettingWidget *)v14[24].m128_u64[0] )
  {
LABEL_23:
    v18 = &v398;
    if ( v398 >= *((_DWORD *)pMinimapGeometryAlpha + 205) )
      v18 = (int *)((char *)pMinimapGeometryAlpha + 820);
    v19 = *((_DWORD *)pMinimapGeometryAlpha + 204);
    if ( v19 < *v18 )
      v19 = *v18;
    if ( *((_DWORD *)pMinimapGeometryAlpha + 201) != v19 )
    {
      *((_DWORD *)pMinimapGeometryAlpha + 201) = v19;
      (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)pMinimapGeometryAlpha + 704LL))(pMinimapGeometryAlpha);
    }
    goto LABEL_29;
  }
  if ( fabs(_mm_shuffle_ps(v393, v393, 85).m128_f32[0]) <= 0.0
    && fabs(_mm_shuffle_ps(v393, v393, 170).m128_f32[0]) <= 0.0
    && fabs(_mm_shuffle_ps(v393, v393, 255).m128_f32[0]) <= 0.0
    && fabs(*(float *)&v404) <= 0.0 )
  {
    v15 = _mm_cvtsi128_si32((__m128i)v393);
    LOBYTE(Src) = v15 & 4;
    *(_WORD *)((char *)&Src + 1) = 0;
    LOWORD(v429) = 0;
    BYTE2(v429) = 0;
    v16 = 0;
    while ( *((_BYTE *)&Src + v16) == *((_BYTE *)&v429 + v16) )
    {
      if ( (unsigned __int64)++v16 >= 3 )
      {
        LOBYTE(Src) = v15 & 8;
        *(_WORD *)((char *)&Src + 1) = 0;
        LOWORD(v429) = 0;
        BYTE2(v429) = 0;
        v17 = 0;
        while ( *((_BYTE *)&Src + v17) == *((_BYTE *)&v429 + v17) )
        {
          if ( (unsigned __int64)++v17 >= 3 )
            goto LABEL_23;
        }
        break;
      }
    }
  }
LABEL_29:
  if ( v5 )
  {
LABEL_30:
    v389 = *(__m128i *)string_constructor(&v392, (__int64)L"minimap_walkability_alpha");
    v391 = *v2;
    if ( !string_compare((__int64)&v391, (__int64)&v389) )
      goto LABEL_53;
  }
  pMinimapWalkAlpha = OptionsUIController->pMinimapWalkAlpha;
  v399 = (int)(float)(sub_1417E5350(OptionsUIController->pOptionsContext) * 100.0);
  if ( byte_1443499CC != 2 )
    goto LABEL_46;
  v21 = *((__m128 **)pMinimapWalkAlpha + 40);
  if ( !v21 )
  {
    v393.m128_i16[0] = 0;
    v393.m128_i8[2] = 0;
    goto LABEL_46;
  }
  v393 = v21[35];
  v394 = v21[36].m128_u64[0];
  v395 = v21[36].m128_i32[2];
  v403 = v393;
  v404 = v394;
  v405 = v395;
  if ( pMinimapWalkAlpha != (UISettingWidget *)v21[24].m128_u64[0] )
  {
LABEL_46:
    v25 = &v399;
    if ( v399 >= *((_DWORD *)pMinimapWalkAlpha + 205) )
      v25 = (int *)((char *)pMinimapWalkAlpha + 820);
    v26 = *((_DWORD *)pMinimapWalkAlpha + 204);
    if ( v26 < *v25 )
      v26 = *v25;
    if ( *((_DWORD *)pMinimapWalkAlpha + 201) != v26 )
    {
      *((_DWORD *)pMinimapWalkAlpha + 201) = v26;
      (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)pMinimapWalkAlpha + 704LL))(pMinimapWalkAlpha);
    }
    goto LABEL_52;
  }
  if ( fabs(_mm_shuffle_ps(v393, v393, 85).m128_f32[0]) <= 0.0
    && fabs(_mm_shuffle_ps(v393, v393, 170).m128_f32[0]) <= 0.0
    && fabs(_mm_shuffle_ps(v393, v393, 255).m128_f32[0]) <= 0.0
    && fabs(*(float *)&v404) <= 0.0 )
  {
    v22 = _mm_cvtsi128_si32((__m128i)v393);
    LOBYTE(Src) = v22 & 4;
    *(_WORD *)((char *)&Src + 1) = 0;
    LOWORD(v429) = 0;
    BYTE2(v429) = 0;
    v23 = 0;
    while ( *((_BYTE *)&Src + v23) == *((_BYTE *)&v429 + v23) )
    {
      if ( (unsigned __int64)++v23 >= 3 )
      {
        LOBYTE(Src) = v22 & 8;
        *(_WORD *)((char *)&Src + 1) = 0;
        LOWORD(v429) = 0;
        BYTE2(v429) = 0;
        v24 = 0;
        while ( *((_BYTE *)&Src + v24) == *((_BYTE *)&v429 + v24) )
        {
          if ( (unsigned __int64)++v24 >= 3 )
            goto LABEL_46;
        }
        break;
      }
    }
  }
LABEL_52:
  if ( !v5 )
    goto LABEL_54;
LABEL_53:
  v389 = *(__m128i *)string_constructor(&v392, (__int64)L"minimap_zoom");
  v391 = *v2;
  if ( string_compare((__int64)&v391, (__int64)&v389) )
  {
LABEL_54:
    pMinimapZoom = OptionsUIController->pMinimapZoom;
    v400 = sub_1417E54B0(OptionsUIController->pOptionsContext);
    if ( byte_1443499CC == 2 )
    {
      v28 = *((__m128 **)pMinimapZoom + 40);
      if ( v28 )
      {
        v393 = v28[35];
        v394 = v28[36].m128_u64[0];
        v395 = v28[36].m128_i32[2];
        v403 = v393;
        v404 = v394;
        v405 = v395;
        if ( pMinimapZoom == (UISettingWidget *)v28[24].m128_u64[0] )
        {
          if ( fabs(_mm_shuffle_ps(v393, v393, 85).m128_f32[0]) <= 0.0
            && fabs(_mm_shuffle_ps(v393, v393, 170).m128_f32[0]) <= 0.0
            && fabs(_mm_shuffle_ps(v393, v393, 255).m128_f32[0]) <= 0.0
            && fabs(*(float *)&v404) <= 0.0 )
          {
            v29 = _mm_cvtsi128_si32((__m128i)v393);
            LOBYTE(Src) = v29 & 4;
            *(_WORD *)((char *)&Src + 1) = 0;
            LOWORD(v429) = 0;
            BYTE2(v429) = 0;
            v30 = 0;
            while ( *((_BYTE *)&Src + v30) == *((_BYTE *)&v429 + v30) )
            {
              if ( (unsigned __int64)++v30 >= 3 )
              {
                LOBYTE(Src) = v29 & 8;
                *(_WORD *)((char *)&Src + 1) = 0;
                LOWORD(v429) = 0;
                BYTE2(v429) = 0;
                v31 = 0;
                while ( *((_BYTE *)&Src + v31) == *((_BYTE *)&v429 + v31) )
                {
                  if ( (unsigned __int64)++v31 >= 3 )
                    goto LABEL_69;
                }
                break;
              }
            }
          }
LABEL_75:
          if ( !v5 )
            goto LABEL_78;
          goto LABEL_76;
        }
      }
      else
      {
        v393.m128_i16[0] = 0;
        v393.m128_i8[2] = 0;
      }
    }
LABEL_69:
    v32 = &v400;
    if ( v400 >= *((_DWORD *)pMinimapZoom + 205) )
      v32 = (int *)((char *)pMinimapZoom + 820);
    v33 = *((_DWORD *)pMinimapZoom + 204);
    if ( v33 < *v32 )
      v33 = *v32;
    if ( *((_DWORD *)pMinimapZoom + 201) != v33 )
    {
      *((_DWORD *)pMinimapZoom + 201) = v33;
      (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)pMinimapZoom + 704LL))(pMinimapZoom);
    }
    goto LABEL_75;
  }
LABEL_76:
  v389 = *(__m128i *)string_constructor(&v392, (__int64)L"always_show_sockets");
  v391 = *v2;
  if ( !string_compare((__int64)&v391, (__int64)&v389) )
  {
    v34 = &OptionsUIController->pOptionsContext;
    goto LABEL_79;
  }
LABEL_78:
  pAlwaysShowSockets = OptionsUIController->pAlwaysShowSockets;
  v36 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pAlwaysShowSockets + 832LL);
  v34 = &OptionsUIController->pOptionsContext;
  v37 = sub_1417E57A0(OptionsUIController->pOptionsContext);
  v36(pAlwaysShowSockets, v37, 0);
LABEL_79:
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"always_attack_in_place"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pAlwaysAttackInPlace = OptionsUIController->pAlwaysAttackInPlace;
    v42 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pAlwaysAttackInPlace + 832LL);
    v43 = sub_1417E70A0(*v34);
    v42(pAlwaysAttackInPlace, v43, 0);
    v40 = &OptionsUIController->pOptionsContext;
  }
  Src = v34;
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"attack_in_place_key_stops_move"),
        v391 = *v2,
        Src = v44,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pAttackInPlaceStopsMove = OptionsUIController->pAttackInPlaceStopsMove;
    v46 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pAttackInPlaceStopsMove + 832LL);
    v47 = sub_1417E71C0(*v34, v38, v39, v40);
    v46(pAttackInPlaceStopsMove, v47, 0);
    v34 = Src;
  }
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_ally_mini_life_bars"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowAllyMiniLifeBars = OptionsUIController->pShowAllyMiniLifeBars;
    v52 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowAllyMiniLifeBars + 832LL);
    v53 = sub_1417E72E0(*v34);
    v52(pShowAllyMiniLifeBars, v53, 0);
    v50 = &OptionsUIController->pOptionsContext;
  }
  Src = v34;
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_enemy_mini_life_bars"),
        v391 = *v2,
        Src = v54,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowEnemyMiniLifeBars = OptionsUIController->pShowEnemyMiniLifeBars;
    v56 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowEnemyMiniLifeBars + 832LL);
    v57 = sub_1417E7470(*v34, v48, v49, v50);
    v56(pShowEnemyMiniLifeBars, v57, 0);
    v34 = Src;
  }
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_player_mini_life_bar"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowPlayerMiniLifeBar = OptionsUIController->pShowPlayerMiniLifeBar;
    v62 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowPlayerMiniLifeBar + 832LL);
    v63 = sub_1417E7600(*v34);
    v62(pShowPlayerMiniLifeBar, v63, 0);
    v60 = &OptionsUIController->pOptionsContext;
  }
  Src = v34;
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_resistance_icons"),
        v391 = *v2,
        Src = v64,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowResistanceIcons = OptionsUIController->pShowResistanceIcons;
    v66 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowResistanceIcons + 832LL);
    v67 = sub_1417EA6A0(*v34, v58, v59, v60);
    v66(pShowResistanceIcons, v67, 0);
    v34 = Src;
  }
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_ally_names_on_map"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowAllyNamesOnMap = OptionsUIController->pShowAllyNamesOnMap;
    v72 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowAllyNamesOnMap + 832LL);
    v73 = sub_1417E78B0(*v34);
    v72(pShowAllyNamesOnMap, v73, 0);
    v70 = &OptionsUIController->pOptionsContext;
  }
  Src = v34;
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"map_overlay_mods_hidden"),
        v391 = *v2,
        Src = v74,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pMapOverlayModsHidden = OptionsUIController->pMapOverlayModsHidden;
    v76 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pMapOverlayModsHidden + 832LL);
    v77 = sub_1417E9520(*v34, v68, v69, v70);
    v76(pMapOverlayModsHidden, v77, 0);
    v34 = Src;
  }
  if ( !v5
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_clock"),
        v391 = *v2,
        v78 = v34,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowClock = OptionsUIController->pShowClock;
    v80 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowClock + 832LL);
    v81 = sub_1417E7A40(*v34);
    v80(pShowClock, v81, 0);
    v78 = &OptionsUIController->pOptionsContext;
  }
  v82 = v34;
  if ( !v2->m128i_i64[1]
    || (v389 = *(__m128i *)&off_142DDA150, v391 = *v2, string_compare((__int64)&v391, (__int64)&v389)) )
  {
    v78 = v82;
    v83 = *(_QWORD *)OptionsUIController->pad_238;
    if ( v83 )
    {
      v84 = *(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v83 + 832LL);
      v85 = sub_1417E87D0(*v34);
      v84(v83, v85, 0);
    }
  }
  v86 = v2->m128i_i64[1];
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"hide_remove_only_tabs"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pHideRemoveOnlyTabs = OptionsUIController->pHideRemoveOnlyTabs;
    v91 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pHideRemoveOnlyTabs + 832LL);
    v92 = sub_1417EE1A0(*v78);
    v91(pHideRemoveOnlyTabs, v92, 0);
    v89 = &OptionsUIController->pOptionsContext;
  }
  Src = v78;
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"output_all_dialogue_to_chat"),
        v391 = *v2,
        Src = v93,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pOutputDialogueToChat = OptionsUIController->pOutputDialogueToChat;
    v95 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pOutputDialogueToChat + 832LL);
    v96 = sub_1417E7B60(*v78, v87, v88, v89);
    v95(pOutputDialogueToChat, v96, 0);
    v78 = Src;
  }
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"quest_tracking"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pQuestTracking = OptionsUIController->pQuestTracking;
    v101 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pQuestTracking + 832LL);
    v102 = sub_1417E7CF0(*v78);
    v101(pQuestTracking, v102, 0);
    v99 = &OptionsUIController->pOptionsContext;
  }
  Src = v78;
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_full_ground_item_descriptions"),
        v391 = *v2,
        Src = v103,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowFullGroundDescs = OptionsUIController->pShowFullGroundDescs;
    v105 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowFullGroundDescs + 832LL);
    v106 = sub_1417E5A10(*v78, v97, v98, v99);
    v105(pShowFullGroundDescs, v106, 0);
    v78 = Src;
  }
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_life_levels"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowLifeLevels = OptionsUIController->pShowLifeLevels;
    v111 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowLifeLevels + 832LL);
    v112 = sub_1417E5BA0(*v78);
    v111(pShowLifeLevels, v112, 0);
    v109 = &OptionsUIController->pOptionsContext;
  }
  Src = v78;
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"hide_reservation_levels"),
        v391 = *v2,
        Src = v113,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pHideReservationLevels = OptionsUIController->pHideReservationLevels;
    v115 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pHideReservationLevels + 832LL);
    v116 = sub_1417E5D30(*v78, v107, v108, v109);
    v115(pHideReservationLevels, v116, 0);
    v78 = Src;
  }
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_flask_buffs"),
        v391 = *v2,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowFlaskBuffs = OptionsUIController->pShowFlaskBuffs;
    v121 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowFlaskBuffs + 832LL);
    v122 = sub_1417E5EC0(*v78);
    v121(pShowFlaskBuffs, v122, 0);
    v119 = &OptionsUIController->pOptionsContext;
  }
  Src = v78;
  if ( !v86
    || (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"show_aura_icons"),
        v391 = *v2,
        Src = v123,
        string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pShowAuraIcons = OptionsUIController->pShowAuraIcons;
    v125 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowAuraIcons + 832LL);
    v126 = sub_1417E6050(*v78, v117, v118, v119);
    v125(pShowAuraIcons, v126, 0);
    v78 = Src;
  }
  if ( !v86 || (v389 = *(__m128i *)&off_142DDA1B0, v391 = *v2, string_compare((__int64)&v391, (__int64)&v389)) )
  {
    pUnknownVtable848 = OptionsUIController->pUnknownVtable848;
    v128 = *(void (__fastcall **)(UISettingWidget *, _QWORD))(*(_QWORD *)pUnknownVtable848 + 848LL);
    v129 = sub_1417EE9B0(*v78);
    v128(pUnknownVtable848, v129);
    if ( !v86 )
      goto LABEL_141;
  }
  v389 = *(__m128i *)&off_142DDA1F0;
  v391 = *v2;
  if ( string_compare((__int64)&v391, (__int64)&v389) )
  {
LABEL_141:
    pCursorHoverImage = OptionsUIController->pCursorHoverImage;
    if ( pCursorHoverImage )
    {
      v131 = sub_1417EED10(*v78);
      sub_14024DFC0(pCursorHoverImage, (unsigned int)(int)(float)(v131 * 100.0), 0, 0);
      if ( qword_144382DE0 )
        sub_141454610();
    }
    if ( !v86 )
      goto LABEL_143;
  }
  v389 = *(__m128i *)string_constructor(&v392, (__int64)L"cursor_hover_image_enabled");
  v391 = *v2;
  if ( string_compare((__int64)&v391, (__int64)&v389) )
  {
LABEL_143:
    pCursorPressedImage = OptionsUIController->pCursorPressedImage;
    v133 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pCursorPressedImage + 832LL);
    v134 = sub_1417EEA70(OptionsUIController->pOptionsContext);
    v133(pCursorPressedImage, v134, 0);
  }
  if ( v86
    && (v389 = *(__m128i *)string_constructor(&v392, (__int64)L"cursor_pressed_image_enabled"),
        v391 = *v2,
        !string_compare((__int64)&v391, (__int64)&v389))
    || (v135 = *(_QWORD *)OptionsUIController->pad_208,
        v136 = *(void (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v135 + 832LL),
        v137 = sub_1417EEB90(OptionsUIController->pOptionsContext),
        v136(v135, v137, 0),
        v86) )
  {
    v389 = *(__m128i *)string_constructor(&v392, (__int64)L"default_mouse_cursor");
    v391 = *v2;
    if ( !string_compare((__int64)&v391, (__int64)&v389) )
      goto LABEL_267;
  }
  sub_14091C4D0(v417);
  v138 = sub_140925480(v417, v416);
  sub_140928320(&v393, v138);
  sub_140101C20(v416);
  sub_14092AE40(
    v393.m128_u64[0],
    v393.m128_u64[1],
    (__int64)(v393.m128_u64[1] - v393.m128_u64[0]) >> 4,
    (unsigned __int8)k);
  (*(void (__fastcall **)(void *))(*(_QWORD *)OptionsUIController->pCursorManager + 840LL))(OptionsUIController->pCursorManager);
  v429 = v393.m128_u64[1];
  v139 = (_QWORD *)v393.m128_u64[0];
  v140 = -1;
  if ( v393.m128_u64[0] != v393.m128_u64[1] )
  {
    v141 = (char *)&Resource::ChildHandle<Loaders::WindowCursors,Loaders::WindowCursors_Row> `RTTI Type Descriptor' + 2;
    for ( i = (char *)&Resource::ChildHandle<Loaders::WindowCursors,Loaders::WindowCursors_Row> `RTTI Type Descriptor'
            + 2; ; v141 = i )
    {
      pCursorManager = OptionsUIController->pCursorManager;
      Src = *(void **)(*(_QWORD *)pCursorManager + 832LL);
      v417[1] = &v408;
      v409 = 0;
      v410 = 0;
      v411 = nullptr;
      v412 = nullptr;
      *(_QWORD *)&v408 = *v139;
      v143 = v139[1];
      *((_QWORD *)&v408 + 1) = v143;
      if ( v143 )
      {
        _InterlockedIncrement((volatile signed __int32 *)(v143 + 60));
        *(_DWORD *)(v143 + 56) = dword_14382000C;
      }
      v411 = off_142E70C98;
      v412 = v141;
      v144 = *(_QWORD *)(*v139 + 40LL);
      v406 = 0;
      v407 = 0u;
      v145 = -1;
      do
        ++v145;
      while ( *(_WORD *)(v144 + 2 * v145) );
      sub_1401386B0(&v406, v144, v145);
      LOBYTE(v146) = 1;
      Src = (void *)((__int64 (__fastcall *)(void *, __int128 *, __int128 *, __int64, _DWORD))Src)(
                      pCursorManager,
                      &v406,
                      &v408,
                      v146,
                      0);
      v147 = *(_QWORD *)(*v139 + 8LL);
      v420.m128i_i64[0] = v147;
      v148 = -1;
      do
        ++v148;
      while ( *(_WORD *)(v147 + 2 * v148) );
      v420.m128i_i64[1] = v148;
      if ( v148 )
      {
        v396 = v420;
        v149 = (_QWORD *)sub_140D7AAB0(&v403, &v396);
        v406 = 0;
        v407 = 0u;
        sub_1401386B0(&v406, *v149, v149[1]);
      }
      else
      {
        v406 = 0;
        *(_QWORD *)&v407 = 0;
        *((_QWORD *)&v407 + 1) = 7;
        LOWORD(v406) = 0;
      }
      v150 = sub_14013D250(&v406, 0, L"Art/2DArt/UIImages/Common/CursorPreviewIcons/", 45);
      v418 = 0;
      v419 = 0u;
      v418 = *(_OWORD *)v150;
      v419 = *(_OWORD *)(v150 + 16);
      *(_QWORD *)(v150 + 16) = 0;
      *(_QWORD *)(v150 + 24) = 7;
      *(_WORD *)v150 = 0;
      sub_1401283E0(&v406);
      v151 = OptionsUIController->pCursorManager;
      v152 = (char *)&v418;
      if ( *((_QWORD *)&v419 + 1) > 7u )
        v152 = (char *)v418;
      v391.m128i_i64[0] = (__int64)v152;
      v391.m128i_i64[1] = v419;
      if ( !(_QWORD)v419 )
      {
        v408 = 0;
        v153 = 0;
        *(_QWORD *)&v409 = 0;
        v154 = 7;
        *((_QWORD *)&v409 + 1) = 7;
        LOWORD(v408) = 0;
        goto LABEL_171;
      }
      v155 = &v152[2 * v419 - 2];
      if ( *(_WORD *)v155 == 46 )
      {
LABEL_166:
        v156 = (v155 - v152) >> 1;
        if ( v156 != -1 )
        {
          if ( (unsigned __int64)v419 < v156 )
            v156 = v419;
          goto LABEL_170;
        }
      }
      else
      {
        while ( v155 != v152 )
        {
          v155 -= 2;
          if ( *(_WORD *)v155 == 46 )
            goto LABEL_166;
        }
      }
      v156 = _mm_srli_si128(v391, 8).m128i_u64[0];
      v152 = (char *)v391.m128i_i64[0];
LABEL_170:
      v408 = 0;
      v409 = 0u;
      sub_1401386B0(&v408, v152, v156);
      v154 = *((_QWORD *)&v409 + 1);
      v153 = v409;
LABEL_171:
      v4 |= 0x188u;
      v157 = &v408;
      if ( v154 > 7 )
        v157 = (__int128 *)v408;
      v389.m128i_i64[0] = (__int64)v157;
      v389.m128i_i64[1] = v153;
      v396 = v389;
      v158 = sub_1417438D0(&v392, &v396);
      sub_1417CCAD0(v151, Src, v158, 0);
      if ( *((_QWORD *)&v409 + 1) > 7u )
      {
        v159 = 2LL * *((_QWORD *)&v409 + 1) + 2;
        v160 = v408;
        if ( v159 >= 0x1000 )
        {
          v159 = 2LL * *((_QWORD *)&v409 + 1) + 41;
          v160 = *(_QWORD *)(v408 - 8);
          if ( (unsigned __int64)(v408 - v160 - 8) > 0x1F )
            invalid_parameter_noinfo_noreturn();
        }
        sub_142B3A010(v160, v159);
      }
      sub_1401283E0(&v418);
      v139 += 2;
      if ( v139 == (_QWORD *)v429 )
        break;
    }
  }
  sub_1417EEDF0(OptionsUIController->pOptionsContext, &v413);
  if ( !v413 )
    goto LABEL_183;
  v421[0] = off_142F89518;
  v421[1] = &v413;
  v422 = v421;
  v161 = sub_1417CD3E0(OptionsUIController->pCursorManager, v421);
  if ( v422 )
  {
    v162 = *v422;
    LOBYTE(v162) = v422 != v421;
    (*(void (__fastcall **)(_QWORD *, __int64))(*v422 + 32LL))(v422, v162);
  }
  if ( !v161 )
LABEL_183:
    (*(void (__fastcall **)(void *, _QWORD))(*(_QWORD *)OptionsUIController->pCursorManager + 848LL))(
      OptionsUIController->pCursorManager,
      0);
  v163 = 0;
  LOBYTE(Src) = 0;
  sub_1400E7CB0(&v396);
  v164 = v396.m128i_i64[0];
  v165 = *(_QWORD *)(v396.m128i_i64[0] + 136);
  v166 = *(_QWORD *)(v396.m128i_i64[0] + 144);
  if ( v166 )
    _InterlockedIncrement((volatile signed __int32 *)(v166 + 8));
  v392.m128i_i64[0] = v165;
  v167 = *(volatile signed __int32 **)(v164 + 144);
  v392.m128i_i64[1] = (__int64)v167;
  if ( v165 )
  {
    if ( (unsigned __int8)sub_14141BD10() )
    {
      v168 = sub_1400E8AC0();
      if ( v168 )
      {
        v163 = *(_DWORD *)(sub_14034F680(v168 + 51992, 23) + 4) != 0;
        LOBYTE(Src) = v163;
      }
    }
  }
  if ( v167 )
  {
    if ( _InterlockedExchangeAdd(v167 + 2, 0xFFFFFFFF) == 1 )
    {
      (**(void (__fastcall ***)(volatile signed __int32 *))v167)(v167);
      if ( _InterlockedExchangeAdd(v167 + 3, 0xFFFFFFFF) == 1 )
        (*(void (__fastcall **)(volatile signed __int32 *))(*(_QWORD *)v167 + 8LL))(v167);
    }
  }
  if ( !v163 && qword_144382DE0 )
    sub_141454310();
  if ( v396.m128i_i64[1] )
  {
    if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v396.m128i_i64[1] + 8), 0xFFFFFFFF) == 1 )
    {
      v169 = v396.m128i_i64[1];
      (**(void (__fastcall ***)(__int64))v396.m128i_i64[1])(v396.m128i_i64[1]);
      if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v169 + 12), 0xFFFFFFFF) == 1 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v396.m128i_i64[1] + 8LL))(v396.m128i_i64[1]);
    }
  }
  v170 = OptionsUIController->pCursorManager;
  v171 = v170[62];
  v172 = v170[61];
  v173 = v172 == v171;
  if ( v172 != v171 )
  {
    do
    {
      if ( *(_BYTE *)(v172 + 16) == 1 )
        break;
      v172 += 24;
    }
    while ( v172 != v171 );
    v173 = v172 == v171;
  }
  if ( v173 )
    v172 = 0;
  if ( !v172 || (v174 = *(float **)v172) == nullptr )
  {
    v175 = (_QWORD *)sub_141788240();
    v176 = sub_141787F60(*v175, 1848);
    v177 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v176 + 8LL))(v176);
    v178 = sub_141797E00(v177);
    v174 = (float *)v178;
    *(_QWORD *)(v178 + 8) = 1848;
    if ( *(float *)(v178 + 616) != 900.0 )
    {
      *(_DWORD *)(v178 + 616) = 1147207680;
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v178 + 720LL))(v178);
      v180 = v174[154];
      if ( v180 < v174[150] )
      {
        v174[150] = v180;
        (*(void (__fastcall **)(float *))(*(_QWORD *)v174 + 384LL))(v174);
      }
    }
    LOBYTE(v179) = 1;
    sub_141783810(OptionsUIController->pCursorManager, v179, (_DWORD)v174, (unsigned int)&qword_142DD7168, 1, 0, 0, 0);
  }
  if ( byte_14436B60E )
  {
    v181 = byte_1443499CC;
    sub_14219E7C0();
    v182 = (unsigned int)dword_14382006C;
  }
  else
  {
    sub_14219E7C0();
    v182 = (unsigned int)dword_14382006C;
    v181 = 0;
  }
  sub_1420AF190(&v429, v182);
  sub_14218D440(&v389, 5815, &v429);
  v183 = v4 | 0x40;
  if ( v181 != 2 || (v184 = *(_WORD **)(v389.m128i_i64[0] + 16)) == nullptr || !*v184 )
    v184 = *(_WORD **)(v389.m128i_i64[0] + 8);
  if ( v389.m128i_i64[1] )
    _InterlockedDecrement((volatile signed __int32 *)(v389.m128i_i64[1] + 60));
  if ( v429 )
  {
    _InterlockedDecrement((volatile signed __int32 *)(v429 + 60));
    v429 = 0;
  }
  memset(v397, 0, 32);
  v185 = -1;
  do
    ++v185;
  while ( v184[v185] );
  sub_1401386B0(v397, v184, v185);
  v4 = v183 | 0x30;
  v390 = v4;
  if ( (_BYTE)Src )
  {
    if ( byte_14436B60E )
    {
      v186 = byte_1443499CC;
      sub_14219E7C0();
      v187 = (unsigned int)dword_14382006C;
    }
    else
    {
      sub_14219E7C0();
      v187 = (unsigned int)dword_14382006C;
      v186 = 0;
    }
    sub_1420AF190(&Src, v187);
    sub_14218D440(&v389, 5816, &Src);
    if ( v186 != 2 || (v188 = *(_WORD **)(v389.m128i_i64[0] + 16)) == nullptr || !*v188 )
      v188 = *(_WORD **)(v389.m128i_i64[0] + 8);
    if ( v389.m128i_i64[1] )
      _InterlockedDecrement((volatile signed __int32 *)(v389.m128i_i64[1] + 60));
    if ( Src )
    {
      _InterlockedDecrement((volatile signed __int32 *)Src + 15);
      Src = nullptr;
    }
    v406 = 0;
    v407 = 0;
    do
      ++v140;
    while ( v188[v140] );
    sub_1401386B0(&v406, v188, v140);
    v189 = sub_14013D250(&v406, 0, L"\n\n", 2);
    v408 = *(_OWORD *)v189;
    v409 = *(_OWORD *)(v189 + 16);
    *(_QWORD *)(v189 + 16) = 0;
    *(_QWORD *)(v189 + 24) = 7;
    *(_WORD *)v189 = 0;
    v4 |= 0x1E00u;
    v390 = v4;
    sub_14012BA20(v397);
    sub_1401283E0(&v408);
    sub_1401283E0(&v406);
  }
  v408 = 0;
  v409 = 0u;
  v190 = *(_QWORD *)&v397[1];
  v191 = v397;
  if ( *((_QWORD *)&v397[1] + 1) > 7u )
    v191 = *(__int128 **)&v397[0];
  Src = v191;
  v192 = 0x7FFFFFFFFFFFFFFELL;
  if ( *(_QWORD *)&v397[1] > 0x7FFFFFFFFFFFFFFEuLL )
    unknown_libname_3();
  if ( *(_QWORD *)&v397[1] > 7u )
  {
    if ( (*(_QWORD *)&v397[1] | 7uLL) <= 0x7FFFFFFFFFFFFFFELL )
    {
      v192 = *(_QWORD *)&v397[1] | 7LL;
      if ( (*(_QWORD *)&v397[1] | 7uLL) < 0xA )
        v192 = 10;
      v193 = v192 + 1;
      if ( (unsigned __int64)(v192 + 1) > 0x7FFFFFFFFFFFFFFFLL )
        sub_1400E1A80();
    }
    else
    {
      v193 = 0x7FFFFFFFFFFFFFFFLL;
    }
    *(_QWORD *)&v408 = sub_1401394F0(2 * v193);
    *(_QWORD *)&v409 = v190;
    *((_QWORD *)&v409 + 1) = v192;
    memcpy((void *)v408, Src, 2 * v190 + 2);
  }
  else
  {
    *(_QWORD *)&v409 = *(_QWORD *)&v397[1];
    *((_QWORD *)&v409 + 1) = 7;
    v408 = *v191;
  }
  sub_141792350(v174, &v408, 0);
  sub_1401283E0(v397);
  if ( v414 )
  {
    _InterlockedDecrement((volatile signed __int32 *)(v414 + 60));
    v414 = 0;
  }
  v196 = v393.m128_u64[0];
  if ( v393.m128_u64[0] )
  {
    v197 = v393.m128_u64[1];
    if ( v393.m128_u64[0] != v393.m128_u64[1] )
    {
      do
      {
        v198 = *(_QWORD *)(v196 + 8);
        if ( v198 )
        {
          _InterlockedDecrement((volatile signed __int32 *)(v198 + 60));
          *(_QWORD *)(v196 + 8) = 0;
        }
        v196 += 16LL;
      }
      while ( v196 != v197 );
      v196 = v393.m128_u64[0];
    }
    v199 = (v394 - v196) & 0xFFFFFFFFFFFFFFF0uLL;
    v200 = v196;
    if ( v199 >= 0x1000 )
    {
      v199 += 39LL;
      v196 = *(_QWORD *)(v196 - 8);
      if ( v200 - v196 - 8 > 0x1F )
        invalid_parameter_noinfo_noreturn();
    }
    sub_142B3A010(v196, v199);
    v393 = 0;
    v394 = 0;
  }
  if ( v417[0] )
    _InterlockedDecrement((volatile signed __int32 *)(v417[0] + 60LL));
  if ( v86 )
  {
LABEL_267:
    v195 = (_WORD *)v2->m128i_i64[0];
    v201 = v2->m128i_i64[1];
    if ( v201 == 15 )
    {
      v194 = L"screen_shake_v2";
      while ( *v195 == *v194 )
      {
        ++v195;
        ++v194;
        if ( !--v201 )
          goto LABEL_271;
      }
    }
    goto LABEL_272;
  }
LABEL_271:
  (*(void (__fastcall **)(UISettingWidget *, const wchar_t *, _WORD *))(*(_QWORD *)OptionsUIController->pScreenShakeV2
                                                                      + 840LL))(
    OptionsUIController->pScreenShakeV2,
    v194,
    v195);
  pScreenShakeV2 = OptionsUIController->pScreenShakeV2;
  v203 = *(void (__fastcall **)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD))(*(_QWORD *)pScreenShakeV2 + 832LL);
  Src = v397;
  memset(v397, 0, 56);
  LOBYTE(v397[0]) = 1;
  *((_QWORD *)&v397[3] + 1) = &bool `RTTI Type Descriptor';
  v204 = sub_1420B32A0(v416, 4235);
  LOBYTE(v205) = 1;
  v203(pScreenShakeV2, v204, v397, v205, 0);
  v206 = OptionsUIController->pScreenShakeV2;
  v207 = *(void (__fastcall **)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD))(*(_QWORD *)v206 + 832LL);
  Src = v397;
  memset(v397, 0, 56);
  *((_QWORD *)&v397[3] + 1) = &bool `RTTI Type Descriptor';
  v208 = sub_1420B32A0(v416, 4236);
  LOBYTE(v209) = 1;
  v207(v206, v208, v397, v209, 0);
  v210 = OptionsUIController->pScreenShakeV2;
  v211 = *(void (__fastcall **)(UISettingWidget *, __int64))(*(_QWORD *)v210 + 848LL);
  v212 = sub_1417DE350();
  v213 = sub_1417E3480(v212);
  v211(v210, v213 ^ 1LL);
  if ( v86 )
  {
LABEL_272:
    v215 = (_WORD *)v2->m128i_i64[0];
    v216 = v2->m128i_i64[1];
    if ( v216 == 16 )
    {
      v214 = L"camera_zrotation";
      while ( *v215 == *v214 )
      {
        ++v215;
        ++v214;
        if ( !--v216 )
          goto LABEL_276;
      }
    }
    goto LABEL_277;
  }
LABEL_276:
  pCameraZRotation = OptionsUIController->pCameraZRotation;
  v218 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pCameraZRotation + 832LL);
  v219 = &OptionsUIController->pOptionsContext;
  v220 = sub_1417E3610(OptionsUIController->pOptionsContext, v214, v215);
  v218(pCameraZRotation, v220, 0);
  if ( v86 )
  {
LABEL_277:
    v221 = (_WORD *)v2->m128i_i64[0];
    v222 = v2->m128i_i64[1];
    if ( v222 == 16 )
    {
      v223 = L"show_global_chat";
      while ( *v221 == *v223 )
      {
        ++v221;
        ++v223;
        if ( !--v222 )
        {
          v219 = &OptionsUIController->pOptionsContext;
          goto LABEL_282;
        }
      }
    }
    goto LABEL_283;
  }
LABEL_282:
  pShowGlobalChat = OptionsUIController->pShowGlobalChat;
  v225 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowGlobalChat + 832LL);
  v226 = sub_1417E6370(*v219);
  v225(pShowGlobalChat, v226, 0);
  if ( v86 )
  {
LABEL_283:
    v227 = (_WORD *)v2->m128i_i64[0];
    v228 = v2->m128i_i64[1];
    if ( v228 == 15 )
    {
      v229 = L"show_trade_chat";
      while ( *v227 == *v229 )
      {
        ++v227;
        ++v229;
        if ( !--v228 )
        {
          v219 = &OptionsUIController->pOptionsContext;
          goto LABEL_288;
        }
      }
    }
    goto LABEL_289;
  }
LABEL_288:
  pShowTradeChat = OptionsUIController->pShowTradeChat;
  v231 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowTradeChat + 832LL);
  v232 = sub_1417E6500(*v219);
  v231(pShowTradeChat, v232, 0);
  if ( v86 )
  {
LABEL_289:
    v233 = (_WORD *)v2->m128i_i64[0];
    v234 = v2->m128i_i64[1];
    if ( v234 == 15 )
    {
      v235 = L"show_guild_chat";
      while ( *v233 == *v235 )
      {
        ++v233;
        ++v235;
        if ( !--v234 )
        {
          v219 = &OptionsUIController->pOptionsContext;
          goto LABEL_294;
        }
      }
    }
    goto LABEL_295;
  }
LABEL_294:
  pShowGuildChat = OptionsUIController->pShowGuildChat;
  v237 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowGuildChat + 832LL);
  v238 = sub_1417E69B0(*v219);
  v237(pShowGuildChat, v238, 0);
  if ( v86 )
  {
LABEL_295:
    v239 = (_WORD *)v2->m128i_i64[0];
    v240 = v2->m128i_i64[1];
    if ( v240 == 20 )
    {
      v241 = L"show_chat_timestamps";
      while ( *v239 == *v241 )
      {
        ++v239;
        ++v241;
        if ( !--v240 )
        {
          v219 = &OptionsUIController->pOptionsContext;
          goto LABEL_300;
        }
      }
    }
    goto LABEL_301;
  }
LABEL_300:
  pShowChatTimestamps = OptionsUIController->pShowChatTimestamps;
  v243 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pShowChatTimestamps + 832LL);
  v244 = sub_1417E6B40(*v219);
  v243(pShowChatTimestamps, v244, 0);
  if ( v86 )
  {
LABEL_301:
    v245 = (_WORD *)v2->m128i_i64[0];
    v246 = v2->m128i_i64[1];
    if ( v246 == 28 )
    {
      v247 = L"additional_support_gem_popup";
      while ( *v245 == *v247 )
      {
        ++v245;
        ++v247;
        if ( !--v246 )
        {
          v219 = &OptionsUIController->pOptionsContext;
          goto LABEL_306;
        }
      }
    }
    goto LABEL_307;
  }
LABEL_306:
  pAddSupportGemPopup1 = OptionsUIController->pAddSupportGemPopup1;
  v249 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pAddSupportGemPopup1 + 832LL);
  v250 = sub_1417E9390(*v219);
  v249(pAddSupportGemPopup1, v250, 0);
  if ( v86 )
  {
LABEL_307:
    v251 = (_WORD *)v2->m128i_i64[0];
    v252 = v2->m128i_i64[1];
    if ( v252 == 28 )
    {
      v253 = L"additional_support_gem_popup";
      while ( *v251 == *v253 )
      {
        ++v251;
        ++v253;
        if ( !--v252 )
        {
          v219 = &OptionsUIController->pOptionsContext;
          goto LABEL_312;
        }
      }
    }
    goto LABEL_313;
  }
LABEL_312:
  pAddSupportGemPopup2 = OptionsUIController->pAddSupportGemPopup2;
  v255 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pAddSupportGemPopup2 + 832LL);
  v256 = sub_1417EAA30(*v219);
  v255(pAddSupportGemPopup2, v256, 0);
  if ( !v86 )
  {
LABEL_317:
    (*(void (__fastcall **)(UISettingWidget *, const wchar_t *, _WORD *))(*(_QWORD *)OptionsUIController->pChatBoxFontSize
                                                                        + 840LL))(
      OptionsUIController->pChatBoxFontSize,
      v257,
      v258);
    for ( j = 0; j < 2; ++j )
    {
      pChatBoxFontSize = OptionsUIController->pChatBoxFontSize;
      v262 = *(void (__fastcall **)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD))(*(_QWORD *)pChatBoxFontSize
                                                                                          + 832LL);
      Src = v397;
      memset(v397, 0, sizeof(v397));
      v263 = sub_1420B32A0(v416, word_142DF3D04[j]);
      LOBYTE(v264) = 1;
      v262(pChatBoxFontSize, v263, v397, v264, 0);
    }
    v265 = OptionsUIController->pChatBoxFontSize;
    v266 = *(void (__fastcall **)(UISettingWidget *, _QWORD))(*(_QWORD *)v265 + 848LL);
    v267 = &OptionsUIController->pOptionsContext;
    v268 = sub_1417E81C0(OptionsUIController->pOptionsContext);
    v266(v265, v268);
    v86 = v2->m128i_i64[1];
    if ( !v86 )
      goto LABEL_321;
    goto LABEL_320;
  }
LABEL_313:
  v258 = (_WORD *)v2->m128i_i64[0];
  v259 = v2->m128i_i64[1];
  if ( v259 == 18 )
  {
    v257 = L"chat_box_font_size";
    while ( *v258 == *v257 )
    {
      ++v258;
      ++v257;
      if ( !--v259 )
        goto LABEL_317;
    }
  }
  v267 = &OptionsUIController->pOptionsContext;
LABEL_320:
  v392 = *v2;
  if ( !(unsigned __int8)sub_1408F87C0(&v392) )
  {
LABEL_371:
    v284 = (_WORD *)v2->m128i_i64[0];
    v285 = v2->m128i_i64[1];
    if ( v285 == 16 )
    {
      v277 = L"always_highlight";
      while ( *v284 == *v277 )
      {
        ++v284;
        ++v277;
        if ( !--v285 )
          goto LABEL_375;
      }
    }
    v328 = (_WORD *)v2->m128i_i64[0];
    v329 = v2->m128i_i64[1];
    if ( v329 == 24 )
    {
      v277 = L"always_highlight.gamepad";
      while ( *v328 == *v277 )
      {
        ++v328;
        ++v277;
        if ( !--v329 )
          goto LABEL_375;
      }
    }
    goto LABEL_376;
  }
LABEL_321:
  pAlwaysHighlight = OptionsUIController->pAlwaysHighlight;
  v401 = sub_1417E83E0(*v267, (unsigned __int8)byte_1443499CC);
  if ( byte_1443499CC == 2 )
  {
    v270 = *((__m128 **)pAlwaysHighlight + 40);
    if ( v270 )
    {
      v393 = v270[35];
      v394 = v270[36].m128_u64[0];
      v395 = v270[36].m128_i32[2];
      v403 = v393;
      v404 = v394;
      v405 = v395;
      v390 = v4;
      if ( pAlwaysHighlight == (UISettingWidget *)v270[24].m128_u64[0] )
      {
        v390 = v4;
        if ( fabs(_mm_shuffle_ps(v393, v393, 85).m128_f32[0]) <= 0.0 )
        {
          v390 = v4;
          if ( fabs(_mm_shuffle_ps(v393, v393, 170).m128_f32[0]) <= 0.0 )
          {
            v390 = v4;
            if ( fabs(_mm_shuffle_ps(v393, v393, 255).m128_f32[0]) <= 0.0 )
            {
              v390 = v4;
              if ( fabs(*(float *)&v404) <= 0.0 )
              {
                v271 = _mm_cvtsi128_si32((__m128i)v393);
                LOBYTE(Src) = v271 & 4;
                *(_WORD *)((char *)&Src + 1) = 0;
                LOWORD(v429) = 0;
                BYTE2(v429) = 0;
                v272 = 0;
                v390 = v4;
                while ( *((_BYTE *)&Src + v272) == *((_BYTE *)&v429 + v272) )
                {
                  if ( (unsigned __int64)++v272 >= 3 )
                  {
                    LOBYTE(Src) = v271 & 8;
                    *(_WORD *)((char *)&Src + 1) = 0;
                    LOWORD(v429) = 0;
                    BYTE2(v429) = 0;
                    v273 = 0;
                    v390 = v4;
                    while ( *((_BYTE *)&Src + v273) == *((_BYTE *)&v429 + v273) )
                    {
                      if ( (unsigned __int64)++v273 >= 3 )
                        goto LABEL_343;
                    }
                    goto LABEL_349;
                  }
                }
              }
            }
          }
        }
        goto LABEL_349;
      }
    }
    else
    {
      v393.m128_i16[0] = 0;
      v393.m128_i8[2] = 0;
    }
  }
LABEL_343:
  v274 = &v401;
  if ( v401 >= *((_DWORD *)pAlwaysHighlight + 205) )
    v274 = (int *)((char *)pAlwaysHighlight + 820);
  v275 = *((_DWORD *)pAlwaysHighlight + 204);
  if ( v275 < *v274 )
    v275 = *v274;
  if ( *((_DWORD *)pAlwaysHighlight + 201) != v275 )
  {
    *((_DWORD *)pAlwaysHighlight + 201) = v275;
    (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)pAlwaysHighlight + 704LL))(pAlwaysHighlight);
    (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)pAlwaysHighlight + 808LL))(pAlwaysHighlight);
  }
LABEL_349:
  pAlwaysHighlightGamepad = OptionsUIController->pAlwaysHighlightGamepad;
  v402 = sub_1417E8550(OptionsUIController->pOptionsContext, (unsigned __int8)byte_1443499CC);
  if ( byte_1443499CC != 2 )
    goto LABEL_364;
  v278 = *((__m128 **)pAlwaysHighlightGamepad + 40);
  if ( !v278 )
  {
    v393.m128_i16[0] = 0;
    v393.m128_i8[2] = 0;
    goto LABEL_364;
  }
  v393 = v278[35];
  v394 = v278[36].m128_u64[0];
  v395 = v278[36].m128_i32[2];
  v403 = v393;
  v404 = v394;
  v405 = v395;
  v390 = v4;
  if ( pAlwaysHighlightGamepad != (UISettingWidget *)v278[24].m128_u64[0] )
  {
LABEL_364:
    v282 = &v402;
    if ( v402 >= *((_DWORD *)pAlwaysHighlightGamepad + 205) )
      v282 = (int *)((char *)pAlwaysHighlightGamepad + 820);
    v283 = *((_DWORD *)pAlwaysHighlightGamepad + 204);
    if ( v283 < *v282 )
      v283 = *v282;
    if ( *((_DWORD *)pAlwaysHighlightGamepad + 201) != v283 )
    {
      *((_DWORD *)pAlwaysHighlightGamepad + 201) = v283;
      (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)pAlwaysHighlightGamepad + 704LL))(pAlwaysHighlightGamepad);
      (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)pAlwaysHighlightGamepad + 808LL))(pAlwaysHighlightGamepad);
    }
    goto LABEL_370;
  }
  v390 = v4;
  if ( fabs(_mm_shuffle_ps(v393, v393, 85).m128_f32[0]) <= 0.0 )
  {
    v390 = v4;
    if ( fabs(_mm_shuffle_ps(v393, v393, 170).m128_f32[0]) <= 0.0 )
    {
      v390 = v4;
      if ( fabs(_mm_shuffle_ps(v393, v393, 255).m128_f32[0]) <= 0.0 )
      {
        v390 = v4;
        if ( fabs(*(float *)&v404) <= 0.0 )
        {
          v277 = (const wchar_t *)(unsigned int)_mm_cvtsi128_si32((__m128i)v393);
          v279 = _mm_cvtsi128_si32((__m128i)v393);
          LOBYTE(Src) = v279 & 4;
          *(_WORD *)((char *)&Src + 1) = 0;
          LOWORD(v429) = 0;
          BYTE2(v429) = 0;
          v280 = 0;
          v390 = v4;
          while ( *((_BYTE *)&Src + v280) == *((_BYTE *)&v429 + v280) )
          {
            if ( (unsigned __int64)++v280 >= 3 )
            {
              LOBYTE(Src) = v279 & 8;
              *(_WORD *)((char *)&Src + 1) = 0;
              LOWORD(v429) = 0;
              BYTE2(v429) = 0;
              v281 = 0;
              v390 = v4;
              while ( *((_BYTE *)&Src + v281) == *((_BYTE *)&v429 + v281) )
              {
                if ( (unsigned __int64)++v281 >= 3 )
                  goto LABEL_364;
              }
              break;
            }
          }
        }
      }
    }
  }
LABEL_370:
  if ( v86 )
    goto LABEL_371;
LABEL_375:
  pAlwaysHighlight2 = OptionsUIController->pAlwaysHighlight2;
  v287 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pAlwaysHighlight2 + 832LL);
  v288 = &OptionsUIController->pOptionsContext;
  v289 = sub_1417E5600(OptionsUIController->pOptionsContext, (unsigned __int8)byte_1443499CC, v277);
  v287(pAlwaysHighlight2, v289, 0);
  if ( v86 )
  {
LABEL_376:
    v290 = (_WORD *)v2->m128i_i64[0];
    v291 = v2->m128i_i64[1];
    if ( v291 == 23 )
    {
      v292 = L"confine_mouse_to_window";
      while ( *v290 == *v292 )
      {
        ++v290;
        ++v292;
        if ( !--v291 )
        {
          v288 = &OptionsUIController->pOptionsContext;
          goto LABEL_381;
        }
      }
    }
    goto LABEL_382;
  }
LABEL_381:
  pConfineMouseToWindow = OptionsUIController->pConfineMouseToWindow;
  v294 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pConfineMouseToWindow + 832LL);
  v295 = sub_1417E6DF0(*v288);
  v294(pConfineMouseToWindow, v295, 0);
  if ( v86 )
  {
LABEL_382:
    v296 = (_WORD *)v2->m128i_i64[0];
    v297 = v2->m128i_i64[1];
    if ( v297 == 16 )
    {
      v298 = L"mouse_wheel_zoom";
      while ( *v296 == *v298 )
      {
        ++v296;
        ++v298;
        if ( !--v297 )
        {
          v288 = &OptionsUIController->pOptionsContext;
          goto LABEL_387;
        }
      }
    }
    goto LABEL_388;
  }
LABEL_387:
  pMouseWheelZoom = OptionsUIController->pMouseWheelZoom;
  v300 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pMouseWheelZoom + 832LL);
  v301 = sub_1417E6CD0();
  v300(pMouseWheelZoom, v301, 0);
  if ( v86 )
  {
LABEL_388:
    v302 = (_WORD *)v2->m128i_i64[0];
    v303 = v2->m128i_i64[1];
    if ( v303 == 10 )
    {
      v304 = L"hide_email";
      while ( *v302 == *v304 )
      {
        ++v302;
        ++v304;
        if ( !--v303 )
        {
          v288 = &OptionsUIController->pOptionsContext;
          goto LABEL_393;
        }
      }
    }
    goto LABEL_394;
  }
LABEL_393:
  pHideEmail = OptionsUIController->pHideEmail;
  v306 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pHideEmail + 832LL);
  v307 = sub_1417E12B0(*v288);
  v306(pHideEmail, v307, 0);
  if ( v86 )
  {
LABEL_394:
    v308 = (const wchar_t *)v2->m128i_i64[0];
    v309 = v2->m128i_i64[1];
    if ( v309 == 23 )
    {
      v310 = L"enable_profanity_filter";
      while ( *v308 == *v310 )
      {
        ++v308;
        ++v310;
        if ( !--v309 )
        {
          v288 = &OptionsUIController->pOptionsContext;
          goto LABEL_399;
        }
      }
    }
    goto LABEL_400;
  }
LABEL_399:
  pEnableProfanityFilter = OptionsUIController->pEnableProfanityFilter;
  v312 = *(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pEnableProfanityFilter + 832LL);
  v313 = sub_1417E8E10(*v288);
  v312(pEnableProfanityFilter, v313, 0);
  if ( !v86 )
  {
LABEL_404:
    pReduceUIAnimations = OptionsUIController->pReduceUIAnimations;
    if ( pReduceUIAnimations )
      (*(void (__fastcall **)(UISettingWidget *, _QWORD, _QWORD))(*(_QWORD *)pReduceUIAnimations + 832LL))(
        pReduceUIAnimations,
        0,
        0);
    goto LABEL_406;
  }
LABEL_400:
  v314 = (_WORD *)v2->m128i_i64[0];
  pReduceUIAnimations = (UISettingWidget *)v2->m128i_i64[1];
  if ( pReduceUIAnimations == (UISettingWidget *)32 )
  {
    v308 = L"reduce_user_interface_animations";
    while ( *v314 == *v308 )
    {
      ++v314;
      ++v308;
      pReduceUIAnimations = (UISettingWidget *)((char *)pReduceUIAnimations - 1);
      if ( !pReduceUIAnimations )
        goto LABEL_404;
    }
  }
LABEL_406:
  result = sub_1400E5B40(pReduceUIAnimations, v308, v314);
  if ( (_BYTE)result )
    return result;
  result = sub_1417EB810(OptionsUIController->pOptionsContext);
  LODWORD(Src) = result;
  if ( v86 )
  {
    v319 = (unsigned __int16 *)v2->m128i_i64[0];
    v318 = v2->m128i_i64[1];
    if ( v318 == 8 )
    {
      v317 = L"language";
      while ( 1 )
      {
        result = *v319;
        if ( (_WORD)result != *v317 )
          break;
        ++v319;
        ++v317;
        if ( !--v318 )
          goto LABEL_412;
      }
    }
  }
  else
  {
LABEL_412:
    v389.m128i_i64[0] = (__int64)L"Data/Languages.dat";
    v389.m128i_i64[1] = 18;
    v320 = v389;
    v392 = v389;
    v321 = sub_142088DA0(v318, v317, v319);
    v389 = v320;
    v322 = sub_1401435F0(v321, &v389, &v392);
    v429 = v322;
    (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)OptionsUIController->pLanguageDropdown + 840LL))(OptionsUIController->pLanguageDropdown);
    v326 = 0;
    v327 = (char *)(v322 + 40);
    for ( i = (char *)(v322 + 40); ; v327 = i )
    {
      if ( v322 )
      {
        if ( byte_1444EE6FD )
        {
          *(_QWORD *)(v322 + 240) = *(_QWORD *)(sub_142088DA0(v324, v323, v325) + 1536);
        }
        else
        {
          _InterlockedExchange64((volatile __int64 *)(v322 + 232), *(_QWORD *)(sub_142088DA0(v324, v323, v325) + 1536));
          v322 = v429;
        }
        sub_14208A290(v322);
      }
      v330 = *(_QWORD *)(*(_QWORD *)v327 + 8LL) - **(_QWORD **)v327;
      v331 = v330 / 208;
      if ( v326 >= (unsigned __int64)(v330 / 208) )
        break;
      if ( byte_1444EE6FD )
      {
        *(_QWORD *)(v322 + 240) = *(_QWORD *)(sub_142088DA0(v330, v331, v325) + 1536);
      }
      else
      {
        _InterlockedExchange64((volatile __int64 *)(v322 + 232), *(_QWORD *)(sub_142088DA0(v330, v331, v325) + 1536));
        v322 = v429;
      }
      sub_14208A290(v322);
      v335 = (unsigned int *)(**(_QWORD **)(v322 + 40) + 208LL * v326);
      if ( byte_1443499CF )
        v336 = (_DWORD)Src == *v335;
      else
        v336 = 1;
      v337 = sub_1400E5B40(v333, v332, v334);
      v323 = *v335;
      v325 = 0;
      v324 = (_DWORD)v323 == 6;
      if ( v324 == v337 && *((_BYTE *)v335 + 201) && (!*((_BYTE *)v335 + 202) || (_DWORD)Src == (_DWORD)v323) )
      {
        pLanguageDropdown = OptionsUIController->pLanguageDropdown;
        v339 = *(void (__fastcall **)(UISettingWidget *, __int64, _OWORD *, bool, _DWORD))(*(_QWORD *)pLanguageDropdown
                                                                                         + 832LL);
        v396.m128i_i64[0] = (__int64)v397;
        memset((char *)v397 + 4, 0, 52);
        LODWORD(v397[0]) = v323;
        *((_QWORD *)&v397[3] + 1) = &enum Loaders::LanguageId `RTTI Type Descriptor';
        v340 = sub_1401246E0(v416, v335 + 10);
        v339(pLanguageDropdown, v340, v397, v336, 0);
      }
      ++v326;
    }
    v423[0] = off_142F86A70;
    v423[1] = &Src;
    v424 = v423;
    v342 = sub_1417CD3E0(OptionsUIController->pLanguageDropdown, v423);
    v2 = k;
    if ( v424 )
    {
      v343 = *v424;
      LOBYTE(v343) = v424 != v423;
      (*(void (__fastcall **)(_QWORD *, __int64))(*v424 + 32LL))(v424, v343);
    }
    if ( !v342 )
      (*(void (__fastcall **)(UISettingWidget *, _QWORD))(*(_QWORD *)OptionsUIController->pLanguageDropdown + 848LL))(
        OptionsUIController->pLanguageDropdown,
        0);
    LOBYTE(v341) = byte_1443499CF == 0;
    result = (*(__int64 (__fastcall **)(UISettingWidget *, __int64))(*(_QWORD *)OptionsUIController->pLanguageDropdown
                                                                   + 80LL))(
               OptionsUIController->pLanguageDropdown,
               v341);
    _InterlockedDecrement((volatile signed __int32 *)(v322 + 60));
    if ( !v2->m128i_i64[1] )
    {
LABEL_449:
      v389.m128i_i64[0] = (__int64)L"Data/Languages.dat";
      v389.m128i_i64[1] = 18;
      v347 = v389;
      v392 = v389;
      v348 = sub_142088DA0(v345, v344, v346);
      v389 = v347;
      v349 = sub_1401435F0(v348, &v389, &v392);
      v429 = v349;
      (*(void (__fastcall **)(UISettingWidget *))(*(_QWORD *)OptionsUIController->pChatLangDropdown + 840LL))(OptionsUIController->pChatLangDropdown);
      pChatLangDropdown = OptionsUIController->pChatLangDropdown;
      v351 = *(void (__fastcall **)(UISettingWidget *, __int64, _OWORD *, __int64, _DWORD))(*(_QWORD *)pChatLangDropdown
                                                                                          + 832LL);
      k = (__m128i *)v397;
      memset((char *)v397 + 4, 0, 52);
      LODWORD(v397[0]) = 11;
      *((_QWORD *)&v397[3] + 1) = &enum Loaders::LanguageId `RTTI Type Descriptor';
      v352 = sub_1420B32A0(v416, 443);
      LOBYTE(v353) = 1;
      v351(pChatLangDropdown, v352, v397, v353, 0);
      v357 = 0;
      v358 = (__m128i *)(v349 + 40);
      for ( k = (__m128i *)(v349 + 40); ; v358 = k )
      {
        if ( v349 )
        {
          if ( byte_1444EE6FD )
          {
            *(_QWORD *)(v349 + 240) = *(_QWORD *)(sub_142088DA0(v355, v354, v356) + 1536);
          }
          else
          {
            _InterlockedExchange64(
              (volatile __int64 *)(v349 + 232),
              *(_QWORD *)(sub_142088DA0(v355, v354, v356) + 1536));
            v349 = v429;
          }
          sub_14208A290(v349);
        }
        v359 = *(_QWORD *)(v358->m128i_i64[0] + 8) - *(_QWORD *)v358->m128i_i64[0];
        v360 = v359 / 208;
        if ( v357 >= (unsigned __int64)(v359 / 208) )
          break;
        if ( byte_1444EE6FD )
        {
          *(_QWORD *)(v349 + 240) = *(_QWORD *)(sub_142088DA0(v359, v360, v356) + 1536);
        }
        else
        {
          _InterlockedExchange64((volatile __int64 *)(v349 + 232), *(_QWORD *)(sub_142088DA0(v359, v360, v356) + 1536));
          v349 = v429;
        }
        sub_14208A290(v349);
        v364 = (unsigned int *)(**(_QWORD **)(v349 + 40) + 208LL * v357);
        if ( byte_1443499CF )
          v365 = (_DWORD)Src == *v364;
        else
          v365 = 1;
        v366 = sub_1400E5B40(v362, v361, v363);
        v354 = *v364;
        v356 = 0;
        v355 = (_DWORD)v354 == 6;
        if ( v355 == v366 && *((_BYTE *)v364 + 201) && (!*((_BYTE *)v364 + 202) || (_DWORD)Src == (_DWORD)v354) )
        {
          v367 = OptionsUIController->pChatLangDropdown;
          v368 = *(void (__fastcall **)(UISettingWidget *, __int64, _OWORD *, bool, _DWORD))(*(_QWORD *)v367 + 832LL);
          v396.m128i_i64[0] = (__int64)v397;
          memset((char *)v397 + 4, 0, 52);
          LODWORD(v397[0]) = v354;
          *((_QWORD *)&v397[3] + 1) = &enum Loaders::LanguageId `RTTI Type Descriptor';
          v369 = sub_1401246E0(v416, v364 + 10);
          v368(v367, v369, v397, v365, 0);
        }
        ++v357;
      }
      if ( (unsigned __int8)sub_1417EBAF0(OptionsUIController->pOptionsContext) )
      {
        v374 = sub_1417EB980(OptionsUIController->pOptionsContext);
        if ( byte_1444EE6FD )
        {
          *(_QWORD *)(v349 + 240) = *(_QWORD *)(sub_142088DA0(v372, v371, v373) + 1536);
        }
        else
        {
          _InterlockedExchange64((volatile __int64 *)(v349 + 232), *(_QWORD *)(sub_142088DA0(v372, v371, v373) + 1536));
          v349 = v429;
        }
        sub_14208A290(v349);
        v378 = *(_DWORD **)(*(_QWORD *)(v349 + 40) + 8LL);
        if ( byte_1444EE6FD )
        {
          *(_QWORD *)(v349 + 240) = *(_QWORD *)(sub_142088DA0(v376, v375, v377) + 1536);
        }
        else
        {
          _InterlockedExchange64((volatile __int64 *)(v349 + 232), *(_QWORD *)(sub_142088DA0(v376, v375, v377) + 1536));
          v349 = v429;
        }
        sub_14208A290(v349);
        for ( m = **(_DWORD ***)(v349 + 40); m != v378; m += 52 )
        {
          if ( *m == v374 )
            break;
        }
        if ( byte_1444EE6FD )
        {
          *(_QWORD *)(v349 + 240) = *(_QWORD *)(sub_142088DA0(v380, v379, v381) + 1536);
        }
        else
        {
          _InterlockedExchange64((volatile __int64 *)(v349 + 232), *(_QWORD *)(sub_142088DA0(v380, v379, v381) + 1536));
          v349 = v429;
        }
        sub_14208A290(v349);
        v383 = v390;
        if ( m == *(_DWORD **)(*(_QWORD *)(v349 + 40) + 8LL) )
        {
          v389.m128i_i64[1] = 0;
          m = nullptr;
          v384 = &v389.m128i_i64[1];
          v385 = 0;
          v386 = v390 | 6;
        }
        else
        {
          v414 = v349;
          _InterlockedIncrement((volatile signed __int32 *)(v349 + 60));
          v349 = v429;
          *(_DWORD *)(v429 + 56) = dword_14382000C;
          v384 = &v414;
          v385 = v414;
          v386 = v383 | 5;
        }
        v396.m128i_i64[0] = (__int64)m;
        v396.m128i_i64[1] = v385;
        *v384 = 0;
        if ( (v386 & 2) != 0 )
        {
          v386 &= ~2u;
          if ( v389.m128i_i64[1] )
          {
            _InterlockedDecrement((volatile signed __int32 *)(v389.m128i_i64[1] + 60));
            v349 = v429;
            v385 = v396.m128i_i64[1];
          }
        }
        if ( (v386 & 1) != 0 && v414 )
        {
          _InterlockedDecrement((volatile signed __int32 *)(v414 + 60));
          v349 = v429;
          v385 = v396.m128i_i64[1];
        }
        if ( !m )
          goto LABEL_494;
        LODWORD(k) = *m;
        v425[0] = off_142F86A70;
        v425[1] = &k;
        v426 = v425;
        v387 = sub_1417CD3E0(OptionsUIController->pChatLangDropdown, v425);
        if ( v426 )
        {
          v388 = *v426;
          LOBYTE(v388) = v426 != v425;
          (*(void (__fastcall **)(_QWORD *, __int64))(*v426 + 32LL))(v426, v388);
        }
        if ( !v387 )
LABEL_494:
          (*(void (__fastcall **)(UISettingWidget *, _QWORD))(*(_QWORD *)OptionsUIController->pChatLangDropdown + 848LL))(
            OptionsUIController->pChatLangDropdown,
            0);
        if ( v385 )
        {
          _InterlockedDecrement((volatile signed __int32 *)(v385 + 60));
          v349 = v429;
        }
      }
      LOBYTE(v370) = byte_1443499CF == 0;
      result = (*(__int64 (__fastcall **)(UISettingWidget *, __int64))(*(_QWORD *)OptionsUIController->pChatLangDropdown
                                                                     + 80LL))(
                 OptionsUIController->pChatLangDropdown,
                 v370);
      _InterlockedDecrement((volatile signed __int32 *)(v349 + 60));
      return result;
    }
  }
  v346 = (unsigned __int16 *)v2->m128i_i64[0];
  v345 = v2->m128i_i64[1];
  if ( v345 == 13 )
  {
    v344 = L"chat_language";
    while ( 1 )
    {
      result = *v346;
      if ( (_WORD)result != *v344 )
        break;
      ++v346;
      ++v344;
      if ( !--v345 )
        goto LABEL_449;
    }
  }
  return result;
}
