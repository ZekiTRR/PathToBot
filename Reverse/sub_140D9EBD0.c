void __fastcall sub_140D9EBD0(__int64 a1)
{
  __int64 v2; // rcx
  _BYTE pExceptionObject[40]; // [rsp+20h] [rbp-28h] BYREF

  sub_140D9EA90();
  if ( CoInitializeEx(nullptr, 0) < 0 )
  {
    sub_1400E1CD0(pExceptionObject, "CoInitializeEx failed");
    throw (std::runtime_error *)pExceptionObject;
  }
  v2 = *(_QWORD *)(a1 + 136);
  if ( !v2 )
    sub_142B1DFF0();
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
  CoUninitialize();
}
