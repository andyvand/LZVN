/*
 * AnV - C conversion of lzvn_encode_partial
 * This is the main compressor for LZVN
 */

#include <stdint.h>
#include <xmmintrin.h>
#include <string.h>
#include <stdlib.h>

#define LODWORD(X) *(unsigned int *)&X

int bsf(int src)
{
    int retval = 0;
    while (src)
    {
        if (src & 1)
        {
            return retval;
        }

        ++retval;
        src >>= 1;
    }

    return 0;
}

size_t lzvn_encode_partial(long long a1, unsigned long long a2, unsigned int *a3, unsigned long long a4, long long a5, long long a6)
{
  unsigned int *v6; // r12@1
  signed long long v7; // rdx@1
  signed long long v8; // rbx@2
  signed long long v9; // rsi@3
  unsigned int v10; // er10@3
  __m128i v11; // xmm0@3
  long long v12; // rdx@3
  unsigned long long v13; // r11@7
  signed long long v14; // rax@7
  signed long long v15; // r8@8
  signed long long v16; // r14@9
  unsigned long long v17; // r13@9
  unsigned long long v18; // rsi@9
  signed long long v19; // rdi@9
  unsigned long long v20; // r8@9
  unsigned long long v21; // r11@9
  unsigned long long v22; // rdx@9
  unsigned long long v23; // rcx@9
  unsigned int v24; // eax@9
  unsigned int v25; // ebx@11
  signed long long v26; // rax@11
  __m128i v27; // xmm0@11
  __m128i v28; // xmm1@11
  __m128i v29; // xmm3@11
  __m128i v30; // xmm4@11
  __m128i v31; // xmm2@11
  __m128i v32; // xmm1@13
  int v33; // ecx@13
  signed long long v34; // rax@13
  unsigned long long v40; // rdi@14
  unsigned long long v41; // r11@14
  unsigned long long v42; // rcx@14
  int v43; // ecx@16
  long long v44; // r14@16
  unsigned long long v45; // r15@16
  signed long long i; // rax@18
  unsigned long long v47; // r15@19
  unsigned long long v48; // r10@19
  unsigned long long v49; // rbx@19
  signed long long v50; // rdx@19
  unsigned long long v51; // rdi@19
  unsigned long long v52; // rax@21
  int v53; // ebx@22
  unsigned int v54; // edi@22
  signed long long v55; // rdx@22
  long long v58; // rbx@27
  long long v59; // rax@28
  long long v60; // r8@31
  signed long long v61; // rdx@31
  signed long long v64; // rdx@39
  long long v66; // rax@42
  unsigned long long v67; // rcx@42
  unsigned long long v68; // r15@43
  unsigned long long v69; // r9@43
  unsigned long long v70; // rdi@44
  unsigned long long v71; // rsi@44
  signed long long v72; // rdx@45
  unsigned long long v73; // rdx@47
  int v74; // ebx@48
  unsigned int v75; // esi@48
  signed long long v76; // rdi@48
  unsigned long long v79; // rdx@53
  unsigned long long v80; // r14@54
  int v81; // edi@56
  signed long long v82; // rdx@57
  signed long long v84; // rdx@61
  unsigned long long v85; // r14@61
  long long v87; // rax@64
  unsigned long long v88; // r9@64
  unsigned long long v89; // r10@65
  unsigned long long v90; // r15@65
  unsigned long long v91; // rsi@66
  signed long long v92; // rdx@67
  unsigned long long v93; // rdx@69
  int v94; // ebx@70
  unsigned int v95; // esi@70
  signed long long v96; // rdi@70
  unsigned long long v99; // rdi@75
  unsigned long long v100; // rdx@76
  int v101; // ebx@78
  signed long long v102; // rdi@79
  signed long long v104; // rdx@83
  long long v106; // rax@86
  unsigned long long v107; // r9@86
  unsigned long long v108; // rsi@88
  signed long long v109; // rdx@89
  unsigned long long v110; // rdx@91
  int v111; // ebx@92
  unsigned int v112; // esi@92
  signed long long v113; // rdi@92
  unsigned long long v116; // rdi@97
  unsigned long long v117; // rdx@98
  int v118; // ebx@100
  signed long long v119; // rdi@101
  unsigned long long v120; // r11@105
  unsigned long long v121; // rbx@105
  unsigned long long v122; // r14@106
  int v123; // edx@106
  signed long long v124; // rax@106
  unsigned long long v127; // rsi@110
  signed long long j; // rax@111
  unsigned long long v129; // rax@114
  int v130; // edi@115
  unsigned int v131; // esi@115
  signed long long v132; // rdx@115
  long long v135; // rcx@118
  long long v136; // rdx@119
  unsigned long long v137; // rax@119
  unsigned long long v138; // rcx@122
  unsigned long long v139; // rax@127
  unsigned long long v140; // rcx@127
  unsigned long long v141; // r10@134
  char *v142; // rsi@136
  unsigned long long v143; // r8@136
  signed long long v144; // r13@136
  signed long long v145; // rax@137
  unsigned long long v146; // rdx@141
  signed long long v147; // rbx@145
  unsigned long long v148; // rcx@147
  signed long long v149; // rdi@150
  unsigned long long v150; // rcx@153
  signed long long v151; // rax@153
  int v152; // ebx@153
  char *v153; // rsi@158
  unsigned long long v154; // r8@158
  signed long long v155; // r13@158
  signed long long v156; // rax@159
  unsigned long long v157; // rdx@163
  signed long long v158; // rdx@167
  unsigned long long v159; // rcx@169
  signed long long v160; // rax@172
  unsigned long long v161; // rdi@174
  unsigned long long v162; // rcx@175
  signed long long v163; // rdx@175
  int v164; // er15@175
  signed long long v165; // rax@180
  signed long long v166; // rax@182
  unsigned int v167; // edi@190
  signed long long v168; // rsi@198
  signed long long v169; // rax@206
  signed long long v170; // rax@208
  signed long long v171; // rsi@214
  signed long long v172; // rax@222
  signed long long v173; // rax@224
  signed long long v174; // rbx@235
  signed long long v175; // rdx@236
  const void *v176; // r15@238
  size_t v177; // r14@238
  size_t v178; // r13@239
  unsigned long long v179; // rbx@243
  signed long long v180; // r12@243
  const void *v181; // rsi@247
  unsigned long long v182; // r15@247
  signed long long v183; // rbx@247
  long long v185; // [sp+8h] [bp-E8h]@1
  signed long long v186; // [sp+10h] [bp-E0h]@9
  signed long long v187; // [sp+18h] [bp-D8h]@9
  signed long long v188; // [sp+20h] [bp-D0h]@9
  unsigned long long v189; // [sp+28h] [bp-C8h]@7
  long long v190; // [sp+30h] [bp-C0h]@1
  signed long long v191; // [sp+38h] [bp-B8h]@9
  signed long long v192; // [sp+38h] [bp-B8h]@236
  unsigned int *v193; // [sp+40h] [bp-B0h]@1
  unsigned long long v194; // [sp+48h] [bp-A8h]@13
  unsigned long long v195; // [sp+50h] [bp-A0h]@13
  unsigned long long v196; // [sp+58h] [bp-98h]@83
  long long v197; // [sp+60h] [bp-90h]@9
  unsigned int v198; // [sp+6Ch] [bp-84h]@11
  unsigned long long v199; // [sp+70h] [bp-80h]@13
  unsigned long long v200; // [sp+70h] [bp-80h]@131
  signed long long v201; // [sp+78h] [bp-78h]@9
  unsigned long long v202; // [sp+80h] [bp-70h]@14
  unsigned long long v203; // [sp+88h] [bp-68h]@7
  unsigned long long v204; // [sp+90h] [bp-60h]@14
  unsigned long long v205; // [sp+98h] [bp-58h]@39
  unsigned long long v206; // [sp+A0h] [bp-50h]@9
  signed long long v207; // [sp+A8h] [bp-48h]@14
  signed long long v208; // [sp+A8h] [bp-48h]@238
  unsigned long long v209; // [sp+B0h] [bp-40h]@18
  unsigned long long v210; // [sp+B0h] [bp-40h]@19
  signed long long v211; // [sp+B0h] [bp-40h]@236
  unsigned long long v212; // [sp+B8h] [bp-38h]@87
  signed long long v213; // [sp+B8h] [bp-38h]@236
  size_t retval;
  int _CF;
  int _ZF;
  int _RDX;
  int _RDI;
  int _RSI;

  v190 = a6;
  v185 = a5;
  v6 = a3;
  v193 = a3;
  v7 = 0LL;
  if ( a2 < 8 )
  {
    v8 = 0LL;
  }
  else
  {
    v8 = 0LL;
    if ( a4 >= 8 )
    {
      v9 = a2 - 8;
      v10 = *v6;
      v11 = _mm_shuffle_epi32(_mm_cvtsi32_si128(*v6), 0);
      v12 = 0LL;
      do
      {
        memset((void *)(a6 + v12), 0, sizeof(__m128i));
        _mm_store_si128((__m128i *)(a6 + v12 + 16), v11);
        v12 += 32LL;
      }
      while ( v12 != 0x80000 );
      if ( a4 > 0xFFFFFFFF )
        a4 = 0xFFFFFFFFLL;
      v203 = a4;
      v13 = a1 + v9;
      v189 = a1 + v9;
      v14 = 0LL;
      if ( a4 < 9 )
      {
        v15 = a1;
        goto LABEL_233;
      }
      v15 = a1;
      if ( v9 > 0 )
      {
        v16 = a1 + v9;
        v203 = a4;
        v186 = (signed long long)((char *)v6 - 1);
        v197 = 0LL;
        v201 = a1;
        v17 = 0LL;
        v18 = 0LL;
        v206 = 0LL;
        v191 = 0LL;
        v188 = a1;
        v187 = a1;
        v19 = 0LL;
        v20 = 0LL;
        v21 = 0LL;
        v22 = 0LL;
        v23 = 0LL;
        v24 = v10;
        while ( 1 )
        {
          v198 = v24;
          v25 = v24;
          v26 = 32LL * ((4161 * (v24 & 0xFFFFFF) >> 12) & 0x3FFF);
          v27 = _mm_load_si128((const __m128i *)(a6 + v26));
          v28 = _mm_load_si128((const __m128i *)(a6 + v26 + 16));
          v29 = _mm_shuffle_epi32(v28, -112);
          v30 = _mm_shuffle_epi32(v27, -112);
          v30 = _mm_cvtsi32_si128(v18);
          v31 = _mm_cvtsi32_si128(v25);
          v29 = v31;
          *(__m128i *)(a6 + v26 + 16) = v29;
          *(__m128i *)(a6 + v26) = v30;
          if ( !v18 || v18 < v17 )
          {
            v47 = v23;
            v48 = v22;
            v49 = v21;
            v210 = v20;
            v50 = v19;
            v51 = v206;
            a4 = v203;
            v13 = v16;
            goto LABEL_228;
          }
          v194 = v19;
          v199 = v23;
          v195 = v21;
          v32 = _mm_xor_si128(v28, _mm_shuffle_epi32(v31, 0));
          v33 = _mm_cvtsi128_si32(v32);
          v34 = 4LL;
          if ( v33 )
          {
            v202 = v22;
            retval = (unsigned int)v33;
            retval = bsf(retval);
            v207 = 0LL;
            v204 = 0LL;
            v40 = 0LL;
            v41 = 0LL;
            v42 = 0LL;
            if ( retval < 0x18 )
              goto LABEL_39;
            v34 = retval >> 3;
          }
          v202 = v22;
          v43 = _mm_cvtsi128_si32(v27);
          v44 = (unsigned int)v43;
          v45 = v18 - (unsigned int)v43;
          v207 = 0LL;
          v204 = 0LL;
          v40 = 0LL;
          v41 = 0LL;
          v42 = 0LL;
          if ( v45 <= 0xFFFF )
          {
            v41 = v34 + v18;
            if ( v34 == 4 )
            {
              v209 = v20;
              for ( i = v18 + 8; ; i = v52 + 8 )
              {
                _CF = i < v203;
                v52 = v41;
                if ( _CF )
                {
                  v53 = *(unsigned int *)((char *)v6 + v41);
                  v54 = *(unsigned int *)((char *)v6 + v41 - v45);
                  v55 = 4LL;
                  if ( v53 != v54 )
                  {
                    _RDI = v53 ^ v54;
                    _RDX = bsf(_RDI);
                    v55 = _RDX >> 3;
                  }
                  v41 += v55;
                  if ( v55 == 4 )
                    continue;
                }
                break;
              }
            }
            else
            {
              v209 = v20;
            }
            v58 = 0LL;
            do
            {
              v59 = v58;
              v42 = v18 + v58;
              if ( !(v58 + v44) )
                break;
              if ( v42 <= v17 )
                break;
              --v58;
            }
            while ( *(unsigned char *)(v186 + v18 + v59) == *(unsigned char *)(v186 + v44 + v59) );
            v60 = v45 > 0x5FF;
            v61 = v41 + v197 + -2 - v60 - v59;
            v40 = v41 + v197 - v59;
            _ZF = (v59 + v60 + v18 + 2 - v41 != 0 || v41 > 1) == 0;
            if ( v59 + v60 + v18 + 2 - v41 == 0 && v41 <= 1 )
              v61 = 0LL;
            v207 = v61;
            if ( v59 + v60 + v18 + 2 - v41 == 0 && v41 <= 1 )
            {
              v45 = 0LL;
              if ( v59 + v60 + v18 + 2 - v41 == 0 && v41 <= 1 )
              {
                v40 = 0LL;
                if ( v59 + v60 + v18 + 2 - v41 == 0 && v41 <= 1 )
                {
                  v41 = 0LL;
                  if ( _ZF )
                    v42 = 0LL;
                }
              }
            }
            v204 = v45;
            v20 = v209;
          }
LABEL_39:
          v205 = v40;
          v210 = v42;
          retval = _mm_cvtsi128_si32(_mm_shuffle_epi32(v32, 1));
          v64 = 4LL;
          if ( (unsigned int)retval )
          {
            retval = (unsigned int)retval;
            _RDX = bsf(retval);
            if ( _RDX < 0x18 )
              goto LABEL_43;
            v64 = _RDX >> 3;
          }
          v66 = (unsigned int)_mm_cvtsi128_si32(_mm_shuffle_epi32(v27, 1));
          v67 = v18 - (unsigned int)v66;
          if ( v67 > 0xFFFF )
          {
LABEL_43:
            v68 = v18;
            v69 = v203;
            goto LABEL_61;
          }
          v70 = v18;
          v71 = v64 + v18;
          if ( v64 == 4 )
          {
            v72 = v70 + 8;
            v68 = v70;
            while ( 1 )
            {
              _CF = v72 < v203;
              v73 = v71;
              if ( !_CF )
                break;
              v74 = *(unsigned int *)((char *)v6 + v71);
              v75 = *(unsigned int *)((char *)v6 + v71 - v67);
              v76 = 4LL;
              if ( v74 != v75 )
              {
                _RSI = v74 ^ v75;
                _RDI = bsf(_RSI);
                v76 = _RDI >> 3;
              }
              v71 = v76 + v73;
              if ( v76 != 4 )
                break;
              v72 = v73 + 8;
            }
          }
          else
          {
            v68 = v70;
          }
          v69 = v203;
          v79 = v68;
          do
          {
            v80 = v79;
            if ( !v66 )
              break;
            if ( v79 <= v17 )
              break;
            --v79;
            v81 = *((unsigned char *)v6 + v66-- - 1);
          }
          while ( *((unsigned char *)v6 + v80 - 1) == v81 );
          v82 = v71 - v80 - ((v67 > 0x5FF) | 2LL);
          if ( v82 > (unsigned long long)v207 || ((v82 == v207) && (v71 > v41) + 1))
          {
            v207 = v71 - v80 - ((v67 > 0x5FF) | 2LL);
            v204 = v67;
            v205 = v71 - v80;
            v41 = v71;
            v210 = v80;
          }
LABEL_61:
          retval = _mm_cvtsi128_si32(_mm_unpackhi_epi32(v32, v32));
          v84 = 4LL;
          v85 = v69;
          if ( (unsigned int)retval )
          {
            retval = (unsigned int)retval;
            _RDX = bsf(retval);
            if ( _RDX < 0x18 )
              goto LABEL_65;
            v84 = _RDX >> 3;
          }
          v87 = (unsigned int)_mm_cvtsi128_si32(_mm_unpackhi_epi32(v27, v27));
          v88 = v68 - (unsigned int)v87;
          if ( v88 > 0xFFFF )
          {
LABEL_65:
            v89 = v68;
            v90 = v202;
            goto LABEL_83;
          }
          v91 = v84 + v68;
          if ( v84 == 4 )
          {
            v92 = v68 + 8;
            v89 = v68;
            while ( 1 )
            {
              _CF = v92 < v85;
              v93 = v91;
              if ( !_CF )
                break;
              v94 = *(unsigned int *)((char *)v6 + v91);
              v95 = *(unsigned int *)((char *)v6 + v91 - v88);
              v96 = 4LL;
              if ( v94 != v95 )
              {
                _RSI = v94 ^ v95;
                _RDI = bsf(_RSI);
                v96 = _RDI >> 3;
              }
              v91 = v96 + v93;
              if ( v96 != 4 )
                break;
              v92 = v93 + 8;
            }
          }
          else
          {
            v89 = v68;
          }
          v99 = v89;
          v90 = v202;
          do
          {
            v100 = v99;
            if ( !v87 )
              break;
            if ( v99 <= v17 )
              break;
            --v99;
            v101 = *((unsigned char *)v6 + v87-- - 1);
          }
          while ( *((unsigned char *)v6 + v100 - 1) == v101 );
          v102 = v91 - v100 - ((v88 > 0x5FF) | 2LL);
          if ( v102 > (unsigned long long)v207 || ((v102 == v207) && (v91 > v41) + 1))
          {
            v207 = v91 - v100 - ((v88 > 0x5FF) | 2LL);
            v204 = v88;
            v205 = v91 - v100;
            v41 = v91;
            v210 = v100;
          }
LABEL_83:
          v196 = v41;
          LODWORD(retval) = _mm_cvtsi128_si32(_mm_shuffle_epi32(v32, 3));
          v104 = 4LL;
          if ( (unsigned int)retval )
          {
            retval = (unsigned int)retval;
            _RDX = bsf(retval);
            if ( _RDX < 0x18 )
              goto LABEL_87;
            v104 = _RDX >> 3;
          }
          v106 = (unsigned int)_mm_cvtsi128_si32(_mm_shuffle_epi32(v27, 3));
          v107 = v89 - (unsigned int)v106;
          if ( v107 > 0xFFFF )
          {
LABEL_87:
            v212 = v89;
            goto LABEL_105;
          }
          v108 = v104 + v89;
          if ( v104 == 4 )
          {
            v109 = v89 + 8;
            v212 = v89;
            while ( 1 )
            {
              _CF = v109 < v85;
              v110 = v108;
              if ( !_CF )
                break;
              v111 = *(unsigned int *)((char *)v6 + v108);
              v112 = *(unsigned int *)((char *)v6 + v108 - v107);
              v113 = 4LL;
              if ( v111 != v112 )
              {
                _RSI = v111 ^ v112;
                _RDI = bsf(_RSI);
                v113 = _RDI >> 3;
              }
              v108 = v113 + v110;
              if ( v113 != 4 )
                break;
              v109 = v110 + 8;
            }
          }
          else
          {
            v212 = v89;
          }
          v116 = v212;
          do
          {
            v117 = v116;
            if ( !v106 )
              break;
            if ( v116 <= v17 )
              break;
            --v116;
            v118 = *((unsigned char *)v6 + v106-- - 1);
          }
          while ( *((unsigned char *)v6 + v117 - 1) == v118 );
          v119 = v108 - v117 - ((v107 > 0x5FF) | 2LL);
          if ( v119 > (unsigned long long)v207 || ((v119 == v207) && (v108 > v41) + 1))
          {
            v207 = v108 - v117 - ((v107 > 0x5FF) | 2LL);
            v204 = v107;
            v205 = v108 - v117;
            v196 = v108;
            v210 = v117;
          }
LABEL_105:
          v120 = v85;
          v121 = v206;
          if ( !v206 )
          {
            v48 = v205;
            goto LABEL_126;
          }
          v122 = v212 - v206;
          v123 = *(unsigned int *)((char *)v6 + v212 - v206);
          v124 = 4LL;
          v48 = v205;
          if ( v198 != v123 )
          {
            _RDX = v198 ^ v123;
            retval = bsf(_RDX);
            if ( (unsigned int)retval < 0x18 )
              goto LABEL_126;
            v124 = retval >> 3;
          }
          if ( v206 <= 0xFFFF )
          {
            v127 = v124 + v212;
            if ( v124 == 4 )
            {
              for ( j = v212 + 8; ; j = v129 + 8 )
              {
                _CF = j < v120;
                v129 = v127;
                if ( _CF )
                {
                  v130 = *(unsigned int *)((char *)v6 + v127);
                  v131 = *(unsigned int *)((char *)v6 + v127 - v206);
                  v132 = 4LL;
                  if ( v130 != v131 )
                  {
                    _RSI = v130 ^ v131;
                    _RDX = bsf(_RSI);
                    v132 = _RDX >> 3;
                  }
                  v127 = v132 + v129;
                  if ( v132 == 4 )
                    continue;
                }
                break;
              }
            }
            v135 = 0LL;
            do
            {
              v136 = v135;
              v137 = v212 + v135;
              if ( !(v135 + v122) )
                break;
              if ( v137 <= v17 )
                break;
              --v135;
            }
            while ( *(unsigned char *)(v186 + v212 + v136) == *(unsigned char *)(v186 + v122 + v136) );
            v138 = v197 + v127 - v136;
            v90 = v202;
            v121 = v206;
            if ( v138 - 1 > v207 )
              goto LABEL_261;
            if ( v136 + v212 + v207 + 1 - v127 )
            {
              v48 = v205;
              goto LABEL_126;
            }
            v48 = v205;
            if ( v127 > v196 + 1 )
            {
LABEL_261:
              v207 = v138 - 1;
              v204 = v206;
              v48 = v197 + v127 - v136;
              v196 = v127;
              v210 = v137;
            }
          }
LABEL_126:
          if ( v48 )
          {
            v18 = v212;
            v139 = v195;
            v140 = v199;
            if ( !v90 )
            {
              v51 = v121;
              v13 = v189;
              a6 = v190;
              v50 = v207;
              v47 = v204;
              v49 = v196;
              goto LABEL_227;
            }
            v13 = v189;
            v49 = v196;
            if ( v195 > v210 )
            {
              if ( v207 > v194 )
                v140 = v204;
              v200 = v140;
              if ( v207 > v194 )
              {
                v90 = v48;
                if ( v207 > v194 )
                  v139 = v196;
              }
              v141 = v139;
              if ( v207 > v194 )
                v20 = v210;
              v142 = (char *)v6 + v17;
              v143 = v20 - v17;
              a6 = v190;
              v144 = v201;
              if ( v143 < 0x10 )
              {
LABEL_144:
                if ( v143 >= 4 )
                {
                  v147 = v189;
                  if ( v143 + v144 + 10 >= v189 )
                    goto LABEL_206;
                  *(unsigned char *)v144 = v143 - 32;
                  if ( v143 )
                  {
                    v148 = 0LL;
                    do
                    {
                      *(unsigned long long *)(v144 + 1 + v148) = *(unsigned long long *)&v142[v148];
                      v148 += 8LL;
                    }
                    while ( v148 < v143 );
                  }
                  v144 += v143 + 1;
                  v142 += v143;
                  v143 = 0LL;
                }
                *(unsigned char *)&v149 = 10 - 2 * v143;
                if ( v149 >= v90 )
                  v149 = v90;
                v147 = v189;
                if ( v144 + 8 < v189 )
                {
                  v150 = v90 - v149;
                  v151 = v149 - 3;
                  v152 = *(unsigned int *)v142;
                  if ( v200 == v206 )
                  {
                    if ( v143 )
                      v149 = (v143 << 6) + 8 * v151 + 6;
                    else
                      v149 = v149 - 16;
                    *(unsigned char *)v144 = v149;
                    *(unsigned int *)(v144 + 1) = v152;
                    v165 = v143 + v144 + 1;
                  }
                  else if ( v200 > 0x5FF )
                  {
                    if ( v200 <= 0x3FFF && v90 != v149 && v90 < 0x23 )
                    {
                      *(unsigned char *)v144 = ((unsigned int)(v90 - 3) >> 2) + 8 * v143 - 96;
                      *(unsigned short *)(v144 + 1) = ((v90 - 3) & 3) | (4 * v200);
                      *(unsigned int *)(v144 + 3) = v152;
                      v147 = v143 + v144 + 3;
                      goto LABEL_206;
                    }
                    *(unsigned char *)v144 = 8 * v151 + ((unsigned char)v143 << 6) + 7;
                    *(unsigned short *)(v144 + 1) = v200;
                    *(unsigned int *)(v144 + 3) = v152;
                    v165 = v143 + v144 + 3;
                  }
                  else
                  {
                    *(unsigned char *)v144 = (v200 & 0xFF) + ((unsigned char)v143 << 6) + 8 * v151;
                    *(unsigned char *)(v144 + 1) = v200;
                    *(unsigned int *)(v144 + 2) = v152;
                    v165 = v143 + v144 + 2;
                  }
                  if ( v150 >= 0x10 )
                  {
                    while ( v165 + 2 < v189 )
                    {
                      v168 = 271LL;
                      if ( v150 < 0x10F )
                        v168 = v150;
                      v150 -= v168;
                      *(unsigned short *)v165 = ((unsigned short)v168 << 8) - 3856;
                      v165 += 2LL;
                      if ( v150 <= 0xF )
                        goto LABEL_201;
                    }
                    goto LABEL_204;
                  }
LABEL_201:
                  if ( v150 )
                  {
                    v147 = v189;
                    if ( v165 + 1 < v189 )
                    {
                      *(unsigned char *)v165 = v150 - 16;
                      v147 = v165 + 1;
                    }
                  }
                  else
                  {
                    v147 = v165;
                  }
                }
              }
              else
              {
                while ( 1 )
                {
                  v145 = 271LL;
                  if ( v143 < 0x10F )
                    v145 = v143;
                  if ( v145 + v144 + 10 >= v189 )
                    break;
                  *(unsigned short *)v144 = ((unsigned short)v145 << 8) - 3872;
                  if ( v145 )
                  {
                    v146 = 0LL;
                    do
                    {
                      *(unsigned long long *)(v144 + 2 + v146) = *(unsigned long long *)&v142[v146];
                      v146 += 8LL;
                    }
                    while ( v146 < v145 );
                  }
                  v143 -= v145;
                  v144 += v145 + 2;
                  v142 += v145;
                  if ( v143 <= 0xF )
                    goto LABEL_144;
                }
LABEL_204:
                v147 = v189;
              }
LABEL_206:
              v169 = v188;
              if ( v147 < v189 )
                v169 = v147;
              v188 = v169;
              v170 = v191;
              v17 = v141;
              if ( v147 < v189 )
                v170 = v141;
              v191 = v170;
              v47 = 0LL;
              v48 = 0LL;
              v210 = 0LL;
              v50 = 0LL;
              v201 = v147;
              v49 = 0LL;
              v18 = v212;
              v51 = v200;
LABEL_227:
              a4 = v203;
              goto LABEL_228;
            }
            v153 = (char *)v6 + v17;
            v154 = v20 - v17;
            a6 = v190;
            v155 = v201;
            if ( v154 < 0x10 )
            {
LABEL_166:
              if ( v154 >= 4 )
              {
                v158 = v189;
                if ( v154 + v155 + 10 >= v189 )
                  goto LABEL_222;
                *(unsigned char *)v155 = v154 - 32;
                if ( v154 )
                {
                  v159 = 0LL;
                  do
                  {
                    *(unsigned long long *)(v155 + 1 + v159) = *(unsigned long long *)&v153[v159];
                    v159 += 8LL;
                  }
                  while ( v159 < v154 );
                }
                v155 += v154 + 1;
                v153 += v154;
                v154 = 0LL;
              }
              v160 = 10 - 2 * v154;
              if ( v160 >= v90 )
                v160 = v90;
              v161 = v90;
              v158 = v189;
              if ( v155 + 8 >= v189 )
                goto LABEL_222;
              v162 = v90 - v160;
              v163 = v160 - 3;
              v164 = *(unsigned int *)v153;
              if ( v199 == v206 )
              {
                if ( v154 )
                  v160 = (v154 << 6) + 8 * v163 + 6;
                else
                  *(unsigned char *)(&v160) = v160 - 16;
                *(unsigned char *)v155 = v160;
                *(unsigned int *)(v155 + 1) = v164;
                v166 = v154 + v155 + 1;
              }
              else if ( v199 > 0x5FF )
              {
                if ( v199 <= 0x3FFF && v161 != v160 && v161 < 0x23 )
                {
                  v167 = v161 - 3;
                  *(unsigned char *)v155 = (v167 >> 2) + 8 * v154 - 96;
                  *(unsigned short *)(v155 + 1) = (v167 & 3) | (4 * v199);
                  *(unsigned int *)(v155 + 3) = v164;
                  v158 = v154 + v155 + 3;
                  goto LABEL_222;
                }
                *(unsigned char *)v155 = 8 * v163 + ((unsigned char)v154 << 6) + 7;
                *(unsigned short *)(v155 + 1) = v199;
                *(unsigned int *)(v155 + 3) = v164;
                v166 = v154 + v155 + 3;
              }
              else
              {
                *(unsigned char *)v155 = (v199 & 0xFF) + ((unsigned char)v154 << 6) + 8 * v163;
                *(unsigned char *)(v155 + 1) = v199;
                *(unsigned int *)(v155 + 2) = v164;
                v166 = v154 + v155 + 2;
              }
              if ( v162 >= 0x10 )
              {
                while ( v166 + 2 < v189 )
                {
                  v171 = 271LL;
                  if ( v162 < 0x10F )
                    v171 = v162;
                  v162 -= v171;
                  *(unsigned short *)v166 = ((unsigned short)v171 << 8) - 3856;
                  v166 += 2LL;
                  if ( v162 <= 0xF )
                    goto LABEL_217;
                }
                goto LABEL_220;
              }
LABEL_217:
              if ( v162 )
              {
                v158 = v189;
                if ( v166 + 1 < v189 )
                {
                  *(unsigned char *)v166 = v162 - 16;
                  v158 = v166 + 1;
                }
              }
              else
              {
                v158 = v166;
              }
            }
            else
            {
              while ( 1 )
              {
                v156 = 271LL;
                if ( v154 < 0x10F )
                  v156 = v154;
                if ( v156 + v155 + 10 >= v189 )
                  break;
                *(unsigned short *)v155 = ((unsigned short)v156 << 8) - 3872;
                if ( v156 )
                {
                  v157 = 0LL;
                  do
                  {
                    *(unsigned long long *)(v155 + 2 + v157) = *(unsigned long long *)&v153[v157];
                    v157 += 8LL;
                  }
                  while ( v157 < v156 );
                }
                v154 -= v156;
                v155 += v156 + 2;
                v153 += v156;
                if ( v154 <= 0xF )
                  goto LABEL_166;
              }
LABEL_220:
              v158 = v189;
            }
LABEL_222:
            v172 = v188;
            if ( v158 < v189 )
              v172 = v158;
            v188 = v172;
            v173 = v191;
            v17 = v195;
            if ( v158 < v189 )
              v173 = v195;
            v191 = v173;
            v201 = v158;
            v18 = v212;
            v51 = v199;
            v50 = v207;
            v47 = v204;
            goto LABEL_227;
          }
          v48 = v90;
          v47 = v199;
          v210 = v20;
          v50 = v194;
          v51 = v121;
          a4 = v120;
          v49 = v195;
          v13 = v189;
          a6 = v190;
          v18 = v212;
LABEL_228:
          if ( v18 + 9 >= a4 || v201 >= v13 )
          {
            v14 = v191;
            v15 = v188;
            a1 = v187;
            break;
          }
          v16 = v13;
          ++v18;
          v24 = *(unsigned int *)((char *)v6 + v18);
          --v197;
          v206 = v51;
          v19 = v50;
          v20 = v210;
          v21 = v49;
          v22 = v48;
          v23 = v47;
        }
      }
LABEL_233:
      if ( a4 <= v14 || v15 >= v13 )
      {
        v7 = v14;
        v174 = v15;
      }
      else
      {
        v7 = v14;
        v174 = v15;
        while ( 1 )
        {
          v211 = v174;
          v213 = v7;
          v192 = v14;
          v175 = a4 - v14;
          if ( a4 - v14 > 0x10F )
            v175 = 271LL;
          v208 = v175;
          v176 = (char *)v6 + v14;
          v177 = v175;
          if ( (unsigned long long)v175 >= 0x10 )
            break;
LABEL_245:
          if ( v177 )
          {
            if ( v177 + v15 + 10 >= v13 )
              goto LABEL_256;
            *(unsigned char *)v15 = v177 - 32;
            v181 = v176;
            v182 = v13;
            v183 = v15;
            memcpy((void *)(v15 + 1), v181, v177);
            v13 = v182;
            v15 = v177 + v183 + 1;
          }
          v14 = v208 + v192;
          v174 = v211;
          if ( v15 < v13 )
            v174 = v15;
          v7 = v213;
          if ( v15 < v13 )
            v7 = v208 + v192;
          a4 = v203;
          if ( v203 <= v14 || v15 >= v13 )
            goto LABEL_257;
        }
        while ( 1 )
        {
          v178 = 271LL;
          if ( v177 < 0x10F )
            v178 = v177;
          if ( v178 + v15 + 10 >= v13 )
            break;
          *(unsigned short *)v15 = ((unsigned short)v178 << 8) - 3872;
          v177 -= v178;
          if ( v178 )
          {
            v179 = v13;
            v180 = v15;
            memcpy((void *)(v15 + 2), v176, v178);
            v15 = v180;
            v6 = v193;
            v13 = v179;
          }
          v15 += v178 + 2;
          v176 = (char *)v176 + v178;
          if ( v177 <= 0xF )
            goto LABEL_245;
        }
LABEL_256:
        v7 = v213;
        v174 = v211;
      }
LABEL_257:
      *(unsigned long long *)v174 = 6LL;
      v8 = v174 + 8 - a1;
    }
  }
  *(unsigned long long *)v185 = v7;
  return v8;
}

