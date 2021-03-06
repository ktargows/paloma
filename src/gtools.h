/*****************************************************************************
* This is the mean header file for gtools.                                   *
* Generated automatically from gtools-h.in by configure.
*****************************************************************************/

/* The parts between the ==== lines are modified by configure when
creating gtools.h out of gtools-h.in.  If configure is not being
used, it is necessary to check they are correct.
====================================================================*/


#define HAVE_ERRNO_H  1      /* <errno.h> exists */
#define HAVE_PERROR  1          /* perror() exists */
#define HAVE_PIPE  1          /* pipe() exists */
#define HAVE_WAIT  1          /* wait() exists */
#define HAVE_POPEN  1          /* popen() and pclose() exist */
#define POPEN_DEC  1         /* popen() is declared in stdio.h */
#define FTELL_DEC  1         /* ftell() is declared in stdio.h */
#define SORTPROG  "sort"         /* name of sort program */
#define HAVE_PID_T 1    /* pid_t is defined */

/*==================================================================*/

#ifndef MAXN 
#define MAXN 64 // modified from MAXN 0 in original
#endif
#define G6LEN(n)  (((n)*((n)-1)/2+5)/6+(n<=SMALLN?1:4))
		/* Exact length of graph6 code except for \n\0 */

#include "naututil.h"      /* which includes stdio.h */

#if HAVE_ERRNO_H
#include <errno.h>
#else
extern int errno;
#endif

#if HAVE_PERROR
#define ABORT(msg) {if (errno != 0) perror(msg); exit(1);}
#else
#define ABORT(msg) {exit(1);}
#endif

#define BIAS6 63
#define MAXBYTE 126
#define SMALLN 62
#define TOPBIT6 32
#define C6MASK 63

#define GRAPH6_HEADER ">>graph6<<"
#define SPARSE6_HEADER ">>sparse6<<"

#define GRAPH6         1
#define SPARSE6        2
#define UNKNOWN_TYPE 256
#define HAS_HEADER   512

#define ARG_OK 0
#define ARG_MISSING 1
#define ARG_TOOBIG 2
#define ARG_ILLEGAL 3

#define MAXARG 2000000000L
#define NOLIMIT (MAXARG+31L)

#define SWBOOLEAN(c,bool) if (sw==c) bool=TRUE;
#define SWINT(c,bool,val,id) if (sw==c) \
        {bool=TRUE;arg_int(&arg,&val,id);}
#define SWLONG(c,bool,val,id) if (sw==c) \
        {bool=TRUE;arg_long(&arg,&val,id);}
#define SWRANGE(c,sep,bool,val1,val2,id) if (sw==c) \
	{bool=TRUE;arg_range(&arg,sep,&val1,&val2,id);}

#define HELP if (argc > 1 && (strcmp(argv[1],"-help")==0 \
			   || strcmp(argv[1],"/?")==0 \
			   || strcmp(argv[1],"--help")==0)) \
       { printf("\nUsage: %s\n\n%s",USAGE,HELPTEXT); return 0;}
#define GETHELP \
fprintf(stderr,"   Use %s -help to see more detailed instructions.\n",argv[0])

#define alloc_error gt_abort

/************************************************************************/

extern FILE *opengraphfile(char*,int*,boolean,long);
extern void writeline(FILE*,char*);
// GG 12/03/2010
extern char *getline_fm(FILE*);
extern int graphsize(char*);
extern void stringtograph(char*,graph*,int);
extern graph *readg(FILE*,graph*,int,int*,int*);
extern char *ntog6(graph*,int,int);
extern char *ntos6(graph*,int,int);
extern void writeg6(FILE*,graph*,int,int);
extern void writes6(FILE*,graph*,int,int);
extern void writelast(FILE*);
extern int longval(char**,long*);
extern void arg_int(char**,int*,char*);
extern void arg_long(char**,long*,char*);
extern void arg_range(char**,char*,long*,long*,char*);
extern void writerange(FILE*,int,long,long);
// GG
extern void gt_abort(const char*);
extern char *stringcopy(char*);
extern boolean strhaschar(char*,int);

extern void fcanonise(graph*,int,int,graph*,char*);
extern void fcanonise_inv
             (graph*,int,int,graph*,char*,void(*)(),int,int,int);
extern void fgroup(graph*,int,int,char*,int*,int*);
extern void fgroup_inv
	     (graph*,int,int,char*,int*,int*,void(*)(),int,int,int);
extern int istransitive(graph*,int,int,graph*);
extern void tg_canonise(graph*,graph*,int,int);

extern int readg_code;
extern char *readg_line;
extern long ogf_linelen;
extern boolean is_pipe;

#ifdef CPUDEFS
CPUDEFS
#endif
