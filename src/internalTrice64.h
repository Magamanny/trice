/*! \file internalTrice64.h
\author thomas.hoehenleitner [at] seerose.net
*******************************************************************************/

#define TRICE64(  tid,fmt, ...) TRICE_COUNT(__VA_ARGS__,TRICE64_12,  TRICE64_11,  TRICE64_10,  TRICE64_9,  TRICE64_8,  TRICE64_7,  TRICE64_6,  TRICE64_5,  TRICE64_4,  TRICE64_3,  TRICE64_2,  TRICE64_1)(  tid,fmt, __VA_ARGS__)
#define trice64(      fmt, ...) TRICE_COUNT(__VA_ARGS__,trice64_12,  trice64_11,  trice64_10,  trice64_9,  trice64_8,  trice64_7,  trice64_6,  trice64_5,  trice64_4,  trice64_3,  trice64_2,  trice64_1)(      fmt, __VA_ARGS__)
#define trice64_M(tid,fmt, ...) TRICE_COUNT(__VA_ARGS__,trice64_12_M,trice64_11_M,trice64_10_M,trice64_9_M,trice64_8_M,trice64_7_M,trice64_6_M,trice64_5_M,trice64_4_M,trice64_3_M,trice64_2_M,trice64_1_M)(tid,fmt, __VA_ARGS__)
#define Trice64(      fmt, ...) TRICE_COUNT(__VA_ARGS__,Trice64_12,  Trice64_11,  Trice64_10,  Trice64_9,  Trice64_8,  Trice64_7,  Trice64_6,  Trice64_5,  Trice64_4,  Trice64_3,  Trice64_2,  Trice64_1)(      fmt, __VA_ARGS__)
#define Trice64_M(tid,fmt, ...) TRICE_COUNT(__VA_ARGS__,Trice64_12_M,Trice64_11_M,Trice64_10_M,Trice64_9_M,Trice64_8_M,Trice64_7_M,Trice64_6_M,Trice64_5_M,Trice64_4_M,Trice64_3_M,Trice64_2_M,Trice64_1_M)(tid,fmt, __VA_ARGS__)
#define TRice64(      fmt, ...) TRICE_COUNT(__VA_ARGS__,TRice64_12,  TRice64_11,  TRice64_10,  TRice64_9,  TRice64_8,  TRice64_7,  TRice64_6,  TRice64_5,  TRice64_4,  TRice64_3,  TRice64_2,  TRice64_1)(      fmt, __VA_ARGS__)
#define TRice64_M(tid,fmt, ...) TRICE_COUNT(__VA_ARGS__,TRice64_12_M,TRice64_11_M,TRice64_10_M,TRice64_9_M,TRice64_8_M,TRice64_7_M,TRice64_6_M,TRice64_5_M,TRice64_4_M,TRice64_3_M,TRice64_2_M,TRice64_1_M)(tid,fmt, __VA_ARGS__)


//!TRICE64_B expects inside pFmt only one format specifier, which is used n times by using pFmt n times.
//! It is usable for showing n 64-bit values.
#define TRICE64_B( id, pFmt, buf, n) do { TRICE_N( id, pFmt, buf, 8*n); } while(0)

//!TRICE64_F expects inside pFmt just a string which is assumed to be a remote function name.
//! The trice tool displays the pFmt string followed by n times (64-bit value i).
//! The idea behind is to generate an id - function pointer referece list from the generated til.json file to
//! compile it into a remote device and execute the inside pFmt named function remotely.
//! Look for "TRICE64_F example" inside triceCheck.c.
#define TRICE64_F  TRICE64_B

#define TRICE64_F TRICE64_B 

#define TRICE_PUT64_1( v0 )                                                 TRICE_PUT64( v0 ); 

#define TRICE_PUT64_2( v0, v1                                           )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); 

#define TRICE_PUT64_3( v0, v1, v2                                       )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 );

#define TRICE_PUT64_4( v0, v1, v2, v3                                   )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 );

#define TRICE_PUT64_5( v0, v1, v2, v3, v4                               )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 );

#define TRICE_PUT64_6( v0, v1, v2, v3, v4, v5                           )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 ); \
                                                                            TRICE_PUT64( v5 );

#define TRICE_PUT64_7( v0, v1, v2, v3, v4, v5, v6                       )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 ); \
                                                                            TRICE_PUT64( v5 ); \
                                                                            TRICE_PUT64( v6 );
                                                                           
#define TRICE_PUT64_8( v0, v1, v2, v3, v4, v5, v6, v7                   )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 ); \
                                                                            TRICE_PUT64( v5 ); \
                                                                            TRICE_PUT64( v6 ); \
                                                                            TRICE_PUT64( v7 );
                                                                           
#define TRICE_PUT64_9( v0, v1, v2, v3, v4, v5, v6, v7, v8               )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 ); \
                                                                            TRICE_PUT64( v5 ); \
                                                                            TRICE_PUT64( v6 ); \
                                                                            TRICE_PUT64( v7 ); \
                                                                            TRICE_PUT64( v8 );
                                                                            
#define TRICE_PUT64_10(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9           )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 ); \
                                                                            TRICE_PUT64( v5 ); \
                                                                            TRICE_PUT64( v6 ); \
                                                                            TRICE_PUT64( v7 ); \
                                                                            TRICE_PUT64( v8 ); \
                                                                            TRICE_PUT64( v9 );
                                                                            
#define TRICE_PUT64_11(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10      )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 ); \
                                                                            TRICE_PUT64( v5 ); \
                                                                            TRICE_PUT64( v6 ); \
                                                                            TRICE_PUT64( v7 ); \
                                                                            TRICE_PUT64( v8 ); \
                                                                            TRICE_PUT64( v9 ); \
                                                                            TRICE_PUT64( v10 );
                                                                            
#define TRICE_PUT64_12(v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 )   TRICE_PUT64( v0 ); \
                                                                            TRICE_PUT64( v1 ); \
                                                                            TRICE_PUT64( v2 ); \
                                                                            TRICE_PUT64( v3 ); \
                                                                            TRICE_PUT64( v4 ); \
                                                                            TRICE_PUT64( v5 ); \
                                                                            TRICE_PUT64( v6 ); \
                                                                            TRICE_PUT64( v7 ); \
                                                                            TRICE_PUT64( v8 ); \
                                                                            TRICE_PUT64( v9 ); \
                                                                            TRICE_PUT64( v10 ); \
                                                                            TRICE_PUT64( v11 );

//! TRICE64_1 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 a 8 bit bit value
#define TRICE64_1( tid, pFmt, v0 ) \
    TRICE_ENTER tid; CNTC(8); \
    TRICE_PUT64_1( v0 )  \
    TRICE_LEAVE

//! TRICE64_2 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v1 are 8 bit bit values
#define TRICE64_2( id, pFmt, v0, v1 ) \
    TRICE_ENTER id; CNTC(16); \
    TRICE_PUT64_2 ( v0, v1 ); \
    TRICE_LEAVE

//! TRICE64_3 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v2 are 8 bit bit values
#define TRICE64_3( id, pFmt, v0, v1, v2 ) \
    TRICE_ENTER id; CNTC(24); \
    TRICE_PUT64_3( v0, v1, v2 ); \
    TRICE_LEAVE

//! TRICE64_4 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v3 are 8 bit bit values
#define TRICE64_4( id, pFmt, v0, v1, v2, v3 ) \
    TRICE_ENTER id; CNTC(32); \
    TRICE_PUT64_4( v0, v1, v2, v3  ); \
    TRICE_LEAVE

//! TRICE64_5 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v4 are 8 bit bit values
#define TRICE64_5( id, pFmt, v0, v1, v2, v3, v4 ) \
    TRICE_ENTER id; CNTC(40); \
    TRICE_PUT64_5( v0, v1, v2, v3, v4  ); \
    TRICE_LEAVE

//! TRICE64_6 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v5 are 8 bit bit values
#define TRICE64_6( id, pFmt, v0, v1, v2, v3, v4, v5 ) \
    TRICE_ENTER id; CNTC(48); \
    TRICE_PUT64_6( v0, v1, v2, v3, v4, v5 ); \
    TRICE_LEAVE

//! TRICE64_8 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v6 are 8 bit bit values
#define TRICE64_7( id, pFmt, v0, v1, v2, v3, v4, v5, v6 ) \
    TRICE_ENTER id; CNTC(56); \
    TRICE_PUT64_7( v0, v1, v2, v3, v4, v5, v6 ); \
    TRICE_LEAVE

//! TRICE64_8 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v7 are 8 bit bit values
#define TRICE64_8( id, pFmt, v0, v1, v2, v3, v4, v5, v6, v7 ) \
    TRICE_ENTER id; CNTC(64); \
    TRICE_PUT64_8( v0, v1, v2, v3, v4, v5, v6, v7 ); \
    TRICE_LEAVE

//! TRICE64_8 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v7 are 8 bit bit values
#define TRICE64_9( id, pFmt, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) \
    TRICE_ENTER id; CNTC(72); \
    TRICE_PUT64_9( v0, v1, v2, v3, v4, v5, v6, v7, v8 ); \
    TRICE_LEAVE

//! TRICE64_8 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v7 are 8 bit bit values
#define TRICE64_10( id, pFmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) \
    TRICE_ENTER id; CNTC(80); \
    TRICE_PUT64_10( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ); \
    TRICE_LEAVE

//! TRICE64_8 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v7 are 8 bit bit values
#define TRICE64_11( id, pFmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) \
    TRICE_ENTER id; CNTC(88); \
    TRICE_PUT64_11( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ); \
    TRICE_LEAVE

//! TRICE64_12 writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 - v11 are 8 bit bit values
#define TRICE64_12( id, pFmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_ENTER id; CNTC(96); \
    TRICE_PUT64_12( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_LEAVE

#define trice64_1( fmt, v0 ) //!< trice64_1 is an empty macro
#define trice64_2( fmt, v0, v1 ) //!< trice64_2 is an empty macro
#define trice64_3( fmt, v0, v1, v2 ) //!< trice64_3 is an empty macro
#define trice64_4( fmt, v0, v1, v2, v3 ) //!< trice64_4 is an empty macro
#define trice64_5( fmt, v0, v1, v2, v3, v4 ) //!< trice64_5 is an empty macro
#define trice64_6( fmt, v0, v1, v2, v3, v4, v5 ) //!< trice64_6 is an empty macro
#define trice64_7( fmt, v0, v1, v2, v3, v4, v5, v6 ) //!< trice64_7 is an empty macro
#define trice64_8( fmt, v0, v1, v2, v3, v4, v5, v6, v7 ) //!< trice64_8 is an empty macro
#define trice64_9( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) //!< trice64_9 is an empty macro
#define trice64_10( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) //!< trice64_10 is an empty macro
#define trice64_11( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) //!< trice64_11 is an empty macro
#define trice64_12( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) //!< trice64_12 is an empty macro

//! trice64_1_m writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 a 8 bit bit value
#define trice64_1_m( tid, v0 ) \
    TRICE_ENTER \
    TRICE_PUT( (8<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_1( v0 ) \
    TRICE_LEAVE

#define trice64_2_m( tid, v0, v1 ) \
    TRICE_ENTER \
    TRICE_PUT( (16<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_2( v0, v1); \
    TRICE_LEAVE

#define trice64_3_m( tid, v0, v1, v2 ) \
    TRICE_ENTER \
    TRICE_PUT( (24<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_3 ( v0, v1, v2 ); \
    TRICE_LEAVE

#define trice64_4_m( tid, v0, v1, v2, v3 ) \
    TRICE_ENTER \
    TRICE_PUT( (32<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_4( v0, v1, v2, v3 ); \
    TRICE_LEAVE

#define trice64_5_m( tid, v0, v1, v2, v3, v4 ) \
    TRICE_ENTER \
    TRICE_PUT( (40<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_5( v0, v1, v2, v3, v4 ); \
    TRICE_LEAVE

#define trice64_6_m( tid, v0, v1, v2, v3, v4, v5 ) \
    TRICE_ENTER \
    TRICE_PUT( (48<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_6( v0, v1, v2, v3, v4, v5 ); \
    TRICE_LEAVE

#define trice64_7_m( tid, v0, v1, v2, v3, v4, v5, v6 ) \
    TRICE_ENTER \
    TRICE_PUT( (56<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_7( v0, v1, v2, v3, v4, v5, v6 ); \
    TRICE_LEAVE

#define trice64_8_m( tid, v0, v1, v2, v3, v4, v5, v6, v7 ) \
    TRICE_ENTER \
    TRICE_PUT( (64<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_8( v0, v1, v2, v3, v4, v5, v6, v7 ); \
    TRICE_LEAVE

#define trice64_9_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) \
    TRICE_ENTER \
    TRICE_PUT( (72<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_9( v0, v1, v2, v3, v4, v5, v6, v7, v8 ); \
    TRICE_LEAVE

#define trice64_10_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) \
    TRICE_ENTER \
    TRICE_PUT( (80<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_10( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ); \
    TRICE_LEAVE

#define trice64_11_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) \
    TRICE_ENTER \
    TRICE_PUT( (88<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_11( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ); \
    TRICE_LEAVE

#define trice64_12_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_ENTER \
    TRICE_PUT( (96<<24) | ((TRICE_CYCLE)<<16) | (0x4000|(tid)) ); \
    TRICE_PUT64_12( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_LEAVE

#define trice64_1_M( tid,  fmt, v0 ) trice64_1_fn( tid,  (uint64_t)(v0) ) //!< trice64_1_M is a macro calling a function to reduce code size.
#define trice64_2_M( tid,  fmt, v0, v1 ) trice64_2_fn( tid,  (uint64_t)(v0), (uint64_t)(v1) ) //!< trice64_2_M is a macro calling a function to reduce code size.
#define trice64_3_M( tid,  fmt, v0, v1, v2 ) trice64_3_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2) ) //!< trice64_3_M is a macro calling a function to reduce code size.
#define trice64_4_M( tid,  fmt, v0, v1, v2, v3 ) trice64_4_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3) ) //!< trice64_4_M is a macro calling a function to reduce code size.
#define trice64_5_M( tid,  fmt, v0, v1, v2, v3, v4 ) trice64_5_fn( tid,  (uint64_t)v0, (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4) ) //!< trice64_5_M is a macro calling a function to reduce code size.
#define trice64_6_M( tid,  fmt, v0, v1, v2, v3, v4, v5 ) trice64_6_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5) ) //!< trice64_6_M is a macro calling a function to reduce code size.
#define trice64_7_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6 ) trice64_7_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6) ) //!< trice64_7_M is a macro calling a function to reduce code size.
#define trice64_8_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6, v7 ) trice64_8_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7) ) //!< trice64_8_M is a macro calling a function to reduce code size.
#define trice64_9_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) trice64_9_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8) ) //!< trice64_9_M is a macro calling a function to reduce code size.
#define trice64_10_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) trice64_10_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9) ) //!< trice64_10_M is a macro calling a function to reduce code size.
#define trice64_11_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) trice64_11_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9), (uint64_t)(v10) ) //!< trice64_11_M is a macro calling a function to reduce code size.
#define trice64_12_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) trice64_12_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9), (uint64_t)(v10), (uint64_t)(v11) ) //!< trice64_12_M is a macro calling a function to reduce code size.

void trice64_1_fn( uint64_t tid,  uint64_t v0 );
void trice64_2_fn( uint64_t tid,  uint64_t v0, uint64_t v1 );
void trice64_3_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2 );
void trice64_4_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3 );
void trice64_5_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4 );
void trice64_6_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5 );
void trice64_7_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6 );
void trice64_8_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7 );
void trice64_9_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8 );
void trice64_10_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9 );
void trice64_11_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9, uint64_t v10 );
void trice64_12_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9, uint64_t v10, uint64_t v11 );

#define Trice64_1( fmt, v0 ) //!< Trice64_1 is an empty macro
#define Trice64_2( fmt, v0, v1 ) //!< Trice64_2 is an empty macro
#define Trice64_3( fmt, v0, v1, v2 ) //!< Trice64_3 is an empty macro
#define Trice64_4( fmt, v0, v1, v2, v3 ) //!< Trice64_4 is an empty macro
#define Trice64_5( fmt, v0, v1, v2, v3, v4 ) //!< Trice64_5 is an empty macro
#define Trice64_6( fmt, v0, v1, v2, v3, v4, v5 ) //!< Trice64_6 is an empty macro
#define Trice64_7( fmt, v0, v1, v2, v3, v4, v5, v6 ) //!< Trice64_7 is an empty macro
#define Trice64_8( fmt, v0, v1, v2, v3, v4, v5, v6, v7 ) //!< Trice64_8 is an empty macro
#define Trice64_9( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) //!< Trice64_9 is an empty macro
#define Trice64_10( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) //!< Trice64_10 is an empty macro
#define Trice64_11( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) //!< Trice64_11 is an empty macro
#define Trice64_12( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) //!< Trice64_12 is an empty macro

//! Trice64_1_m writes trice data as fast as possible in a buffer.
//! \param id is a 16 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 a 8 bit bit value
#define Trice64_1_m( tid, v0 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 8<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_1( v0 ) \
    TRICE_LEAVE

#define Trice64_2_m( tid, v0, v1 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 16<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_2( v0, v1); \
    TRICE_LEAVE

#define Trice64_3_m( tid, v0, v1, v2 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 24<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_3 ( v0, v1, v2 ); \
    TRICE_LEAVE

#define Trice64_4_m( tid, v0, v1, v2, v3 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 32<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_4( v0, v1, v2, v3 ); \
    TRICE_LEAVE

#define Trice64_5_m( tid, v0, v1, v2, v3, v4 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 40<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_5( v0, v1, v2, v3, v4 ); \
    TRICE_LEAVE

#define Trice64_6_m( tid, v0, v1, v2, v3, v4, v5 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 48<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_6( v0, v1, v2, v3, v4, v5 ); \
    TRICE_LEAVE

#define Trice64_7_m( tid, v0, v1, v2, v3, v4, v5, v6 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 56<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_7( v0, v1, v2, v3, v4, v5, v6 ); \
    TRICE_LEAVE

#define Trice64_8_m( tid, v0, v1, v2, v3, v4, v5, v6, v7 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 64<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_8( v0, v1, v2, v3, v4, v5, v6, v7 ); \
    TRICE_LEAVE

#define Trice64_9_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 72<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_9( v0, v1, v2, v3, v4, v5, v6, v7, v8 ); \
    TRICE_LEAVE

#define Trice64_10_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 80<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_10( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ); \
    TRICE_LEAVE

#define Trice64_11_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 88<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_11( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ); \
    TRICE_LEAVE

#define Trice64_12_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_ENTER \
    uint64_t ts = TriceStamp16(); \
    TRICE_PUT(0x80008000|(tid<<16)|tid); \
    TRICE_PUT( 96<<24 | (TRICE_CYCLE<<16) | ts ); \
    TRICE_PUT64_12( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_LEAVE

#define Trice64_1_M( tid,  fmt, v0 ) Trice64_1_fn( tid,  (uint64_t)(v0) ) //!< Trice64_1_M is a macro calling a function to reduce code size.
#define Trice64_2_M( tid,  fmt, v0, v1 ) Trice64_2_fn( tid,  (uint64_t)(v0), (uint64_t)(v1) ) //!< Trice64_2_M is a macro calling a function to reduce code size.
#define Trice64_3_M( tid,  fmt, v0, v1, v2 ) Trice64_3_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2) ) //!< Trice64_3_M is a macro calling a function to reduce code size.
#define Trice64_4_M( tid,  fmt, v0, v1, v2, v3 ) Trice64_4_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3) ) //!< Trice64_4_M is a macro calling a function to reduce code size.
#define Trice64_5_M( tid,  fmt, v0, v1, v2, v3, v4 ) Trice64_5_fn( tid,  (uint64_t)v0, (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4) ) //!< Trice64_5_M is a macro calling a function to reduce code size.
#define Trice64_6_M( tid,  fmt, v0, v1, v2, v3, v4, v5 ) Trice64_6_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5) ) //!< Trice64_6_M is a macro calling a function to reduce code size.
#define Trice64_7_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6 ) Trice64_7_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6) ) //!< Trice64_7_M is a macro calling a function to reduce code size.
#define Trice64_8_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6, v7 ) Trice64_8_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7) ) //!< Trice64_8_M is a macro calling a function to reduce code size.
#define Trice64_9_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) Trice64_9_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8) ) //!< Trice64_9_M is a macro calling a function to reduce code size.
#define Trice64_10_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) Trice64_10_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9) ) //!< Trice64_10_M is a macro calling a function to reduce code size.
#define Trice64_11_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) Trice64_11_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9), (uint64_t)(v10) ) //!< Trice64_11_M is a macro calling a function to reduce code size.
#define Trice64_12_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) Trice64_12_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9), (uint64_t)(v10), (uint64_t)(v11) ) //!< Trice64_12_M is a macro calling a function to reduce code size.

void Trice64_1_fn( uint64_t tid,  uint64_t v0 );
void Trice64_2_fn( uint64_t tid,  uint64_t v0, uint64_t v1 );
void Trice64_3_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2 );
void Trice64_4_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3 );
void Trice64_5_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4 );
void Trice64_6_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5 );
void Trice64_7_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6 );
void Trice64_8_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7 );
void Trice64_9_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8 );
void Trice64_10_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9 );
void Trice64_11_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9, uint64_t v10 );
void Trice64_12_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9, uint64_t v10, uint64_t v11 );

#define TRice64_1( fmt, v0 ) //!< TRice64_1 is an empty macro
#define TRice64_2( fmt, v0, v1 ) //!< TRice64_2 is an empty macro
#define TRice64_3( fmt, v0, v1, v2 ) //!< TRice64_3 is an empty macro
#define TRice64_4( fmt, v0, v1, v2, v3 ) //!< TRice64_4 is an empty macro
#define TRice64_5( fmt, v0, v1, v2, v3, v4 ) //!< TRice64_5 is an empty macro
#define TRice64_6( fmt, v0, v1, v2, v3, v4, v5 ) //!< TRice64_6 is an empty macro
#define TRice64_7( fmt, v0, v1, v2, v3, v4, v5, v6 ) //!< TRice64_7 is an empty macro
#define TRice64_8( fmt, v0, v1, v2, v3, v4, v5, v6, v7 ) //!< TRice64_8 is an empty macro
#define TRice64_9( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) //!< TRice64_9 is an empty macro
#define TRice64_10( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) //!< TRice64_10 is an empty macro
#define TRice64_11( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) //!< TRice64_11 is an empty macro
#define TRice64_12( fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) //!< TRice64_12 is an empty macro

//! TRice64_1_m writes trice data as fast as possible in a buffer.
//! \param id is a 14 bit Trice id in upper 2 bytes of a 32 bit value
//! \param v0 a 8 bit bit value
#define TRice64_1_m( tid, v0 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 8<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_1( v0 ) \
    TRICE_LEAVE

#define TRice64_2_m( tid, v0, v1 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 16<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_2( v0, v1); \
    TRICE_LEAVE

#define TRice64_3_m( tid, v0, v1, v2 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 24<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_3 ( v0, v1, v2 ); \
    TRICE_LEAVE

#define TRice64_4_m( tid, v0, v1, v2, v3 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 32<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_4( v0, v1, v2, v3 ); \
    TRICE_LEAVE

#define TRice64_5_m( tid, v0, v1, v2, v3, v4 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 40<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_5( v0, v1, v2, v3, v4 ); \
    TRICE_LEAVE

#define TRice64_6_m( tid, v0, v1, v2, v3, v4, v5 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 48<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_6( v0, v1, v2, v3, v4, v5 ); \
    TRICE_LEAVE

#define TRice64_7_m( tid, v0, v1, v2, v3, v4, v5, v6 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 56<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_7( v0, v1, v2, v3, v4, v5, v6 ); \
    TRICE_LEAVE

#define TRice64_8_m( tid, v0, v1, v2, v3, v4, v5, v6, v7 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 64<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_8( v0, v1, v2, v3, v4, v5, v6, v7 ); \
    TRICE_LEAVE

#define TRice64_9_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 72<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_9( v0, v1, v2, v3, v4, v5, v6, v7, v8 ); \
    TRICE_LEAVE

#define TRice64_10_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 80<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_10( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ); \
    TRICE_LEAVE

#define TRice64_11_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 88<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_11( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ); \
    TRICE_LEAVE

#define TRice64_12_m( tid, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_ENTER \
    uint32_t ts = TRICE_HTOTL(TriceStamp32()); \
    TRICE_PUT((ts<<16) | 0xc000 | tid); \
    TRICE_PUT( 96<<24 | (TRICE_CYCLE<<16) | (ts>>16) ); \
    TRICE_PUT64_12( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) \
    TRICE_LEAVE

#define TRice64_1_M( tid,  fmt, v0 ) TRice64_1_fn( tid,  (uint64_t)(v0) ) //!< TRice64_1_M is a macro calling a function to reduce code size.
#define TRice64_2_M( tid,  fmt, v0, v1 ) TRice64_2_fn( tid,  (uint64_t)(v0), (uint64_t)(v1) ) //!< TRice64_2_M is a macro calling a function to reduce code size.
#define TRice64_3_M( tid,  fmt, v0, v1, v2 ) TRice64_3_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2) ) //!< TRice64_3_M is a macro calling a function to reduce code size.
#define TRice64_4_M( tid,  fmt, v0, v1, v2, v3 ) TRice64_4_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3) ) //!< TRice64_4_M is a macro calling a function to reduce code size.
#define TRice64_5_M( tid,  fmt, v0, v1, v2, v3, v4 ) TRice64_5_fn( tid,  (uint64_t)v0, (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4) ) //!< TRice64_5_M is a macro calling a function to reduce code size.
#define TRice64_6_M( tid,  fmt, v0, v1, v2, v3, v4, v5 ) TRice64_6_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5) ) //!< TRice64_6_M is a macro calling a function to reduce code size.
#define TRice64_7_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6 ) TRice64_7_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6) ) //!< TRice64_7_M is a macro calling a function to reduce code size.
#define TRice64_8_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6, v7 ) TRice64_8_fn( tid,  (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7) ) //!< TRice64_64_M is a macro calling a function to reduce code size.
#define TRice64_9_M( tid,  fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8 ) TRice64_9_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8) ) //!< TRice64_9_M is a macro calling a function to reduce code size.
#define TRice64_10_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9 ) TRice64_10_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9) ) //!< TRice64_10_M is a macro calling a function to reduce code size.
#define TRice64_11_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10 ) TRice64_11_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9), (uint64_t)(v10) ) //!< TRice64_11_M is a macro calling a function to reduce code size.
#define TRice64_12_M( tid, fmt, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11 ) TRice64_12_fn( tid, (uint64_t)(v0), (uint64_t)(v1), (uint64_t)(v2), (uint64_t)(v3), (uint64_t)(v4), (uint64_t)(v5), (uint64_t)(v6), (uint64_t)(v7), (uint64_t)(v8), (uint64_t)(v9), (uint64_t)(v10), (uint64_t)(v11) ) //!< TRice64_12_M is a macro calling a function to reduce code size.

void TRice64_1_fn( uint64_t tid,  uint64_t v0 );
void TRice64_2_fn( uint64_t tid,  uint64_t v0, uint64_t v1 );
void TRice64_3_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2 );
void TRice64_4_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3 );
void TRice64_5_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4 );
void TRice64_6_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5 );
void TRice64_7_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6 );
void TRice64_8_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7 );
void TRice64_9_fn( uint64_t tid,  uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8 );
void TRice64_10_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9 );
void TRice64_11_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9, uint64_t v10 );
void TRice64_12_fn( uint64_t tid, uint64_t v0, uint64_t v1, uint64_t v2, uint64_t v3, uint64_t v4, uint64_t v5, uint64_t v6, uint64_t v7, uint64_t v8, uint64_t v9, uint64_t v10, uint64_t v11 );
