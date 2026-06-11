// Здесь происходит изменение FOV

void __fastcall sub_14010B860(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // rdi
  __int64 v5; // rbx
  __int64 v6; // rax
  float *v7; // rax
  float v8; // xmm7_4
  float v9; // xmm9_4
  unsigned int v10; // ecx
  float v11; // xmm3_4
  float *v12; // r8
  float v13; // xmm7_4
  float v14; // xmm5_4
  float v15; // xmm9_4
  float v16; // xmm3_4
  float v17; // xmm5_4
  unsigned int v18; // r8d
  float v19; // xmm7_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm9_4
  unsigned int v23; // r11d
  unsigned int v24; // eax
  _BYTE v25[16]; // [rsp+20h] [rbp-58h] BYREF
  float v26; // [rsp+90h] [rbp+18h] BYREF
  float v27; // [rsp+94h] [rbp+1Ch]
  char v28; // [rsp+98h] [rbp+20h] BYREF

  if ( !*(_BYTE *)a3 )
  {
    if ( *(_QWORD *)(a1 + 776) )
    {
      v4 = *(_QWORD *)(a1 + 800);
      if ( (unsigned __int8)sub_1417E6CD0(*(_QWORD *)(v4 + 152)) )
      {
        if ( byte_1443499CC != 2 )
        {
          v5 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(v4 + 128) + 936LL))(*(_QWORD *)(v4 + 128));
          v6 = (*(__int64 (__fastcall **)(__int64, char *))(*(_QWORD *)v5 + 128LL))(v5, &v28);
          v7 = (float *)sub_1417827E0(v5, v25, v6);
          v8 = *v7;
          v9 = v7[1];
          sub_1400E8740(v5, &v26);
          v10 = *(_DWORD *)(v4 + 1184);
          v11 = v8;
          v13 = v8 + *v12;
          v14 = v9;
          v15 = v9 + v12[1];
          v16 = v11 * v26;
          v17 = v14 * v27;
          v18 = v10 + *(_DWORD *)(v4 + 1188);
          v19 = (float)(v13 * v26) - v16;
          v20 = v16 + (float)(int)xmmword_1443499F0;
          v21 = v17 + (float)SDWORD1(xmmword_1443499F0);
          v22 = (float)(v15 * v27) - v17;
          v23 = (int)(float)((float)(int)xmmword_1443499F0 + *(float *)(a3 + 12));
          if ( v10 < (int)v20 )
            v10 = (int)v20;
          v24 = (int)(float)((float)SDWORD1(xmmword_1443499F0) + *(float *)(a3 + 16));
          if ( v23 >= v10 && v24 >= (int)v21 )
          {
            if ( (int)(float)(v19 + v20) < v18 )
              v18 = (int)(float)(v19 + v20);
            if ( v23 < v18 && v24 < (int)(float)(v22 + v21) )
            {
              if ( !*(_BYTE *)(v4 + 1272) )

                  /*Запись в FOV */
                *(float *)(v4 + 1200) = fminf(
                                          fmaxf((float)((float)*(int *)(a3 + 24) * 0.2) + *(float *)(v4 + 1200), 0.0),
                                          1.0);
              *(_BYTE *)a3 = 1;
            }
          }
        }
      }
    }
  }
}
