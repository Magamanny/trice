/*! \file trice.h
\author thomas.toehenleitner [at] seerose.net
*******************************************************************************/

#ifndef TRICE_H_
#define TRICE_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TRICE_NO_CODE_ENCODING 10
#define TRICE_BARE_ENCODING    20
#define TRICE_ESC_ENCODING     30
#define TRICE_PACK_ENCODING    40

#define TRICE_LITTLE_ENDIANESS 0x00112233
#define TRICE_BIG_ENDIANESS    0x33221100

#include "triceConfig.h"
#include "intern/triceConfigCompiler.h"
#include "intern/triceFifo.h"
#include "intern/triceSeggerRTT.h"
#ifdef ENCRYPT
#include "intern/triceXteaCrypto.h"
#endif

#define TRICE_U8_JOIN(  first, second ) ((uint16_t)((((uint8_t )(first))<< 8)|((uint8_t )(second)))) //!< helper macro
#define TRICE_U16_JOIN( first, second ) (          ((((uint32_t)(first))<<16)|((uint16_t)(second)))) //!< helper macro


#if TRICE_HARDWARE_ENDIANESS == TRICE_TRANSFER_ENDIANESS
#define TRICE_HTONS(n) ((uint16_t)(n))
#define TRICE_HTON(n)  ((uint32_t)(n))
#else
#define TRICE_HTONS(n) ( (((uint16_t)(n))>>8) | (((uint16_t)(n))<<8) )
#define TRICE_HH(n)                     ((uint32_t)(n)>>24)
#define TRICE_HL(n) ((uint32_t)(uint8_t)((uint32_t)(n)>>16))
#define TRICE_LH(n) ((uint32_t)         ((uint16_t)(n)>> 8))
#define TRICE_LL(n) ((uint32_t)         (( uint8_t)(n)    ))
#define TRICE_HTON(n) ((TRICE_LL(n)<<24)|(TRICE_LH(n)<<16)|(TRICE_HL(n)<<8)|TRICE_HH(n) )
#endif
#define TRICE_HTON_U32PUSH(v) TRICE_U32PUSH( TRICE_HTON(v) )

#if TRICE_NOCODE_ENCODING == TRICE_ENCODING
#include "intern/triceNoCode.h"
#endif

#if TRICE_ESC_ENCODING == TRICE_ENCODING
#include "intern/triceEscEncoder.h"
#include "intern/triceFifoToBytesBuffer.h"
#endif


#if TRICE_BARE_ENCODING == TRICE_ENCODING
#include "intern/triceFastBareEncoder.h"
#include "intern/triceFifoToBytesBuffer.h"
#endif

#if TRICE_PACK_ENCODING == TRICE_ENCODING
#include "intern/tricePackEncoder.h"
#endif

#ifndef TRICE_SYNC // some encoder define a sync trice
#define TRICE_SYNC do{ } while(0)// otherwise empty definition for compability
#endif

#ifdef __cplusplus
}
#endif

#endif // TRICE_H_
