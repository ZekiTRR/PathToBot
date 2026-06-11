__int64 __fastcall sub_140DA2C30(LPVOID lpThreadParameter)
{
  __int64 result; // rax
  const std::exception *v2; // rbx
  __int64 v3; // rax
  const std::exception *v4; // [rsp+20h] [rbp-38h] BYREF
  __int128 v5; // [rsp+30h] [rbp-28h] BYREF
  __int64 v6; // [rsp+40h] [rbp-18h] BYREF

  try
  {
    sub_1401D17A0();
    result = 0;
  }
  catch ( const std::exception *v4 )
  {
    v2 = v4;
    v3 = (*(__int64 (__fastcall **)(const std::exception *))(*(_QWORD *)v4 + 8LL))(v4);
    v5 = *(_OWORD *)sub_1400E5DC0(&v6, v3);
    sub_140DA2D80(&v5);
    sub_14208A6F0(v2);
    abort();
  }
  return result;
}
