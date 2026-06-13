__int64 __fastcall sub_1415787A0(__int64 a1)
{
  __int64 result; // rax
  __int64 *v2; // r14
  __int64 v3; // rbp
  __int64 v4; // rdi
  unsigned int v5; // ebx
  unsigned __int64 v6; // rsi
  __int64 v7; // rcx
  __int64 v8; // rbx
  __int64 i; // rdi
  _BYTE *v10; // rcx

  result = *(_QWORD *)(a1 + 72);
  v2 = (__int64 *)(a1 + 8);
  v3 = a1 + 8 + 8 * result;
  if ( a1 + 8 != v3 )
  {
    do
    {
      v4 = *v2;
      if ( !(*(unsigned __int8 (__fastcall **)(_QWORD))(**(_QWORD **)(*v2 + 120) + 344LL))(*(_QWORD *)(*v2 + 120))
        || (result = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(v4 + 120) + 352LL))(*(_QWORD *)(v4 + 120)),
            (_BYTE)result) )
      {
        result = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(v4 + 120) + 360LL))(*(_QWORD *)(v4 + 120));
        if ( !(_BYTE)result || (*(_BYTE *)(v4 + 140) & 0x40) != 0 )
          result = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)(v4 + 120) + 344LL))(*(_QWORD *)(v4 + 120));
      }
      v5 = 0;
      v6 = (__int64)(*(_QWORD *)(v4 + 24) - *(_QWORD *)(v4 + 16)) >> 3;
      if ( v6 )
      {
        do
        {
          v7 = *(_QWORD *)(*(_QWORD *)(v4 + 16) + 8LL * (int)v5);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 72LL))(v7);
          result = ++v5;
        }
        while ( v5 < v6 );
      }
      v8 = *(_QWORD *)(v4 + 88);
      for ( i = *(_QWORD *)(v4 + 96); v8 != i; v8 += 16 )
      {
        v10 = *(_BYTE **)(v8 + 8);
        if ( v10 )
        {
          if ( (v10[8] & 1) == 0 )
            result = (*(__int64 (__fastcall **)(_BYTE *))(*(_QWORD *)v10 + 16LL))(v10);
        }
      }
      ++v2;
    }
    while ( v2 != (__int64 *)v3 );
  }
  return result;
}
