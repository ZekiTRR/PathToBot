// My code
#include "struct.h" // Structure HUD::Player

__int64 __fastcall sub_141DC7620(__int64 a1, __int64 *a2, float a3, __int64 a4, float a5, float a6, char a7)
{
  __int64 v7; // xmm0_8
  char v8; // al
  float v9; // xmm3_4
  __int64 v10; // rcx
  __int64 *v11; // r9
  __int64 v12; // xmm1_8
  __int64 v13; // r10
  _QWORD *v14; // rax
  Player *v15; // r10
  float v16; // xmm4_4
  float v17; // xmm5_4
  float v19; // xmm0_4
  char v20; // [rsp+30h] [rbp+8h] BYREF

  v7 = *a2;
  v8 = a7;
  *(float *)(a1 + 12) = a3;
  *(_QWORD *)(a1 + 4) = v7;
  *(_BYTE *)a1 = v8;
  *(float *)&v7 = sub_14014EB60();
  v9 = a5;
  *(_DWORD *)(v10 + 40) = v7;
  v10 += 16;
  v12 = *v11;
  *(float *)(v13 + 24) = v9;
  *(_QWORD *)v10 = v12;
  v14 = (_QWORD *)sub_1400E6210(v10, &v20);
  *(_QWORD *)&v15->pad_000[28] = *v14;
  if ( v17 != v16 || v9 != v16 )
    *(float *)&v15->pad_000[36] = v9 - v17;
  v19 = 1.0 / a6;
  *(_QWORD *)v15->pad_038 = 0;
  *(_DWORD *)&v15->pad_038[8] = 1065353216;
  v15->Speed = v19;
  return 0;
}
