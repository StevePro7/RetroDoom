//#if !defined(__R_STATE_H__)
//#define __R_STATE_H__
//
//// Need data structure definitions.
//#include "d_player.h"
//
////
//// Refresh internal data structures,
////  for rendering.
////
//
//// needed for texture pegging
//extern fixed_t      *textureheight;
//
//extern byte         **brightmap;
//extern dboolean     *nobrightmap;
//
//// needed for pre rendering (fracs)
//extern fixed_t      *spritewidth;
//extern fixed_t      *spriteheight;
//
//extern fixed_t      *spriteoffset;
//extern fixed_t      *spritetopoffset;
//extern fixed_t      *newspriteoffset;
//extern fixed_t      *newspritetopoffset;
//
//extern int          viewwidth;
//extern int          scaledviewwidth;
//extern int          viewheight;
//
//extern int          firstflat;
//
//// for global animation
//extern int          *flattranslation;
//extern int          *texturetranslation;
//
//// Sprite...
//extern int          firstspritelump;
//extern int          lastspritelump;
//
////
//// Lookup tables for map data.
////
//extern spritedef_t  *sprites;
//
//extern int          numvertexes;
//extern vertex_t     *vertexes;
//
//extern int          numsegs;
//extern seg_t        *segs;
//
//extern int          numsectors;
//extern sector_t     *sectors;
//
//extern int          numliquid;
//extern int          numdamaging;
//
//extern int          numsubsectors;
//extern subsector_t  *subsectors;
//
//extern int          numnodes;
//extern node_t       *nodes;
//
//extern int          numlines;
//extern line_t       *lines;
//
//extern int          numsides;
//extern side_t       *sides;
//
//extern int          numtextures;
//
//extern int          numspawnedthings;
//extern int          thingid;
//extern int          numdecorations;
//
//typedef enum
//{
//    DOOMBSP,
//    DEEPBSP,
//    ZDBSPX
//} mapformat_t;
//
//extern mapformat_t  mapformat;
//extern const char   *mapformats[];
//
//extern dboolean     boomcompatible;
//extern dboolean     mbfcompatible;
//extern dboolean     blockmaprebuilt;
//extern dboolean     nojump;
//extern dboolean     nomouselook;
//
////
//// POV data.
////
//extern fixed_t      viewx;
//extern fixed_t      viewy;
//extern fixed_t      viewz;
//
//extern angle_t      viewangle;
//extern player_t     *viewplayer;
//
//extern angle_t      clipangle;
//
//extern int          viewangletox[FINEANGLES / 2];
//extern angle_t      xtoviewangle[SCREENWIDTH + 1];
//
//extern visplane_t   *floorplane;
//extern visplane_t   *ceilingplane;
//
//#endif
