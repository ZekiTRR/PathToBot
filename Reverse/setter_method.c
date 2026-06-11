__int64 __fastcall setter_method(unsigned __int8 *a1, unsigned __int8 a2, char a3)
{
  bool v5; // zf
  __int64 result; // rax

  if ( a1[0x4D2] != a2 )
  {
    v5 = a1[0x4D4] == 0;
    a1[0x4D2] = a2;
    if ( !v5 )
      (*(void (__fastcall **)(_QWORD))(**((_QWORD **)a1 + 127) + 96LL))(*((_QWORD *)a1 + 127));
    if ( a3 )
      (*(void (__fastcall **)(unsigned __int8 *))(*(_QWORD *)a1 + 848LL))(a1);
    return (*(__int64 (__fastcall **)(unsigned __int8 *, _QWORD))(*(_QWORD *)a1 + 840LL))(a1, a1[1234]);
  }
  return result;
}
