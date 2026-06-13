// Hidden C++ exception states: #wind=1
__int64 __fastcall sub_140DA2420(__int64 a1)
{
  __int64 v2; // rbx
  __int64 result; // rax
  __int64 v4; // rdx
  volatile signed __int32 *v5; // rcx
  int v6; // eax
  _BYTE *v7; // rdx
  _BYTE *v8; // rdx
  _BYTE v9[16]; // [rsp+20h] [rbp-58h] BYREF
  _BYTE v10[56]; // [rsp+30h] [rbp-48h] BYREF
  _BYTE *v11; // [rsp+68h] [rbp-10h]

  while ( 1 )
  {
    v2 = *(_QWORD *)(a1 + 8);
    if ( *(_BYTE *)(*(_QWORD *)(*(_QWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + 360LL) + 44LL)
      && !*(_BYTE *)(v2 + 374) )
    {
      if ( (unsigned int)sub_142B1EAF0(v2 + 216) )
        std::_Throw_Cpp_error(5);
      if ( *(_DWORD *)(v2 + 292) == 0x7FFFFFFF )
      {
        *(_DWORD *)(v2 + 292) = 2147483646;
        std::_Throw_Cpp_error(6);
      }
      while ( !*(_BYTE *)(v2 + 374) )
        sub_142B1BBE8(v2 + 296, v2 + 216);
      Mtx_unlock((_Mtx_t)(v2 + 216));
    }
    result = sub_140DA1BA0(v2, v9);
    if ( !v9[0] )
      break;
    if ( !v11 )
      sub_142B1DFF0();
    (*(void (__fastcall **)(_BYTE *))(*(_QWORD *)v11 + 16LL))(v11);
    v5 = *(volatile signed __int32 **)(v2 + 40);
    v6 = *(_DWORD *)(v2 + 32);
    _InterlockedDecrement(v5);
    if ( !v6 )
      _InterlockedDecrement(v5 + 1);
    LOBYTE(v4) = 1;
    sub_140D9F130(v2, v4);
    if ( v11 )
    {
      v7 = v10;
      LOBYTE(v7) = v11 != v10;
      (*(void (__fastcall **)(_BYTE *, _BYTE *))(*(_QWORD *)v11 + 32LL))(v11, v7);
    }
  }
  if ( v11 )
  {
    v8 = v10;
    LOBYTE(v8) = v11 != v10;
    return (*(__int64 (__fastcall **)(_BYTE *, _BYTE *))(*(_QWORD *)v11 + 32LL))(v11, v8);
  }
  return result;
}
