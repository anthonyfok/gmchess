/*
 * =====================================================================================
 * 
 *       Filename:  gmchess.h
 * 
 *    Description:  定义一些常量
 * 
 *        Version:  1.0
 *        Created:  2009年02月14日 18时28分19秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  Cyclone
 * 
 * =====================================================================================
 */

#ifndef  GMCHESS_FILE_HEADER_INC
#define  GMCHESS_FILE_HEADER_INC

#include <stdio.h>
//保存的最大历史局面数
const int MAX_COUNT=512;

// 每种子力的开始序号和结束序号
 const int KING_FROM = 0;
 const int ADVISOR_FROM = 1;
 const int ADVISOR_TO = 2;
 const int BISHOP_FROM = 3;
 const int BISHOP_TO = 4;
 const int KNIGHT_FROM = 5;
 const int KNIGHT_TO = 6;
 const int ROOK_FROM = 7;
 const int ROOK_TO = 8;
 const int CANNON_FROM = 9;
 const int CANNON_TO = 10;
 const int PAWN_FROM = 11;
 const int PAWN_TO = 15;

const int RANK_TOP = 3;
const int RANK_BOTTOM = 12;
const int FILE_LEFT = 3;
const int FILE_CENTER = 7;
const int FILE_RIGHT = 11;


//初始化的FEN串
const char *const cszStartFen = "rnbakabnr/9/1c5c1/p1p1p1p1p/9/9/P1P1P1P1P/1C5C1/9/RNBAKABNR w";

// 棋子类型对应的棋子符号
const char *const cszPieceBytes = "KABNRCPkabnrcp";

const int PieceTypes[48] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 6, 6, 6,
  7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 12, 13, 13, 13, 13, 13
};

enum {  
	RED_KING=0,RED_ADVISOR,RED_BISHOP,RED_KNIGHT,RED_ROOT,RED_CANNON,RED_PAWN,
	BLACK_KING,BLACK_ADVISOR,BLACK_BISHOP,BLACK_KNIGHT,BLACK_ROOT,BLACK_CANNON,BLACK_PAWN,
	RED_KING_DIE,BLACK_KING_DIE,
	NULL_CHESSMAN,SELECTED_CHESSMAN,
};

/** 棋子数组示例*/
const int PieceExample[48] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0xc7, 0xc6, 0xc8, 0xc5, 0xc9, 0xc4, 0xca, 0xc3, 0xcb, 0xa4,0xaa,0x93,0x95,0x97,0x99,0x9b,
  0x37,  0x36,  0x38,  0x35,  0x39, 0x34,  0x3a,  0x33,  0x3b,  0x54,  0x5a,  0x63,  0x65,  0x67,  0x69,0x6b
};

#ifdef __DEBUG_D

#define DLOG(fmt, ...) \
    { \
        char buffer[36] = {0}; \
        time_t t = time(NULL); \
        strftime(buffer, 36, "%F %T ", localtime(&t)); \
        fprintf(stderr, "%s %s|%d| " fmt, \
                buffer, __FILE__, __LINE__, ##__VA_ARGS__); \
    }

#define RLOG(fmt, ...) \
    { \
        char buffer[36] = {0}; \
        time_t t = time(NULL); \
        strftime(buffer, 36, "%F %T ", localtime(&t)); \
        fprintf(stderr, "%s %s|%d| " fmt, \
                buffer, __FILE__, __LINE__, ##__VA_ARGS__); \
    }

#elif __RELEASE_D

#define DLOG(fmt, ...) \
        ;

#define RLOG(fmt, ...) \
    { \
        char buffer[36] = {0}; \
        time_t t = time(NULL); \
        strftime(buffer, 36, "%F %T ", localtime(&t)); \
        fprintf(stdout, "%s " fmt, buffer, ##__VA_ARGS__); \
    }

#else // by default: __RELEASE_D and __DEBUG_D are not present in compilation

#define DLOG(fmt, ...) \
    { \
        char buffer[36] = {0}; \
        time_t t = time(NULL); \
        strftime(buffer, 36, "%F %T ", localtime(&t)); \
        fprintf(stderr, "%s %s|%d| " fmt, \
                buffer, __FILE__, __LINE__, ##__VA_ARGS__); \
    }

#define RLOG(fmt, ...) \
    { \
        char buffer[36] = {0}; \
        time_t t = time(NULL); \
        strftime(buffer, 36, "%F %T ", localtime(&t)); \
        fprintf(stdout, "%s " fmt, buffer, ##__VA_ARGS__); \
    }

#endif



#endif   /* ----- #ifndef GMCHESS_FILE_HEADER_INC  ----- */

