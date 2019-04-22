/***************************************************************************
                          ut_geo_const.h  -  description
                             -------------------
    begin                : Fri Aug 25 2000
    copyright            : (C) 2000 by CADCAM-Services Franz Reiter
    email                : franz.reiter@cadcam.co.at

****************************************************************************

*//*!
\file ../ut/ut_geo_const.h
\ingroup grp_const


\code

full include in ../ut/ut_geo2d.c

Adding constant:
extern const <typ> <nam>
const <typ> <nam> { <values> };

touch ../ut/ut_geo2d.c && ./do c

\endcode *//*

*/

#define _UT3D_VECTOR_NUL { 0., 0., 0. }


// CurvPoly
#define _PLG_NUL  { 0, 0., 0., NULL, NULL,\
                    (char)0, (char)-1, (char)1, (char)0 };
//                   dir,     clo,     trm      uu

// CurvPrcv
#define _PRCV_NUL { 0L, 0, 0, 0,\
                    NULL, NULL, NULL,\
                    (short)0, (char)2, (char)0 };
//                  typ,      fTmp,    uu1

// CurvCCV
#define _CCV_NUL  { FLT_32_MAX, FLT_32_MAX, 0L, 0L, 0L,\
                    (unsigned short)0, (unsigned short)0,\
                    (short)0, (short)0, (char)0, (char)-1, (char)-1, (char)0 };
//                  typ,      us1;      dir,     clo,      trm,      stat;

// Plane        
#define _PLANE_NUL { {0.,0.,0.}, {1.,0.,0.}, {0.,1.,0.}, {0.,0.,1.}, 0.}
//                      po          vx          vy          vz        p

// GridBox
#define _GRIDBOX_NUL {{0.,0.,0.}, 0,0,0, 0.,0.,0.}

// ColRGB
#define _ColRGB_NUL { 100,100,100, 0,  0,  0,  0,  1}
//                     r   g   b  uu  tra sym tex col

// ObjTab
#define _OBJTAB_NUL { NULL, NULL, UME_NEW, NULL, 0,0,\
                      (UINT_16)0, (char)0, (char)0 }

// IndTab
#define _INDTAB_NUL  { 0,0,  0,0,0,0}

// Mat_4x3         // VX   VY   VZ   PO
#define _MAT_4x3   { {1.0, 0.0, 0.0, 0.0},\
                     {0.0, 1.0, 0.0, 0.0},\
                     {0.0, 0.0, 1.0, 0.0} }

// _RSYS_2D       Refsys 2D
#define _RSYS_2D   { (Plane*)&PLANE_NUL, _MAT_4x3, _MAT_4x3,\
                    0., (char)2, (char)2, (char)0, (char)0 }
               //  bpd    bpi,     bpv,     uu3,     uu4;



//================================================================
// constant geometric objects:
#ifndef INCLUDE_FULL
extern const Point   UT3D_PT_NUL;
extern const Vector  UT3D_VECTOR_NUL;

extern const Vector  UT3D_VECTOR_X;
extern const Vector  UT3D_VECTOR_Y;
extern const Vector  UT3D_VECTOR_Z;

extern const Vector  UT3D_VECTOR_IX;
extern const Vector  UT3D_VECTOR_IY;
extern const Vector  UT3D_VECTOR_IZ;

extern const CurvPoly UT3D_PLG_NUL;
extern const CurvCCV  UT3D_CCV_NUL;
extern const CurvPrcv UT3D_PRCV_NUL;

extern const Plane    PLANE_NUL;
extern const GridBox  GRIDBOX_NUL;

extern const Mat_3x3 UT3D_MAT_3x3;
extern const Mat_4x3 UT3D_MAT_4x3;
extern const Mat_4x4 UT3D_MAT_4x4;

extern const Refsys  UT3D_RSYS_2D;

 
//----------------------------------------------------------------
#else


const Point2  UT2D_PT_NUL     = { 0.0, 0.0 };
const Point   UT3D_PT_NUL     = { 0.0, 0.0, 0.0 };

const Point2  UT2D_PT_INFTY   = { FLT_32_MAX, FLT_32_MAX};

const Vector2 UT2D_VECTOR_NUL = { 0.0, 0.0 };
const Vector2 UT2D_VECTOR_X   = { 1.0, 0.0 };
const Vector2 UT2D_VECTOR_Y   = { 0.0, 1.0 };

const Vector2 UT2D_VECTOR_IX  = {-1.0, 0.0 };
const Vector2 UT2D_VECTOR_IY  = { 0.0,-1.0 };


const Vector  UT3D_VECTOR_NUL = _UT3D_VECTOR_NUL;
// const Vector  UT3D_VECTOR_NUL = { 0.0, 0.0, 0.yy0 };

const Vector  UT3D_VECTOR_X   = { 1.0, 0.0, 0.0 };
const Vector  UT3D_VECTOR_Y   = { 0.0, 1.0, 0.0 };
const Vector  UT3D_VECTOR_Z   = { 0.0, 0.0, 1.0 };

const Vector  UT3D_VECTOR_IX  = {-1.0, 0.0, 0.0 };
const Vector  UT3D_VECTOR_IY  = { 0.0,-1.0, 0.0 };
const Vector  UT3D_VECTOR_IZ  = { 0.0, 0.0,-1.0 };


const Mat_3x3 UT3D_MAT_3x3    = { {1.0, 0.0, 0.0},
                                  {0.0, 1.0, 0.0},
                                  {0.0, 0.0, 1.0} };

const Mat_4x4 UT3D_MAT_4x4    = { {1.0, 0.0, 0.0, 0.0},
                                  {0.0, 1.0, 0.0, 0.0},
                                  {0.0, 0.0, 1.0, 0.0},
                                  {0.0, 0.0, 0.0, 1.0} };



const CurvPoly UT3D_PLG_NUL   = _PLG_NUL;
const CurvCCV  UT3D_CCV_NUL   = _CCV_NUL;
const CurvPrcv UT3D_PRCV_NUL  = _PRCV_NUL;
const Plane    PLANE_NUL      = _PLANE_NUL;
const GridBox  GRIDBOX_NUL    = _GRIDBOX_NUL;
const IndTab   INDTAB_NUL     = _INDTAB_NUL;
const ObjTab   OBJTAB_NUL     = _OBJTAB_NUL;

const Mat_4x3  UT3D_MAT_4x3   = _MAT_4x3;
const Refsys   UT3D_RSYS_2D   = _RSYS_2D;

#endif


//================  EOF =====================
