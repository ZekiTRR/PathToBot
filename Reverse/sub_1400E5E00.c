_QWORD *__fastcall sub_1400E5E00(_QWORD *a1, __int64 a2)
{
  __int64 v2; // rax

  *a1 = a2;
  v2 = -1;
  do
    ++v2;
  while ( *(_WORD *)(a2 + 2 * v2) );
  a1[1] = v2;
  return a1;
}
