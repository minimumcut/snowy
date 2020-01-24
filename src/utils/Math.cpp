#include "Math.hpp"
#include "Singular_Value_Decomposition_Preamble.hpp"

#define USE_SCALAR_IMPLEMENTATION
#undef USE_SSE_IMPLEMENTATION
#undef USE_AVX_IMPLEMENTATION
#define COMPUTE_U_AS_MATRIX
#define COMPUTE_V_AS_MATRIX

void svd3(const Mat3& a, Mat3& u, Mat3& s, Mat3& v) 
{
  // this code only supports the scalar version (otherwise we'd need to pass arrays of matrices)  

#include "Singular_Value_Decomposition_Kernel_Declarations.hpp"

    ENABLE_SCALAR_IMPLEMENTATION(Sa11.f=a[0][0];)                                      ENABLE_SSE_IMPLEMENTATION(Va11=_mm_loadu_ps(a11);)                                  ENABLE_AVX_IMPLEMENTATION(Va11=_mm256_loadu_ps(a11);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa21.f=a[1][0];)                                      ENABLE_SSE_IMPLEMENTATION(Va21=_mm_loadu_ps(a21);)                                  ENABLE_AVX_IMPLEMENTATION(Va21=_mm256_loadu_ps(a21);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa31.f=a[2][0];)                                      ENABLE_SSE_IMPLEMENTATION(Va31=_mm_loadu_ps(a31);)                                  ENABLE_AVX_IMPLEMENTATION(Va31=_mm256_loadu_ps(a31);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa12.f=a[0][1];)                                      ENABLE_SSE_IMPLEMENTATION(Va12=_mm_loadu_ps(a12);)                                  ENABLE_AVX_IMPLEMENTATION(Va12=_mm256_loadu_ps(a12);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa22.f=a[1][1];)                                      ENABLE_SSE_IMPLEMENTATION(Va22=_mm_loadu_ps(a22);)                                  ENABLE_AVX_IMPLEMENTATION(Va22=_mm256_loadu_ps(a22);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa32.f=a[2][1];)                                      ENABLE_SSE_IMPLEMENTATION(Va32=_mm_loadu_ps(a32);)                                  ENABLE_AVX_IMPLEMENTATION(Va32=_mm256_loadu_ps(a32);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa13.f=a[0][2];)                                      ENABLE_SSE_IMPLEMENTATION(Va13=_mm_loadu_ps(a13);)                                  ENABLE_AVX_IMPLEMENTATION(Va13=_mm256_loadu_ps(a13);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa23.f=a[1][2];)                                      ENABLE_SSE_IMPLEMENTATION(Va23=_mm_loadu_ps(a23);)                                  ENABLE_AVX_IMPLEMENTATION(Va23=_mm256_loadu_ps(a23);)
    ENABLE_SCALAR_IMPLEMENTATION(Sa33.f=a[2][2];)                                      ENABLE_SSE_IMPLEMENTATION(Va33=_mm_loadu_ps(a33);)                                  ENABLE_AVX_IMPLEMENTATION(Va33=_mm256_loadu_ps(a33);)

#include "Singular_Value_Decomposition_Main_Kernel_Body.hpp"

    ENABLE_SCALAR_IMPLEMENTATION(u[0][0]=Su11.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u11,Vu11);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u11,Vu11);)
    ENABLE_SCALAR_IMPLEMENTATION(u[1][0]=Su21.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u21,Vu21);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u21,Vu21);)
    ENABLE_SCALAR_IMPLEMENTATION(u[2][0]=Su31.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u31,Vu31);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u31,Vu31);)
    ENABLE_SCALAR_IMPLEMENTATION(u[0][1]=Su12.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u12,Vu12);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u12,Vu12);)
    ENABLE_SCALAR_IMPLEMENTATION(u[1][1]=Su22.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u22,Vu22);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u22,Vu22);)
    ENABLE_SCALAR_IMPLEMENTATION(u[2][1]=Su32.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u32,Vu32);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u32,Vu32);)
    ENABLE_SCALAR_IMPLEMENTATION(u[0][2]=Su13.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u13,Vu13);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u13,Vu13);)
    ENABLE_SCALAR_IMPLEMENTATION(u[1][2]=Su23.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u23,Vu23);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u23,Vu23);)
    ENABLE_SCALAR_IMPLEMENTATION(u[2][2]=Su33.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(u33,Vu33);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(u33,Vu33);)

    ENABLE_SCALAR_IMPLEMENTATION(v[0][0]=Sv11.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v11,Vv11);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v11,Vv11);)
    ENABLE_SCALAR_IMPLEMENTATION(v[1][0]=Sv21.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v21,Vv21);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v21,Vv21);)
    ENABLE_SCALAR_IMPLEMENTATION(v[2][0]=Sv31.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v31,Vv31);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v31,Vv31);)
    ENABLE_SCALAR_IMPLEMENTATION(v[0][1]=Sv12.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v12,Vv12);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v12,Vv12);)
    ENABLE_SCALAR_IMPLEMENTATION(v[1][1]=Sv22.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v22,Vv22);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v22,Vv22);)
    ENABLE_SCALAR_IMPLEMENTATION(v[2][1]=Sv32.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v32,Vv32);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v32,Vv32);)
    ENABLE_SCALAR_IMPLEMENTATION(v[0][2]=Sv13.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v13,Vv13);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v13,Vv13);)
    ENABLE_SCALAR_IMPLEMENTATION(v[1][2]=Sv23.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v23,Vv23);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v23,Vv23);)
    ENABLE_SCALAR_IMPLEMENTATION(v[2][2]=Sv33.f;)                                      ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(v33,Vv33);)                                 ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(v33,Vv33);)

    ENABLE_SCALAR_IMPLEMENTATION(s[0][0]=Sa11.f;)                                     ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(sigma1,Va11);)                              ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(sigma1,Va11);)
    ENABLE_SCALAR_IMPLEMENTATION(s[1][1]=Sa22.f;)                                     ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(sigma2,Va22);)                              ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(sigma2,Va22);)
    ENABLE_SCALAR_IMPLEMENTATION(s[2][2]=Sa33.f;)                                     ENABLE_SSE_IMPLEMENTATION(_mm_storeu_ps(sigma3,Va33);)                              ENABLE_AVX_IMPLEMENTATION(_mm256_storeu_ps(sigma3,Va33);)

}