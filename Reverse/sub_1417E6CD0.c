char sub_1417E6CD0()
{
  __int64 v0; // rcx
  __int64 v1; // rax
  unsigned __int64 v2; // r11
  _WORD **v3; // r9
  _WORD *v4; // rdx
  unsigned __int64 v5; // r10
  const wchar_t *v6; // r8
  __int64 v7; // rcx
  _WORD *v8; // rdx
  const wchar_t *v9; // r8
  __int64 v10; // rcx
  _QWORD v12[2]; // [rsp+20h] [rbp-28h] BYREF
  _QWORD v13[2]; // [rsp+30h] [rbp-18h] BYREF

  v12[1] = 16;
  v12[0] = L"mouse_wheel_zoom";
  v13[0] = L"UI";
  v0 = *(_QWORD *)sub_1417E05B0();
  v13[1] = 2;
  v1 = sub_1417FFE30(v0, v13, v12);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 56);
    v3 = (_WORD **)(v1 + 32);
    v4 = (_WORD *)(v1 + 32);
    if ( v2 > 7 )
      v4 = *v3;
    v5 = *(_QWORD *)(v1 + 48);
    v6 = L"true";
    v7 = v5;
    if ( v5 > 4 )
      v7 = 4;
    if ( v7 )
    {
      while ( *v4 == *v6 )
      {
        ++v4;
        ++v6;
        if ( !--v7 )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      if ( v5 == 4 )
      {
        LOBYTE(v1) = 1;
        return v1;
      }
    }
    v8 = (_WORD *)(v1 + 32);
    if ( v2 > 7 )
      v8 = *v3;
    v9 = L"false";
    v10 = *(_QWORD *)(v1 + 48);
    if ( v5 > 5 )
      v10 = 5;
    for ( ; v10; --v10 )
    {
      if ( *v8 != *v9 )
        break;
      ++v8;
      ++v9;
    }
    LOBYTE(v1) = 0;
  }
  return v1;
}
